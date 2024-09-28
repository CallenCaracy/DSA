#ifndef HASHTABLE_H
#define HASHTABLE_H

// use 65% as the packing density

#include <stdbool.h>

typedef char String[30];
#define MAX 20

typedef struct {
    int studID;
    String studName;
    String program;
    int year;
}Student;

typedef struct NodeType{
    Student stud;
    struct NodeType *link;
}NodeType, *NodePtr;

typedef struct {
    NodePtr elems[MAX];
    int count;
} HashTable;

int getHash(Student s);
/*
    Get the hash based on the summation of the first 3 lteers of the name plus the letters in the program and must be able to return a value from 0 - 19.
*/ 

void initDictionary(HashTable *ht);
bool insert(HashTable *ht, Student s);
bool delete(HashTable *ht, Student s);

bool insertSorted(HashTable *ht, NodePtr temp, int pos);
Student createStud(int ID, String Name, String Program, int year);
void visualizeTable(HashTable ht);
#endif