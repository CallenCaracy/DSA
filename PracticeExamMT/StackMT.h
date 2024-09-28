#ifndef STACKMT_H
#define STACKMT_H

#include <stdbool.h>
typedef char String[30];

typedef struct {
    int prodID;
    String prodName;
    int prodQty;
    float prodPrice;
} Product;

typedef struct node {
    Product prod;
    struct node *link;
} NodeType, *NodePtr, *Stack;

typedef struct {
    NodePtr *data;
    int count;
    int max;
} ProdDict;


// Stack
void initStack(Stack *s);
bool isEmpty(Stack p);
bool push(Stack *s, Product p);
bool pop(Stack *s);
Product peek(Stack s);
void visualizeStack(Stack s);


// Dictionary 75% Load 
void initDictionary(ProdDict *pd, int max);
int getHash(ProdDict pd, Product p);
bool insertDictionary(ProdDict *pd, Product p);
bool insertSortDict(ProdDict *pd, Stack s);
bool deleteDictionary(ProdDict *pd, Product p);
Product getDictionary(ProdDict *pd, int prodID, String prodName);
void visualizeDictionary(ProdDict pd);


// Product
Product createProd(int prodID, String prodName, int prodQty, float prodPrice);
void convertStackToDictionary(Stack *productStack, ProdDict *pd);

#endif