#include<stdio.h>

void toh(int n, int rod1, int rod3, int rod2)
{
    if(n == 1)
    {
        printf("Moving Disk 1 from rod %d to rod %d\n", rod1, rod3);
        return;
    }
    toh(n-1, rod1, rod2, rod3);
    printf("Moving Disk %d from rod %d to rod %d\n", n, rod1, rod3);
    toh(n-1, rod2, rod3, rod1);
}

int main()
{
    int n;
    printf("Enter number of disks\n");
    scanf("%d", &n);
    toh(n, 1, 3, 2);
    return 0;
}