#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 32000

int main() {
    char ip[16]; // Store the IP address as a string (xxx.xxx.xxx.xxx)
    int port;
    char name[16];
    char option[2];

    printf("Enter the IP address: ");
    fgets(ip, sizeof(ip), stdin);
    ip[strcspn(ip, "\n")] = '\0'; // Remove newline character

    printf("Enter the port number: ");
    scanf("%d", &port);
    getchar(); // Consume the newline character left in the input buffer

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
    ssize_t bytesReceived;

    bytesReceived = recv(clientSocket, buffer, MAX_BUFFER_SIZE - 1, 0);
    if (bytesReceived == -1) {
        perror("Error receiving message from server");
    } else {
        buffer[bytesReceived] = '\0';
        printf("Server says: %s\n", buffer);
    }

    printf("Enter the name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline character

    const char *message = name;
    send(clientSocket, message, strlen(message), 0);

    while(1){
        bytesReceived = recv(clientSocket, buffer, MAX_BUFFER_SIZE - 1, 0);
        if (bytesReceived == -1) {
            perror("Error receiving message from server");
        } else {
            buffer[bytesReceived] = '\0';
            printf("Server says: %s\n", buffer);
            if(strcmp(buffer, "Successful") == 0){
                break;  
            } else{
                printf("Enter select the option: ");
                fgets(option, sizeof(option), stdin);
                option[strcspn(option, "\n")] = '\0'; // Remove newline character

                const char *message = option;
                send(clientSocket, message, strlen(message), 0);
            }
        }

        
    }


    while (1) {
        printf("Enter the path of the image to send (or type 'Exit' to quit): ");
        fgets(buffer, MAX_BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';  // Remove newline character

        if (strcmp(buffer, "Exit") == 0) {
            printf("Exiting....");
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

        bytesReceived = recv(clientSocket, buffer, MAX_BUFFER_SIZE - 1, 0);
        buffer[bytesReceived] = '\0';
        printf("Server says: %s\n", buffer);
    }

    // Close the client socket
    close(clientSocket);

    return 0;
}