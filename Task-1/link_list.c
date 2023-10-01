// Define the linked list node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the linked list structure
typedef struct LinkedList {
    Node* head;
} LinkedList;

// Function to create a new linked list
LinkedList* createLinkedList();

// Function to insert a node at the end of the linked list
void append(LinkedList* list, int data);

// Function to print the linked list
void printLinkedList(LinkedList* list);

// Other functions for deletion, searching, etc.
