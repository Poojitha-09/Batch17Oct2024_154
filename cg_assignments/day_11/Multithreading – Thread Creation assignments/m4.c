/* 4. Write a program

a. to read a set of words as command line arguments and to create an array of threads (Consider a maximum of 5 words )

b. process each word using an separate thread. Let each thread append “_ed” to the input word and return to main thread

c. main thread to wait for completion of each thread, retrieve returned string display with thread number, free memory  */ 


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char *word;
    char *modified_word;
    int thread_num;
} thread_data_t;
void *process_word(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    data->modified_word = (char *)malloc(strlen(data->word) + 4); // "_ed" is 3 chars
    if (data->modified_word == NULL) {
        perror("Memory allocation failed");
        pthread_exit(NULL);
    }
    strcpy(data->modified_word, data->word);
    strcat(data->modified_word, "_ed");
    pthread_exit((void *)data->modified_word);
}

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 6) {
        printf("Usage: %s <word1> <word2> ... <word5>\n", argv[0]);
        return -1;
    }

    int num_threads = argc - 1; 
    pthread_t threads[num_threads];
    thread_data_t thread_data[num_threads];
    for (int i = 0; i < num_threads; i++) {
        thread_data[i].word = argv[i + 1];  
        thread_data[i].thread_num = i + 1;

        if (pthread_create(&threads[i], NULL, process_word, (void *)&thread_data[i]) != 0) {
            perror("Thread creation failed");
            return -1;
        }
    }
    for (int i = 0; i < num_threads; i++) {
        void *result;
        if (pthread_join(threads[i], &result) != 0) {
            perror("Thread join failed");
            return -1;
        }
        printf("Thread %d: %s\n", thread_data[i].thread_num, (char *)result);
        free(result);
    }

    return 0;
}
