#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "LinearHash.h"

int getHash(Student s, HashTable ht){
    unsigned int hash = s.studID;
    int pos = 0;
    for(int i = 0; i < strlen(s.program); i++){
        pos += s.program[i];
    }
    
    for(int i = 0; i < 3 && i < strlen(s.studName); i++){
        pos += s.studName[i];
    }

    hash = hash << 1;
    pos = (pos + hash) % ht.max;

    return pos;
}

void initDictionary(HashTable *ht, int max) {
    ht->count = 0;
    ht->max = max;
    ht->elems = malloc(sizeof(Status) * max);
    for(int i = 0; i < ht->max; i++){
        ht->elems[i].stat = 'E';
    }
}

bool insert(HashTable *ht, Student s){
    int pos = getHash(s, *ht);

    if(ht->count > ht->max * 0.60){
        printf("Full, can't insert.\n"); 
        return false;
    }

    if(ht->elems[pos].stat == 'E'){
        ht->elems[pos].stat = 'O';
        ht->elems[pos].stud = s;
        ht->count++;
        return true;
    }
    
    if(ht->elems[pos].stat == 'O'){
        while (ht->elems[pos].stat != 'E')
        {
            pos = (pos + 1) % ht->max;
        }
        ht->elems[pos].stat = 'O';
        ht->elems[pos].stud = s;
        ht->count++;
        return true;
    }
    return false;
}

bool delete(HashTable *ht, Student s){
    int pos = getHash(s, *ht);
    int originalPos = pos;

    while(ht->elems[pos].stat != 'E'){
        if(ht->elems[pos].stud.studID == s.studID){
            ht->elems[pos].stat = 'D';
            ht->count--;
            return true;
        }
        pos = (pos + 1) % ht->max;
        if(originalPos == pos) break;
    }
    return false;
}

Student createStud(int ID, String Name, String Program, int year){
    Student s;

    s.studID = ID;
    strcpy(s.studName, Name);
    strcpy(s.program, Program);
    s.year = year;

    return s;
}

void visualizeTable(HashTable ht){
    int hold = ht.max * 0.60;
    float perc = ((float)ht.count / ht.max) * 100;
    printf("Linear Hash Table: (Count: %d, Max: %d, Percentage Used: %0.2f%%, Usable Space: %d)\n", ht.count, ht.max, perc, hold + 1);
    for(int i = 0; i < ht.max; i++){
        printf("[%d] | [%c] = ", i, ht.elems[i].stat);
        if(ht.elems[i].stat == 'O'){
            printf("Student ID: %d, Student Name: %s, Program: %s, Year: %d.\n", ht.elems[i].stud.studID,
                                                                              ht.elems[i].stud.studName,
                                                                              ht.elems[i].stud.program,
                                                                              ht.elems[i].stud.year);
        }else if(ht.elems[i].stat == 'D'){
            printf("Deleted.\n");
        }else if(ht.elems[i].stat == 'E'){
            printf("Empty.\n");
        }
    }
}

void resizeMax(HashTable *ht){
    HashTable newHt;
    int newMax = ht->max + 10;
    printf("Resizing hash table from %d to %d\n", ht->max, newMax);
    initDictionary(&newHt, newMax);
    
    for(int i = 0; i < ht->max; i++){
        if(ht->elems[i].stat == 'O'){
            insert(&newHt, ht->elems[i].stud);
        }
    }
    clearData(ht);
    *ht = newHt;
}

void clearData(HashTable *ht) {
    if (ht->elems != NULL) {
        free(ht->elems);
        ht->elems = NULL; 
    }
}