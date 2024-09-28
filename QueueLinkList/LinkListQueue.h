#ifndef LINKLISTQUEUE_H
#define LINKLISTQUEUE_H
#include "Data.h"
#include <stdbool.h>

typedef Student Data;

typedef struct node {
    Data elem;
    struct node *link;
} NodeType, *NodePtr;

typedef struct {
    NodePtr head;
    NodePtr tail;
}Queue;

void initQueue(Queue *q);
Queue createQueue();
bool isEmpty(Queue q);
bool isFull(Queue q);
void display(Queue q);
void displayVer2(Queue q);
void displayVer3(Queue q);
void displayGotStuds(Name *n);
bool enqueue(Queue *q, Data d);
bool dequeue(Queue *q);
Data front(Queue q);
void makeNull(Queue *q);
Data createStudent(int studID, Name name, char sex, char program[6]);
Name *getStudent(Queue q, char program[6], char sex);
int getSizeQueue(Queue q, char program[6], char sex);
void insertSort(Queue *q, int studID, char fname[20], char lname[20], char gender, char program[6]);

// void insertionSort(Data arr[], int n);
// void insertSort(Queue *q);

#endif