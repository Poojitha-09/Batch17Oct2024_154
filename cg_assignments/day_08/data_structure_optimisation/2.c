/* 2. Define an appropriate data structure to store Person details namely name [max length 100 bytes], age (considering person living for 100 years).  */


#include <stdio.h>
#include <string.h>
typedef struct {
    char name[100];  
    int age;         
} Person;

int main() {
    Person person = {"John Doe", 25};  
    printf("Person Details:\n");
    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);

    return 0;
}
