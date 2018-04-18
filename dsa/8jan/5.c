#include<stdio.h>

char a[10], b[10];

void process(void);
int main()
{
    scanf("%s", a);
    process();
    return 0;
}

void process()
{
    int i, j;
    for(i = 0; a[i] != '\0'; i++);
    int len = i;
    int l = (len/2);
    for(i = 0, j = l - 1; i < l; i++, j--)
    {
        b[i] = a[j];
    }
    for(i = l, j = len - 1; i < len; i++, j--)
    {
        b[i] = a[j];
    }
    printf("%s\n", b);
}