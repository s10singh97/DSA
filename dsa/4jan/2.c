#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[5], i, j, n;
	printf("Enter an array\n");
	for(i = 0; i < 5; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("Enter the nth minimum position\n");
	scanf("%d", &n); 
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 4; j++)
		{
			if(a[j] > a[j+1])
			{
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
	printf("The %dth minimum position of the array is %d\n", n, a[n-1]);
	return 0;
}

