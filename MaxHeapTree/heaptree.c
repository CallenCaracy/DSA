#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "heaptree.h"

void initBinaryHeap(HeapPtr *head, int max){
    *head = malloc(sizeof(BinaryHeap));

    (*head)->count = 0;
    (*head)->max = max;
    (*head)->elems = malloc(sizeof(int) * max);
    for(int i = 0; i < max; i++){
        (*head)->elems[i] = 0;
    }
}

bool isEmpty(HeapPtr head){
    return head->count == 0;
}

bool isFull(HeapPtr head){
    return head->count == head->max - 1;
}

bool insert(HeapPtr *head, int num){
    if(isFull(*head)){
        printf("The array is full");
        return false;
    }

    int i = (*head)->count;
    while(i > 0 && (*head)->elems[(i - 1)] < num){
        (*head)->elems[i] = (*head)->elems[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    (*head)->elems[i] = num;
    (*head)->count++;
    return true;
}

bool delete(HeapPtr *head){
    if(isEmpty(*head)){
        printf("The array is empty");
        return false;
    }

    int lastIndex = (*head)->count - 1;
    int lastElement = (*head)->elems[lastIndex];
    (*head)->elems[0] = lastElement;
    (*head)->count--;

    int i = 0;
    while (true) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int largest = i;

        if (leftChild < (*head)->count && (*head)->elems[leftChild] > (*head)->elems[largest]) {
            largest = leftChild;
        }

        if (rightChild < (*head)->count && (*head)->elems[rightChild] > (*head)->elems[largest]) {
            largest = rightChild;
        }

        if (largest != i) {
            int temp = (*head)->elems[i];
            (*head)->elems[i] = (*head)->elems[largest];
            (*head)->elems[largest] = temp;

            i = largest;
        } else {
            break;
        }
    }

    return true;
}

void visualize(HeapPtr head){
    if(isEmpty(head)){
        return;
    }

    for(int i = 0; i < head->count; i++){
        printf("%d ", head->elems[i]);
    }
}
