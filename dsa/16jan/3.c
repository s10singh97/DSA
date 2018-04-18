#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
	int a,b;
};
struct node s[5], *p;

int main()
{
	p = s;
	int i, j, k = 0, n;
	float e[25];
	printf("Enter the number of elements(less than 5)\n");
	scanf("%d", &n);
	printf("Enter coordinates of the elements as 2-D array\n");
	for(i = 0; i < n; i++)
	{
		scanf("%d %d", &((p+i) -> a), &((p+i) -> b));
	}
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(i == j)
				continue;
			else
			{
				e[k] = (float)(sqrt(pow(((p+i) -> a) - ((p+j) -> a), 2) + pow(((p+i) -> b) - ((p+j) -> b), 2)));
				k++;
			}
		}
	}
	float small = e[0];
	for(i = 0; i < k; i++)
	{
		if(small > e[i])
			small = e[i];
	}
	printf("%f\n", small);
	return 0;
}
