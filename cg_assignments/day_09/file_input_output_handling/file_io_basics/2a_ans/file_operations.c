#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_operations.h"

// Function to read an integer from the file
int read_integer(FILE *fp) {
    int num;
    if (fscanf(fp, "%d", &num) != 1) {
        return -1;  // Return -1 if fscanf fails
    }
    return num;
}

// Function to read a string from the file
int read_string(FILE *fp, char *str, int max_len) {
    if (fgets(str, max_len, fp) == NULL) {
        return -1;  // Return -1 if fgets fails
    }
    str[strcspn(str, "\n")] = '\0';  // Remove the newline character at the end
    return 0;
}

// Function to merge the contents of the two input files into the output file
int merge_files(FILE *fp1, FILE *fp2, FILE *fp_out) {
    int num;
    char str[80];
    
    while (1) {
        // Read an integer from the first file
        num = read_integer(fp1);
        if (num == -1) break;  // End of file or error in reading integers

        // Read a string from the second file
        if (read_string(fp2, str, 80) == -1) {
            break;  // End of file or error in reading strings
        }

        // Write the integer and string to the output file
        fprintf(fp_out, "%d%s\n", num, str);
    }
    
    return 0;
}

// Function to display the contents of the output file
void display_file(FILE *fp) {
    char line[100];
    rewind(fp);  // Ensure we are at the beginning of the file
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);  // Print each line of the file
    }
}
