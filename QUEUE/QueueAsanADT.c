#include "stdio.h"
#include "stdbool.h"
#define MAX 5
struct Queue {
    int  FRONT;
    int REAR;
    int Data[MAX];
};


bool isFull (struct Queue *Q) 
{
    if(Q->REAR == MAX - 1) {
        return true;
    }
    return false;
}

bool isEmpty (struct Queue *Q) {
    if(Q->REAR < Q->FRONT) {
        return true;
    }
    return false;
}

void enqueue (struct Queue *Q, int add) {
    if(isFull(Q)) // Since Q is a pointer to a Queue structure (struct Queue *Q), the address of the Queue structure is being passed to the isFull function.
    {
        printf("Queue is full\n");
    } else {
        Q->REAR++;
        Q->Data[Q->REAR] = add;
        // to view the added element from the queue
        printf("Added %d to the queue\n", Q->Data[Q->REAR]);
    }
}

void dequeue (struct Queue *Q) {
    if(isEmpty(Q)) {
        printf("Queue is Empty\n");
    } 
    else {
        printf("Removed %d from the queue\n", Q->Data[Q->FRONT]);
        Q->FRONT++;
    }
}

void front (struct Queue *Q) {
    if(isEmpty(Q)) {
        printf("Queue is Empty\n");
    } else {
        printf("Front element is %d\n", Q->Data[Q->FRONT]);
    }
}

void display (struct Queue *Q) {
    if(isEmpty(Q)) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue elements are: ");
        for(int i = Q->FRONT; i <= Q->REAR; i++) {
            printf("%d ", Q->Data[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Queue Q={0,-1};
    int choice, data;
    do {
        printf("***************************************\n");
        printf("1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the element to be enqueued: ");
                scanf("%d", &data);
                enqueue(&Q, data);
                break;
            case 2:
                dequeue(&Q);
                break;
            case 3:
                display(&Q);
                break;
            case 4:
                printf("BYE!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}