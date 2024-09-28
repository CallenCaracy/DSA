#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MyStack.c"
#include "Student.c"

int main(void) {
    Stack stackA = createStack();
    Stack BSITRoom = createStack();
    Stack BSISRoom = createStack();
    String prog;
    
    push(&stackA, createStud(1, "Clarence", "BSIT"));
    push(&stackA, createStud(2, "V", "BSIT"));
    push(&stackA, createStud(3, "Sep", "BSIT"));
    push(&stackA, createStud(4, "Pau", "BSIS"));
    push(&stackA, createStud(5, "John", "BSIS"));
    push(&stackA, createStud(6, "Jared", "BSIS"));
    visualize(stackA);
    sort(&stackA);
    visualize(stackA);
    
    BSITRoom = getStudent(stackA, "BSIT");
    visualize(BSITRoom);
    BSITRoom = getStudent(stackA, "BSIS");
    visualize(BSITRoom);
    
    return 0;
}