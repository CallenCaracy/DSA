#ifndef ARRAY_LIST_STATIC_H
#define ARRAY_LIST_STATIC_H

#include <stdbool.h>

#define MAX 10

typedef struct {
    int elems[MAX];
    int count;
}List;

void initList(List *list);
void display(List list);
List createList();

bool insertFront(List *list, int item);
bool insertRear(List *list, int item);
bool insertInto(List *list, int item, int position);

bool deleteFront(List *list);
bool deleteRear(List *list);
bool deleteItem(List *list, int target);

#endif