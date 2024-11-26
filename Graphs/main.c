#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "graph.c"

int main(void){
    int vertices = 4;
    GraphPtr graph = createGraph();

    addEdge(graph, createStud(1, "IT", "C-values"), createStud(4, "IT", "Clarence"));
    addEdge(graph, createStud(5, "IT", "Balbacuasa"), createStud(6, "IT", "Raal"));
    addEdge(graph, createStud(2, "IT", "Johnny Mark"), createStud(5, "IT", "Balbacuasa"));
    addEdge(graph, createStud(3, "IT", "Kyer"), createStud(2, "IT", "Johnny Mark"));
    addEdge(graph, createStud(4, "IT", "Clarence"), createStud(3, "IT", "Kyer"));
    addEdge(graph, createStud(6, "IT", "Raal"), createStud(1, "IT", "C-values"));

    display(graph);
    return 0;
}