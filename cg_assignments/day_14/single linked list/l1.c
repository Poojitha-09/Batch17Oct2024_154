#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ID_LEN 6  
typedef struct Node {
    char id[MAX_ID_LEN];  
    int val;               
    struct Node *next;     
} Node;
extern int search_update_name(Node **head, char *search, char *replace);
extern int sorted_insert_name(Node **head, char *name, int val);
extern int sorted_insert_val(Node **head, char *name, int val);
Node* create_node(char *id, int val) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    strncpy(new_node->id, id, MAX_ID_LEN - 1);
    new_node->id[MAX_ID_LEN - 1] = '\0';  // Ensure null termination
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}
int search_update_name(Node **head, char *search, char *replace) {
    Node *current = *head;

    while (current != NULL) {
        if (strcmp(current->id, search) == 0) {
            strncpy(current->id, replace, MAX_ID_LEN - 1);
            current->id[MAX_ID_LEN - 1] = '\0';  // Ensure null termination
            return 1;  // Success
        }
        current = current->next;
    }
    return 0;  // Not found
}
int sorted_insert_name(Node **head, char *name, int val) {
    Node *new_node = create_node(name, val);
    if (!new_node) return -1;

    if (*head == NULL || strcmp((*head)->id, name) > 0) {
        // Insert at the head if the list is empty or the new node's id is smaller
        new_node->next = *head;
        *head = new_node;
        return 1;
    }

    Node *current = *head;
    while (current->next != NULL && strcmp(current->next->id, name) < 0) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
    return 1;
}
int sorted_insert_val(Node **head, char *name, int val) {
    Node *new_node = create_node(name, val);
    if (!new_node) return -1;

    if (*head == NULL || (*head)->val > val) {
        // Insert at the head if the list is empty or the new node's value is smaller
        new_node->next = *head;
        *head = new_node;
        return 1;
    }
    Node *current = *head;
    while (current->next != NULL && current->next->val < val) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    return 1;
}
void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("ID: %s, Value: %d\n", current->id, current->val);
        current = current->next;
    }
}

int main() {
    Node *head = NULL;
    sorted_insert_name(&head, "John", 100);
    sorted_insert_name(&head, "Alice", 50);
    sorted_insert_val(&head, "Bob", 75);
    printf("List after insertions:\n");
    print_list(head);
    search_update_name(&head, "Alice", "Charlie");
    printf("\nList after updating Alice to Charlie:\n");
    print_list(head);
    return 0;
}
