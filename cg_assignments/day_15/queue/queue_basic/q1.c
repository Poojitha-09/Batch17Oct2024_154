/* Refer the example code of queue using array in socodery. Modify the data structure as below and accordingly update the code to add support to keep MAX_QUEUE_SIZE user input strings read at runtime. Consider a configurable queue capacity*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 5
typedef struct queue {
    int arr[MAX_QUEUE_SIZE];   
    char **data;               
    int front;                 
    int rear;                  
    int size;                  
} queue_t;
void init_queue(queue_t *q);
int is_full(queue_t *q);
int is_empty(queue_t *q);
int enqueue(queue_t *q, int val, char *str);
int dequeue(queue_t *q, int *val, char **str);
void print_queue(queue_t *q);
void free_queue(queue_t *q);

int main() {
    queue_t q;
    init_queue(&q);
    for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
        char input_str[100];
        int input_val;
        printf("Enter a string for queue position %d: ", i + 1);
        fgets(input_str, sizeof(input_str), stdin);
        input_str[strcspn(input_str, "\n")] = 0;  
        printf("Enter an integer value for queue position %d: ", i + 1);
        scanf("%d", &input_val);
        getchar();  // To consume the trailing newline character from scanf
        if (enqueue(&q, input_val, input_str) == -1) {
            printf("Queue is full. Cannot add more elements.\n");
            break;
        }
    }
    printf("\nQueue content:\n");
    print_queue(&q);
    printf("\nDequeuing all elements:\n");
    int val;
    char *str;
    while (!is_empty(&q)) {
        if (dequeue(&q, &val, &str) == 0) {
            printf("Dequeued value: %d, String: %s\n", val, str);
            free(str);  // Free the memory allocated for the string
        }
    }
    free_queue(&q);
    return 0;
}
void init_queue(queue_t *q) {
    q->front = 0;
    q->rear = 0;
    q->size = 0;
    q->data = (char **)malloc(MAX_QUEUE_SIZE * sizeof(char *));  
    if (!q->data) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
}
int is_full(queue_t *q) {
    return q->size == MAX_QUEUE_SIZE;
}
int is_empty(queue_t *q) {
    return q->size == 0;
}
int enqueue(queue_t *q, int val, char *str) {
    if (is_full(q)) {
        return -1;  
    }
    q->arr[q->rear] = val;
    q->data[q->rear] = (char *)malloc(strlen(str) + 1);
    if (!q->data[q->rear]) {
        printf("Memory allocation failed!\n");
        return -1;
    }
    strcpy(q->data[q->rear], str);
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->size++;

    return 0;  
}
int dequeue(queue_t *q, int *val, char **str) {
    if (is_empty(q)) {
        return -1;  
    }
    *val = q->arr[q->front];
    *str = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    q->size--;

    return 0;  
}
void print_queue(queue_t *q) {
    int i = q->front;
    int count = q->size;
    while (count > 0) {
        printf("Value: %d, String: %s\n", q->arr[i], q->data[i]);
        i = (i + 1) % MAX_QUEUE_SIZE;
        count--;
    }
}
void free_queue(queue_t *q) {
    for (int i = 0; i < q->size; i++) {
        free(q->data[(q->front + i) % MAX_QUEUE_SIZE]);
    }
    free(q->data);
}
