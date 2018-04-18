#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}node;

node *top = NULL;
node *end = NULL;

node *create(int d)
{
    node *temp = (node*)malloc(sizeof(node));
    temp -> data = d;
    temp -> next = NULL;
    return temp;
}

void insert_atend(node *temp)
{
    if(top == NULL)
    {
        top = temp;
        end = temp;
        return;
    }
    end -> next = temp;
    end = temp;
}

void insert_atbeg(node *temp)
{
    if(top == NULL)
    {
        top = temp;
        end = temp;
        return;
    }
    temp -> next = top;
    top = temp;
}

void insert(int key, node *temp)
{
    node *cursor = top;
    while(cursor -> data != key)
        cursor = cursor -> next;
    temp -> next = cursor -> next;
    cursor -> next = temp;
}

void del_atbeg()
{
    node *temp = top;
    top = top -> next;
    free(temp);
}

void del_atend()
{
    node *temp = top;
    node *t;
    while(temp -> next != NULL)
    {
        t = temp;
        temp = temp -> next;
    }
    free(t -> next);
    t -> next = NULL;
}

void del(int key)
{
    node *cursor = top, *temp;
    while(cursor -> data != key)
    {
        temp = cursor;
        cursor = cursor -> next;
    }
    temp -> next = cursor -> next;
    free(cursor);
}

void print()
{
    node *temp = top;
    while(temp != NULL)
    {
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

void search(int key)
{
    int c = 0;
    node *cursor = top;
    while(cursor -> data != key)
    {
        cursor = cursor -> next;
        c++;
        if(cursor == NULL)
        {
            printf("There is no such element present in this linked list\n");
            return;
        }
    }
    printf("Your data is at %d position\n", c+1);
}

int main()
{
    int n, dat, i, p, choice, delop, searchop;
    node *f = NULL;
    do
    {
        printf("\n\n1. Insert at beginning\n2. Insert at end\n3. Insert anywhere\n");
        printf("4. Delete from beginning\n5. Delete at end\n6. Delete from anywhere\n");
        printf("7. Search\n8. Print List\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1 : printf("How many nodes do you want to enter?\n");
                     scanf("%d", &n);
                     for(i = 0; i < n; i++)
                     {
                        printf("Enter the data\n");
                        scanf("%d", &dat);
                        f = create(dat);
                        insert_atbeg(f);
                        print();
                     }
                     break;

            case 2 : printf("How many nodes do you want to enter?\n");
                     scanf("%d", &n);
                     for(i = 0; i < n; i++)
                     {
                        printf("Enter the data\n");
                        scanf("%d", &dat);
                        f = create(dat);
                        insert_atend(f);
                        print();
                     }
                     break;

            case 3 : if(top == NULL)
                     {
                         printf("Please enter the data via other method first\n");
                         break;
                     }
                     printf("How many nodes do you want to enter?\n");
                     scanf("%d", &n);
                     for(i = 0; i < n; i++)
                     {
                        printf("Enter the data\n");
                        scanf("%d", &dat);
                        print();
                        printf("After which element do you want to enter this data?\n");
                        scanf("%d", &p);
                        f = create(dat);
                        insert(p, f);
                        print();
                     }
                     break;

            case 4 : del_atbeg();
                     print();
                     break;

            case 5 : del_atend();
                     print();
                     break;

            case 6 : printf("Enter the element you want to delete\n");
                     scanf("%d", &delop);
                     del(delop);
                     print();
                     break;

            case 7 : print();
                     printf("Enter the element you want to search for\n");
                     scanf("%d", &searchop);
                     search(searchop);
                     break;

            case 8 : print();

            default : break;
        }
    }while((choice >= 1) && (choice <= 8));
    printf("Your final list is :\n");
    print();
    return 0;
}