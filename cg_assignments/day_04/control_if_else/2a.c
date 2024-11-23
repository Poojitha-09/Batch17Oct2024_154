/* 2. WAP to read a designation code and display his designation as a string. Use the following mapping. */ 


#include <stdio.h>

int main() {
    int code;

    // Prompt user to enter a designation code
    printf("Enter the designation code: ");
    scanf("%d", &code);

    // Using if-else or switch to map the code to its respective designation
    switch (code) {
        case 2:
            printf("Software Developer\n");
            break;
        case 3:
            printf("Senior Software Developer\n");
            break;
        case 4:
            printf("Team Lead\n");
            break;
        case 5:
            printf("Senior Team Lead\n");
            break;
        default:
            printf("Incorrect designation code\n");
            break;
    }

    return 0;
}
