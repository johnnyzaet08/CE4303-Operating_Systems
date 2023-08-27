#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

// Function to save an image to a file
void saveImageToFile(const unsigned char *imageBuffer, long imageSize, const char *filename) {
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
    // Check for the correct number of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s 5000\n", argv[0]);
        return 1;
    }

    // Extract the port number from the command line argument
    int port = atoi(argv[1]);

    // Create a socket for the server
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        perror("Error creating socket");
        return 1;
    }

    // Set up the server address structure
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the server address
    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
        perror("Error binding");
        close(serverSocket);
        return 1;
    }

    // Listen for incoming connections
    if (listen(serverSocket, 5) == -1) {
        perror("Error listening");
        close(serverSocket);
        return 1;
    }

    printf("Waiting for connections on port %d...\n", port);

    while (1) {
        // Accept a new client connection
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
            // Receive the image size from the client
            long imageSize;
            ssize_t bytesReceived = recv(clientSocket, &imageSize, sizeof(imageSize), 0);

            // Handle disconnection or error
            if (bytesReceived <= 0) {
                if (bytesReceived == 0) {
                    printf("Client disconnected.\nWaiting for connections on port %d...\n", port);
                } else {
                    perror("Error receiving data from client");
                }
                break;
            }

            // Receive the image data from the client
            unsigned char *imageBuffer = (unsigned char *)malloc(imageSize);
            bytesReceived = recv(clientSocket, imageBuffer, imageSize, 0);

            // Handle disconnection or error while receiving image data
            if (bytesReceived <= 0) {
                if (bytesReceived == 0) {
                    printf("Client disconnected.\nWaiting for connections on port %d...\n", port);
                } else {
                    perror("Error receiving data from client");
                }
                free(imageBuffer);
                break;
            }

            // Save the received image to a file
            char filename[50];
            snprintf(filename, sizeof(filename), "image_%ld.jpg", imageSize);
            saveImageToFile(imageBuffer, imageSize, filename);

            free(imageBuffer);

            printf("Image received and processed.\n");
        }

        // Close the client socket
        close(clientSocket);
    }

    // Close the server socket
    close(serverSocket);

    return 0;
}