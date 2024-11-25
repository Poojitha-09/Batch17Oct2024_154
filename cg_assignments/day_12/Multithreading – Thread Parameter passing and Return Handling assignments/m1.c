/* 1. Create a multithreaded program to

a. read 3 lines as a single command line argument

b. extract every line and pass it to a thread.

c. each thread should sort all the words in the line in ascending order and return sorted line to the main thread

d. main thread to wait for all child threads to complete, then read and display the sorted line ”.

e. Release any allocated memory */ 


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold data for each thread
typedef struct {
    char *line;
    char *sorted_line;
} thread_data_t;

// Function to compare two strings (for sorting words in ascending order)
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

// Thread function to sort the words in the given line
void *sort_line(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    
    // Split the line into words
    char *line_copy = strdup(data->line);
    if (line_copy == NULL) {
        perror("Memory allocation failed");
        pthread_exit(NULL);
    }

    char *token = strtok(line_copy, " ");
    char *words[50]; // Array to hold the words
    int word_count = 0;

    // Tokenize the line into words
    while (token != NULL) {
        words[word_count] = token;
        word_count++;
        token = strtok(NULL, " ");
    }

    // Sort the words in ascending order
    qsort(words, word_count, sizeof(char *), compare);

    // Allocate memory for the sorted line
    data->sorted_line = (char *)malloc(1024 * sizeof(char)); // Arbitrary size for the result
    if (data->sorted_line == NULL) {
        perror("Memory allocation failed");
        free(line_copy);
        pthread_exit(NULL);
    }

    // Reconstruct the sorted line
    data->sorted_line[0] = '\0'; // Initialize the string
    for (int i = 0; i < word_count; i++) {
        strcat(data->sorted_line, words[i]);
        if (i < word_count - 1) {
            strcat(data->sorted_line, " ");
        }
    }

    free(line_copy);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    // Check if exactly 3 arguments (lines) are passed
    if (argc != 4) {
        printf("Usage: %s <line1> <line2> <line3>\n", argv[0]);
        return -1;
    }

    pthread_t threads[3];          // Thread identifiers
    thread_data_t thread_data[3];  // Data to pass to threads

    // Create threads to process each line
    for (int i = 0; i < 3; i++) {
        thread_data[i].line = argv[i + 1]; // Pass command-line argument to the thread
        if (pthread_create(&threads[i], NULL, sort_line, (void *)&thread_data[i]) != 0) {
            perror("Thread creation failed");
            return -1;
        }
    }

    // Wait for all threads to finish and retrieve the sorted lines
    for (int i = 0; i < 3; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Thread join failed");
            return -1;
        }
        // Print the sorted line from the thread
        printf("Sorted Line %d: %s\n", i + 1, thread_data[i].sorted_line);

        // Free the dynamically allocated memory for the sorted line
        free(thread_data[i].sorted_line);
    }

    return 0;
}
