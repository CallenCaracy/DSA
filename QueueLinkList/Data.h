#ifndef DATA_H
#define DATA_H
#include <stdbool.h>

typedef struct {
    char fname[20];
    char lname[20];
} Name;

typedef struct {
    int studID;
    Name studName;
    char sex;
    char program[6];
}Student;

Name createName(char fname[20], char lname[20]);

#endif