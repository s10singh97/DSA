// Binary Tree using Linked List

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int n;
    struct Node *parent, *left, *right;
}node;

node* createnode(int d)
{
    node *temp = (node*)malloc(sizeof(node));
    temp -> n = d;
    temp -> parent = NULL;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

