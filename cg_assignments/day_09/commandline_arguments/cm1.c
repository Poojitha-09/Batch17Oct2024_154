/* 1. Write a program to
a. read a name(of max length 40 characters), ip address (as char * string in dotted notation) and port number (unsigned short) of the cloud server as command line arguments.
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the server struct
struct server {
    char name[41];
    char ip[16];
    unsigned short port;
};

// Function to validate IP address
int isValidIP(char *ip) {
    int octets[4];
    if (sscanf(ip, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]) != 4) {
        return 0;  // Invalid format
    }

    for (int i = 0; i < 4; i++) {
        if (octets[i] < 0 || octets[i] > 255) {
            return 0;  // Invalid range
        }
    }

    return 1;
}

// Function to validate port number
int isValidPort(unsigned short port) {
    return (port >= 1 && port <= 65535);
}

// Function to display server configuration
void display(struct server *servercfg) {
    printf("\nServer Configuration:\n");
    printf("Name: %s\n", servercfg->name);
    printf("IP Address: %s\n", servercfg->ip);
    printf("Port: %d\n", servercfg->port);
}

// Function to update server configuration
int update(struct server *servercfg) {
    char temp[41];
    unsigned short tempPort;
    char tempIP[16];

    // Update server name
    printf("Enter new server name (max 40 characters): ");
    fgets(temp, 41, stdin);
    temp[strcspn(temp, "\n")] = '\0';  // Remove newline character
    strncpy(servercfg->name, temp, 40);

    // Update server IP address
    printf("Enter new server IP address: ");
    fgets(tempIP, 16, stdin);
    tempIP[strcspn(tempIP, "\n")] = '\0';  // Remove newline character
    if (!isValidIP(tempIP)) {
        printf("Invalid IP address format.\n");
        return 0;
    }
    strncpy(servercfg->ip, tempIP, 15);

    // Update port number
    printf("Enter new port number (1-65535): ");
    if (scanf("%hu", &tempPort) != 1 || !isValidPort(tempPort)) {
        printf("Invalid port number.\n");
        return 0;
    }
    servercfg->port = tempPort;

    return 1;  // Success
}

// Main function
int main(int argc, char *argv[]) {
    // Validate the number of arguments
    if (argc != 4) {
        printf("Error: Please provide exactly 3 arguments (name, IP, port).\n");
        return 1;
    }

    struct server myServer;

    // Validate and assign the name
    strncpy(myServer.name, argv[1], 40);
    myServer.name[40] = '\0';  // Ensure null termination

    // Validate and assign the IP address
    if (!isValidIP(argv[2])) {
        printf("Error: Invalid IP address format.\n");
        return 1;
    }
    strncpy(myServer.ip, argv[2], 15);
    myServer.ip[15] = '\0';  // Ensure null termination

    // Validate and assign the port number
    unsigned short port = (unsigned short)atoi(argv[3]);
    if (!isValidPort(port)) {
        printf("Error: Invalid port number (should be between 1 and 65535).\n");
        return 1;
    }
    myServer.port = port;

    // Display the initial configuration
    display(&myServer);

    // Ask user if they want to update the configuration
    char choice;
    printf("\nDo you want to update the server configuration? (y/n): ");
    scanf(" %c", &choice);
    getchar();  // To consume the newline left by scanf

    if (choice == 'y' || choice == 'Y') {
        if (update(&myServer)) {
            printf("\nUpdated ");
            display(&myServer);
        } else {
            printf("Failed to update configuration.\n");
        }
    }

    return 0;
}
