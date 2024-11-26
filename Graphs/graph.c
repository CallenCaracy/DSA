#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"

Student createStud(int sID, String program, String name){
    Student s;

    s.StudID = sID;
    strcpy(s.program, program);
    strcpy(s.studName, name);

    return s;
}

NodeType *createNode(int v, Student stud){
    NodeType *newNode = malloc(sizeof(NodeType));

    newNode->vertex = v;
    newNode->stud = stud;
    newNode->next = NULL;

    return newNode;
}

GraphNode *createGraph(){
    GraphPtr newGraph = malloc(sizeof(GraphNode));

    newGraph->adjList = malloc(sizeof(NodeType) * MAX);
    for(int i = 0; i < MAX; i++){
        newGraph->adjList[i] = NULL;
    }

    return newGraph;
}

bool edgeExists(NodePtr head, int vertex){
    while (head) {
        if (head->vertex == vertex)
            return true;
        head = head->next;
    }
    return false;
}

void addEdge(GraphPtr graph, Student srcStud, Student destStud) {
    int srcIndex = getHash(srcStud);
    int destIndex = getHash(destStud);

    if (!edgeExists(graph->adjList[srcIndex], destIndex)) {
        NodePtr newNode1 = createNode(destIndex, destStud);
        newNode1->next = graph->adjList[srcIndex];
        graph->adjList[srcIndex] = newNode1;
    }

    if (!edgeExists(graph->adjList[destIndex], srcIndex)) {
        NodePtr newNode2 = createNode(srcIndex, srcStud);
        newNode2->next = graph->adjList[destIndex];
        graph->adjList[destIndex] = newNode2;
    }
}


int getHash(Student s) {
    int hash = 0;
    for (int i = 0; i < strlen(s.program); i++) {
        hash = (hash * 31 + s.program[i]) % MAX;
    }
    for (int i = 0; i < strlen(s.studName); i++) {
        hash = (hash * 31 + s.studName[i]) % MAX;
    }
    printf("Hash for %s: %d\n", s.studName, hash);
    return hash;
}

void display(GraphPtr graph){
    for(int i = 0; i < MAX; i++){
        NodePtr temp = graph->adjList[i];
        if(temp != NULL){
            char *name = getName(graph, i);
            printf("[[Hash Bucket %d: %s]] => ", i, name);
        } else {
            printf("[[Hash Bucket %d]] => ", i);
        }       
        while (temp) {
            printf("[ID: %d, %s, (Vertex: %d)] -> ", temp->stud.StudID, temp->stud.studName, temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

char *getName(GraphPtr graph, int target){
    for(int i = 0; i < MAX; i++){
        NodePtr temp = graph->adjList[i];
        while(temp){
            if(temp->vertex == target){
                return temp->stud.studName;
            }
            temp = temp->next;
        }
    }
    return "";
}