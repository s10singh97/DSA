#include<stdio.h>

int main()
{
    int a[10], i, j, n, c;
    printf("How many elements you want to enter(less than 10)\n");
    scanf("%d", &c);
	printf("Enter elements\n");
	for(i = 0; i < c; i++)
	{
		scanf("%d", &a[i]);
	}
	int *p = a;
	printf("Enter the nth minimum position\n");
	scanf("%d", &n);
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
	printf("The %dth minimum element of the array is %d\n", n, *(p+n-1));
    return 0;
}