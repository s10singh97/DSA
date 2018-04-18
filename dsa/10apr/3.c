#include<stdio.h>
#include<stdlib.h>

#define SIZE 1000
#define ASIZE 10

typedef struct Node
{
    int n;
    struct Node *next;
}
node;

node *hashtable[SIZE];
int a[ASIZE];

int hash_it(int *a)
{
    unsigned int hash = 0;
    for (int i = 0; i < ASIZE; i++)
        hash = (hash << 2) ^ a[i];
    return hash % SIZE;
}

bool check(int num)
{
    int h = hash_it(a);
    node* point = hashtable[h];
    while (point != NULL)
    {
        if (point -> n == num)
        {
            return true;
        }
        else
        {
            point = point -> next;
        }
    }
    return false;
}