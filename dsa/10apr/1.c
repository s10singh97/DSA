//Hashing with no collision

#include<stdio.h>
#include<stdlib.h>

int hashtable[10] = {0}, a[5];

void input()
{
    printf("Enter 5 elements\n");
    for(int i = 0; i < 5; i++)
    {
        printf("Enter element %d : ", i + 1);
        scanf("%d", &a[i]);
    }
}

void hash_function()
{
    int i = 0;
    while(i < 5)
    {
        int d = a[i] % 10;
        hashtable[d] = a[i];
        i++;
    }
}

void output()
{
    for(int i = 0; i < 10; i++)
    {
        printf("%d\t", hashtable[i]);
    }
    printf("\n");
}

int main()
{
    input();
    hash_function();
    output();
    return 0;
}