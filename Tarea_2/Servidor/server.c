#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_BUFFER_SIZE 32000

int current_connections = 0;
char dir_colors[256];
char dir_histo[256];
char dir_log[256];
char messageLog[4096];

void printToLog(char *message){
    FILE *logFile;
    logFile = fopen(dir_log, "a");
    if (logFile == NULL) {
        perror("Error opening log file");
    }
    fprintf(logFile, message);
    fclose(logFile);
}

// Define the main color enum
enum MainColor {
    RED,
    GREEN,
    BLUE
};

// Function to determine the main color of an RGB pixel
enum MainColor getMainColor(uint8_t r, uint8_t g, uint8_t b) {
    if (r > g && r > b) {
        return RED;
    } else if (g > r && g > b) {
        return GREEN;
    } else {
        return BLUE;
    }
}

// Function to separate the image into main color channels
const char *separateImageByMainColor(unsigned char *imageBuffer, int imageSize) {
    int redCount = 0;
    int greenCount = 0;
    int blueCount = 0;

    for (int i = 0; i < imageSize; i += 3) {  // Assuming 3 bytes per pixel (RGB)
        uint8_t r = imageBuffer[i];
        uint8_t g = imageBuffer[i + 1];
        uint8_t b = imageBuffer[i + 2];

        enum MainColor mainColor = getMainColor(r, g, b);

        switch (mainColor) {
            case RED:
                redCount++;
                break;
            case GREEN:
                greenCount++;
                break;
            case BLUE:
                blueCount++;
                break;
        }
    }

    enum MainColor dominantColor;
    if (redCount > greenCount && redCount > blueCount) {
        dominantColor = RED;
    } else if (greenCount > redCount && greenCount > blueCount) {
        dominantColor = GREEN;
    } else {
        dominantColor = BLUE;
    }

    const char *colorNames[] = { "Red", "Green", "Blue" };
    snprintf(messageLog, sizeof(messageLog), "Dominant Color: %s\n", colorNames[dominantColor]);
    printToLog(messageLog);
    return colorNames[dominantColor];
}

void histogramEqualization(unsigned char *imageBuffer, int imageSize) {
    int histogram[256] = {0};
    int cumulativeHistogram[256] = {0};

    for (int i = 0; i < imageSize; i++) {
        histogram[imageBuffer[i]]++;
    }

    cumulativeHistogram[0] = histogram[0];
    for (int i = 1; i < 256; i++) {
        cumulativeHistogram[i] = cumulativeHistogram[i - 1] + histogram[i];
    }

    for (int i = 0; i < imageSize; i++) {
        imageBuffer[i] = (cumulativeHistogram[imageBuffer[i]] * 255) / imageSize;
    }
}

void saveImageToFile(unsigned char *imageBuffer, long imageSize, char *clientName, char *clientOption) {
    
    char filename[2048];

    if(strcmp(clientOption, "1") == 0){
        snprintf(filename, sizeof(filename), "%s%s_image_%ld.jpg", dir_histo, clientName, imageSize);
        histogramEqualization(imageBuffer, imageSize);
    } else{
        const char *dominantColor = separateImageByMainColor(imageBuffer, imageSize);
        snprintf(filename, sizeof(filename), "%s%s/%s_image_%ld.jpg", dir_colors, dominantColor, clientName, imageSize);
    }


    FILE *imageFile = fopen(filename, "wb");
    if (!imageFile) {
        snprintf(messageLog, sizeof(messageLog), "Error opening file to save the image");
        printToLog(messageLog);
    }

    size_t bytesWritten = fwrite(imageBuffer, 1, imageSize, imageFile);
    if (bytesWritten != imageSize) {
        snprintf(messageLog, sizeof(messageLog), "Error writing image to file");
        printToLog(messageLog);
    } else {
        snprintf(messageLog, sizeof(messageLog), "Image saved as %s\n", filename);
        printToLog(messageLog);
    }

    fclose(imageFile);
}

struct ClientThreadArgs {
    int clientSocket;
};

