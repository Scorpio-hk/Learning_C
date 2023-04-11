#include<stdio.h>
#define DAY_TO_WEEK 7
int main(void)
{
    int input,day,week;
    printf("input days:");
    scanf("%d",&input);
    while (input > 0)
    {   
        week = input / DAY_TO_WEEK;
        day = input % DAY_TO_WEEK;
        printf("%d days are %d weeks, %d days\n",input,week,day);
        scanf("%d",&input);
    }
    printf("input error,exit");
}