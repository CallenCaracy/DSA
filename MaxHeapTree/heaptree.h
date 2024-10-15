#ifndef HEAPTREE_H
#define HEAPTREE_H

typedef struct {
    int *elems;
    int count;
    int max;
}BinaryHeap, *HeapPtr;

void initBinaryHeap(HeapPtr *head, int max);
bool isEmpty(HeapPtr head);
bool isFull(HeapPtr head);
bool insert(HeapPtr *head, int num);
bool delete(HeapPtr *head);
void visualize(HeapPtr head);

#endif