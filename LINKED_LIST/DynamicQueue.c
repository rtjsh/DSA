// Queue using Linked List
#include <stdio.h>
#include <stdlib.h>
struct SLL
{
  int data;
  struct SLL *next;
};
struct SLL *front,*rear = NULL;
struct SLL *createNode(int element)
{
  struct SLL *NewNode;
  NewNode = (struct SLL *)malloc(sizeof(struct SLL));
  if (NewNode == NULL)
    return NULL;
  else
  {
    NewNode->data = element;
    NewNode->next = NULL;
    return NewNode;
  }
}
void Enqueue(int element)
{
    struct SLL *NewNode = createNode(element);
    if (NewNode == NULL)
        printf("Cannot allocate memory\n");
    else
    {
        if (front == NULL) // Queue is empty
            front = rear = NewNode;
        else
        {
            rear->next = NewNode; // Add new node at the end
            rear = NewNode;       // Update the rear pointer
        }
        printf("%d was inserted.\n", element); // Print the inserted element
    }
}

int Dequeue()
{
    struct SLL *temp;
    int element = -1;
    if (front == NULL)
    {
        printf("Queue is Empty\n");
    }
    else if (front->next == NULL)
    {
        temp = front;
        front = rear = NULL;
        element = temp->data;
        free(temp);
    }
    else
    {
        temp = front;
        front = front->next;
        element = temp->data;
        free(temp);
    }
    if (element != -1)
        printf("%d was deleted from queue\n", element);
    return element;
}

void display()
{
  struct SLL *temp;
  if (front == NULL)
  {
    printf("QUEUE IS EMPTY\n");
  }
  else
  {
    temp = front;
    do
    {
      printf("%d ->", temp->data);
      temp = temp->next;
    } while (temp != NULL);
    printf("NULL\n");
  }
}
int main()
{
  int choice, data;
    int position;

    do
    {
        printf("***************************************\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
      switch (choice)
        {
        case 1:
            printf("Enter the data you want to be inserted:\t ");
            scanf("%d", &data);
            Enqueue(data);
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting\n");
            break;
        default:
            printf("Invalid Choice\n");
        }
    } while (choice != 4);
}