#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

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

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s 5000\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

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

    if (listen(serverSocket, 5) == -1) {
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

        printf("Connection established with the client.\n");

        char buffer[MAX_BUFFER_SIZE];
        while (1) {
            long imageSize;
            ssize_t bytesReceived = recv(clientSocket, &imageSize, sizeof(imageSize), 0);

            if (bytesReceived <= 0) {
                if (bytesReceived == 0) {
                    printf("Client disconnected.\nWaiting for connections on port %d...\n", port);
                } else {
                    perror("Error receiving data from client");
                }
                break;
            }

            unsigned char *imageBuffer = (unsigned char *)malloc(imageSize);
            bytesReceived = recv(clientSocket, imageBuffer, imageSize, 0);

            if (bytesReceived <= 0) {
                if (bytesReceived == 0) {
                    printf("Client disconnected.\nWaiting for connections on port %d...\n", port);
                } else {
                    perror("Error receiving data from client");
                }
                free(imageBuffer);
                break;
            }

            // Save the received image to a file with a unique name
            saveImageToFile(imageBuffer, imageSize, "server");

            free(imageBuffer);

            printf("Image received and processed.\n");
        }

        close(clientSocket);
    }

    close(serverSocket);

    return 0;
}
