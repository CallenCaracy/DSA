#ifndef LINEARHASH_H
#define LINEARHASH_H

// use 65% as the packing density

#include <stdbool.h>

typedef char String[30];
#define MAX 10

typedef struct {
    int studID;
    String studName;
    String program;
    int year;
}Student;

typedef struct {
    Student stud;
    char stat;
} Status;

typedef struct {
    Status *elems;
    int count;
    int max;
} HashTable;

int getHash(Student s, HashTable ht);
void initDictionary(HashTable *ht, int max);
bool insert(HashTable *ht, Student s);
bool delete(HashTable *ht, Student s);

bool insertSorted(HashTable *ht, int pos);
Student createStud(int ID, String Name, String Program, int year);
void visualizeTable(HashTable ht);
void resizeMax(HashTable *ht);
void clearData(HashTable *ht);

#endif