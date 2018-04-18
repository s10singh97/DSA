#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void push(int dat)
{
    if(rear == MAX - 1)
    {
        printf("Queue is Full\n");
        return;
    }
    if(rear == -1)
    {
        front++;
        rear++;
        queue[rear] = dat;
        return;
    }
    rear++;
    queue[rear] = dat;
}

void pop()
{
    if(rear == -1)
    {
        printf("List is Empty\n");
        return;
    }

    if(front > rear)
    {
        printf("List is Empty\n");
        return;
    }
    int val = queue[rear];
    char ch;
    printf("Are you sure you want to Delete %d\n", val);
    scanf(" %c", &ch);
    if(ch == 'y' || ch == 'Y')
        front++;
    else
        return;
}

void display()
{
    if(rear == -1 || front > rear)
    {
        printf("Queue is Empty\n");
        return;
    }
    int i;
    for(i = front; i <= rear; i++)
    {
        printf(" %d ->", queue[i]);
    }
    printf(" NULL\n");
}


int main()
{
    int choice, dat;
    do
    {
        printf("\n\t\t\t********** MENU **********\n");
        printf("1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\n\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Enter data\n");
                    scanf("%d", &dat);
                    push(dat);
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
    }while(choice <= 4);
    printf("Your final Queue is :\n");
    display();
    return 0;
}
