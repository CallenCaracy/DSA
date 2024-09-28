#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Student.h"

Student createStud(int id, String name, String program) {
    Student newStud;
    
    newStud.id = id;
    strcpy(newStud.name, name);
    strcpy(newStud.program, program);
    return newStud;
}
