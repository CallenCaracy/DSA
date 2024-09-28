#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Queue.c"

int main(void) {
    QueueADT q = createQueue(MAX);

    enqueue(&q, createStud(1, createStudName("Alice", "Johnson"), 0, "Computer Science"));
    enqueue(&q, createStud(2, createStudName("Bob", "Smith"), 1, "Engineering"));
    enqueue(&q, createStud(3, createStudName("Bur", "Ger"), 1, "Crazy"));
    enqueue(&q, createStud(4, createStudName("Milo", "40"), 0, "Psycho"));
    enqueue(&q, createStud(5, createStudName("Super", "Burger"), 0, "Insane"));
    enqueue(&q, createStud(6, createStudName("Fish", "Fillet"), 1, "Incel"));
    enqueue(&q, createStud(7, createStudName("Coffee", "30"), 1, "Madman"));
    enqueue(&q, createStud(8, createStudName("Crispy", "Chicken"), 0, "Flabbergasted"));
    enqueue(&q, createStud(9, createStudName("Miss", "You"), 1, "Sadman"));
    enqueue(&q, createStud(10, createStudName("Miss", "You"), 1, "Sadman")); // testing the capacity
    visualize(q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    visualize(q);

    display(q);

    makeEmpty(&q);
    visualize(q);

    free(q.studList); 
    
    return 0;
}