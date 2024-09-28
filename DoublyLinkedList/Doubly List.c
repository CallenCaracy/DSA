#include <stdio.h>
#include <stdlib.h>

#define MAX_String 50
typedef char String[MAX_String];

typedef struct NumberList {
    struct NumberList* next;
    int data;
    struct NumberList* prev;
} NumberList, *Plist;

void moveBack(Plist* current);
void moveForward(Plist* current);

Plist createNode(int data);
void insertRear(Plist* head, int data);
void printList(Plist head);
void freeList(Plist* head);

int main(void) {
    Plist head = NULL;
    Plist current = NULL;  // Pointer to keep track of the current node
    
    String arr[] = {"Add Number", "Move Forward", "Move Back", "Exit"};
    int choice;
    
    do {
        // Loop through the array of strings and print each option
        for (int i = 0; i < 4; i++) {
            printf("%d. %s\n", i + 1, arr[i]);    
        }

        // Get the user's choice
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        // Handle the user's choice
        switch(choice) {
            case 1: {
                printf("You chose to add a number.\n");
                int number;
                printf("Enter the number to add: ");
                scanf("%d", &number);
                insertRear(&head, number);
                
                // If the list was previously empty, set the current to head
                if (current == NULL) {
                    current = head;
                }

                printList(head);
                break;
            }
            case 2:
                if (current == NULL) {
                    printf("List is empty\n\n");
                } else {
                    printf("You chose to move forward.\n\n");
                    moveForward(&current);
                }
                break;
            case 3:
                if (current == NULL) {
                    printf("List is empty\n\n");
                } else {
                    printf("You chose to move back.\n\n");
                    moveBack(&current);
                }
                break;
            case 4:
                printf("Exiting...\n\n");
                freeList(&head);
                break;
            default:
                printf("Invalid choice! Please try again.\n\n");
        }

    } while (choice != 4);
    
    return 0;
}

// Function to create a new node
Plist createNode(int data) {
    Plist newNode = (Plist)malloc(sizeof(NumberList));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the rear of the list
void insertRear(Plist* head, int data) {
    Plist newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        Plist temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to move the current pointer forward
void moveForward(Plist* current) {
    if ((*current)->next != NULL) {
        *current = (*current)->next;
        printf("Moved forward. Current node data: %d\n\n", (*current)->data);
    } else {
        printf("Already at the end of the list.\n\n");
    }
}

// Function to move the current pointer backward
void moveBack(Plist* current) {
    if ((*current)->prev != NULL) {
        *current = (*current)->prev;
        printf("Moved back. Current node data: %d\n\n", (*current)->data);
    } else {
        printf("Already at the beginning of the list.\n\n");
    }
}

// Function to print the entire list
void printList(Plist head) {
    Plist temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}

// Function to free the entire list
void freeList(Plist* head) {
    Plist temp = *head;
    while (temp != NULL) {
        Plist next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
    printf("List memory has been freed.\n\n");
}
