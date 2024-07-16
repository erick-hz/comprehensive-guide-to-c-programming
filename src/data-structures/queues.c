#include <stdio.h>
#include <stdlib.h>

// Define a node in the queue
struct Node
{
    int data;
    struct Node *next;
};

// Define the queue structure
struct Queue
{
    struct Node *front;
    struct Node *rear;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a queue
struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to add an element to the queue
void enqueue(struct Queue *queue, int data)
{
    struct Node *newNode = createNode(data);
    if (queue->rear == NULL)
    {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Function to remove an element from the queue
int dequeue(struct Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    struct Node *temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;

    // If the front becomes NULL, then change rear to NULL
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

// Function to print the elements of the queue
void printQueue(struct Queue *queue)
{
    struct Node *temp = queue->front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Queue *queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("Queue: ");
    printQueue(queue);

    printf("Dequeued: %d\n", dequeue(queue));
    printf("Queue: ");
    printQueue(queue);

    printf("Dequeued: %d\n", dequeue(queue));
    printf("Queue: ");
    printQueue(queue);

    printf("Dequeued: %d\n", dequeue(queue));
    printf("Queue: ");
    printQueue(queue);

    printf("Dequeued: %d\n", dequeue(queue)); // This should indicate that the queue is empty

    return 0;
}
