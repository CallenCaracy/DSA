#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *elems;
    int count;
    int max;
} Set;

// typedef char Set;

Set createSet(int max);
void initSet(Set *s, int max);

bool addElement(Set *s, int item);
bool removeElement(Set *s, int item);
void displaySet(Set s);
bool isElement(Set s, int item);
bool isSubset(Set a, Set b);
int cardinality(Set s);

Set unionSet(Set a, Set b);
Set intersectionSet(Set a, Set b);
Set differenceSet(Set a, Set b);
Set symmetricDifferenceSet(Set a, Set b);

int main(void) {
    Set A = createSet(8);
    Set B = createSet(8);
    
    printf("A\n");
    displaySet(A);
    addElement(&A, 2);
    displaySet(A);
    addElement(&A, 1);
    // displaySet(A);
    // removeElement(&A, 2);
    displaySet(A);
    addElement(&A, 5);
    displaySet(A);
    
    
    printf("B\n");
    displaySet(B);
    addElement(&B, 2);
    displaySet(B);
    addElement(&B, 1);
    displaySet(B);
    addElement(&B, 7);
    displaySet(B);
    // removeElement(&B, 2);
    // displaySet(B);
    
    isSubset(A, B);
    
    Set U = unionSet(A, B);
    displaySet(U);
    
    Set I = intersectionSet(A, B);
    displaySet(I);
    
    Set D = differenceSet(A, B);
    displaySet(D);
        
    Set D2 = differenceSet(B, A);
    displaySet(D2);
    
    Set SD = symmetricDifferenceSet(B, A);
    displaySet(SD);
    
    return 0;
}

Set createSet(int max){
    Set s;
  
    s.count = 0;
    s.max = max;
    s.elems = calloc(max, sizeof(int));
    
    return s;
}
void initSet(Set *s, int max){
    s->count = 0;
    s->max = max;
    s->elems = calloc(max, sizeof(int));
    if(s->elems == NULL){
        printf("Failed to allocate memory.");
    }
}

bool addElement(Set *s, int item){
    if(cardinality(*s) < s->max && !isElement(*s, item)){
        s->elems[item] = 1;
        s->count++;
        return true;
    }
    printf("Failed or Already Occupied.\n");
    return false;
}

bool removeElement(Set *s, int item){
    if(cardinality(*s) != 0 && isElement(*s, item)){
        s->elems[item] = 0;
        s->count--;
        return true;
    }
    printf("Failed or Already Empty.\n");
    return false;
}

void displaySet(Set s) {
    printf("Set {");
    bool first = true; 
    for (int i = 0; i < s.max; i++) {
        if (isElement(s, i)) {
            if (!first) {
                printf(", ");
            }
            printf("%d", i);
            first = false;
        }
    }
    printf("}\n");
}

bool isElement(Set s, int item) {
    if (item < 0 || item >= s.max) {
        printf("Element out of bounds.\n");
        return false;
    }
    return s.elems[item] == 1;
}

bool isSubset(Set a, Set b){
    if(cardinality(b) == 0){
        printf("The second set is an empty set, so it is a subset of the first set.\n");
        return true;
    }
    
    if(cardinality(a) == 0){
        printf("The second set is not a subset of the first set because the first set is empty.\n");
        return false;
    }
    
    for (int i = 0; i < b.max; i++) {
        if (b.elems[i] == 1 && a.elems[i] != 1) {
            printf("%d in second set is not present in the first set, therefore, the second set is not a subset of the first set.\n", i);
            return false;
        }
    }
    
    printf("The second Set is a subset of first Set.\n");
    printf("Set A: ");
    displaySet(a);
    printf("Set B: ");
    displaySet(b);
    return true;
}

int cardinality(Set s) {
    return s.count;
}

Set unionSet(Set a, Set b){
    Set U = createSet(a.max >= b.max ? a.max : b.max);
    
    for(int i = 0; i < a.max; i++){
        if(isElement(a, i)){
            addElement(&U, i);
        }
    }
    
    for(int i = 0; i < b.max; i++){
        if(isElement(b, i) && !isElement(U, i)){
            addElement(&U, i);
        }
    }
    return U;
}

Set intersectionSet(Set a, Set b){
    Set I = createSet(a.max >= b.max ? a.max : b.max);
    
    for(int i = 0; i < a.max; i++){
        if(isElement(a, i) && isElement(b, i)){
            addElement(&I, i);
        }
    }
    return I;
}
Set differenceSet(Set a, Set b){
    Set D = createSet(a.max);
    
    for(int i = 0; i < a.max; i++){
        if(isElement(a, i) && !isElement(b, i)){
            addElement(&D, i);
        }
    }
    return D;
}

Set symmetricDifferenceSet(Set a, Set b){
    Set SD = createSet(a.max >= b.max ? a.max : b.max);
    
    Set D1 = differenceSet(a, b);
    Set D2 = differenceSet(b, a);
    SD = unionSet(D1, D2);
    
    return SD;
}