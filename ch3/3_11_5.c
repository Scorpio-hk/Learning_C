#include<stdio.h>
int main(void)
{
    int age;
    float seconds = 3.156e7;
    printf("输入年龄：");
    scanf("%d",&age);
    printf("\nage to seconds is %f",age * seconds);
    getchar();
}