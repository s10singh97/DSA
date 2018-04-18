#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[5], i;
    char ch[20];
    printf("Enter a numerical array\n");
    for(i = 0; i < 5; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter a character array\n");
    scanf("%s", ch);
    for(i = 4; i >= 0; i--)
    {
        printf("%d", a[i]);
    }
    printf("\n");
    for(i = 0; ch[i] !='\0'; i++);
    int c = i;
    for(i = c; i >= 0; i--)
    {
        printf("%c", ch[i]);
    }
    printf("\n");
    return 0;
}

