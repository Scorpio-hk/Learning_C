/*
#include <stdio.h>
double min(double x, double y);
double min(double x, double y)
{
    double small;
    if (x < y)
    {
        small = x;
    }
    else
    {
        small = y;
    }
    return small;
}
int main()
{
    double a, b;
    scanf("%lf%lf", &a, &b);
    printf("the smaller is %f", min(a, b));
}
*/
#include<stdio.h>
int main()
{
    int n=0;
    int k=1950;
    scanf("%d",&n);
    printf("%d",n-k+1);
    return 0;//11111
}