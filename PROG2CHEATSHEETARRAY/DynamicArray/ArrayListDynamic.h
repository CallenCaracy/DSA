#ifndef ARRAY_LIST_DYNAMIC_H
#define ARRAY_LIST_DYNAMIC_H

#include <stdbool.h>

#define MAX 10

typedef struct {
    int *elems;
    int count;
    int size;
} List;

void initList(List *list);
List createList();
void resizeList(List *list);
void display(List list);
void freeList(List *list);

bool insertFront(List *list, int item);
bool insertRear(List *list, int item);
bool insertInto(List *list, int item, int position);

bool deleteFront(List *list);
bool deleteRear(List *list);
bool deleteItem(List *list, int target);

#endif