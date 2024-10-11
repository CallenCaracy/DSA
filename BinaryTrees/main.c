#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "binarytree.c"

int main(void){
    TreePtr head;
    initTree(&head);

    insertTree(&head, 45);
    insertTree(&head, 30);
    insertTree(&head, 20);
    insertTree(&head, 40);
    insertTree(&head, 80);
    insertTree(&head, 50);
    insertTree(&head, 70);

    visualizeTemp(head);
    printf("\n");
    breadthFirstSearch(head);
    depthFirstSearch(head);

    return 0;
}