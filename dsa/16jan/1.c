#include<stdio.h>

int main()
{
    int a[10], i, j, n;
    int *p = a;
    printf("How many elements do you want to enter (less than 10)\n");
    scanf("%d", &n);
    printf("Enter the numbers\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = 0; i < n; i++)
	{
		for(j = 0; j < (n - 1); j++)
		{
			if((*(p+j)) > (*(p+j+1)))
			{
				int t = *(p+j);
				*(p+j) = *(p+j+1);
				*(p+j+1) = t;
			}
		}
	}

	for(i = 0; i < n; i++)
	    printf("%d\t", *(p+i));

	printf("\n");
    return 0;
}

