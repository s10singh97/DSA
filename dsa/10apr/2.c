//Hashing using Linked List

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

#define SIZE 10
#define TABLE_SIZE 10

typedef struct Node
{
    int n;
    struct Node *next;
}node;

int a[SIZE];
node *hashtable[TABLE_SIZE];


node *createnode(int n)
{
    node* temp = (node*)malloc(sizeof(node));
    temp -> n = n;
    temp -> next = NULL;
    return temp;
}

void hashinit()
{
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        hashtable[i] = (node*)malloc(sizeof(node));
        hashtable[i] -> n = INT_MIN;
    }
}

void input()
{
    printf("Enter %d elements\n", SIZE);
    for(int i = 0; i < SIZE; i++)
    {
        printf("Enter element %d : ", i + 1);
        scanf("%d", &a[i]);
    }
}

void hash_function()
{
    int i = 0;
    while(i < SIZE)
    {
        int d = a[i] % 10;
        if(hashtable[d] -> n == INT_MIN)
        {
            hashtable[d] -> n = a[i];
        }
        else
        {
            node *f = createnode(a[i]);
            node *point = hashtable[d];
            point -> next = f;
            point = f;
        }
        i++;
    }
}

bool search(int num)
{
    int d = num % 10;
    if(num == hashtable[d] -> n)
    {
        return true;
    }
    else
    {
        node *point = hashtable[d];
        while(point != NULL)
        {
            if(point -> n == num)
                return true;
            else
                point = point -> next;
        }
        return false;
    }
}

int main()
{
    int num;
    hashinit();
    input();
    hash_function();
    printf("Enter the number to be searched for : ");
    scanf("%d", &num);
    bool flag = search(num);
    if(flag == true)
        printf("Element exits\n");
    else
        printf("Element does not exists\n");
    return 0;
}