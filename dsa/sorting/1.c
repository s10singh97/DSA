//Bubble Sort

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

void bubblesort(int a[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void print(int a[], int n)
{
    for(int i =0; i < n; i++)
        printf("%d\n", a[i]);
}

int main()
{
    int a[SIZE], i;
    printf("Enter 10 elements\n");
    for(i = 0; i < SIZE; i++)
        scanf("%d", &a[i]);
    bubblesort(a, SIZE);
    print(a, SIZE);
    return 0;
}