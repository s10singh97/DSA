#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next, *prev;
};

node *top = NULL;
node *end = NULL;

node *createnode(int dat)
{
    node *temp = (node *)malloc(sizeof(node));
    temp -> data = dat;
    temp -> next = NULL;
    temp -> prev = NULL;
    return temp;
}

void insert_atbeg(node *temp)
{
    if(temp -> next == NULL)
    {
        top = temp;
        end = temp;
        return;
    }
    temp -> next = top;
    top -> prev = temp;
    top = temp;
}

void insert_atend(node *temp)
{
    if(temp -> next == NULL)
    {
        top = temp;
        end = temp;
        return;
    }
    end -> next = temp;
    temp -> prev = end;
    end = temp;
}

void insert(int key, node *temp)
{
    node *cursor = top;
    int i;
    for(i = 1; i < key; i++)
        cursor = cursor -> next;
    temp -> next = cursor -> next;
    cursor -> next -> prev = temp;
    cursor -> next = temp;
    temp -> prev = cursor;
}

void del_atbeg()
{
    node *temp = top;
    top = top -> next;
    top -> prev = NULL;
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
    free(temp);
    t -> next = NULL;
    end = t;
}

void del(int key)
{
    node *cursor = top, *temp;
    if(cursor -> data == key)
        del_atbeg();
    //else if(cursor -> next == NULL)
    //    del_atend();
    else
    {
        while(cursor -> data != key)
        {
            temp = cursor;
            cursor = cursor -> next;
        }
        temp -> next = cursor -> next;
        cursor -> next -> prev = temp;
        free(cursor);
    }
}

void print_front()
{
    node *temp = top;
    printf("NULL <-> ");
    while(temp != NULL)
    {
        printf("%d <-> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

void print_back()
{
    node *temp = end;
    printf("NULL <-> ");
    while(temp != NULL)
    {
        printf("%d <-> ", temp -> data);
        temp = temp -> prev;
    }
    printf("NULL\n");
}

void search(int key)
{
    node *cursor = top;
    int c = 0;
    while(cursor -> data != key)
    {
        c++;
        cursor = cursor -> next;
    }
    printf("%d is at position : %d\n", cursor -> data, c+1);
}

int main()
{
    int n, dat, i, p, choice, delop, searchop;
    node *f = NULL;
    do
    {
        printf("\n\t\t\t********* MAIN MENU *********\n1. Insert at beginning\n2. Insert at end\n3. Insert anywhere\n");
        printf("4. Delete from beginning\n5. Delete at end\n6. Delete from anywhere\n");
        printf("7. Search\n8. Print List from beginning\n9. Print list from back\n");
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
                        print_front();
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
                        print_front();
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
                        print_front();
                        printf("After which position do you want to enter this data?\n");
                        scanf("%d", &p);
                        f = create(dat);
                        insert(p, f);
                        print_front();
                     }
                     break;

            case 4 : print_front();
                     del_atbeg();
                     print_front();
                     break;

            case 5 : print_front();
                     del_atend();
                     print_front();
                     break;

            case 6 : print_front();
                     printf("Enter the element you want to delete\n");
                     scanf("%d", &delop);
                     del(delop);
                     print_front();
                     break;

            case 7 : print_front();
                     printf("Enter the element you want to search for\n");
                     scanf("%d", &searchop);
                     search(searchop);
                     break;

            case 8 : print_front();
                     break;

            case 9 : print_back();
                     break;

            default : break;
        }
    }while((choice >= 1) && (choice <= 9));
    printf("Your final list is :\n");
    print_front();
    return 0;
}