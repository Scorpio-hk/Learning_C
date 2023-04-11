#include<stdio.h>
int main(void)
{
    float inchtall;
    printf("Input your inchtall:");
    scanf("%f",&inchtall);
    printf("\ninch to cm is:%.2f",inchtall * 2.54);
    getchar();
}