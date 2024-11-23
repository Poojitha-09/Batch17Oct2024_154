/*Refer the example code of queue using list in socodery. Modify the data structure as below and accordingly update the code to add support to keep string data read from user (of maximum length 80 characters) at runtime. Ensure 0 memory leaks.

typedef struct node_q

{

Int data;

char *data; 
struct node_q *next;

}node; */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR_LENGTH 80
typedef struct node_q {
    int data;               
    char *str_data;         
    struct node_q *next;    
} node;
typedef struct {
    node *front;   
    node *rear;    
} queue;
void init_queue(queue *q);
int is_empty(queue *q);
int enqueue(queue *q, int data, const char *str);
int dequeue(queue *q, int *data, char **str);
void print_queue(queue *q);
void free_queue(queue *q);

int main() {
    queue q;
    init_queue(&q);
    for (int i = 0; i < 3; i++) {  
        int num;
        char input_str[MAX_STR_LENGTH];
        printf("Enter an integer for queue position %d: ", i + 1);
        scanf("%d", &num);
        getchar();  

        printf("Enter a string (max 80 characters) for queue position %d: ", i + 1);
        fgets(input_str, sizeof(input_str), stdin);
        input_str[strcspn(input_str, "\n")] = '\0';  
        if (enqueue(&q, num, input_str) == -1) {
            printf("Queue is full or memory allocation failed!\n");
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
            printf("Dequeued: %d, String: %s\n", val, str);
            free(str);  // Free the dynamically allocated string
        }
    }
    free_queue(&q);
    return 0;
}
void init_queue(queue *q) {
    q->front = NULL;
    q->rear = NULL;
}
int is_empty(queue *q) {
    return q->front == NULL;
}
int enqueue(queue *q, int data, const char *str) {
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) {
        return -1;  
    }

    new_node->data = data;
    new_node->str_data = (char *)malloc(strlen(str) + 1);
    if (new_node->str_data == NULL) {
        free(new_node);
        return -1;  
    }
    strcpy(new_node->str_data, str);

    new_node->next = NULL;

    if (is_empty(q)) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }

    return 0; 
}

// Dequeue operation: Remove an element from the queue
int dequeue(queue *q, int *data, char **str) {
    if (is_empty(q)) {
        return -1;  
    }

    node *temp = q->front;
    *data = temp->data;
    *str = temp->str_data;  

    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL; 
    }

    free(temp);  
    return 0;    
}
void print_queue(queue *q) {
    node *current = q->front;
    while (current != NULL) {
        printf("Integer: %d, String: %s\n", current->data, current->str_data);
        current = current->next;
    }
}

void free_queue(queue *q) {
    node *current = q->front;
    while (current != NULL) {
        node *temp = current;
        current = current->next;
        free(temp->str_data);  
        free(temp);  
    }
    q->front = NULL;
    q->rear = NULL;
}


