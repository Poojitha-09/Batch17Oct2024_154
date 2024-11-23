/*3. Write below functions to extract and return the required inputs from an email id string of max length 80 characters. Program should be able to detect an invalid email id too based on following validations. Also value returned should be in scope and accessible in caller.

a. valid email id will have username, host and domain name (as .com/.edu) */ 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LENGTH 80
char *getuser(char input[]) {
    char *at = strchr(input, '@'); 
    if (at == NULL || at == input) {
        // No '@' found or '@' is the first character, invalid email
        return NULL;
    }
    size_t len = at - input;
    char *username = (char *)malloc(len + 1);
    if (username == NULL) {
        return NULL; // Memory allocation failed
    }

    strncpy(username, input, len);
    username[len] = '\0';
    
    return username;
}
char *gethost(char input[]) {
    char *at = strchr(input, '@');  
    if (at == NULL || *(at + 1) == '\0') {
        return NULL;
    }
    char *dot = strchr(at + 1, '.');
    if (dot == NULL || dot == at + 1) {
         return NULL;
    }
    size_t len = dot - (at + 1);
    char *hostname = (char *)malloc(len + 1);
    if (hostname == NULL) {
        return NULL; // Memory allocation failed
    }

    strncpy(hostname, at + 1, len);
    hostname[len] = '\0';
    
    return hostname;
}
char *getdomain(char input[]) {
    char *dot = strrchr(input, '.'); // Find the last '.' symbol
    if (dot == NULL || *(dot + 1) == '\0') {
        // No '.' found or '.' is the last character, invalid domain
        return NULL;
    }
    char *domain = (char *)malloc(strlen(dot + 1) + 1);
    if (domain == NULL) {
        return NULL; 
    }

    strcpy(domain, dot + 1);
    return domain;
}
int isValidDomain(char input[]) {
    char *domain = getdomain(input);
    if (domain == NULL) {
        return 0; // Invalid domain
    }

    // Check if the domain is either .com or .edu
    int valid = (strcmp(domain, "com") == 0 || strcmp(domain, "edu") == 0);
    free(domain); 
    return valid;
}

int main() {
    char email[MAX_LENGTH + 1];
    printf("Enter email id: ");
    fgets(email, MAX_LENGTH + 1, stdin);
    if (isValidDomain(email)) {
        char *username = getuser(email);
        char *hostname = gethost(email);
        char *domain = getdomain(email);
        if (username != NULL) {
            printf("Username: %s\n", username);
            free(username);
        } else {
            printf("Invalid username\n");
        }

        if (hostname != NULL) {
            printf("Hostname: %s\n", hostname);
            free(hostname);
        } else {
            printf("Invalid hostname\n");
        }

        if (domain != NULL) {
            printf("Domain: %s\n", domain);
            free(domain);
        } else {
            printf("Invalid domain\n");
        }
    } else {
        printf("Invalid email id. Domain must be '.com' or '.edu'.\n");
    }

    return 0;
}
