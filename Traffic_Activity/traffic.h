#ifndef TRAFFIC_H
#define TRAFFIC_H

#include <stdbool.h>

typedef enum {
    PM = 1, PD, M, D, ML, DL, MR, DR
}Entity;

typedef struct{
    int priority;
    Entity trafficMov;
    int time;
}TrafficData;

typedef struct {
    TrafficData *elems;
    int count;
    int max;
}BinaryHeapPriority, *HeapPtrPriority;

char* translate(TrafficData data);
void initBinaryHeap(HeapPtrPriority *head, int max);
bool isEmpty(HeapPtrPriority head);
bool isFull(HeapPtrPriority head);
bool insert(HeapPtrPriority *head, int time, char *trafficMov);
bool delete(HeapPtrPriority *head);
void heapify(HeapPtrPriority *head, int i);
void visualize(HeapPtrPriority head);


#endif