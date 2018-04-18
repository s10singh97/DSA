#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[5], i;
	printf("Enter 5 elements\n");
	for(i = 0; i < 5; i++)
	{
		scanf("%d", &a[i]);
	}
	int t = a[4];
	for(i = 3; i >= 0; i--)
	{
		a[i+1] = a[i];
	}
	a[0] = t;
	for(i = 0; i < 5; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
	return 0;
}
