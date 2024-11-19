#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

typedef struct node {
    int vertex;
    struct node *next;
}NodeType, *NodePtr;

typedef struct {
    int numVertices;
    struct node **adjacentList;
}GraphNode, *GraphPtr;

NodeType *createNode(int v);
GraphNode *createGraph(int vertices);
void addEdge(GraphPtr graph, int src, int dest);
void display(GraphPtr graph);

#endif