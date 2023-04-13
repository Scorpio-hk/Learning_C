#include <stdio.h>
int main()
{
//用户输入两个数字，求出两个数字的最大公约数
    int a, b, bigger, smaller;
    printf("请输入两个数字:");
    scanf("%d%d", &a, &b);
    if (a > b)
    {
        bigger = a;
        smaller = b;
    }
    else
    {
        bigger = b;
        smaller = a;
    }
    while (bigger % smaller != 0)
    {
        int temp;
        temp = bigger % smaller;
        bigger = smaller;
        smaller = temp;
    }
    printf("最大公约数是:%d", smaller);
    return 0;
}