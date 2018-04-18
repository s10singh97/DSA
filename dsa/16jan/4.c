#include <stdio.h>
#include <stdlib.h>
#include<math.h>

struct node
{
	int a,b;
};
struct node s[5], *p;

int main()
{
	p = s;
	int i, j, k = 0;
	float e[25];
	printf("Enter coordinates of five elements as 2-D array\n");
	for(i = 0; i < 5; i++)
	{
		scanf("%d %d", &((p+i) -> a), &((p+i) -> b));
	}
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
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
