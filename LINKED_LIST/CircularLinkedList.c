#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to display the circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Function to delete a node from the circular linked list
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = *head, *prev = NULL;
    while (temp->data != key) {
        if (temp->next == *head) {
            printf("Node with data %d not found.\n", key);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    if (temp == *head && temp->next == *head) {
        *head = NULL;
        free(temp);
        return;
    }
    if (temp == *head) {
        prev = *head;
        while (prev->next != *head) {
            prev = prev->next;
        }
        *head = temp->next;
        prev->next = *head;
        free(temp);
    } else if (temp->next == *head) {
        prev->next = *head;
        free(temp);
    } else {
        prev->next = temp->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);

    printf("Circular Linked List: ");
    display(head);

    deleteNode(&head, 20);
    printf("After deleting 20: ");
    display(head);

    deleteNode(&head, 10);
    printf("After deleting 10: ");
    display(head);

    return 0;
}