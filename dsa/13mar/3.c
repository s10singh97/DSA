//circular queue

#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int front = -1, rear = -1, queue[MAX];

void push(int dat)
{
    if((rear == MAX - 1 && front == 0) || rear == front - 1)
    {
        printf("Queue is Full\n");
    }
    else if(rear == MAX - 1 && front != 0)
    {
        rear = 0;
        queue[rear] = dat;
    }
    else if(rear == -1) //Queue is empty
    {
        front++;
        queue[++rear] = dat;
    }
    else
        queue[++rear] = dat;
}

void pop()
{
    if(rear == -1)
    {
        printf("Queue is Empty\n");
        return;
    }
    if(front == rear) //Single element is present
    {
        front = -1;
        rear = -1;
    }
    else if(front == MAX - 1)
    {
        front = 0;
    }
    else
        front++;
}

void display()
{
    if(front == -1)
    {
        printf("Queue is Full\n");
    }
    printf("Elements are\n");
    if(rear >= front)
    {
        int i;
        for(i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);

        }
    }
    else
    {
        for (int i = front; i < MAX; i++)
            printf("%d ", queue[i]);

        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
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