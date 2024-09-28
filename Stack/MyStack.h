#ifndef MY_STACK_H
#define MY_STACK_H

#include <stdbool.h>
#include "Student.h"

#define MAX 10

typedef struct {
    Student elems[MAX];
    int count;
} Stack;

void initStack(Stack *s);
Stack createStack();
bool isEmpty(Stack s);
bool isFull(Stack s);
void visualize(Stack s);

bool push(Stack *s, Student stud);
bool pop(Stack *s);
Student peek(Stack s);

Stack getEven(Stack s);
Stack getStudent(Stack s, String program);
void sort(Stack* s);

#endif