#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int stack[MAX];
int top = -1;

void push(int dat)
{
    if(top == MAX - 1)
    {
        printf("Stack is Full\n");
        return;
    }
    top++;
    stack[top] = dat;
}

void pop()
{
    if(top == -1)
    {
        printf("List is Empty\n");
        return;
    }
    int val = stack[top];
    char ch;
    printf("Are you sure you want to Delete %d\n", val);
    scanf(" %c", &ch);
    if(ch == 'y' || ch == 'Y')
        top--;
    else
        return;
}

void display()
{
    if(top == -1)
    {
        printf("Stack is Empty\n");
        return;
    }
    int i;
    for(i = top; i >= 0; i--)
    {
        printf(" %d ->", stack[i]);
    }
    printf(" NULL\n");
}

void search(int dd)
{
    int i = 0;
    while(stack[i] != dd)
    {
        if(i == (MAX - 1))
        {
            printf("%d does not exist in this Stack\n", dd);
            return;
        }
        i++;
    }
    printf("%d is at %d", dd, i + 1);
}

int main()
{
    int choice, dat, searchop;
    do
    {
        printf("\n\t\t\t********** MENU **********\n");
        printf("1. PUSH\n2. POP\n3. DISPLAY\n4. SEARCH\n5. EXIT\n\n");
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

            case 4: printf("Enter the data you want to search for\n");
                    scanf("%d", &searchop);
                    search(searchop);
                    break;

            case 5: exit(0);

            default: printf("Please enter a valid choice\n");
        }
    }while(choice <= 5);
    printf("Your final Stack is :\n");
    display();
    return 0;
}
