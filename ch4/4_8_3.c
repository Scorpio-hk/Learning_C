#include<stdio.h>
int main(void)
{
    float value;
    scanf("%f",&value);
    printf("The input is %.1f,or %.1e\n",value,value);
    printf("The input is %+.2f,or %.3e",value,value);
}