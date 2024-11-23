#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LENGTH 20
struct Person {
    char *name;  // Dynamically allocated name
    unsigned int age;
};
int main() {
    struct Person people[2];
    for (int i = 0; i < 2; i++) {
        people[i].name = (char *)malloc(MAX_NAME_LENGTH * sizeof(char));  // Dynamically allocate memory for the name

        if (people[i].name == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("Enter name %d (max 20 characters): ", i + 1);
        fgets(people[i].name, MAX_NAME_LENGTH, stdin);
        people[i].name[strcspn(people[i].name, "\n")] = '\0';  // Remove trailing newline

        printf("Enter age for %s: ", people[i].name);
        scanf("%u", &people[i].age);
        getchar();  // Consume newline left by scanf
    }
    FILE *file = fopen("out.bin", "wb");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }
    for (int i = 0; i < 2; i++) {
        fprintf(file, "%s,%u\n", people[i].name, people[i].age);
    }
    fclose(file);
    file = fopen("out.bin", "rb");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }
    printf("\nContents of the file:\n");
    char read_name[MAX_NAME_LENGTH];
    unsigned int read_age;
    while (fscanf(file, "%19[^,],%u\n", read_name, &read_age) == 2) {
        printf("Name: %s, Age: %u\n", read_name, read_age);
    }
    printf("\nVerifying if the displayed contents match user input:\n");
    for (int i = 0; i < 2; i++) {
        printf("Entered: Name = %s, Age = %u\n", people[i].name, people[i].age);
    }
    printf("\nSize of each name and age pair:\n");
    printf("Size of name (max 20 chars) + age (4 bytes): %zu bytes\n", sizeof(char) * MAX_NAME_LENGTH + sizeof(unsigned int));
    printf("Total size of 2 name-age pairs: %zu bytes\n", 2 * (sizeof(char) * MAX_NAME_LENGTH + sizeof(unsigned int)));
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    printf("Size of the file: %ld bytes\n", file_size);
    printf("\nFile content is not directly readable because it's in binary format, but we used fprintf() to write in a human-readable format.\n");
    for (int i = 0; i < 2; i++) {
        free(people[i].name);
    }
    fclose(file);
    return 0;
}
