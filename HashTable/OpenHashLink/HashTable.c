#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "HashTable.h"


Student createStud(int ID, String Name, String Program, int year){
    Student s;
    
    s.studID = ID;
    strcpy(s.studName, Name);
    strcpy(s.program, Program);
    s.year = year;
    
    return s;
}

void initDictionary(HashTable *ht){
    ht->count = 0;
    for(int i = 0; i < MAX; i++){
        ht->elems[i] = NULL;
    }
}

bool insert(HashTable *ht, Student s){
    NodePtr temp = malloc(sizeof(NodeType));
    if(temp == NULL){
        return false;
    }
    temp->stud = s;
    temp->link = NULL;
    int pos = getHash(s);
    int i = pos;

    if(ht->count <= MAX * 0.60){
        if(ht->elems[i] == NULL){
            ht->elems[i] = temp;
        }else{
            insertSorted(ht, temp, pos);
        }
        ht->count++;
        return true;
    }else {
        printf("Hash table is full (60%% capacity reached).\n");
        free(temp);
        return false;
    }
}

bool delete(HashTable *ht, Student s) {
    int pos = getHash(s);
    NodePtr current = ht->elems[pos];
    NodePtr prev = NULL;

    while (current != NULL && current->stud.studID != s.studID) {
        prev = current;
        current = current->link;
    }

    if (current == NULL) {
        printf("Student not found.\n");
        return false;
    }

    if (prev == NULL) {
        ht->elems[pos] = current->link; 
    } else {
        prev->link = current->link;
    }

    free(current);
    ht->count--;
    return true;
}

void visualizeTable(HashTable ht) {
    printf("HashTable: \n");
    for (int i = 0; i < MAX; i++) {
        if (ht.elems[i] != NULL) {
            NodePtr current = ht.elems[i];
            printf("[%d] -> ", i);
            while (current != NULL) {
                printf("ID: %d, Name: %s, Program: %s, Year: %d -> ", 
                       current->stud.studID, current->stud.studName, 
                       current->stud.program, current->stud.year);
                current = current->link;
            }
            printf("NULL\n");
        } else {
            printf("[%d] = NULL\n", i);
        }
    }
}

int getHash(Student s){
    int count = 0;
    for(int i = 0; i < strlen(s.program); i++){
        count += s.program[i];
    }
    
    for(int i = 0; i < 3 && i < strlen(s.studName); i++){
        count += s.studName[i];
    }
    return count % MAX;
}

bool insertSorted(HashTable *ht, NodePtr temp, int pos) {
    NodePtr current = ht->elems[pos];
    NodePtr prev = NULL;

    while (current != NULL && current->stud.studID < temp->stud.studID) {
        prev = current;
        current = current->link;
    }

    if (prev == NULL) {
        temp->link = ht->elems[pos]; 
        ht->elems[pos] = temp;
    } else {
        prev->link = temp;   
        temp->link = current;
    }
    
    return true;
}