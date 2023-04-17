#include<stdio.h>
int main()
{
    int a,b,c;
    a=20;
    b=30;
    c=40;
    int* parr[10]={&a,&b,&c};
/*     int i=1;
    for(i=1;i<=sizeof(parr)/sizeof(parr[0]);i++)
    {
        printf("%d\n",**(parr+i-1));
    } */


    printf("%d",*(parr[0]));
    /* printf("%d",**(parr)); */
}