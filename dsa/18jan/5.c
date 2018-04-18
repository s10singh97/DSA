#include<stdio.h>

void insert(int a[], int&, int);
void output(int a[], int &);
void del(a[], int&);

int main()
{
    int n, stack[100], top = -1;
    char ans;
    do
    {
        printf("Enter data\n");
        scanf("%d", &n);
        insert(stack, top, n);
        printf("Do you want to enter more...\n");
        scanf(" %c", &ans);
    }while(ans = 'y' || ans = 'Y')
    output(stack, top);
    char a;
    printf("Do you want to delete an element\n");
    scanf("%c", &a);
    if(a == 'y' || a = 'Y')
        del(stack, top);
    else
        printf("Tnak You...\nExitting Now!!\n");
}

void insert(int stack[], int &top, int n)
{
    if(top == n - 1)
        printf("Overflow!!\n");
    else
    {
        stack[++top] = n;
    }
}

void output(int stack[], int &top)
{
    int i;
    for(i = top - 1; i >= 0; i--)
        printf("%d\t", stack[i]);
}

void del(int stack[], &top)
{
    int data = stack[top];
    printf("Are you sure to delete this node\n");
    char c;
    scanf(" %c", &c);
    if(c == 'y' || c == 'Y')
        top++;
}