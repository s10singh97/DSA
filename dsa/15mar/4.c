#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5

struct student
{
    char na[20];
    char grade[2];
    int id;
};

struct student s[MAX];

int main()
{
    int c = 1, i, n, m;
    for(i = 0; i < MAX; i++)
    {
        s[i].id = c;
        c++;
    }
    strcpy(s[0].na, "Ram");
    strcpy(s[0].grade, "AA");

    strcpy(s[1].na, "Shyam");
    strcpy(s[1].grade, "AB");

    strcpy(s[2].na, "Lakhman");
    strcpy(s[2].grade, "BB");

    strcpy(s[3].na, "Bharat");
    strcpy(s[3].grade, "BC");

    strcpy(s[4].na, "Sita");
    strcpy(s[4].grade, "AA");


    printf("Enter the id to fetch details\n");
    scanf("%d", &n);

    int first = 0;
    int last = MAX;
    while (first <= last)
    {
        m = (first + last)/2;
        if (s[m].id < n)
            first = m + 1;
        else if (s[m].id == n)
        {
            printf("\n%d\n", s[m].id);
            printf("%s\n", s[m].na);
            printf("%s\n", s[m].grade);
            break;
        }
        else
            last = m - 1;
    }
    if (first > last)
        printf("Not found! %d is not present in the list.\n", n);

    return 0;
}



