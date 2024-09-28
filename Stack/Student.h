#ifndef STUDENT_H
#define STUDENT_H

typedef char String[50];

typedef struct {
    int id;
    String name;
    String program;
} Student;

Student createStud(int id, String name, String program);

#endif