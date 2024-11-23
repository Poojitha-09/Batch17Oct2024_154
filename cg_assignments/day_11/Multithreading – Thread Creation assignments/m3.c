/* 3. Refer the program in “thread_prg.c”. Complete the TBD sections , check the final solution for memory leak if any */ 

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int data;
} thread_data_t;
void *thread_function(void *arg) {
    thread_data_t *t_data = (thread_data_t *)arg;
    printf("Thread processing data: %d\n", t_data->data);
    t_data->data += 10;

    pthread_exit(NULL);  // Exit the thread
}

int main() {
    pthread_t thread1, thread2;
    thread_data_t *data1, *data2;
    data1 = (thread_data_t *)malloc(sizeof(thread_data_t));
    data2 = (thread_data_t *)malloc(sizeof(thread_data_t));

    if (data1 == NULL || data2 == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }
    data1->data = 5;
    data2->data = 15;
    if (pthread_create(&thread1, NULL, thread_function, (void *)data1) != 0) {
        printf("Failed to create thread 1\n");
        free(data1);  // Clean up memory before exit
        free(data2);
        return -1;
    }

    if (pthread_create(&thread2, NULL, thread_function, (void *)data2) != 0) {
        printf("Failed to create thread 2\n");
        free(data1);  // Clean up memory before exit
        free(data2);
        return -1;
    }
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Updated data from thread 1: %d\n", data1->data);
    printf("Updated data from thread 2: %d\n", data2->data);
    free(data1);
    free(data2);

    return 0;
}


