#include<stdio.h>
int main(void)
{
    char x[40];                 //char字符串
    char m[40];
    printf("input your x:");
    scanf("%s",x);              //打印时应用%s而不是%c，%s是字符串，%c是单个字符
    printf("\ninput your m :");
    scanf("%s",m);
    printf("u are %s%s",m,x);
    getchar();

}