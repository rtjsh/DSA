// Question: Implement a stack as an ADT[Abstract Datatype] in C that can store user-defined function

#include <stdio.h>
#include <stdbool.h>

#define MAX 5 // Maximum capacity of stack

// User-defined structure
typedef struct {
    char name[50];
    int j_no;
} Player;

// Stack structure
typedef struct {
    int TOS;             // Index of the TOS element
    Player Data[MAX];    // Array to hold elements (of type Player)
} Stack;

// Function prototype of stack operations 

bool isFull(Stack *S);
bool isEmpty(Stack *S);
void push(Stack *S, Player p);
Player pop(Stack *S);
Player peek(Stack *S);
void printStack(Stack *S);

// Main function
int main() {
    Stack S;
    S.TOS = -1; // Initializes the stack to empty
    int choice = 0; // Variable "choice" might contain a random garbage value so initializing it, makes the loop fully functional
    while (choice!=5) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Print Stack\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Player p;
                printf("Enter player's name: ");
                scanf("%s", p.name);
                printf("Enter jersey's number: ");
                scanf("%d", &p.j_no);
                push(&S, p);
                break;
            }
            case 2: {
                if (isEmpty(&S)) {
                    printf("Stack is empty\n");
                } else {
                    Player p = pop(&S);
                    printf("Popped: Player's name = %s, Jersey's Number = %d\n", p.name, p.j_no);
                }
                break;
            }
            case 3: {
                if (isEmpty(&S)) {
                    printf("Stack is empty\n");
                } else {
                    Player p = peek(&S);
                    printf("TOS: Player's name = %s, Jersey's Number = %d\n", p.name, p.j_no);
                }
                break;
            }
            case 4:
                printStack(&S);
                break;
            case 5:
               break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

// Function definitions


// It checks if the stack is full
bool isFull(Stack *S) {
    return S->TOS == MAX - 1;
}

// It checks if the stack is empty
bool isEmpty(Stack *S) {
    return S->TOS == -1; // The function returns true (1).
}

// It pushes an element on the top of the stack[TOS]
void push(Stack *S, Player p) {
    if (isFull(S)) {
        printf("Stack is full, cannot push\n");
    } else {
        S->TOS++;
        S->Data[S->TOS] = p; // Adds the player to the stack
        printf("Pushed: Player's name = %s, Jersey's Number = %d\n", p.name, p.j_no);
    }
}

// It pops an element from the stack
Player pop(Stack *S) {
    Player empty = {"", -1}; // It returns an empty player if the stack is empty
    if (isEmpty(S)) {
        printf("Stack is empty, cannot pop\n");
        return empty;
    }
    return S->Data[S->TOS--];
}

// It peeks at the top element of the stack [TOP]
Player peek(Stack *S) {
    Player empty = {"", -1};
    if (isEmpty(S)) {
        printf("Stack is empty, cannot peek\n");
        return empty;
    }
    return S->Data[S->TOS];
}

// Print all elements in the stack
void printStack(Stack *S) {
    if (isEmpty(S)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack contents (tos to bottom):\n");
        for (int i = S->TOS; i >= 0; i--) {
            printf("Player's name: %s, Jersey's Number: %d\n", S->Data[i].name, S->Data[i].j_no);
        }
    }
}
