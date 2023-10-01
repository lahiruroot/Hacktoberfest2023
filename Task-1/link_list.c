#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


// Function to create a new node

struct Node* createNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));

    // for safety we are initializing next with NULL
    node->next = NULL;

    node->data = data;

    return node;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);

    printf("Linked List: ");
    display(head);

    return 0;
}
