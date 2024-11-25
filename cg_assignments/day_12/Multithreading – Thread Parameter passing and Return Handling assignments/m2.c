/* 2. Write a program to read a file name, to read lines , process it using two or more threads (i.e one thread/line) to count and display the words in the line. For this implement functions below, integrate and test solution.
//receive thread count as argument, create an array of pthread_t (double pointer allocated memory in heap) and return pointer
a) createthreads()
//to receive filename, thread array as args, process each line using a thread function
b) process_file()
//receive a line as input, count words and display, return line and word count to parent thread in a structure
c) thread_proc()
Ensure that there are no memory leaks */ 

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold data passed to each thread
typedef struct {
    char *line;
    int word_count;
} thread_data_t;

// Function to count words in a line
int count_words(const char *line) {
    int count = 0;
    const char *ptr = line;
    int in_word = 0;

    while (*ptr) {
        if (*ptr != ' ' && *ptr != '\t' && *ptr != '\n') {
            if (!in_word) {
                in_word = 1;
                count++;
            }
        } else {
            in_word = 0;
        }
        ptr++;
    }
    return count;
}

// Thread function to process each line and count words
void *thread_proc(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;

    // Count words in the line
    data->word_count = count_words(data->line);

    // Display the result
    printf("Line: %s\nWord Count: %d\n\n", data->line, data->word_count);

    pthread_exit(NULL);
}

// Function to create threads and pass lines to them
pthread_t* createthreads(char *filename, int *num_threads) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    // Count the number of lines in the file
    int count = 0;
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)) {
        count++;
    }
    fclose(file);

    // Allocate memory for the thread array
    pthread_t *threads = (pthread_t *)malloc(count * sizeof(pthread_t));
    *num_threads = count;  // Return the number of threads to create

    // Reopen the file to process lines again
    file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        free(threads);
        return NULL;
    }

    // Allocate memory for thread data
    thread_data_t *thread_data = (thread_data_t *)malloc(count * sizeof(thread_data_t));
    if (!thread_data) {
        perror("Memory allocation failed");
        free(threads);
        fclose(file);
        return NULL;
    }

    // Create threads, one for each line in the file
    for (int i = 0; i < count; i++) {
        if (fgets(buffer, sizeof(buffer), file)) {
            thread_data[i].line = strdup(buffer);  // Copy the line into heap memory
            if (!thread_data[i].line) {
                perror("Memory allocation failed");
                free(threads);
                free(thread_data);
                fclose(file);
                return NULL;
            }
            pthread_create(&threads[i], NULL, thread_proc, &thread_data[i]);
        }
    }

    fclose(file);
    return threads;
}

// Main function to read file and create threads
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int num_threads;
    pthread_t *threads = createthreads(argv[1], &num_threads);
    if (!threads) {
        return 1;
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Free allocated memory
    free(threads);
    return 0;
}

 