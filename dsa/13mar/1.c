//queue using linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}node;

node *top = NULL, *end = NULL;

node *createnode(int dat)
{
    node *temp = (node*)malloc(sizeof(node));
    temp -> data = dat;
    temp -> next = NULL;
    return temp;
}

void push(node *temp)
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

void pop()
{
    if(top == NULL)
    {
        printf("List is Empty!!\n");
        return;
    }
    node *temp = top;
    top = top -> next;
    free(temp);
}

void display()
{
    if(top == NULL)
    {
        printf("Your List is Empty\n");
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
    node *f;
    int i, da;
    do
    {
        printf("\t\t\t********** MENU **********\n\n");
        printf("1. Insert Node\n2. Delete Node\n3. Display\n4. Exit\n");
        scanf("%d", &i);
        switch(i)
        {
            case 1: printf("Enter data\n");
                    scanf("%d", &da);
                    f = createnode(da);
                    push(f);
                    display();
                    break;

            case 2: printf("\nDeleting Node !!\n");
                    pop();
                    display();
                    break;

            case 3: display();
                    break;

            case 4: exit(0);

            default: printf("Please enter a valid choice\n");
        }
    }while(i <= 4);
    printf("Your final list is :\n");
    display();
    return 0;
}