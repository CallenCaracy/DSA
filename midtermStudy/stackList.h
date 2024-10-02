#ifndef STACKLIST_H
#define STACKLIST_H
#include <stdbool.h>

typedef char String[20];

typedef struct {
    String fName;
    String mName;
    String lName;
    String cityName;
}Person;

typedef struct {
    Person *data;
    int count;
    int max;
} ArrayList;

typedef struct node{
    Person data;
    struct node *link;
}NodeType, *NodePtr, *Stack;

void initList(ArrayList *list, int max);
bool addPerson(ArrayList *list, Person p);
void visualizeArray(ArrayList list);
NodeType getVoters(Stack *s, ArrayList *list, char *cityTarget);

void iniStack(Stack *s);
Person peek(Stack s);
bool isEmpty(Stack s);
bool push(Stack *s, Person p);
bool pop(Stack *s);
void visualizeStack(Stack s);
Person createPerson(String fName, String mName, String lName, String cityName);

#endif