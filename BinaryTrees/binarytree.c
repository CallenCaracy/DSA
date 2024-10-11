#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "binarytree.h"

void initTree(TreePtr *t){
    *t = NULL;
}

bool insertTree(TreePtr *t, int data){
    TreePtr *trav = t;
    while(*trav != NULL && (*trav)->data != data){
        trav = ((*trav)->data < data) ? &(*trav)->right : &(*trav)->left ;
    }

    if(*trav == NULL){
        *trav = malloc(sizeof(TreeNode));
        if(*trav != NULL){
            (*trav)->data = data;
            (*trav)->left = NULL;
            (*trav)->right = NULL;
            return true;
        }
    }
    return false;
}

bool breadthFirstSearch(TreePtr t) {
    if (t == NULL) return false;
    
    QueuePtr front = NULL, rear = NULL;
    enqueue(&front, &rear, t);
    printf("BFS: ");
    while (!isQueueEmpty(front)) {
        TreePtr current = dequeue(&front, &rear);
        printf("%d ", current->data);

        if (current->left != NULL) {
            enqueue(&front, &rear, current->left);
        }
        if (current->right != NULL) {
            enqueue(&front, &rear, current->right);
        }
    }
    printf("\n");
    return true;
}

bool depthFirstSearch(TreePtr t) {
    if (t == NULL) return false;

    StackPtr top = NULL;
    push(&top, t);
    printf("DFS: ");
    while (!isStackEmpty(top)) {
        TreePtr current = pop(&top);
        printf("%d ", current->data);

        if (current->right != NULL) {
            push(&top, current->right);
        }
        if (current->left != NULL) {
            push(&top, current->left);
        }
    }
    printf("\n");
    return true;
}

void visualizeTemp(TreePtr t){
    if(t != NULL){
        visualizeTemp(t->left);
        printf("%d ", t->data);
        visualizeTemp(t->right);
    }
}




bool enqueue(QueuePtr *front, QueuePtr *rear, TreePtr t) {
    QueuePtr newNode = malloc(sizeof(QueueNode));
    if (newNode != NULL) {
        newNode->t = t;
        newNode->next = NULL;
        if (*rear != NULL) {
            (*rear)->next = newNode;
        }
        *rear = newNode;
        if (*front == NULL) {
            *front = *rear;
        }
        return true;
    }
    return false;
}

TreePtr dequeue(QueuePtr *front, QueuePtr *rear) {
    if (*front == NULL) return NULL;
    QueuePtr temp = *front;
    TreePtr treeNode = temp->t;
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    free(temp);
    return treeNode;
}


bool push(StackPtr *top, TreePtr t) {
    StackPtr newNode = malloc(sizeof(StackNode));
    if (newNode != NULL) {
        newNode->t = t;
        newNode->next = *top;
        *top = newNode;
        return true;
    }
    return false;
}

TreePtr pop(StackPtr *top) {
    if (*top == NULL) return NULL;
    StackPtr temp = *top;
    TreePtr treeNode = temp->t;
    *top = (*top)->next;
    free(temp);
    return treeNode;
}

bool isStackEmpty(StackPtr top) {
    return top == NULL;
}

bool isQueueEmpty(QueuePtr front) {
    return front == NULL;
}