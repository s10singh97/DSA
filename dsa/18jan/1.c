#include<stdio.h>

void sort(int *, int);
void output(int *, int);


int main()
{
    int a[50], i, n;
    printf("Enter number of elements\n");
    scanf("%d", &n);
    printf("Enter the elements\n");
    for(i = 0; i < n; i++)
        scanf("%d", (a+i));
    sort(a, n);
    output(a, n);
    return 0;
}

void sort(int *a, int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n - 1; j++)
        {
            if(*(a+j) > *(a+j+1))
            {
                int temp = *(a+j);
                *(a+j) = *(a+j+1);
                *(a+j+1) = temp;
            }
        }
    }
}

void output(int *a, int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%d\t", *(a+i));
    printf("\n");
}