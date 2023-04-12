#include <stdio.h>
int summ(int *x, int *y);

int summ(int *x, int *y)
{
    return *x + *y;
}
int main()
{
    int a, b, sum;
    a = 10;
    b = 30;

    sum = summ(&a, &b);
    printf("%d", sum);
}
//上面是求和函数的指针写法
//下面是不用指针的写法


/*
int summ(int x,int y);

int summ(int x,int y)
{
    return x+y;
}
int main()
{
    int a, b, sum;
    a = 10;
    b = 30;
    sum = summ(a, b);
    printf("%d", sum);
}
*/