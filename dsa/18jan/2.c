#include<stdio.h>

void op(int*, int);
void output(int *, int);

int main()
{
    int a[50], i, n, c;
    printf("How many elements you want to enter ?\n");
    scanf("%d", &c);
	printf("Enter elements\n");
	for(i = 0; i < c; i++)
	    scanf("%d", &a[i]);
	printf("Enter the nth minimum position\n");
	scanf("%d", &n);
	op(a, c);
	output(a, n);
    return 0;
}

void op(int *p, int c)
{
    int i, j;
    for(i = 0; i < c; i++)
	{
		for(j = 0; j < c - 1; j++)
		{
			if(*(p+j) > *(p+j+1))
			{
				int t = *(p+j);
				*(p+j) = *(p+j+1);
				*(p+j+1) = t;
			}
		}
	}
}

void output(int *p, int n)
{
    printf("The %dth minimum element of the array is %d\n", n, *(p+n-1));
}