/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// This is a function that defines the Node structure for the Linked List:
typedef struct node {
    int data;
    struct node* next;
} NODE;

// This is a function that defines the Queue structure:
typedef struct queue {
    NODE* front;
    NODE* rear;
} QUEUE;

// This is a function that initializes an empty queue:
void initQueue(QUEUE* q) {
    q->front = q->rear = NULL;
}

// This is a function that will allow us to insert an element into the queue:
void insert(QUEUE* q, int elm) {
    // To create a new node:
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    if (newNode == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }
    newNode->data = elm;
    newNode->next = NULL;

    // This should satisfy the condition that if the queue is empty, then we will set both front and rear to the new node
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        // Otherwise, we have to add the new node to the rear and update rear
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// This is a function that deletes an element from the queue
int delete(QUEUE* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        exit(1);
    }

    // The function that enables us to get the front element
    int deletedValue = q->front->data;
    NODE* temp = q->front;

    // The function that allows us to move front to the next node
    q->front = q->front->next;
    free(temp);

    // Satisfying the condition that if front becomes NULL, we then set rear to NULL as well
    if (q->front == NULL) {
        q->rear = NULL;
    }

    return deletedValue;
}

// This is a function to print the elements of the queue
void printQueue(QUEUE q) {
    NODE* current = q.front;
    printf("Queue: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    QUEUE q;
    initQueue(&q);

    int choice, elm;

    do {
        printf("\nQueue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &elm);
                insert(&q, elm);
                break;
            case 2:
                if (q.front == NULL) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Deleted element: %d\n", delete(&q));
                }
                break;
            case 3:
                printQueue(q);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
