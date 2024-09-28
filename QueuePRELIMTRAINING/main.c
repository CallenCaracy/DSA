#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "NQueue.c"

int main(void) {
    NQueue nq = createQueue(10);
    
    enqueue(&nq, createName("Clarence", "Diangco"));
    enqueue(&nq, createName("Clarence", "Diangco"));
    dequeue(&nq);
    enqueue(&nq, createName("Lake", "AkoPakitaPaspas"));
    enqueue(&nq, createName("At", "To ban"));
    enqueue(&nq, createName("IShowSpeed", "AkoPakitaPaspas"));
    enqueue(&nq, createName("Don't", "Kyer"));
    enqueue(&nq, createName("Coder", "Colder"));
    enqueue(&nq, createName("Yay", "Wow"));
    enqueue(&nq, createName("Callen", "Caracy"));
    enqueue(&nq, createName("Last", "Boi"));
    enqueue(&nq, createName("Last", "Boi")); //testing the limit
    
    displayQueue(nq);
    
    Name *removed = filterNames(&nq, "AkoPakitaPaspas");
    displayRemovedName(removed);
    
    displayQueue(nq);
    insertSorted(&nq, createName("Sorted", "Boi"));
    insertSorted(&nq, createName("Sorted", "Boi"));
    insertSorted(&nq, createName("Sorted", "Boi"));
    displayQueue(nq);

    free(removed);
    return 0;
}