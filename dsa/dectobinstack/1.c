#include<stdio.h>
#define MAX 10

int top = -1, stack[MAX];

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

int main()
{
    int n, i;
    printf("Enter a number to find it's binary equivalent\n");
    scanf("%d", &n);
    while(n)
    {
        push(n % 2);
        n /= 2;
    }
    for(i = top; i >= 0; i--)
    {
        printf("%d", stack[i]);
    }
    printf("\n");
    return 0;
}