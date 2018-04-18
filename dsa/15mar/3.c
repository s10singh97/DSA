#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}node;

typedef struct Rev
{
    int data;
    struct Rev *next;
}rev;

node *top = NULL, *end = NULL;
rev *rtop = NULL, *rend = NULL;

node *createnode(dat)
{
    node *temp = (node*)malloc(sizeof(node));
    temp -> data = dat;
    temp -> next = NULL;
    return temp;
}

void insert(node *temp)
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

void rr(rev *tt)
{
    if(rtop == NULL)
    {
        rtop = tt;
        rend = tt;
        return;
    }
    rend -> next = tt;
    rend = tt;
}

void reverse()
{
    node *temp = top, *t;
    while(top -> next != NULL)
    {
        while(temp -> next != NULL)
        {
            t = temp;
            temp = temp -> next;
        }
        rev * tt = (rev*)malloc(sizeof(rev));
        tt -> data = temp -> data;
        tt -> next = NULL;
        rr(tt);
        end = t;
        end -> next = NULL;
        temp = top;
    }
}

void displayr()
{
    if(rtop == NULL)
    {
        printf("Your list is empty\n");
        return;
    }
    rev *temp = rtop;
    while(temp != NULL)
    {
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    node *t = top;
    printf("%d -> NULL\n", t -> data);

}

void display()
{
    if(top == NULL)
    {
        printf("Your list is empty\n");
        return;
    }
    node *temp = top;
    while(temp != NULL)
    {
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

int main()
{
    int n, ch, datas, i;
    node *f;
    do
    {
        printf("\n\n1. Insert\n2. Reverse\n3. Display\n");
        scanf("%d", &n);
        switch(n)
        {
            case 1: printf("Enter number of nodes\n");
                    scanf("%d", &ch);
                    for(i = 0; i < ch; i++)
                    {
                        printf("Enter data\n");
                        scanf("%d", &datas);
                        f = createnode(datas);
                        insert(f);
                    }
                    display();
                    break;

            case 2: reverse();
                    displayr();
                    break;

            case 3: display();
                    break;

            default: break;
        }
    }while(n <= 3);
    return 0;
}