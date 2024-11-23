/*3. WAP to read a maximum of N (N is user input) strings or less from the user at runtime, each string could be of variable length not exceeding a maximum length of 80 characters, allocate memory in heap as per string length and store the strings. Stop reading inputs if input string is “end” or “END”. Display the stored strings. Free the memory before exiting program. Some of the functions to be implemented are: */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 80  // Maximum length of each string

// Function to allocate memory for a double pointer to hold n pointers
char **allocate_array_memory(char **ptr, int n) {
    ptr = (char **)malloc(n * sizeof(char *));  // Allocate space for n pointers
    if (ptr == NULL) {
        printf("Memory allocation failed for array of strings.\n");
        exit(1);  // Exit if memory allocation fails
    }
    return ptr;
}

// Function to allocate memory for each string
char *allocate_string_memory(char *string) {
    string = (char *)malloc((MAX_LENGTH + 1) * sizeof(char));  // Allocate space for the string
    if (string == NULL) {
        printf("Memory allocation failed for string.\n");
        exit(1);  // Exit if memory allocation fails
    }
    return string;
}

// Function to display the strings
void display(char **arr, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] != NULL) {
            printf("%s\n", arr[i]);
        }
    }
}

// Function to free the memory allocated for the array of string pointers
void free_array_memory(char **ptr, int n) {
    for (int i = 0; i < n; i++) {
        if (ptr[i] != NULL) {
            free(ptr[i]);  // Free each string
        }
    }
    free(ptr);  // Free the array of pointers
}

// Function to free memory for a single string
void free_string_memory(char *ptr) {
    free(ptr);
}

int main() {
    int n;
    char **strings;  // Double pointer to store the strings
    char *temp_str;  // Temporary pointer to store each input string
    int i = 0;

    // Prompt user for the number of strings to read
    printf("Enter the number of strings (N): ");
    scanf("%d", &n);
    getchar();  // Consume the newline character left by scanf

    // Allocate memory for the array of string pointers
    strings = allocate_array_memory(strings, n);

    // Read strings from the user
    while (i < n) {
        printf("Enter string %d: ", i + 1);
        temp_str = allocate_string_memory(temp_str);
        fgets(temp_str, MAX_LENGTH, stdin);  // Read the input string
        
        // Remove the newline character if present
        temp_str[strcspn(temp_str, "\n")] = '\0';

        // If the input is "end" or "END", stop reading
        if (strcmp(temp_str, "end") == 0 || strcmp(temp_str, "END") == 0) {
            free_string_memory(temp_str);  // Free the temporary string memory
            break;
        }

        // Store the string in the array
        strings[i] = temp_str;
        i++;
    }

    // Display the stored strings
    printf("\nStored strings are:\n");
    display(strings, i);

    // Free the memory
    free_array_memory(strings, i);

    return 0;
}

