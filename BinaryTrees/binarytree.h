#ifndef BINARYTREE_H
#define BINARYTREE_H

typedef struct nodeT {
    int data;
    struct nodeT *left;
    struct nodeT *right;
} TreeNode, *TreePtr;

typedef struct nodeQ {
    TreePtr t;
    struct nodeQ *next;
} QueueNode, *QueuePtr;

typedef struct nodeS {
    TreePtr t;
    struct nodeS *next;
} StackNode, *StackPtr;

void initTree(TreePtr *t);
bool insertTree(TreePtr *t, int data);
void visualizeTemp(TreePtr t);
bool breadthFirstSearch(TreePtr t);
bool depthFirstSearch(TreePtr t);

bool enqueue(QueuePtr *front, QueuePtr *rear, TreePtr t);
TreePtr dequeue(QueuePtr *front, QueuePtr *rear);
bool isStackEmpty(StackPtr top);

bool push(StackPtr *top, TreePtr t);
TreePtr pop(StackPtr *top);
bool isQueueEmpty(QueuePtr front);

#endif