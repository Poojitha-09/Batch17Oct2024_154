/* 1. Refer the code in “student.c”. Implement the following requirements.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for student
struct student {
    int id;                // Student ID
    char *name;            // Pointer to store student's name
    float percentage;      // Percentage of the student
};

// Function to read and update the student's name
char *read_update_name(char *name) {
    char temp[100];
    printf("Enter student name: ");
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = '\0';  // Remove newline character

    // Allocate memory for the name dynamically
    name = (char *)malloc(strlen(temp) + 1);
    if (name == NULL) {
        printf("Memory allocation failed for name\n");
        return NULL;
    }

    strcpy(name, temp);  // Copy the input name to dynamically allocated memory
    return name;
}

// Function to read and update the student's percentage
int read_update_percentage(float *percent) {
    printf("Enter student percentage: ");
    if (scanf("%f", percent) != 1) {
        printf("Invalid percentage input\n");
        return -1;
    }
    return *percent;
}

// Function to display student details
void display_student(struct student *record) {
    printf("Id is: %d \n", record->id);
    printf("Name is: %s \n", record->name);
    printf("Percentage is: %.2f \n", record->percentage);
}

// Main function to demonstrate the usage of the student structure
int main() {
    struct student record;

    record.id = 1;

    // Allocate memory for the name dynamically
    record.name = read_update_name(record.name);
    if (record.name == NULL) {
        return -1;  // Exit if memory allocation failed
    }

    // Read and update the percentage
    if (read_update_percentage(&record.percentage) == -1) {
        return -1;  // Exit if there was an error reading percentage
    }

    // Display the updated student record
    display_student(&record);

    // Free the dynamically allocated memory for the name
    free(record.name);

    return 0;
}
