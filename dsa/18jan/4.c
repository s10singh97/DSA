#include <stdio.h>
#include <stdlib.h>

void op(int *, char *, int);

int main()
{
    int a[20], i, n;
    char ch[20];
    printf("How many elements you want to enter ?\n");
    scanf("%d", &n);
    printf("Enter a numerical array of 5 elements\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter a character array\n");
    scanf("%s", ch);
    op(a, ch, n);
    return 0;
}

void op(int *a, char *ch, int n)
{
    int i;
    for(i = n - 1; i >= 0; i--)
    {
        printf("%d", *(a+i));
    }
    printf("\n");
    for(i = 0; ch[i] !='\0'; i++);
    int c = i;
    for(i = c; i >= 0; i--)
    {
        printf("%c", ch[i]);
    }
    printf("\n");
}
