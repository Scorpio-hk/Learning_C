#include<stdio.h>
int main(void)
{
    float kuatuo=950;
    float howmanykt;
    double sfz=3e-23;
    printf("input how many kuatuo:");
    scanf("%f",&howmanykt);
    printf("sfz is :%e",howmanykt * kuatuo / sfz);
    getchar();
}