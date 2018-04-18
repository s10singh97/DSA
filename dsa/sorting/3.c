//Insertion Sort

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

void insertionsort(int a[], int n)
{
    int i , key, j;
    for(i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key) //Shifting elements rightwards
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j+1] = key;
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
    insertionsort(a, SIZE);
    print(a, SIZE);
    return 0;
}