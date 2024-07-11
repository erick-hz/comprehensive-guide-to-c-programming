#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node
{
    int data;          // Data stored in the node
    struct Node *next; // Pointer to the next node
};

// Function to print the elements of the linked list
void printList(struct Node *n)
{
    while (n != NULL)
    {
        printf("%d ", n->data); // Print the data of the current node
        n = n->next;            // Move to the next node
    }
}

int main()
{
    struct Node *head = NULL;   // Pointer to the first node (head) of the linked list
    struct Node *second = NULL; // Pointer to the second node
    struct Node *third = NULL;  // Pointer to the third node

    // Allocate memory for the nodes in the linked list
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Assign data to the first node and link it to the second node
    head->data = 1;
    head->next = second;

    // Assign data to the second node and link it to the third node
    second->data = 2;
    second->next = third;

    // Assign data to the third node and set its next pointer to NULL (end of list)
    third->data = 3;
    third->next = NULL;

    // Print the linked list starting from the head node
    printList(head);

    return 0; // Return 0 to indicate successful execution
}
