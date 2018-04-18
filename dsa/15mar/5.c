#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}node;

node *top = NULL, *end = NULL;

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

void pop(node* temp1, node* t1)
{
    node *cur = top;
    while(cur != temp1)
    {
        cur = cur -> next;
    }
    temp1 -> next = temp1 -> next -> next;
    t1 = NULL;
}

void fun()
{
    node* temp = top, *t = top, *temp1 = temp, *t1 = t;
    while (temp != NULL)
    {
        t = temp -> next;
        while (t != NULL)
        {
            if ((temp -> data) + (t -> data) == 0)
            {
                pop(temp1, t1);
            }
            t = t -> next;
        }
        temp1 = temp;
        t1 = temp;
        temp = temp -> next;
    }
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
        printf("1. insert\n2. fun\n3. Display\n");
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

            case 2: fun();
                    display();
                    break;

            case 3: display();
                    break;
        }
    }while(n <= 3);
    return 0;
}