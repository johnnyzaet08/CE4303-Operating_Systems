#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Check for the correct number of command line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <127.0.0.1> <5000>\n", argv[0]);
        return 1;
    }

    const char *ip = argv[1];
    int port = atoi(argv[2]);

    // Create a socket for the client
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        perror("Error creating socket");
        return 1;
    }

    // Set up the server address structure
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &serverAddress.sin_addr) <= 0) {
        perror("Invalid or unsupported IP address");
        close(clientSocket);
        return 1;
    }

    // Connect to the server
    if (connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
        perror("Error connecting to the server");
        close(clientSocket);
        return 1;
    }

    char buffer[MAX_BUFFER_SIZE];
    while (1) {
        printf("Enter the path of the image to send (or type 'Exit' to quit): ");
        fgets(buffer, MAX_BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';  // Remove newline character

        if (strcmp(buffer, "Exit") == 0) {
            printf("Exiting...\n");
            break;
        }

        FILE *imageFile = fopen(buffer, "rb");
        if (!imageFile) {
            perror("Error opening the image");
            continue;
        }

        fseek(imageFile, 0, SEEK_END);
        long imageSize = ftell(imageFile);
        fseek(imageFile, 0, SEEK_SET);

        if (imageSize <= 0) {
            perror("Invalid image size");
            fclose(imageFile);
            continue;
        }

        // Send the image size to the server
        send(clientSocket, &imageSize, sizeof(imageSize), 0);

        unsigned char *imageBuffer = (unsigned char *)malloc(imageSize);
        fread(imageBuffer, 1, imageSize, imageFile);
        fclose(imageFile);

        // Send the image data to the server
        send(clientSocket, imageBuffer, imageSize, 0);
        free(imageBuffer);

        printf("Image sent successfully.\n");
    }

    // Close the client socket
    close(clientSocket);

    return 0;
}