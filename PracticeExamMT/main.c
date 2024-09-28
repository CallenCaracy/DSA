#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "StackMT.c"

int main() {
    Stack s;
    initStack(&s);

    ProdDict pd;
    initDictionary(&pd, 10);

    push(&s, createProd(1, "Tandaway", 10, 19.99));
    push(&s, createProd(2, "Shabu", 5, 29.99));
    push(&s, createProd(1, "Tandaway", 3, 19.53));
    push(&s, createProd(1, "Tandaway", 104, 19.29));
    push(&s, createProd(1, "Tandaway", 104, 19.29));
    push(&s, createProd(3, "Marijuanna", 5, 10042.65));
    push(&s, createProd(4, "Black Tar Heroine", 32, 10223.59));
    push(&s, createProd(2, "Shabu", 2, 29.99));
    push(&s, createProd(2, "Shabu", 91, 29.99));
    pop(&s);

    visualizeStack(s);

    convertStackToDictionary(&s, &pd);

    visualizeDictionary(pd);

    deleteDictionary(&pd, createProd(3, "Marijuanna", 5, 10042.65));

    visualizeDictionary(pd);

    while (!isEmpty(s)) {
        pop(&s);
    }
    free(pd.data); 

    return 0;
}