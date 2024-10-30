#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "traffic.h"

void initBinaryHeap(HeapPtrPriority *head, int max){
    *head = malloc(sizeof(BinaryHeapPriority));
    if(*head == NULL){
        return;
    }

    (*head)->count = 0;
    (*head)->max = max;
    (*head)->elems = malloc(sizeof(TrafficData) * max);
    if((*head)->elems == NULL){
        free(*head);
        return;
    }
    for(int i = 0; i < (*head)->max; i++){
        (*head)->elems[i].time = 0;
        strcpy((*head)->elems[i].trafficMov, "");
    }
}

bool isEmpty(HeapPtrPriority head){
    return head->count == 0;
}

bool isFull(HeapPtrPriority head){
    return head->count == head->max -1;
}

bool insert(HeapPtrPriority *head, int time, char *trafficMov){
    if(isFull(*head)){
        printf("The array is full");
        return false;
    }

    int i = (*head)->count;
    while(i > 0 && (*head)->elems[(i - 1)].time > time){
        (*head)->elems[i] = (*head)->elems[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    (*head)->elems[i].time = time;
    strcpy((*head)->elems[i].trafficMov, trafficMov);
    (*head)->count++;
    return true;
}

bool delete(HeapPtrPriority *head){
    if(isEmpty(*head)){
        printf("The array is empty");
        return false;
    }

    int lastIndex = (*head)->count - 1;
    (*head)->elems[0] = (*head)->elems[lastIndex];
    (*head)->count--;

    heapify(head, 0);

    return true;
}

void heapify(HeapPtrPriority *head, int i){
    int largest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (leftChild < (*head)->count && (*head)->elems[leftChild].time < (*head)->elems[largest].time) {
        largest = leftChild;
    }

    if (rightChild < (*head)->count && (*head)->elems[rightChild].time < (*head)->elems[largest].time) {
        largest = rightChild;
    }

    if (largest != i) {
        TrafficData temp = (*head)->elems[i];
        (*head)->elems[i] = (*head)->elems[largest];
        (*head)->elems[largest] = temp;

        heapify(head, largest);
    }
}

void visualize(HeapPtrPriority head){
    if(isEmpty(head)){
        return;
    }

    for (int i = 0; i < head->count; i++){
        printf("Time: %d, Movement: %s\n", head->elems[i].time, head->elems[i].trafficMov);
    }
}

char* translate(TrafficData data){
    char stringVersion[2];
    switch(data.priority){
        case 1:
            return strcpy(stringVersion, "PM");
            break;
        case 2:
            return strcpy(stringVersion, "PD");
            break;
        case 3:
            return strcpy(stringVersion, "M");
            break;
        case 4:
            return strcpy(stringVersion, "D");
            break;
        case 5:
            return strcpy(stringVersion, "ML");
            break;
        case 6:
            return strcpy(stringVersion, "DL");
            break;
        case 7:
            return strcpy(stringVersion, "MR");
            break;
        case 8:
            return strcpy(stringVersion, "DR");
            break;
        default:
            return strcpy(stringVersion, "NA");
            break;
    }
}