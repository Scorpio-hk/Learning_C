#include<stdio.h>
int main(void)
{
    int num1,num2;
    printf("input a number:");
    scanf("%d",&num1);
    num2 = num1 + 10;
    while (num1 <= num2)
    {
        printf("\n%d\n",num1);
        num1++;
    }
    
}   