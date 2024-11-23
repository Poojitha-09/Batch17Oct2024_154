/* 1. Write a program to read a line of text containing 2 or more words, tokenize, display the words, concatenate the words using ‘_’ and display the final string. Consider line length of 80 characters. Provide a modular solution implementing following functions.

//process the input string and return a concatenated string allocated memory in heap

char *process_string(char *line);


In main(), free the allocated memory after displaying the concatenated string */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *process_string(char *line) {
    char *result = NULL;
    size_t result_len = 0;
    char *token = strtok(line, " ");  // Tokenize based on spaces

    while (token != NULL) {
        if (result == NULL) {
            result = (char *)malloc(strlen(token) + 1);  
        } else {
            result = (char *)realloc(result, result_len + strlen(token) + 2);  
            result[result_len] = '_';  // Add the underscore
            result_len++;  
        }
        strcpy(result + result_len, token);
        result_len += strlen(token);  
        token = strtok(NULL, " ");
    }

    return result; 
}

int main() {
    char line[80];
    printf("Enter a line of text (up to 80 characters): ");
    fgets(line, sizeof(line), stdin);
    line[strcspn(line, "\n")] = '\0';
    char *final_string = process_string(line);
    printf("Concatenated string: %s\n", final_string);
    free(final_string);

    return 0;
}
