/* 1. Write a program to create 3 threads with the detach and cancel status as below. */


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define THREAD_COUNT 3
typedef struct thread_info {
    int thread_id;
    int cancel_type;
    int cancel_status;
    int detached;
} thread_info_t;

pthread_t threads[THREAD_COUNT];
thread_info_t thread_data[THREAD_COUNT];
void timestamp(char *buffer, size_t length) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(buffer, length, "%Y-%m-%d %H:%M:%S", tm_info);
}
void *thread_func(void *arg) {
    thread_info_t *data = (thread_info_t *)arg;
    char buffer[100];
    timestamp(buffer, sizeof(buffer));
    printf("%s Thread#%d Detach: %s Cancel Type: %d Cancel Status: %d\n", 
           buffer, 
           data->thread_id, 
           data->detached ? "Y" : "N", 
           data->cancel_type, 
           data->cancel_status);

    if (data->thread_id == 1) {
        while (1) {
            timestamp(buffer, sizeof(buffer));
            printf("%s T1: Health OK\n", buffer);
            sleep(2);
        }
    } else if (data->thread_id == 2) {
        // Thread 2: Print numbers from 1000, step 2 every 3 seconds
        int count = 1000;
        while (1) {
            timestamp(buffer, sizeof(buffer));
            printf("%s %ld %d\n", buffer, pthread_self(), count);
            count += 2;
            sleep(3);
        }
    } else if (data->thread_id == 3) {
        // Thread 3: Print numbers from 2000, step 2 every 3 seconds
        int count = 2000;
        while (1) {
            timestamp(buffer, sizeof(buffer));
            printf("%s %ld %d\n", buffer, pthread_self(), count);
            count += 2;
            sleep(3);
        }
    }
    return NULL;
}

void *cancel_threads(void *arg) {
    sleep(180); // Wait for 3 minutes before canceling the threads
    for (int i = 0; i < THREAD_COUNT; i++) {
        if (pthread_cancel(threads[i]) == 0) {
            printf("Thread#%d is cancelled.\n", i + 1);
        }
    }
    return NULL;
}

int main() {
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    thread_data[0].thread_id = 1;
    thread_data[0].detached = 1;
    thread_data[0].cancel_type = PTHREAD_CANCEL_DISABLE;
    thread_data[0].cancel_status = PTHREAD_CANCEL_DISABLE;
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    pthread_create(&threads[0], &attr, thread_func, &thread_data[0]);
    thread_data[1].thread_id = 2;
    thread_data[1].detached = 0;
    thread_data[1].cancel_type = PTHREAD_CANCEL_ENABLE;
    thread_data[1].cancel_status = PTHREAD_CANCEL_DEFERRED;
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    pthread_create(&threads[1], &attr, thread_func, &thread_data[1]);
    thread_data[2].thread_id = 3;
    thread_data[2].detached = 0;
    thread_data[2].cancel_type = PTHREAD_CANCEL_ENABLE;
    thread_data[2].cancel_status = PTHREAD_CANCEL_ASYNCHRONOUS;
    pthread_create(&threads[2], &attr, thread_func, &thread_data[2]);
    pthread_attr_destroy(&attr);
    pthread_t cancel_thread;
    pthread_create(&cancel_thread, NULL, cancel_threads, NULL);
    pthread_join(cancel_thread, NULL);

    return 0;
}
