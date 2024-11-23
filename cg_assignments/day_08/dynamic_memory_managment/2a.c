/* 2. WAP to read a URL as input from the user, extract the host name and domain name, store them collectively in an appropriate data structure allocating dynamic memory for its members as per required length. Display the structure contents. Free the memory finally. Some of the functions to be implemented are:*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isValidURL(char *url) {
    // Basic validation to check if URL starts with http:// or https://
    return (strstr(url, "http://") == url || strstr(url, "https://") == url);
}

char *gethost(char *url) {
    if (!isValidURL(url)) {
        return NULL;
    }

    // Extract the part after "http://"
    char *start = strstr(url, "://");
    if (start == NULL) return NULL;
    start += 3;  // Skip "://"

    // Extract hostname until the first '/'
    char *end = strchr(start, '/');
    if (end == NULL) {
        end = start + strlen(start);
    }

    size_t length = end - start;
    char *host = (char *)malloc(length + 1);
    if (host == NULL) {
        return NULL;
    }
    strncpy(host, start, length);
    host[length] = '\0';
    return host;
}

char *getdomain(char *url) {
    char *host = gethost(url);
    if (host == NULL) return NULL;

    // Find the last period in the hostname to extract the domain
    char *dot = strrchr(host, '.');
    if (dot == NULL) {
        free(host);
        return NULL;
    }

    char *domain = strdup(dot + 1);  // Copy everything after the last period
    free(host);
    return domain;
}

void display(char *host, char *domain) {
    if (host != NULL && domain != NULL) {
        printf("Host: %s\n", host);
        printf("Domain: %s\n", domain);
    } else {
        printf("Error extracting hostname or domain from the URL.\n");
    }
}

int main() {
    char url[100];
    printf("Enter the URL: ");
    scanf("%99s", url);  // Read URL from user

    char *host = gethost(url);
    char *domain = getdomain(url);

    display(host, domain);

    // Free allocated memory
    if (host != NULL) free(host);
    if (domain != NULL) free(domain);

    return 0;
}
