#include<stdio.h>
#include<stdlib.h>

int *func(void);

int main() {
    int num, *ptr = NULL;
    ptr = func(); 
    num = *ptr;
    printf("Value: %d\n", num); 
    free(ptr);  
    return 0;
}

int *func() {
    int *local = (int *)malloc(sizeof(int));  
    if (local == NULL) {
        printf("Memory allocation failed\n");
        exit(1);  // Exit if memory allocation fails
    }

    *local = 10;  // Assign value
    return local; // Return the pointer to the allocated memory
}
