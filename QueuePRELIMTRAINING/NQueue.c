#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "NQueue.h"

void initNQueue(NQueue *nq, int max){
    nq->front = 1;
    nq->rear = 0;
    nq->max = max;
    nq->elems = malloc(sizeof(Name) * max);
}

NQueue createQueue(int max){
    NQueue nq;
    
    nq.front = 1;
    nq.rear = 0;
    nq.max = max;
    nq.elems = malloc(sizeof(Name) * max);
    
    return nq;
}

bool isEmpty(NQueue nq){
    return (nq.rear + 1) % nq.max == nq.front;
}

bool isFull(NQueue nq){
    return (nq.rear + 2) % nq.max == nq.front;
}

void displayQueue(NQueue nq){
    printf("Queue contents:\n");
    
    if (isEmpty(nq)) {
        printf("Queue is empty.\n");
        return;
    }

    int i = nq.front;
    do {
        printf("INDEX: %d, Name: %s %s.\n", 
               i,
               nq.elems[i].fname, 
               nq.elems[i].lname);
        i = (i + 1) % nq.max;
    } while (i != (nq.rear + 1) % nq.max);
}

void displayRemovedName(Name *removed){
    printf("Removed Names:\n");
    
    if(!removed){
        printf("Empty.\n");
        return;
    }

    int i = 0;
    while(strlen(removed[i].fname) > 0 || strlen(removed[i].lname) > 0){
        printf("Name: %s %s.\n", removed[i].fname, removed[i].lname);
        i++;
    }
}

bool enqueue(NQueue *nq, Name n){
    if(!isFull(*nq)){
        nq->rear = (nq->rear + 1) % nq->max;
        nq->elems[nq->rear] = n;
        printf("Enqueued: %s %s at position %d.\n", nq->elems[nq->rear].fname, nq->elems[nq->rear].lname, nq->rear);
        return true;
    }
    printf("Queue is full, cannot enqueue.\n");
    return false;
}

bool dequeue(NQueue *nq) {
    if(!isEmpty(*nq)){
        printf("Dequeuing %s %s.\n", nq->elems[nq->rear].fname, nq->elems[nq->rear].lname, nq->rear);
        nq->front = (nq->front + 1) % nq->max;
        return true;
    }
    printf("Queue is empty, cannot dequeue.\n");
    return false;
}

Name front(NQueue nq){
    if (!isEmpty(nq)) {
        return nq.elems[nq.front];
    } else {
        printf("Queue is empty, cannot retrieve front element.\n");
    }
}

Name createName(char fname[30], char lname[30]){
    Name n;
    
    strcpy(n.fname, fname);
    strcpy(n.lname, lname);
    
    return n;
}

/*Removes the names that matches the filterString to the lastname. 
  Returns the removed names. Use the concept of adding a sentinel
  at the end indicating the last item in list as empty strings for
  fname and lname. If there are no names that will match then the
  function should return the sentinel.*/
Name *filterNames(NQueue *nq, char *filterString){
    if (isEmpty(*nq) || !filterString){
        Name *sentinel = malloc(sizeof(Name));
        if (sentinel) {
            *sentinel = createName("", "");
        }
        return sentinel;
    }
    
    int queueSize = (nq->rear - nq->front + nq->max + 1) % nq->max;
    Name *result = malloc(sizeof(Name) * (queueSize + 1));
    if(!result){
        return NULL;
    }
    
    int i = nq->front;
    int count = 0;
    
    for(int j = 0; j < queueSize; j++){
        if(strcmp(nq->elems[i].lname, filterString) == 0){
            result[count++] = nq->elems[i];
            
            for(int k = i; k != nq->rear; k = (k + 1) % nq->max){
                nq->elems[k] = nq->elems[(k + 1) % nq->max];
            }
            nq->rear = (nq->rear - 1 + nq->max) % nq->max;
        }else{
            i = (i + 1) % nq->max;
        }
    }
    
    if(count == 0){
        *result = createName("", "");
    }else{
        strcpy(result[count].fname, "");
        strcpy(result[count].lname, "");
    }
    
    return result;
}


/*Insert soreted base on lastname. Rember to use the property 
  of the queue but without using the functions (enqueue, dequeue, front)*/
bool insertSorted(NQueue *nq, Name n) {
    if (isFull(*nq)) {
        printf("Queue is full, cannot insert.\n");
        return false;
    }

    int pos = nq->front;
    
    while (pos != (nq->rear + 1) % nq->max) {
        if (strcmp(nq->elems[pos].lname, n.lname) > 0) {
            break;
        }
        pos = (pos + 1) % nq->max;
    }

    int numShift = (nq->rear - pos + nq->max) % nq->max + 1;
    
    int targetPos = (pos + numShift) % nq->max;
    memcpy(&nq->elems[pos + 1], &nq->elems[pos], sizeof(Name) * numShift);

    nq->elems[pos] = n;
    nq->rear = (nq->rear + 1) % nq->max;

    return true;
}