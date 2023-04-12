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