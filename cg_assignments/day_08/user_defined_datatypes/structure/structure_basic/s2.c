/* 2. Extend the above program and create and initialize an array of 3 structures. Reuse the read() and display() functions to read, initialize and display structures*/



#include <stdio.h>
#include <string.h>

// Define the enum for employee designations
typedef enum {
    MANAGER,
    DEVELOPER,
    TESTER,
    HR
} Designation;

// Define the structure to store employee details
typedef struct {
    char name[50];          // Name of the employee
    unsigned int age;       // Age of the employee (0 to 100)
    Designation designation; // Employee's designation (enum)
} EMP;

// Function to read employee details from user input
void read(EMP *emp) {
    // Input employee name
    printf("Enter employee name (max 50 characters): ");
    if (fgets(emp->name, sizeof(emp->name), stdin)) {
        emp->name[strcspn(emp->name, "\n")] = '\0';  // Remove newline character
    }

    // Input employee age
    printf("Enter employee age: ");
    if (scanf("%u", &emp->age) != 1) {
        printf("Invalid age input.\n");
        return;
    }

    // Input employee designation
    printf("Enter employee designation (0: Manager, 1: Developer, 2: Tester, 3: HR): ");
    int desig;
    if (scanf("%d", &desig) != 1 || desig < 0 || desig > 3) {
        printf("Invalid designation input.\n");
        return;
    }
    emp->designation = (Designation) desig;

    // Clear input buffer after reading integers
    while (getchar() != '\n');
}

// Function to display employee details
void display(const EMP *emp) {
    printf("\nEmployee Details:\n");
    printf("Name: %s\n", emp->name);
    printf("Age: %u\n", emp->age);

    // Display designation based on the enum value
    switch (emp->designation) {
        case MANAGER:
            printf("Designation: Manager\n");
            break;
        case DEVELOPER:
            printf("Designation: Developer\n");
            break;
        case TESTER:
            printf("Designation: Tester\n");
            break;
        case HR:
            printf("Designation: HR\n");
            break;
        default:
            printf("Designation: Unknown\n");
            break;
    }
}

// Function to update an employee record
int update(EMP *emp) {
    int choice;
    printf("\nUpdate Employee Record:\n");
    printf("1. Update Name\n2. Update Age\n3. Update Designation\n4. Exit\n");
    printf("Enter your choice: ");
    
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input.\n");
        return 0;
    }

    while (getchar() != '\n');  // Clear input buffer
    
    switch (choice) {
        case 1:
            // Update name
            printf("Enter new name: ");
            if (fgets(emp->name, sizeof(emp->name), stdin)) {
                emp->name[strcspn(emp->name, "\n")] = '\0';  // Remove newline character
            }
            break;
        case 2:
            // Update age
            printf("Enter new age: ");
            if (scanf("%u", &emp->age) != 1) {
                printf("Invalid age input.\n");
                return 0;
            }
            break;
        case 3:
            // Update designation
            printf("Enter new designation (0: Manager, 1: Developer, 2: Tester, 3: HR): ");
            int desig;
            if (scanf("%d", &desig) != 1 || desig < 0 || desig > 3) {
                printf("Invalid designation input.\n");
                return 0;
            }
            emp->designation = (Designation) desig;
            break;
        case 4:
            // Exit the update function
            return 0;
        default:
            printf("Invalid choice.\n");
            break;
    }
    return 1;
}

// Function to copy an employee record to a new employee and return it
EMP copy(const EMP *emp) {
    EMP newEmp;
    // Copy the details of the original employee to the new employee
    strncpy(newEmp.name, emp->name, sizeof(newEmp.name));
    newEmp.age = emp->age;
    newEmp.designation = emp->designation;
    return newEmp;
}

// Main function to execute the program
int main() {
    // Create an array of 3 employee instances
    EMP employees[3];

    // Read employee details from user for each structure in the array
    for (int i = 0; i < 3; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);
        read(&employees[i]);
    }

    // Display employee details for each structure in the array
    for (int i = 0; i < 3; i++) {
        printf("\nDetails of Employee %d:\n", i + 1);
        display(&employees[i]);
    }

    // Update employee records and display them
    for (int i = 0; i < 3; i++) {
        int updated;
        do {
            updated = update(&employees[i]);
            if (updated) {
                display(&employees[i]);  // Display updated details
            }
        } while (updated);
    }

    // Copy the employee records to new employee structures and display
    for (int i = 0; i < 3; i++) {
        EMP empCopy = copy(&employees[i]);
        printf("\nNew Employee (Copied Record) %d Details:\n", i + 1);
        display(&empCopy);
    }

    return 0;
}
