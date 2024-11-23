/* Mandatory


1. Refer code in “simple_thread.c”.

a. Modify the thread function to read and return username read from the user. Allocate heap memory for the user name and free in caller after displaying it.

b. Display the thread id’s of parent and child thread */ 

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void *get_username(void *arg) {
    char *username = (char *)malloc(100 * sizeof(char));  
    if (username == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    printf("Enter your username: ");
    fgets(username, 100, stdin);  
    username[strcspn(username, "\n")] = 0;  
    pthread_t thread_id = pthread_self(); 
    printf("Child thread ID: %lu\n", thread_id);
    return (void *)username;  
}

int main() {
    pthread_t thread_id;
    int ret = pthread_create(&thread_id, NULL, get_username, NULL);
    if (ret != 0) {
        printf("Thread creation failed\n");
        return -1;
    }
    pthread_t parent_thread_id = pthread_self();
    printf("Parent thread ID: %lu\n", parent_thread_id);
    void *username_ptr;
    pthread_join(thread_id, &username_ptr);
    printf("Hello, %s!\n", (char *)username_ptr);
    free(username_ptr);

    return 0;
}


