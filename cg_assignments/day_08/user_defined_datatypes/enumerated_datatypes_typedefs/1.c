/*1. WAP to define an enum to store designations in an organization. List of possible values are
{E2F=1, E2, E3, E4, E5}
Prompt and read a designation from the user. Then display his designation string such as */


#include <stdio.h>
#include <string.h>
typedef struct {
    char hostName[100];   
    int port;             
    char username[50];    
    char password[50];    
    char connectionType[20]; 
    int timeout;          
    char encoding[20];    
    int windowRows;       
    int windowCols;     
} PuttyConfig;

int main() {
    PuttyConfig config = {
        "192.168.1.100",    // Hostname
        22,                 // Port
        "admin",            // Username
        "securepassword",   // Password
        "SSH",              // Connection Type
        30,                 // Timeout in seconds
        "UTF-8",            // Encoding
        24,                 // Window rows
        80                  // Window columns
    };

    // Display the configuration
    printf("PuTTY Server Configuration:\n");
    printf("Host Name: %s\n", config.hostName);
    printf("Port: %d\n", config.port);
    printf("Username: %s\n", config.username);
    printf("Password: %s\n", config.password);
    printf("Connection Type: %s\n", config.connectionType);
    printf("Timeout: %d seconds\n", config.timeout);
    printf("Encoding: %s\n", config.encoding);
    printf("Window Size: %dx%d\n", config.windowRows, config.windowCols);
    return 0;
}
