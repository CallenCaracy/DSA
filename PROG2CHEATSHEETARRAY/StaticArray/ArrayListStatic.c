#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ArrayListStatic.h"

void initList(List *list) {
    list->count = 0;
}

void display(List list){
    printf("{");
    for(int i = 0; i < list.count; ++i) {
        printf("%d", list.elems[i]);
        if(i < list.count - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

List createList() {
    List list;
    list.count = 0;
    return list;
}

// bool insertFront(List *list, int item) {
//     if(list->count < MAX) {
//         for(int i = list->count; i > 0; --i) {
//             list->elems[i] = list->elems[i-1];
//         }
//         list->elems[0] = item;
//         (list->count)++;
//         return true;
//     }
//     return false;
// }

bool insertFront(List *list, int item) {
    if(list->count < MAX) {
        memcpy(&list->elems[1], &list->elems[0], list->count * sizeof(int));
        list->elems[0] = item;
        (list->count)++;
        return true;
    }
    return false;
}

bool insertRear(List *list, int item) {
    if(list->count < MAX){
        list->elems[(list->count)++] = item;
        return true;
    }
    return false;
}

// bool insertInto(List *list, int item, int position) {
//     if(position < 0 || position > list->count || list->count >= MAX) {
//         return false;
//     }
//     for(int i = list->count; i > position; --i) {
//         list->elems[i] = list->elems[i-1];
//     }
//     list->elems[position] = item;
//     (list->count)++;
//     return true;
// }

bool insertInto(List *list, int item, int position) {
    if(position < 0 || position > list->count || list->count >= MAX) {
        return false;
    }
    
    memcpy(&list->elems[position + 1], &list->elems[position], (list->count - position) * sizeof(int));
    list->elems[position] = item;
    (list->count)++;
    return true;
}

// bool deleteFront(List *list) {
//     if(list->count > 0) {
//         for(int i = 0; i < list->count - 1; ++i) {
//             list->elems[i] = list->elems[i+1];
//         }
//         (list->count)--;
//         return true;
//     }
//     return false;
// }

bool deleteFront(List *list) {
    if(list->count > 0) {
        memcpy(&list->elems[0], &list->elems[1], (list->count - 1) * sizeof(int));
        (list->count)--;
        return true;
    }
    return false;
}

bool deleteRear(List *list) {
    if(list->count > 0) {
        (list->count)--;
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
        memcpy(&list->elems[pos], &list->elems[pos + 1], (list->count - pos - 1) * sizeof(int));
    }

    (list->count)--; 
    return true;
}
