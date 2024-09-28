#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkListQueue.c"
#include "Data.c"

int main(void) {
    Queue QueueA = createQueue();
    
    enqueue(&QueueA, createStudent(1122323, createName("Volter", "Voltage"), 'F', "BSIT"));
    enqueue(&QueueA, createStudent(5254323, createName("You-Sip", "C-Values"), 'M', "BSIT"));
    enqueue(&QueueA, createStudent(1534622, createName("I-Banned", "Dont-Kyer"), 'F', "BSIT"));
    enqueue(&QueueA, createStudent(9865853, createName("Marker", "Parker"), 'F', "BSCS"));
    enqueue(&QueueA, createStudent(4569594, createName("Gene", "Loitering"), 'M', "BSCE"));
    enqueue(&QueueA, createStudent(890314, createName("Joshie", "Onwe"), 'F', "BSCS"));
    enqueue(&QueueA, createStudent(8453214, createName("Wawo", "Wang"), 'M', "BSCS"));
    enqueue(&QueueA, createStudent(1012133, createName("Callen", "Caracy"), 'F', "BSIT"));


    displayVer3(QueueA);

    dequeue(&QueueA);
    dequeue(&QueueA);
    dequeue(&QueueA);

    displayVer3(QueueA);
    
    Name *StudNames = getStudent(QueueA, "BSCS", 'F');  
    if (StudNames != NULL) {
        displayGotStuds(StudNames);  
        free(StudNames);  
        printf("\n");
    } else {
        printf("Empty\n");
    }

    Name *StudNamesA = getStudent(QueueA, "BSIT", 'F'); 
    if (StudNamesA != NULL) {
        displayGotStuds(StudNamesA);  
        free(StudNamesA);  
    } else {
        printf("Empty\n");
    }
    insertSort(&QueueA, 9999329, "MeTee", "WeToo", 'M', "BSIS");
    displayVer3(QueueA);

    return 0;
}