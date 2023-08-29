#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_BUFFER_SIZE 1024

int current_connections = 0;

void saveImageToFile(const unsigned char *imageBuffer, long imageSize, const char *prefix) {
    char filename[50];
    snprintf(filename, sizeof(filename), "%s_image_%ld.jpg", prefix, imageSize);

    FILE *imageFile = fopen(filename, "wb");
    if (!imageFile) {
        perror("Error opening file to save the image");
        return;
    }

    size_t bytesWritten = fwrite(imageBuffer, 1, imageSize, imageFile);
    if (bytesWritten != imageSize) {
        perror("Error writing image to file");
    } else {
        printf("Image saved as %s\n", filename);
    }

    fclose(imageFile);
}

struct ClientThreadArgs {
    int clientSocket;
};

void *clientThread(void *args) {
    const char *clientName;
    struct ClientThreadArgs *threadArgs = (struct ClientThreadArgs *)args;
    int clientSocket = threadArgs->clientSocket;
    free(args); // Free the memory allocated for thread arguments

    const char *message = "Welcome to the server!";
    send(clientSocket, message, strlen(message), 0);

    char buffer[MAX_BUFFER_SIZE];
    ssize_t bytesReceived;

    // Receive a message from the client
    bytesReceived = recv(clientSocket, buffer, MAX_BUFFER_SIZE - 1, 0);
    if (bytesReceived == -1) {
        perror("Error receiving message from client");
    } else {
        buffer[bytesReceived] = '\0';
        clientName = buffer;
        printf("Connection stablished with new client: %s\n", clientName);
    }
    

    while(1){
        long imageSize;
        bytesReceived = recv(clientSocket, &imageSize, sizeof(imageSize), 0);

        if (bytesReceived <= 0) {
            if (bytesReceived == 0) {
                printf("Connection finished with: %s\n", clientName);
                break;
            } else {
                perror("Error receiving data from client");
            }
            close(clientSocket);
            return NULL;
        }

        unsigned char *imageBuffer = (unsigned char *)malloc(imageSize);
        bytesReceived = recv(clientSocket, imageBuffer, imageSize, 0);

        if (bytesReceived <= 0) {
            if (bytesReceived == 0) {
                printf("Connection finished with: %s\n", clientName);
                break;
            } else {
                perror("Error receiving data from client");
            }
            free(imageBuffer);
            close(clientSocket);
            return NULL;
        }

        // Save the received image to a file with a unique name
        saveImageToFile(imageBuffer, imageSize, "server");

        free(imageBuffer);

        message = "Image received and processed";
        send(clientSocket, message, strlen(message), 0);

    }

    current_connections --;    
    close(clientSocket);

    return NULL;
}

int main() {
    int port = 0;
    int max_connections = 0;
    char dir_colors[MAX_BUFFER_SIZE];
    char dir_histo[MAX_BUFFER_SIZE];
    char dir_log[MAX_BUFFER_SIZE];

    FILE *configFile = fopen("/etc/server/config.conf", "r");
    if (!configFile) {
        perror("Error opening config file");
        return 1;
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
        perror("Error creating socket");
        return 1;
    }

    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
        perror("Error binding");
        close(serverSocket);
        return 1;
    }

    if (listen(serverSocket, max_connections) == -1) {
        perror("Error listening");
        close(serverSocket);
        return 1;
    }

    printf("Waiting for connections on port %d...\n", port);

    while (1) {
        struct sockaddr_in clientAddress;
        socklen_t clientSize = sizeof(clientAddress);

        int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientSize);
        if (clientSocket == -1) {
            perror("Error accepting connection");
            continue;
        }

        if (max_connections > 0) {
            // Check if max_connections limit is reached
            if (current_connections >= max_connections) {
                printf("Max connections reached. Rejecting a client.\n");
                close(clientSocket);
                continue;
            }
        }

        current_connections++;

        struct ClientThreadArgs *threadArgs = malloc(sizeof(struct ClientThreadArgs));
        threadArgs->clientSocket = clientSocket;

        pthread_t tid;
        if (pthread_create(&tid, NULL, clientThread, threadArgs) != 0) {
            perror("Error creating client thread");
            close(clientSocket);
            free(threadArgs);
        }
        pthread_detach(tid);
    }

    close(serverSocket);

    return 0;
}
