//Insertion Sort using Binary Search

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int search(int a[], int k, int first, int last)
{
    if (last <= first)
    {
        if(k > a[first])
            return (first + 1);
        else
            return (first);
    }
    int mid = (first + last)/2;
    if(k == a[mid])
        return (mid + 1);
    else if(k > a[mid])
    {
        int l = search(a, k, mid + 1, last);
        return l;
    }
    else
    {
        int l = search(a, k, first, mid - 1);
        return l;
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
    int a[SIZE], i, j, key, insert_at;
    printf("Enter 10 elements\n");
    for(i = 0; i < SIZE; i++)
        scanf("%d", &a[i]);

    for (i = 1; i < SIZE; i++)
    {
        key = a[i];
        j = i - 1;
        insert_at = search(a, key, 0, j);
        while (j >= insert_at)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
    print(a, SIZE);
    return 0;
}