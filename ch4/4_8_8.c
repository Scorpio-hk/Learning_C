#include<stdio.h>
#define JIALUN_SHEN 3.785
#define YINGLI_QIANMI 1.609 
int main(void)
{
    float yl;
    float jl;
    printf("input your feet:\n");
    scanf("%f",&yl);
    printf("input your jl:\n");
    scanf("%f",&jl);
    printf("in usa ,u %.1f",yl/jl);
    printf("in eu, u %.1f",(jl * JIALUN_SHEN)/(yl * YINGLI_QIANMI));
}