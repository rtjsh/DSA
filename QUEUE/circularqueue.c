/* A circular queue of size 𝑛 can hold at most (n−1) elements when implemented using an array. To utilize all 
  n slots, you can maintain a separate variable (e.g., size) to track the number of elements in the queue explicitly as done in the program circularQueueAll.c. */

#include<stdio.h>
#include<stdbool.h>

#define MAX 5

struct Queue {
    int FRONT;
    int REAR;
    int Data[MAX];
};

bool isFull(struct Queue *Q)
{
    return (Q->FRONT == (Q->REAR + 1) % MAX);
}

bool isEmpty(struct Queue *Q)
{
    return (Q->FRONT == Q->REAR);
}

void Enqueue(struct Queue *Q, int add)
{
    if(isFull(Q))
    {
        printf("Queue is full\n");
    }
    else
    {
        Q->Data[Q->REAR] = add;
        printf("Added %d to the queue\n", Q->Data[Q->REAR]);
        Q->REAR = (Q->REAR + 1) % MAX;
    }
}

void Dequeue(struct Queue *Q)
{
    if(isEmpty(Q))
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Removed %d from the queue\n", Q->Data[Q->FRONT]);
        Q->FRONT = (Q->FRONT + 1) % MAX;
    }
}

int main()
{
    struct Queue Q = {0, 0};
    int choice,data;
    do
    {
        printf("***************************************\n");
        printf("1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the data to be added: ");
                scanf("%d", &data);
                Enqueue(&Q, data);
                break;
            case 2:
                Dequeue(&Q);
                break;
            case 3:
                if(isEmpty(&Q))
                {
                    printf("Queue is Empty\n");
                }
                else
                {
                printf("Queue elements are: ");
                for(int i = Q.FRONT; i < Q.REAR; i++)
                {
                    printf("%d ", Q.Data[i]);
                }
                printf("\n");
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 4);
}