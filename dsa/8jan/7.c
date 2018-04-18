#include<stdio.h>

void input();
void sort();
void altsort();

int a[10], i, j, b[10];

int main()
{
    input();
    sort();
    altsort();
	return 0;
}

void input()
{
    for(i = 0; i < 10; i++)
        scanf("%d", &a[i]);
}

void sort()
{
    for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 9; j++)
		{
			if(a[j] > a[j+1])
			{
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
}

void altsort()
{
    for(i = 0, j = 0; i < 10;)
	{
	    if((i % 2) != 0)
	    {
	        b[i] = 0;
	        i++;
	    }
	    else
	    {
	        b[i] = a[j];
	        j++;
	        i++;
	    }
	}

	for(i = 0, j = 9; i < 10;)
	{
	    if((i % 2) == 0)
	    {
	        i++;
	    }
	    else
	    {
	        b[i] = a[j];
	        j--;
	        i++;
	    }
	}

    printf("\nAlternate Sorted Array is :\t");

	for(i = 0; i < 10; i++)
	    printf("%d\t", b[i]);
	printf("\n");
}