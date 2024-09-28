#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ArrayListDynamic.c"

int main(void) {
    List myList = createList();
    
    insertRear(&myList, 10);
    insertRear(&myList, 20);
    insertRear(&myList, 30);
    insertRear(&myList, 40);
    
    display(myList);
    
    insertFront(&myList, 5);
    display(myList);
    
    insertInto(&myList, 25, 2);
    display(myList);
    
    deleteItem(&myList, 20);
    display(myList);
    
    deleteFront(&myList);
    display(myList);
    
    deleteRear(&myList);
    display(myList);
    
    freeList(&myList);
    
    return 0;
}