#ifndef GRAPH_H
#define GRAPH_H

#define MAX 30

#include <stdbool.h>
typedef char String[12];

typedef struct {
    int StudID;
    String program;
    String studName;
}Student;

typedef struct node {
    int vertex;
    Student stud;
    struct node *next;
}NodeType, *NodePtr;

typedef struct {       
    NodePtr *adjList;   
} GraphNode, *GraphPtr;

NodeType *createNode(int v, Student stud);
GraphNode *createGraph();
void addEdge(GraphPtr graph, Student srcStud, Student destStud);
void display(GraphPtr graph);
int getHash(Student s);
Student createStud(int sID, String program, String name);
char *getName(GraphPtr graph, int target);

#endif