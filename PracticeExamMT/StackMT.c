#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "StackMT.h"

// Stack
void initStack(Stack *s) {
    *s = NULL;
}

bool isEmpty(Stack p){
    return p == NULL;
}

bool push(Stack *s, Product p){
    Stack temp = malloc(sizeof(NodeType));
    
    temp->prod = p;
    temp->link = *s;
    *s = temp;

    return true;
}

bool pop(Stack *s){
    if(*s == NULL){
        return false;
    }

    Stack temp = *s;
    *s = temp->link;
    free(temp);

    return true;
}

Product peek(Stack s){
    return s->prod;
}

void visualizeStack(Stack s) {
    if (isEmpty(s)) {
        printf("The stack is empty.\n");
        return;
    }
    Stack current = s;
    while (current != NULL) {
        printf("Product ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", 
            current->prod.prodID, 
            current->prod.prodName, 
            current->prod.prodQty, 
            current->prod.prodPrice);
        current = current->link;
    }
}



// Dictionary 75% Load 

void initDictionary(ProdDict *pd, int max){
    pd->count = 0;
    pd->max = max;
    pd->data = malloc(sizeof(NodePtr) * max);
    for(int i = 0; i < max; i++){
        pd->data[i] = NULL;
    }
}

int getHash(ProdDict pd, Product p){
    int pos = p.prodID;

    for(int i = 0; i < 5; i++){
        pos += p.prodName[i];
    }
    return pos % pd.max;
}

bool insertDictionary(ProdDict *pd, Product p){
    if(pd->count > pd->max * 0.70){
        printf("Full, can't insert.\n"); 
        return false;
    }

    int pos = getHash(*pd, p);
    Stack temp = malloc(sizeof(NodeType));
    temp->prod = p;
    temp->link = NULL;

    if(pd->data[pos] == NULL){
        pd->data[pos] = temp;
        pd->count++;
        return true;
    }else{
        insertSortDict(pd, temp);
        pd->count++;
        return true;
    }
    return false;
}

bool insertSortDict(ProdDict *pd, Stack s) {
    int pos = getHash(*pd, s->prod);
    NodePtr curr = pd->data[pos];
    NodePtr prev = NULL;

    while(curr != NULL && curr->prod.prodID < s->prod.prodID){
        prev = curr;
        curr = curr->link;
    }

    if(prev == NULL){
        s->link = pd->data[pos];
        pd->data[pos] = s;
    }else {
        prev->link = s;
        s->link = curr;
    }
    return true;
}

bool deleteDictionary(ProdDict *pd, Product p){
    int pos = getHash(*pd, p);
    NodePtr curr = pd->data[pos];
    NodePtr prev = NULL;

    while(curr != NULL && curr->prod.prodID != p.prodID){
        prev = curr;
        curr = curr->link;
    }

    if(curr == NULL){
        return false;
    }

    if(prev == NULL){
        pd->data[pos] = curr->link;
    }else{
        prev->link = curr->link;
    }

    free(curr);
    pd->count--;
    return true;
}

Product getDictionary(ProdDict *pd, int prodID, String prodName){
    int pos = getHash(*pd, createProd(prodID, prodName, 0, 0.0));
    NodePtr find = pd->data[pos];

    while(find != NULL){
        if(find->prod.prodID == prodID && strcmp(find->prod.prodName, prodName) == 0){
            return find->prod;
        }
        find = find->link;
    }
    return (Product){0};
}

// Create a function that converts a product stack into a dictionary. if similar product exist automatically adds it into the prodQty
void convertStackToDictionary(Stack *s, ProdDict *pd) {
    Stack curr = *s;
    Product p;
    Product found;

    while(curr != NULL){
        p = curr->prod;
        found = getDictionary(pd, p.prodID, p.prodName);

        if(found.prodID != 0){
            found.prodQty += p.prodQty;
            deleteDictionary(pd, found);
            insertDictionary(pd, found);
        }else{
            insertDictionary(pd, p);
        }
        curr = curr->link;
    }

    while(!isEmpty(*s)){
        pop(s);
    }
}

void visualizeDictionary(ProdDict pd) {
    printf("Dictionary contents:\n");
    for (int i = 0; i < pd.max; i++) {
        printf("[%d] -> ", i);
        if (pd.data[i] != NULL) {
            NodePtr current = pd.data[i];
            while (current != NULL) {
                printf("{Product ID: %d, Name: %s, Quantity: %d, Price: %.2f} -> ", 
                    current->prod.prodID, 
                    current->prod.prodName, 
                    current->prod.prodQty, 
                    current->prod.prodPrice);
                current = current->link;
            }
            printf("NULL\n");
        } else {
            printf("Empty\n", i);
        }
    }
}

// Product
Product createProd(int prodID, String prodName, int prodQty, float prodPrice){
    Product p;

    p.prodID = prodID;
    strcpy(p.prodName, prodName);
    p.prodQty = prodQty;
    p.prodPrice = prodPrice;

    return p;
}