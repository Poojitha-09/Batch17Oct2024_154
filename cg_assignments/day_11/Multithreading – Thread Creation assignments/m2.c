/*2. Refer the code “pthread_creation.c”. Modify the existing functions as below.

a. Main()- read a line of text and pass to new threadproc function below

threadproc() – to create 2 child threads to count words and to count characters, display the received values, return the values to the caller

Other thread functions to be used by threadproc() are given below

startroutine1()—to count words and return word count to caller

startroutine2() – to return the character count to the caller */ 


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct {
    int word_count;
    int char_count;
} result_t;
void *startroutine1(void *arg) {
    char *text = (char *)arg;
    int word_count = 0;
    char *token = strtok(text, " \t\n"); 
    while (token != NULL) {
        word_count++;
        token = strtok(NULL, " \t\n");
    }
    int *count = malloc(sizeof(int));
    *count = word_count;
    pthread_exit((void *)count); 
}
void *startroutine2(void *arg) {
    char *text = (char *)arg;
    int char_count = 0;

    while (*text) {
        if (!isspace(*text)) {
            char_count++;
        }
        text++;
    }
    int *count = malloc(sizeof(int));
    *count = char_count;
    pthread_exit((void *)count); 
}
void *threadproc(void *arg) {
    char *text = (char *)arg;
    pthread_t thread1, thread2;
    int *word_count;
    int *char_count;
    pthread_create(&thread1, NULL, startroutine1, (void *)text);
    pthread_create(&thread2, NULL, startroutine2, (void *)text);
    pthread_join(thread1, (void **)&word_count);
    pthread_join(thread2, (void **)&char_count);
    printf("Word Count: %d\n", *word_count);
    printf("Character Count: %d\n", *char_count);
    free(word_count);
    free(char_count);
    pthread_exit(NULL); 
}

int main() {
    char input_text[1000];
    printf("Enter a line of text: ");
    fgets(input_text, sizeof(input_text), stdin);
    input_text[strcspn(input_text, "\n")] = '\0';
    pthread_t main_thread;
    pthread_create(&main_thread, NULL, threadproc, (void *)input_text);
    pthread_join(main_thread, NULL);
    return 0;
}



