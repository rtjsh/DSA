#include<stdio.h>
#include<stdlib.h>

struct SLL{
    int data;
    struct SLL *next;
};

struct SLL *first, *last = NULL;

struct SLL* createNode(int element)
{
    struct SLL *NewNode;
    NewNode = (struct SLL*)malloc(sizeof(struct SLL));
    if(NewNode == NULL)  // Memory allocation fails as "NULL" is returned by "malloc()"
    {
        return NULL;
    }
    else
    {
        NewNode-> data = element;
        NewNode -> next = NULL;
        return NewNode;
    }
}

void insertAtBeginning(int element)
{
    struct SLL *NewNode = createNode(element);
    if(NewNode==NULL)
    {
        printf("Memory Allocation Failed\n");
    }
    else{
        if(first == NULL) // List is Empty
        {
            first = last = NewNode;
        }
        else{
            NewNode -> next = first;
            first = NewNode;
        }
        printf("%d was inserted at the beginning.\n",first->data);
    }

}

void insertAtEnd(int element)
{
    struct SLL *NewNode = createNode(element);
    if(NewNode==NULL)
    {
        printf("Memory Allocation Failed\n");
    }
    else{
        if(first == NULL) // List is Empty
        {
            first = last = NewNode;
        }
        else{
            last -> next = NewNode;
            last = NewNode;
        }
        printf("%d was inserted at the end.\n",last->data);
    }
}

int deleteFromBeginning()
{
    struct SLL *temp;
    int element = -1;
    if(first==NULL){
        printf("List is Empty.");
    }

    else if(first->next == NULL)
    {
        temp = first;
        first = last = NULL;
        element = temp->data;
        free(temp);
    }
    else{
        temp = first;
        first = first->next;
        element = temp->data;
        free(temp);
    }
    return element;
}

int deleteFromEnd(){
    struct SLL *temp;
    int element = -1;
    if(first==NULL){
        printf("List is Empty.");

    }

    else if(first->next == NULL)
    {
        temp = first;
        first = last = NULL;
        element = temp->data;
        free(temp);
    }
    else{
        temp = first;
        while(temp->next != last){
            temp = temp->next;
        }
        last = temp;
        temp= temp->next;
        element= temp->data;
        free(temp);
        last->next = NULL;
    }
    return element;
}

int insertAtSpecific(int element, int position){
    struct SLL *NewNode = createNode(element);
    struct SLL *temp;
    if(NewNode==NULL)
    {
        printf("Memory Allocation Failed\n");
    }
    else if(first==NULL)
    {
        printf("List is Empty\n");
    }
    else{
        temp = first;
        for(int i=1;i<position-1;i++)
        {
            temp= temp->next;
        }
        NewNode-> next = temp-> next;
        temp-> next = NewNode;
    }
    printf("%d was inserted at position %d.\n",element, position);
}

int deleteAtSpecific(int position){
    
}



void display()
{
    struct SLL *temp;
    if(first==NULL)
    {
        printf("List is Empty.");
    }
    else{
        temp = first;
        do{
            printf("%d -> ", temp->data);
            temp = temp-> next;
        }while(temp!=NULL);
        
        printf("NULL\n");
    }
}


int main()
{
    int data;
    insertAtBeginning(100);
    display();
    insertAtEnd(200);
    display();
    insertAtBeginning(500);
    display();
    data = deleteFromBeginning();
    if(data!=-1){
        printf("%d was deleted from the beginning.\n",data);
    }
    display();
    data = deleteFromEnd();
    if(data!=-1){
        printf("%d was deleted from the end.\n",data);
    }
    display();
    insertAtSpecific(600,2);
    display();
    return 0;
}






