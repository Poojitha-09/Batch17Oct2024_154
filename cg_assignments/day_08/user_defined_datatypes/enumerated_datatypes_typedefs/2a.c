/* 2. Define a typedef structure to keep the configuration of putty server. Identify and place all the required members. Create a structure variable and initialize it with user defined values and finally display the contents.*/ 


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
    int saveSession;         
} PuttyConfig;

int main() {
    // Declare a variable of type PuttyConfig and initialize it with user-defined values
    PuttyConfig config = {
        "192.168.0.1",    
        22,              
        "admin",          
        "adminpassword",  
        "SSH",            
        30,              
        "UTF-8",         
        24,              
        80,               
        1                 
    };

    // Display the PuTTY server configuration
    printf("PuTTY Server Configuration:\n");
    printf("Host Name: %s\n", config.hostName);
    printf("Port: %d\n", config.port);
    printf("Username: %s\n", config.username);
    printf("Password: %s\n", config.password);  // Note: In real-world scenarios, passwords should be encrypted
    printf("Connection Type: %s\n", config.connectionType);
    printf("Timeout: %d seconds\n", config.timeout);
    printf("Encoding: %s\n", config.encoding);
    printf("Window Size: %dx%d\n", config.windowRows, config.windowCols);
    printf("Save Session: %s\n", config.saveSession ? "Yes" : "No");

    return 0;
}

