#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Queue.h"

void initQueue(QueueADT *q, int Max) {
    q->max = Max;
    q->front = 1;
    q->rear = 0;
    q->studList = malloc(sizeof(Student) * Max);
}

QueueADT createQueue(int Max) {
    QueueADT q;
    
    q.max = Max;
    q.front = 1;
    q.rear = 0;
    q.studList = malloc(sizeof(Student) * Max);
    
    return q;
}

bool isEmpty(QueueADT q) {
    return (q.rear + 1) % q.max == q.front;
}

bool isFull(QueueADT q) {
    return (q.rear + 2) % q.max == q.front;
}

void makeEmpty(QueueADT *q) {
    q->front = 1;
    q->rear = 0;
}

void visualize(QueueADT q) {    
    printf("Queue contents:\n");
    
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    int i = q.front;
    do {
        printf("INDEX: %d, ID: %d, Name: %s %s, Program: %s,", 
               i,
               q.studList[i].studID, 
               q.studList[i].studName.fname, 
               q.studList[i].studName.lname, 
               q.studList[i].program);
        if(q.studList[i].sex == 1){
            printf(" Gender: Male\n");
        }else {
            printf(" Gender: Female\n");
        }
        i = (i + 1) % q.max;
    } while (i != (q.rear + 1) % q.max);
}



void display(QueueADT q) {
    printf("Queue Front: [");
    if (isEmpty(q)) {
        printf("Queue is empty]\n");
        return;
    }
    printf("%d: %s %s, %s", q.studList[q.front].studID,
                             q.studList[q.front].studName.fname, 
                             q.studList[q.front].studName.lname,
                             q.studList[q.front].program);
    if(q.studList[q.front].sex == 1){
        printf(" Gender: Male]\n");
    }else {
        printf(" Gender: Female]\n");
    }
                         
    printf("\nQueue Rear: [");
    printf("%d: %s %s, %s", q.studList[q.rear].studID,
                             q.studList[q.rear].studName.fname, 
                             q.studList[q.rear].studName.lname,
                             q.studList[q.rear].program);
    if(q.studList[q.rear].sex == 1){
        printf(" Gender: Male]\n\n");
    }else {
        printf(" Gender: Female]\n\n");
    }
}

bool enqueue(QueueADT *q, Student s) {
    if (!isFull(*q)) {
        q->rear = (q->rear + 1) % q->max;
        q->studList[q->rear] = s;
        printf("Enqueued: %d at position %d\n", s.studID, q->rear);
        return true;
    }
    printf("Queue is full, cannot enqueue.\n");
    return false;
}

bool dequeue(QueueADT *q) {
    if (!isEmpty(*q)) {
        q->front = (q->front + 1) % q->max;
        printf("Dequeued.\n");
        return true;
    }
    printf("Queue is empty, cannot dequeue.\n");
    return false;
}

Student front(QueueADT q) {
    if (!isEmpty(q)) {
        return q.studList[q.front];
    } else {
        printf("Queue is empty, cannot retrieve front element.\n");
    }
}

Student createStud(int id, Name studName, bool sex, String program) {
    Student newStud;
    
    newStud.studID = id;
    newStud.studName = studName;
    strcpy(newStud.program, program);
    newStud.sex = sex;
    
    return newStud;
}

Name createStudName(String fname, String lname) {
    Name n;
    
    strcpy(n.fname, fname);
    strcpy(n.lname, lname);
    
    return n;
}