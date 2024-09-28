#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ArrayListStatic.c"

typedef char String [50];

int main(void) {
    List myList = createList();
    int choice, value, position;
    String arr[] = {"Insert Front", "Insert Rear", "Insert Into", "Delete Front", "Delete Rear", "Delete Item", "Display Array List", "Exit"};

    do
    {
        int i;
        for(i = 0; i < 8; i++){
            printf("%d: %s.\n", i + 1, arr[i]);
        }
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter a Value to be in First: ");
            scanf("%d", &value);
            insertFront(&myList, value);
            break;
        case 2:
            printf("Enter a Value to be in Last: ");
            scanf("%d", &value);
            insertRear(&myList, value);
            break;
        case 3:
            printf("Enter a Value: ");
            scanf("%d", &value);
            printf("Enter a Position: ");
            scanf("%d", &position);
            insertInto(&myList, value, position);
            break;
        case 4:
            printf("Deleting the First Value...\n");
            deleteFront(&myList);
            printf("Done!\n\n");
            break;
        case 5:
            printf("Deleting the Last Value...\n");
            deleteRear(&myList);
            printf("Done!\n\n");
            break;
        case 6:
            printf("Enter a Value to be Deleted: ");
            scanf("%d", &value);
            deleteItem(&myList, value);
            break;
        case 7:
            display(myList);
            break;
        case 8:
            printf("Exiting...\n");
            printf("Goodbye\n\n");
            break;
        
        default:
            printf("Invalid Input\n\n");
            break;
        }

    } while (choice != 8);    
    return 0;
}