#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct Node
{
    int data;
    struct Node* next;
}node;

node *top = NULL;
node *end = NULL;

void insert_atend(int d)
{
    node *temp = (node*)malloc(sizeof(node));
    temp -> data = d;
    temp -> next = NULL;
    if(top == NULL)
    {
        top = temp;
        end = temp;
        return;
    }
    end -> next = temp;
    end = temp;
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

int main()
{
    int dat;
    char ch;
    do{
        printf("Enter node\nEnter data : ");
        scanf("%d", &dat);
        insert_atend(dat);
        print();
        printf("Want to enter more nodes ?\n");
        scanf(" %c", &ch);
    }while(ch == 'y');
    printf("Want to delete last element?\n");
    scanf(" %c", &ch);
    if (ch == 'y')
    {
        do
        {
            del_atend();
            print();
            printf("Want to delete last element again?\n");
            scanf(" %c", &ch);
        }while(ch == 'y');
    }
    else
    {
        printf("Exiting!!\n");
        sleep(2);
    }
    printf("Your final list is :\n");
    print();
    return 0;
}