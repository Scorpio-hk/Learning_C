#include <stdio.h>
void swap(int *x, int *y);

void swap(int *x, int *y)
{
    int temp;
    temp = *x; // a存入临时
    *x = *y;   // 将临时a存入b
    *y = temp;
}
int main()
{
    int a = 10;
    int b = 20;
    swap(&a, &b);
    printf("%d,%d\n", a, b);
    return 0;
}
