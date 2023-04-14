#include<stdio.h>
//用户输入一个数字，函数isSushu()判断是否是素数
int isSushu(int x);
int main()
{
    int a;
    printf("input");
    scanf("%d", &a);
    if (isSushu(a))
    {
        printf("is");
    }
    else
    {
        printf("not");
    }
    return 0;
}
int isSushu(int x)
{
    int i;
    for (i = 2; i < x; i++)
    {
        if (x % i == 0)
        {
            return 0;//如果不是素数(比如，8%2，取余0，不是素数)  （比如11%2，有余数，x % i不等于0，返回1，返回1，if1为真）
        }
    }
    return 1;//是素数
}