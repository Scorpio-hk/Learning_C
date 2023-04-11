#include<stdio.h>
int main(void)
{
    int i,j;
    char le='A';
    for(i=1;i<=6;i++)
    {
        for(j=1;j<=i;j++)
            printf("%c",le++);//le++是先用le，再加
        printf("\n");      
    }
}