#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ArrayListDynamic.h"

void initList(List *list) {
    list->size = MAX;
    list->count = 0;
    list->elems = (int *)malloc(list->size * sizeof(int));
    if (list->elems == NULL) {
        printf("Failed to allocate memory.\n");
    }
}

void display(List list) {
    printf("{");
    for (int i = 0; i < list.count; ++i) {
        printf("%d", list.elems[i]);
        if (i < list.count - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

List createList() {
    List list;
    initList(&list);
    return list;
}

void resizeList(List *list) {
    list->size *= 2;
    list->elems = (int *)realloc(list->elems, list->size * sizeof(int));
    if (list->elems == NULL) {
        printf("Failed to reallocate memory.\n");
    }
}

void freeList(List *list) {
    free(list->elems);
    list->elems = NULL;
    list->size = 0;
    list->count = 0;
}

bool insertFront(List *list, int item) {
    if (list->count == list->size) {
        resizeList(list);
    }
    memmove(&list->elems[1], &list->elems[0], list->count * sizeof(int));
    list->elems[0] = item;
    list->count++;
    return true;
}

bool insertRear(List *list, int item) {
    if (list->count == list->size) {
        resizeList(list);
    }
    list->elems[list->count++] = item;
    return true;
}

bool insertInto(List *list, int item, int position) {
    if (position < 0 || position > list->count) {
        return false;
    }
    if (list->count == list->size) {
        resizeList(list);
    }
    memmove(&list->elems[position + 1], &list->elems[position], (list->count - position) * sizeof(int));
    list->elems[position] = item;
    list->count++;
    return true;
}

bool deleteFront(List *list) {
    if (list->count > 0) {
        memmove(&list->elems[0], &list->elems[1], (list->count - 1) * sizeof(int));
        list->count--;
        return true;
    }
    return false;
}

bool deleteRear(List *list) {
    if (list->count > 0) {
        list->count--;
        return true;
    }
    return false;
}

bool deleteItem(List *list, int target) {
    int pos = -1;

    for (int i = 0; i < list->count; i++) {
        if (list->elems[i] == target) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        return false;
    }

    if (pos < list->count - 1) {
        memmove(&list->elems[pos], &list->elems[pos + 1], (list->count - pos - 1) * sizeof(int));
    }

    list->count--;
    return true;
}