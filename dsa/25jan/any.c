#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct Node
{
    int data;
    struct Node *next;
}node;

node *top = NULL;

void insert(int key, int d)
{
    node *temp = (node *)malloc(sizeof(node));
    temp -> data = d;
    temp -> next = NULL;
    node *cursor = top;
    while(cursor -> data != key)
        cursor = cursor -> next;
    temp -> next = cursor -> next;
    cursor -> next = temp;
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

int main()
{
    node *f = (node*)malloc(sizeof(node));
    f -> data = 7;
    f -> next = NULL;
    top = f;
    print();
    int dat, k;
    char ch;
    do{
        printf("Enter node\nEnter data : ");
        scanf("%d", &dat);
        printf("After which element you want to enter this??\n");
        scanf("%d", &k);
        insert(k, dat);
        print();
        printf("Want to enter more nodes ?\n");
        scanf(" %c", &ch);
    }while(ch == 'y');
    printf("Want to delete any element?\n");
    scanf(" %c", &ch);
    if (ch == 'y')
    {
        do
        {
            printf("Which element do you want to delete?\n");
            scanf("%d", &k);
            del(k);
            print();
            printf("Want to delete first element again?\n");
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