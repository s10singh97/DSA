#include <stdlib.h>
#include <stdio.h>
// Declare the Node

struct Node{

        int data;
        struct Node* next;
        };

struct Node* head = NULL;
// Insert the node a the beginning of a linked list

void insert(int data){

        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = data;
        temp->next = head;
        head = temp;

}

void print()
{
    struct Node *n = head;
    while (n != NULL)
    {
        printf(" %d\n", n->data);
        n = n->next;
    }
}

int main()
{
        insert(4);
        insert(5);
        insert(6);
        insert(7);
        print();
}