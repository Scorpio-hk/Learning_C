#include<stdio.h>
#include<float.h>
int main(void)
{
    float floatValue = 1.0 / 3.0;
    double doubleValue = 1.0 / 3.0;

    printf("%.6f\n%.12f\n%.16f\n%d\n",doubleValue,doubleValue,doubleValue,DBL_DIG);
    printf("%.6f\n%.12f\n%.16f\n%d\n",floatValue,floatValue,floatValue,FLT_DIG);
}