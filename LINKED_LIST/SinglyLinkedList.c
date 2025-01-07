#include <stdio.h>
#include <stdlib.h>

struct SLL
{
    int data;
    struct SLL *next;
};

struct SLL *first, *last = NULL;

struct SLL *createNode(int element)
{
    struct SLL *NewNode;
    NewNode = (struct SLL *)malloc(sizeof(struct SLL)); // Defalut return type of malloc is void* so we need to typecast it to struct SLL*
    // Dynamic memory allocation is required for creating the NewNode in the linked list implementation because the size of the linked list is not fixed, and it grows or shrinks during runtime depending on the number of elements added or removed.

    if (NewNode == NULL) // Memory allocation fails as "NULL" is returned by "malloc()"
    {
        return NULL;
    }
    else
    {
        NewNode->data = element;
        NewNode->next = NULL;
        return NewNode;
    }
}

void insertAtBeginning(int element)
{
    struct SLL *NewNode = createNode(element);
    if (NewNode == NULL)
    {
        printf("Memory Allocation Failed\n");
    }
    else
    {
        if (first == NULL) // List is Empty
        {
            first = last = NewNode;
        }
        else
        {
            NewNode->next = first;
            first = NewNode;
        }
        printf("%d was inserted at the beginning.\n", first->data);
    }
}

void insertAtEnd(int element)
{
    struct SLL *NewNode = createNode(element);
    if (NewNode == NULL)
    {
        printf("Memory Allocation Failed\n");
    }
    else
    {
        if (first == NULL) // List is Empty
        {
            first = last = NewNode;
        }
        else
        {
            last->next = NewNode;
            last = NewNode;
        }
        printf("%d was inserted at the end.\n", last->data);
    }
}

int deleteFromBeginning()
{
    struct SLL *temp;
    int element = -1;
    if (first == NULL)
    {
        printf("List is Empty.");
    }

    else if (first->next == NULL)
    {
        temp = first;
        first = last = NULL;
        element = temp->data;
        free(temp);
    }
    else
    {
        temp = first;
        first = first->next;
        element = temp->data;
        free(temp);
    }
    return element;
}

int deleteFromEnd()
{
    struct SLL *temp;
    int element = -1;
    if (first == NULL)
    {
        printf("List is Empty.");
    }

    else if (first->next == NULL)
    {
        temp = first;
        first = last = NULL;
        element = temp->data;
        free(temp);
    }
    else
    {
        temp = first;
        while (temp->next != last)
        {
            temp = temp->next;
        }
        last = temp;
        temp = temp->next;
        element = temp->data;
        free(temp);
        last->next = NULL;
    }
    return element;
}

int insertAtSpecific(int element, int position)
{
    struct SLL *NewNode = createNode(element);
    struct SLL *temp;
    if (NewNode == NULL)
    {
        printf("Memory Allocation Failed\n");
    }
    else if (first == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        temp = first;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        NewNode->next = temp->next;
        temp->next = NewNode;
    }
    printf("%d was inserted at position %d.\n", element, position);
}

int deleteAtSpecific(int position)
{
    struct SLL *temp;
    int element = -1;
    if (first == NULL)
    {
        printf("List is Empty.");
    }
    else
    {
        temp = first;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        struct SLL *temp1 = temp->next;
        temp->next = temp1->next;
        element = temp1->data;
        free(temp1);
    }
    return element;
}

void display()
{
    struct SLL *temp;
    if (first == NULL)
    {
        printf("List is Empty.");
    }
    else
    {
        temp = first;
        do
        {
            printf("%d -> ", temp->data);
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
        printf("1. Insert at Beginning\n2. Insert at End\n3. Delete from Beginning\n4. Delete from End\n5. Insert at Specific Position\n6. Delete at Specific Position\n7. Display\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
      switch (choice)
        {
        case 1:
            printf("Enter the data you want to insert at beginning: ");
            scanf("%d", &data);
            insertAtBeginning(data);
            break;
        case 2:
            printf("Enter the data you want to insert at end: ");
            scanf("%d", &data);
            insertAtEnd(data);
            break;
        case 3:
            printf("%d was deleted from the beginning.\n", deleteFromBeginning());
            break;
        case 4:
            printf("%d was deleted from the end.\n", deleteFromEnd());
            break;
        case 5:
            printf("Enter the position you want to enter the data: ");
            scanf("%d", &position);
            printf("Enter the data you want to insert at position %d: ", position);
            scanf("%d", &data);
            insertAtSpecific(data, position);
            break;
        case 6:
            printf("Enter the position from which you want to delete the data: ");
            scanf("%d", &position);
            printf("%d was deleted from position %d.\n", deleteAtSpecific(position), position);
            break;
        case 7:
            display();
            break;
        case 8:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid Choice\n");
        }
    } while (choice != 8);
    return 0;
}
