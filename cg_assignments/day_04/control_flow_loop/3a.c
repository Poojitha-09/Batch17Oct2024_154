/* 3.Write a program to continuously read a string of maximum length 80 chars, End the program if string is END, else convert to upper case, display and continue. (use while) */ 

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[81];  

    while (1) {
        printf("Enter a string (max 80 chars, type 'END' to exit): ");
        fgets(input, sizeof(input), stdin);  
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "END") == 0) {
            break;  
        }

        if (strlen(input) > 80) {
            printf("Error: Input exceeds 80 characters.\n");
            continue;  // Skip the rest of the loop if the input is too long
        }

        for (int i = 0; input[i] != '\0'; i++) {
            input[i] = toupper((unsigned char) input[i]);  
        }

        printf("Uppercase: %s\n", input);
    }

    printf("Program ended.\n");
    return 0;
}