void *clientThread(void *args) {
    struct ClientThreadArgs *threadArgs = (struct ClientThreadArgs *)args;
    int clientSocket = threadArgs->clientSocket;
    free(args); // Free the memory allocated for thread arguments

    char buffer[MAX_BUFFER_SIZE];
    ssize_t bytesReceived;
    char clientName[16];
    char clientOption[2];

    char *message = "Welcome to the server! What is your name?";
    send(clientSocket, message, strlen(message), 0);

    // Receive a message from the client
    bytesReceived = recv(clientSocket, buffer, MAX_BUFFER_SIZE - 1, 0);
    if (bytesReceived == -1) {
        snprintf(messageLog, sizeof(messageLog), "Error receiving message from client");
        printToLog(messageLog);
    } else {
        buffer[bytesReceived] = '\0';
        strcpy(clientName, buffer);
        snprintf(messageLog, sizeof(messageLog), "Connection stablished with new client: %s\n", clientName);
        printToLog(messageLog);
    }
    
    while(1){
        message = "Please select an option: \n1. Equalization histogram \n2. Classify images";
        send(clientSocket, message, strlen(message), 0);

        bytesReceived = recv(clientSocket, buffer, MAX_BUFFER_SIZE - 1, 0);
        if (bytesReceived == -1) {
            snprintf(messageLog, sizeof(messageLog), "Error receiving message from client");
            printToLog(messageLog);
        } else {
            buffer[bytesReceived] = '\0';
            strcpy(clientOption, buffer);
            if(strcmp(clientOption, "1") == 0 || strcmp(clientOption, "2") == 0){
                snprintf(messageLog, sizeof(messageLog), "%s selected option: %s\n", clientName, clientOption);
                printToLog(messageLog);
                message = "Successful";
                send(clientSocket, message, strlen(message), 0);
                break;
            }
        }
    }
    

    while(1){
        snprintf(messageLog, sizeof(messageLog), "Waiting image from %s\n", clientName);
        printToLog(messageLog);

        long imageSize;
        bytesReceived = recv(clientSocket, &imageSize, sizeof(imageSize), 0);

        if (bytesReceived <= 0) {
            if (bytesReceived == 0) {
                snprintf(messageLog, sizeof(messageLog), "Connection finished with: %s\n", clientName);
                printToLog(messageLog);
                break;
            } else {
                snprintf(messageLog, sizeof(messageLog), "Error receiving data from client");
                printToLog(messageLog);
            }
        }

        unsigned char *imageBuffer = (unsigned char *)malloc(imageSize);
        size_t totalReceived = 0;

        while (totalReceived < imageSize) {
            ssize_t recvResult = recv(clientSocket, imageBuffer + totalReceived, imageSize - totalReceived, 0);
            if (recvResult <= 0) {
                if (recvResult == 0) {
                    snprintf(messageLog, sizeof(messageLog), "Connection finished with: %s\n", clientName);
                    printToLog(messageLog);
                } else {
                    snprintf(messageLog, sizeof(messageLog), "Error receiving data from client");
                    printToLog(messageLog);
                }
                free(imageBuffer);
            }
            totalReceived += recvResult;
        }

        // Save the received image to a file with a unique name
        saveImageToFile(imageBuffer, imageSize, clientName, clientOption);

        free(imageBuffer);

        message = "Image received and processed";
        send(clientSocket, message, strlen(message), 0);

    }

    current_connections --;    
    return NULL;
}

int main() {
    int port = 0;
    int max_connections = 0;

    FILE *configFile = fopen("/etc/server/config.conf", "r");
    if (!configFile) {
        snprintf(messageLog, sizeof(messageLog), "Error opening config file");
        printToLog(messageLog);
    }

    char key[MAX_BUFFER_SIZE];
    char value[MAX_BUFFER_SIZE];
    while (fscanf(configFile, "%[^:]:%s\n", key, value) == 2) {
        if (strcmp(key, "Port") == 0) {
            port = atoi(value);
        } else if (strcmp(key, "MaxConecctions") == 0) {
            max_connections = atoi(value);
        } else if (strcmp(key, "DirColors") == 0) {
            strcpy(dir_colors, value);
        } else if (strcmp(key, "DirHisto") == 0) {
            strcpy(dir_histo, value);
        } else if (strcmp(key, "DirLog") == 0) {
            strcpy(dir_log, value);
        }
    }

    fclose(configFile);

    if (port == 0 || max_connections == 0) {
        fprintf(stderr, "Invalid configuration values\n");
        return 1;
    }

    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

     if (serverSocket == -1) {
        snprintf(messageLog, sizeof(messageLog), "Error creating socket");
        printToLog(messageLog);
        return 1;
    }

    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
        snprintf(messageLog, sizeof(messageLog), "Error binding");
        printToLog(messageLog);
        close(serverSocket);
        return 1;
    }

    if (listen(serverSocket, max_connections) == -1) {
        snprintf(messageLog, sizeof(messageLog), "Error listening");
        printToLog(messageLog);
        close(serverSocket);
        return 1;
    }

    snprintf(messageLog, sizeof(messageLog), "Waiting for connections on port %d...\n", port);
    printToLog(messageLog);

    while (1) {
        struct sockaddr_in clientAddress;
        socklen_t clientSize = sizeof(clientAddress);

        int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientSize);
        if (clientSocket == -1) {
            snprintf(messageLog, sizeof(messageLog), "Error accepting connection");
            printToLog(messageLog);
            continue;
        }

        if (max_connections > 0) {
            // Check if max_connections limit is reached
            if (current_connections >= max_connections) {
                snprintf(messageLog, sizeof(messageLog), "Max connections reached. Rejecting a client.\n");
                printToLog(messageLog);
                close(clientSocket);
                continue;
            }
        }

        current_connections++;

        struct ClientThreadArgs *threadArgs = malloc(sizeof(struct ClientThreadArgs));
        threadArgs->clientSocket = clientSocket;

        pthread_t tid;
        if (pthread_create(&tid, NULL, clientThread, threadArgs) != 0) {
            snprintf(messageLog, sizeof(messageLog), "Error creating client thread");
            printToLog(messageLog);
            close(clientSocket);
            free(threadArgs);
        }
        pthread_detach(tid);
    }

    close(serverSocket);

    return 0;
}
