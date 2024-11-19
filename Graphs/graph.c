#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"

NodeType *createNode(int v){
    NodeType *newNode = malloc(sizeof(NodeType));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

GraphNode *createGraph(int vertices){
    GraphPtr newGraph = malloc(sizeof(GraphNode));
    newGraph->numVertices = vertices;
    newGraph->adjacentList = malloc(sizeof(NodeType) * vertices);

    for(int i = 0; i < vertices; i++){
        newGraph->adjacentList[i] = NULL;
    }
    return newGraph;
}

void addEdge(GraphPtr graph, int src, int dest){
    NodePtr newNode = createNode(dest);
    newNode->next = graph->adjacentList[src];
    graph->adjacentList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjacentList[dest];
    graph->adjacentList[dest] = newNode;
}

void display(GraphPtr graph){
    for(int i = 0; i < graph->numVertices; i++){
        NodePtr temp = graph->adjacentList[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}