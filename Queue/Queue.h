#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
typedef char String[20];
#define MAX 10

typedef struct {
    String fname, lname;
} Name;

typedef struct {
    int studID;
    Name studName;
    bool sex;
    String program;
    int year;
} Student;

typedef struct {
    Student *studList;
    int max;
    int rear;
    int front;
} QueueADT;

void initQueue(QueueADT *q, int Max);
QueueADT createQueue(int Max);
bool isEmpty(QueueADT q);
bool isFull(QueueADT q);
void makeEmpty(QueueADT *q);

void visualize(QueueADT q);
void display(QueueADT q);

bool enqueue(QueueADT *q, Student s);
bool dequeue(QueueADT *q);
Student front(QueueADT q);

Name createStudName(String fname, String lname);
Student createStud(int id, Name studName, bool sex, String program);

#endif