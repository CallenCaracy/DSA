#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "graph.c"

int main(void){
    int vertices = 4;
    GraphPtr graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);

    display(graph);
    return 0;
}