// Stack
#include <stdio.h>
#include <stdlib.h>
struct SLL
{
  int data;
  struct SLL *next;
};
struct SLL *top = NULL;
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
void Insertion(int element)
{
  struct SLL *NewNode = createNode(element);
  if (NewNode == NULL)
    printf("Cannot allocate memory");
  else
  {
    if (top == NULL)
      top = NewNode;
    else
    {
      NewNode->next = top;
      top = NewNode;
    }
    printf("%d was inserted at the beginning\n", top->data);
  }
}
void Deletion()
{
  struct SLL *temp;
  int element = -1;
  if (top == NULL)
    printf("Stack is Empty\n");
  else if (top->next == NULL)
  {
    temp = top;
    element = temp->data;
    top = NULL;
    free(temp);
    printf("%d was deleted from stack\n", element);
  }
  else
  {
    temp = top;
    element = temp->data;
    top = top->next;
    free(temp);
    printf("%d was deleted from stack\n", element);
  }
}
void display()
{
  struct SLL *temp;
  if (top == NULL)
  {
    printf("STACK IS EMPTY\n");
  }
  else
  {
    temp = top;
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
        printf("1. Insertion\n2. Deletion\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
      switch (choice)
        {
        case 1:
            printf("Enter the data you want to be inserted:\t ");
            scanf("%d", &data);
            Insertion(data);
            break;
        case 2:
            Deletion();
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