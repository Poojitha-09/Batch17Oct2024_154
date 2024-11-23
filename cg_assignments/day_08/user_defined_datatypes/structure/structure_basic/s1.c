/* 1. WAP to define read and store the following details together in a structure and display the structure details */ 



#include <stdio.h>
#include <string.h>
typedef enum {
    MANAGER,
    DEVELOPER,
    TESTER,
    HR
} Designation;
typedef struct {
    char name[50];         
    unsigned int age;       
    Designation designation; 
} EMP;
void read(EMP *emp) {
    printf("Enter employee name (max 50 characters): ");
    if (fgets(emp->name, sizeof(emp->name), stdin)) {
        emp->name[strcspn(emp->name, "\n")] = '\0';  
    }
    printf("Enter employee age: ");
    if (scanf("%u", &emp->age) != 1) {
        printf("Invalid age input.\n");
        return;
    }
    printf("Enter employee designation (0: Manager, 1: Developer, 2: Tester, 3: HR): ");
    int desig;
    if (scanf("%d", &desig) != 1 || desig < 0 || desig > 3) {
        printf("Invalid designation input.\n");
        return;
    }
    emp->designation = (Designation) desig;
    while (getchar() != '\n');
}
void display(const EMP *emp) {
    printf("\nEmployee Details:\n");
    printf("Name: %s\n", emp->name);
    printf("Age: %u\n", emp->age);
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
int update(EMP *emp) {
    int choice;
    printf("\nUpdate Employee Record:\n");
    printf("1. Update Name\n2. Update Age\n3. Update Designation\n4. Exit\n");
    printf("Enter your choice: ");
    
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input.\n");
        return 0;
    }

    while (getchar() != '\n');  
    switch (choice) {
        case 1:
            // Update name
            printf("Enter new name: ");
            if (fgets(emp->name, sizeof(emp->name), stdin)) {
                emp->name[strcspn(emp->name, "\n")] = '\0';  
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
EMP copy(const EMP *emp) {
    EMP newEmp;
    strncpy(newEmp.name, emp->name, sizeof(newEmp.name));
    newEmp.age = emp->age;
    newEmp.designation = emp->designation;
    return newEmp;
}
int main() {
    EMP emp1;
    read(&emp1);
    display(&emp1);
    int updated;
    do {
        updated = update(&emp1);
        if (updated) {
            display(&emp1);  
        }
    } while (updated);
    EMP emp2 = copy(&emp1);
    printf("\nNew Employee (Copied Record) Details:\n");
    display(&emp2);

    return 0;
}
