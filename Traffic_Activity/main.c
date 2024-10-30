#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "traffic.c"

int main(void){
    HeapPtrPriority heap;
    initBinaryHeap(&heap, 10);

    insert(&heap, 5, "Light Traffic");
    insert(&heap, 2, "Heavy Traffic");
    insert(&heap, 8, "Moderate Traffic");
    insert(&heap, 1, "No Traffic");
    insert(&heap, 3, "Accident Ahead");
    insert(&heap, 7, "Construction Zone");
    insert(&heap, 6, "Rush Hour");
    insert(&heap, 4, "Road Closure");

    printf("Heap after inserting dummy data:\n");
    visualize(heap);

    delete(&heap);
    printf("\nHeap after deleting the root element:\n");
    visualize(heap);

    return 0;
}