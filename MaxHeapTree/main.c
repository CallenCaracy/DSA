#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "heaptree.c"

int main(void){
    HeapPtr head;
    initBinaryHeap(&head, 10);

    insert(&head, 10);
    insert(&head, 3);
    insert(&head, 12);
    insert(&head, 121);
    insert(&head, 65);
    insert(&head, 19);
    insert(&head, 321);
    delete(&head);

    visualize(head);

    return 0;
}