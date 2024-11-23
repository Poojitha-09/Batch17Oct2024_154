/* 1. Read 2 lines of text as single command line argument, validate the arguments, extract the lines, write to file “fout.txt”. Now open file read the content and display. Implement the functions
int write(FILE *fptr, char *line);
int read(FILE *fptr, char *linebuf);i
[Assume maximum line length as 80]  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 80
int write(FILE *fptr, char *line) {
    if (fptr == NULL || line == NULL) {
        return -1; 
    }

    if (fprintf(fptr, "%s\n", line) < 0) {
        return -1; 
    }

    return 0; 
}
int read(FILE *fptr, char *linebuf) {
    if (fptr == NULL || linebuf == NULL) {
        return -1; 
    }

    if (fgets(linebuf, MAX_LINE_LENGTH, fptr) == NULL) {
        return -1; 
    }

    return 0; 
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <line1> <line2>\n", argv[0]);
        return 1; 
    }
    if (strlen(argv[1]) == 0 || strlen(argv[2]) == 0) {
        printf("Both lines must contain text.\n");
        return 1;
    }
    FILE *fptr = fopen("fout.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    // Write both lines to the file
    if (write(fptr, argv[1]) != 0) {
        printf("Error writing line 1 to file.\n");
        fclose(fptr);
        return 1;
    }
    if (write(fptr, argv[2]) != 0) {
        printf("Error writing line 2 to file.\n");
        fclose(fptr);
        return 1;
    }
    fclose(fptr); 
    fptr = fopen("fout.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }
    char linebuf[MAX_LINE_LENGTH];
    printf("Contents of fout.txt:\n");

    while (read(fptr, linebuf) == 0) {
        printf("%s", linebuf); 
    }
    fclose(fptr);

    return 0;
}
