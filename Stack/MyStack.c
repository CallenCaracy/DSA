#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "MyStack.h"

void initStack(Stack *s) {
    s->count = 0;
}

Stack createStack() {
    Stack s;
    
    s.count = 0;
    
    return s;
}

bool isEmpty(Stack s) {
    return s.count == 0;
}

bool isFull(Stack s) {
    return s.count >= MAX;
}

// void visualize(Stack s) {
//     printf("List {");
//     for(int i = 0; i < s.count; ++i) {
//         printf("%d", s.elems[i]);
//         if(i < s.count-1){
//             printf(", ");
//         }
//     }
// }

void visualize(Stack s) {
    printf("List {");
    for(int i = 0; i < s.count; ++i) {
        printf("\nStudent ID: %d| Name: %s| Program: %s", s.elems[i].id, s.elems[i].name, s.elems[i].program);
        if(i < s.count-1){
            printf(",\n");
        }
    }
    printf("\n}\n\n");
}

bool push(Stack *s, Student stud) {
    if(!isFull(*s)) {
        s->elems[(s->count)++] = stud;
        return true;
    }
    return false;
}

bool pop(Stack *s) {
    if(!isEmpty(*s)) {
        (s->count)--;
        return true;
    }    
    return false;
}

Student peek(Stack s) {
    return s.elems[s.count-1];
}

Stack getStudent(Stack s, String program) {
    Stack hall = createStack();
    String hold;
    int i = 0;
    
    while(!isEmpty(s)) {
        if(strcmp(program, s.elems[i].program) == 0){
            push(&hall, s.elems[i]);
        }
        i++;
        pop(&s);
    }
    return hall;
}

void sort(Stack *s) {
    Stack tempStack = createStack();  // Create an auxiliary stack
    Student tempStudent;

    while (!isEmpty(*s)) {
        // Pop the top element from the original stack
        tempStudent = peek(*s);
        pop(s);

        // While the temporary stack is not empty and the top element of the temporary
        // stack has a greater id than tempStudent.id, pop from the temporary stack and push it
        // back to the original stack
        while (!isEmpty(tempStack) && peek(tempStack).id > tempStudent.id) {
            push(s, peek(tempStack));
            pop(&tempStack);
        }

        // Push tempStudent into the temporary stack
        push(&tempStack, tempStudent);
    }

    // Transfer the sorted elements from the temporary stack back to the original stack
    while (!isEmpty(tempStack)) {
        push(s, peek(tempStack));
        pop(&tempStack);
    }
}




// Stack getEven(Stack s) {
//     Stack even = createStack();
//     int item;
    
//     while(!isEmpty(s)) {
//         item = peek(s);
//         if(item % 2 == 0) {
//             push(&even, item);
//         }
//         pop(&s);
//     }
//     return even;
// }