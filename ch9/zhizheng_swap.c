#include <stdio.h>
void swap(int *x, int *y);
int main()
{
    int a, b;
    printf("输入两个数字:\n");
    scanf("%d%d", &a, &b);
    swap(&a, &b);
    printf("%d    %d",a,b);
    return 0;
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y= temp;
}