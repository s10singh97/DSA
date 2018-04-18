#include<stdio.h>
#include<stdlib.h>

typedef struct student
{
    char *id;
    char *name;
    struct student *p;
}node;

void printList(node *n)
{
  while (n != NULL)
  {
     printf(" %s  %s \n", n->name, n->id);
     n = n->p;
  }
}

int main()
{
    node *first, *second, *third;
    first = (node *)malloc(sizeof(node));
    second = (node *)malloc(sizeof(node));
    third = (node *)malloc(sizeof(node));
    first->id = "2017kucp1054";
    first->name = "Shashwat";
    second->id = "2017kucp1055";
    second->name = "Neeraj";
    third->id = "2017kucp1056";
    third->name = "Saksham";
    first->p = second;
    second->p = third;
    third->p = NULL;
    printList(first);
    return 0;
}