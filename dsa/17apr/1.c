//Binary Search Tree for 3 elements

#include<stdio.h>
#include<stdlib.h>
#define SIZE 3

typedef struct Node
{
    int n;
    struct Node *top, *left, *right;
}node;

int a[SIZE];
node *root = NULL;

node * createnode(int d)
{
    node *temp = (node*)malloc(sizeof(node));
    temp -> n = d;
    temp -> top = NULL;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

void insert(node *temp)
{
    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        if((temp -> n) < (root -> n))
        {
            root -> left = temp;
            temp -> top = root;
        }
        else
        {
            root -> right = temp;
            temp -> top = root;
        }
    }
}

void print()
{
    printf("%d\t%d\t%d\n", root -> n, root -> left -> n, root -> right -> n);
}

int main()
{
    printf("Enter 3 numbers\n");
    for(int i = 0; i < SIZE; i++)
    {
        printf("Enter %d element : ", i + 1);
        scanf("%d", &a[i]);
        node *f = createnode(a[i]);
        insert(f);
    }
    print();
    return 0;
}