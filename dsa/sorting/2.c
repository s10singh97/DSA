//Selection Sort

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

void selectionsort(int a[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(a[j] < a[i])
            {
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
}

void print(int a[], int n)
{
    printf("\n");
    for(int i =0; i < n; i++)
        printf("%d\n", a[i]);
}

int main()
{
    int a[SIZE], i;
    printf("Enter 10 elements\n");
    for(i = 0; i < SIZE; i++)
        scanf("%d", &a[i]);
    selectionsort(a, SIZE);
    print(a, SIZE);
    return 0;
}