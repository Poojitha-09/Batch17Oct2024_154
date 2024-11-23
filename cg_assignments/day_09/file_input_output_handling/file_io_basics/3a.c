/* 3. Copy the file “string_process_prg.c“ to your local directory. Consider a line length of 80 characters. Create “input.txt” file with appropriate data.

a) Fix the issues (warnings and errors in file).

b) Implement display()

c) Test the program for the expected output i.e to display file contents.

d) Free the allocated memory */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 80  // Max line length

// Function to read strings from the file and store them dynamically
int getFileString(char ***text, const char *input)
{
    FILE *fp;
    int textCount = 0;
    int len = 0;
    char buff[MAX_SIZE];

    fp = fopen(input, "r");  // Open the input file in read mode
    if (fp != NULL)
    {
        // Allocate memory for an array of pointers to strings
        *text = (char **)malloc(sizeof(char *) * (MAX_SIZE + 1));
        if (*text == NULL)
        {
            printf("\nNot able to allocate memory for text array.");
            return -1;  // Return failure code
        }

        // Read each line from the file
        while (fgets(buff, MAX_SIZE, fp) != NULL)
        {
            len = strlen(buff) + 1;  // Get the length of the string including the null terminator
            (*text)[textCount] = (char *)malloc(len);  // Allocate memory for each string

            if ((*text)[textCount] != NULL)
            {
                strcpy((*text)[textCount], buff);  // Copy the string into the allocated memory

                // Remove the trailing newline if it exists
                if ((*text)[textCount][len - 2] == '\n') {
                    (*text)[textCount][len - 2] = '\0';
                }

                textCount++;  // Increment the counter for lines read
            }
            else
            {
                printf("\nMemory allocation failed for line %d.", textCount);
                return -1;  // Return failure code
            }
        }

        fclose(fp);  // Close the file
        return textCount;  // Return the number of lines read
    }
    else
    {
        printf("\nFile cannot be opened.");
        return -1;  // Return failure code
    }
}

// Function to display the array of strings
void display(char **arr, int num)
{
    if (arr == NULL || num <= 0)
    {
        printf("\nNo data to display.\n");
        return;
    }

    // Print each string in the array
    for (int i = 0; i < num; i++)
    {
        printf("%s\n", arr[i]);
    }
}

// Main function to drive the program
int main(int argc, char *argv[])
{
    char **text = NULL;
    int textCount = 0;

    if (argc != 2)
    {
        printf("\nUsage: %s <input_file>\n", argv[0]);
        return 1;  // Return failure
    }

    textCount = getFileString(&text, argv[1]);  // Read strings from the input file
    if (textCount > 0)
    {
        display(text, textCount);  // Display the strings
    }

    // Free the dynamically allocated memory
    if (text != NULL)
    {
        for (int i = 0; i < textCount; i++)
        {
            free(text[i]);  // Free each string
        }
        free(text);  // Free the array of pointers
    }

    return 0;  // Return success
}
