#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "LinkListQueue.h"

void initQueue(Queue *q) {
    q->head = NULL;
    q->tail = NULL;
}

Queue createQueue() {
    Queue q;
    
    q.head = NULL;
    q.tail = NULL;
    
    return q;
}

bool isEmpty(Queue q) {
    return q.head == NULL;    
}

void display(Queue q) {
    if (isEmpty(q)) {
        printf("Empty.");
        return;
    }
    
    Data info;
    Data hold = q.head->elem;
    
    while(!isEmpty(q)){
        info = front(q);
        printf("Student ID: %d,\nName: %s %s,\nSex: %c,\nProgram: %s.\n\n", info.studID,
                                                                        info.studName.fname,
                                                                        info.studName.lname,
                                                                        info.sex,
                                                                        info.program);
        dequeue(&q);
        enqueue(&q, info);
        if(front(q).studID == hold.studID){
            break;
        }
    }    
}

void displayVer2(Queue q){
    NodePtr *trav = &q.head;

    while (*trav != NULL){
        printf("Student ID: %d,\nName: %s %s,\nSex: %c,\nProgram: %s.\n\n", (*trav)->elem.studID,
                                                                            (*trav)->elem.studName.fname,
                                                                            (*trav)->elem.studName.lname,
                                                                            (*trav)->elem.sex,
                                                                            (*trav)->elem.program);
        trav = &(*trav)->link;
    }
}

void displayVer3(Queue q) {
    printf("______________________________________________________\n");
    printf("| Student ID |        Name         | Sex |  Program  |\n");
    printf("|------------|---------------------|-----|-----------|\n");
    while (q.head) {
        printf("|  %-9d | %-8s %-10s |  %c  |   %-7s |\n", 
               q.head->elem.studID,
               q.head->elem.studName.fname,
               q.head->elem.studName.lname,
               q.head->elem.sex,
               q.head->elem.program);
        q.head = q.head->link;
    }
    printf("------------------------------------------------------\n");
}

bool enqueue(Queue *q, Data d) {
    NodePtr newQ = malloc(sizeof(NodeType));
    if (newQ == NULL) {
        return false;
    }

    newQ->elem = d;
    newQ->link = NULL;
    
    if(isEmpty(*q)){
        q->head = newQ;
    }else {
        q->tail->link = newQ;
        
    }
    q->tail = newQ;
    return true;
}

bool dequeue(Queue *q) {
    if (isEmpty(*q)) {
        return false;
    }
    
    NodePtr rmQ = q->head;
    q->head = q->head->link;
    // printf("{Dequeued: %d, %s %s, %c, %s}\n", rmQ->elem.studID, 
    //                             rmQ->elem.studName.fname, 
    //                             rmQ->elem.studName.lname, 
    //                             rmQ->elem.sex, 
    //                             rmQ->elem.program);
    free(rmQ);

    if(!q->head){
        q->tail = NULL;
    }
    return true;
}

Data front(Queue q) {
    return q.head->elem;    
}

void makeNull(Queue *q) {
    NodePtr nullQ = q->head;
    NodePtr nextQ = NULL;
    
    while(nullQ != NULL){
        nextQ = nullQ->link;
        free(nullQ);
        nullQ = nextQ;
    }
}

Data createStudent(int studID, Name name, char sex, char program[6]) {
    Data stud;
    
    stud.studID = studID;
    stud.studName = name;
    stud.sex = sex;
    strcpy(stud.program, program);
    
    return stud;
}

Name *getStudent(Queue q, char program[6], char sex) {
    int size = getSizeQueue(q, program, sex);
    Name *temp = malloc(sizeof(Name) * (size + 1));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    int i = 0;
    NodePtr current = q.head;  
    
    while (current != NULL) {
        if (strcmp(current->elem.program, program) == 0 && current->elem.sex == sex) {
            strcpy(temp[i].fname, current->elem.studName.fname);
            strcpy(temp[i].lname, current->elem.studName.lname);
            i++;
        }
        current = current->link;  
    }
    strcpy(temp[i].fname, " ");
    strcpy(temp[i].lname, " ");
    return temp;
}

int getSizeQueue(Queue q, char program[6], char sex) {
    int count = 0;
    NodePtr current = q.head;
    
    while (current) {
        if (strcmp(current->elem.program, program) == 0 && current->elem.sex == sex) {
            count++;
        }
        current = current->link;
    }
    return count;
}

void displayGotStuds(Name *n) {
    int i = 0;
    while (strcmp(n[i].fname, " ") != 0) {
        printf("{Displaying Student: %s %s}\n", n[i].fname, n[i].lname);
        i++;
    }
}

void insertSort(Queue *q, int studID, char fname[20], char lname[20], char sex, char program[6]){
    NodeType *temp = q->head;
    NodeType *prev = NULL;    
    NodeType *curr = NULL;
    NodeType *new = malloc(sizeof(NodeType));

    new->elem.studID = studID;
    strcpy(new->elem.studName.fname, fname);
    strcpy(new->elem.studName.lname, lname);
    new->elem.sex = sex;
    strcpy(new->elem.program, program);
    new->link = NULL;

    if (isEmpty(*q) || studID < q->head->elem.studID) {
        new->link = q->head; 
        q->head = new;        
        if (q->tail == NULL) {   
            q->tail = new;
        }
        return;
    }

    while (curr != NULL && curr->elem.studID < studID) {
        prev = curr;
        curr = curr->link;
    }

    if (curr == NULL) {
        enqueue(q, new->elem);  
        free(new); 
        return;
    }

    new->link = curr;  
    prev->link = new;  

    if (new->link == NULL) {
        q->tail = new;
    }
}

// void insertSort(Queue *q) {
//     if (isEmpty(*q)) {
//         return;
//     }

//     int size = 0;
//     NodePtr current = q->head;
    
//     // Count the number of elements in the queue
//     while (current != NULL) {
//         size++;
//         current = current->link;
//     }

//     // Create an array to hold the elements
//     Data *arr = malloc(size * sizeof(Data));
//     if (arr == NULL) {
//         printf("Memory allocation failed\n");
//         return;
//     }

//     // Dequeue all elements and store them in the array
//     current = q->head;
//     for (int i = 0; i < size; i++) {
//         arr[i] = front(*q);
//         dequeue(q);
//     }

//     // Sort the array using insertion sort
//     insertionSort(arr, size);

//     // Enqueue the sorted elements back into the queue
//     for (int i = 0; i < size; i++) {
//         enqueue(q, arr[i]);
//     }

//     // Free the temporary array
//     free(arr);
// }

// void insertionSort(Data arr[], int n) {
//     int i, j;
//     Data key;
//     for (i = 1; i < n; i++) {
//         key = arr[i];
//         j = i - 1;

//         // Move elements of arr[0..i-1], that are greater than key,
//         // to one position ahead of their current position
//         while (j >= 0 && arr[j].studID > key.studID) {
//             arr[j + 1] = arr[j];
//             j = j - 1;
//         }
//         arr[j + 1] = key;
//     }
// }