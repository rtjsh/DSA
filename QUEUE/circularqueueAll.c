// Follows no specific principle

#include<stdio.h>

#define MAX 5

struct CircularQueue {
    int FRONT;
    int REAR;
    int size;
    int DATA[MAX];
};

typedef struct CircularQueue CQ;

void enqueue(CQ *Q, int element) {
    if (Q->size == MAX) {
        printf("Queue is FULL.\n");
    } else {
        Q->DATA[Q->REAR] = element;
        Q->REAR = (Q->REAR + 1) % MAX;
        Q->size++;
        printf("%d was ENQUEUED.\n", element);
    }
}

int dequeue(CQ *Q) {
    if (Q->size == 0) {
        printf("Queue is EMPTY.\n");
        return -1; // Return -1 to indicate queue is empty
    } else {
        int element = Q->DATA[Q->FRONT];
        Q->FRONT = (Q->FRONT + 1) % MAX;
        Q->size--;
        return element;
    }
}

void display(CQ *Q) {
    if (Q->size == 0) {
        printf("Queue is EMPTY.\n");
    } else {
        printf("Queue elements are: ");
        for (int i = 0; i < Q->size; i++) {
            int index = (Q->FRONT + i) % MAX;
            printf("%d ", Q->DATA[index]);
        }
        printf("\n");
    }
}

int main() {
    int choice, data;
    CQ Q = {0, 0, 0};
    
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
                data = dequeue(&Q);
                if (data != -1) {
                    printf("Dequeued element: %d\n", data);
                }
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
