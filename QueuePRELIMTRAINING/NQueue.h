#ifndef NQUEUE_H
#define NQUEUE_H
#include <stdbool.h>

typedef struct {
    char fname[30];
    char lname[30];
} Name;

typedef struct {
    Name *elems;
    int front;
    int rear;
    int max;
} NQueue;

void initNQueue(NQueue *nq, int max);
NQueue createQueue(int max);
bool isEmpty(NQueue nq);
bool isFull(NQueue nq);
void displayQueue(NQueue nq);
void displayRemovedName(Name *removed);

bool enqueue(NQueue *nq, Name n);
bool dequeue(NQueue *nq);
Name front(NQueue nq);

Name createName(char fname[30], char lname[30]);
Name *filterNames(NQueue *nq, char *filterString);
bool insertSorted(NQueue *nq, Name n);

#endif