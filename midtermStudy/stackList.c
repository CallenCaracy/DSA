#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stackList.h"

void iniStack(Stack *s){
    *s = NULL;
}

Person peek(Stack s){
    return s->data;
}

bool isEmpty(Stack s){
    return s == NULL;
}

bool push(Stack *s, Person p){
    NodePtr temp = malloc(sizeof(NodeType));
    
    temp->data = p;
    temp->link = *s;
    *s = temp;

    return true;
}

bool pop(Stack *s){
    if(isEmpty(*s)){
        return false;
    }
    NodePtr temp = NULL;

    temp = *s;
    *s = temp->link;
    free(temp);

    return true;
}

void visualizeStack(Stack s){
    NodePtr temp = s;
    printf("Stack:\n");
    while(temp != NULL){
        printf("Name: %s %s %s,\n%s.\n\n", temp->data.fName,
                                       temp->data.mName,
                                       temp->data.lName,
                                       temp->data.cityName);
        temp = temp->link;
    }
}

Person createPerson(String fName, String mName, String lName, String cityName){
    Person p;

    strcpy(p.fName, fName);
    strcpy(p.lName, lName);
    strcpy(p.mName, mName);
    strcpy(p.cityName, cityName);

    return p;
}

void initList(ArrayList *list, int max){
    list->data = malloc(sizeof(Person) * max);
    list->max = max;
    list->count = 0;
}

bool addPerson(ArrayList *list, Person p){
    if(list->count > list->max){
        return false;
    }
    list->data[list->count++] = p;
    return true;
}

void visualizeArray(ArrayList list){
    printf("ArrayList: \n");
    for(int i = 0; i < list.count; i++){
        printf("Name: %s %s %s,\n%s.\n\n", list.data[i].fName,
                                           list.data[i].mName,
                                           list.data[i].lName,
                                           list.data[i].cityName);
    }
}

void getVoters(Stack *s, ArrayList *list, char *cityTarget){

    for(int i = 0; i < list->max ; i++){
        if(strcmp(list->data[i].cityName, cityTarget) == 0){
            // push(s, list->data[i]);
            NodePtr temp = malloc(sizeof(NodeType));
            temp->data = list->data[i];
            temp->link = *s;
            *s = temp;
        }
    }
}
