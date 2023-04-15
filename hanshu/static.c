#include <stdio.h>
void test()
{
    static int a = 1;//static修饰a之后，a变为静态变量
    a++;
    printf("%d\n", a);
}

int main()
{
    int i = 0;
    while (i < 10)
    {
        test();
        i++;
    }
    return 0;
}