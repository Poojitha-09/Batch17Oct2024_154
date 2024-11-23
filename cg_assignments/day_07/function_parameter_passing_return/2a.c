#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 50
void read_extract_characters(char *str, char *extracted_str);

int main() {
    char str[MAX_LENGTH + 1];          
    char extracted_str[MAX_LENGTH + 1]; 
    printf("Enter a string (max 50 characters): ");
    fgets(str, MAX_LENGTH + 1, stdin); 
    str[strcspn(str, "\n")] = '\0';
    read_extract_characters(str, extracted_str);
    printf("Extracted characters at odd indices: %s\n", extracted_str);

    return 0;
}

void read_extract_characters(char *str, char *extracted_str) {
    int i, j = 0;  
    // Loop through the input string and extract characters at odd indices
    for (i = 1; str[i] != '\0'; i += 2) {
        extracted_str[j++] = str[i];  
    }
    extracted_str[j] = '\0';
}
