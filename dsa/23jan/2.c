#include<stdio.h>
#include<stdlib.h>

typedef struct student
{
    char *id;
    char *name;
    struct student *p;
}node;

void printList(node *head)
{
    node *n = head;
    while (n != NULL)
    {
        printf(" %s  %s \n", n->name, n->id);
        n = n->p;
    }
}

node *createnode(char *identity, char*fname)
{
    node * ptr = (node *)malloc(sizeof(node));
    ptr -> id = identity;
    ptr -> name = fname;
    ptr -> p = NULL;
    return ptr;
}

node* insert(node *pr, node *first)
{
    if(first != NULL)
        pr -> p = first;
    first = pr;
    return first;
}

int main()
{
    node *first = NULL, *head;
    char fname[26], identity[26], ch;
    do
    {
        printf("Enter the node\nEnter name : ");
        scanf("%s", fname);
        printf("Enter id : ");
        scanf("%s", identity);
        node * pr = createnode(identity, fname);
        head = insert(pr, first);
        printList(head);
        printf("Do you want to enter another node ?? \n");
        scanf(" %c", &ch);
    }while(ch == 'y' || ch == 'Y');
    return 0;
}