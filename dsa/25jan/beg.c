#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct Node
{
    int data;
    struct Node* next;
}node;

node *top = NULL;

void insert_atbeg(int d)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = d;
    temp->next = top;
    top = temp;
}

void del_atbeg()
{
    node *temp = top;
    top = top -> next;
    free(temp);
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
    do
    {
        printf("Enter node\nEnter data : ");
        scanf("%d", &dat);
        insert_atbeg(dat);
        print();
        printf("Want to enter more nodes ?\n");
        scanf(" %c", &ch);
    }while(ch == 'y');
    printf("Want to delete first element?\n");
    scanf(" %c", &ch);
    if (ch == 'y')
    {
        do
        {
            del_atbeg();
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