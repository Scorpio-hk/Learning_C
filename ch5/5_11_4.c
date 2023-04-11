#include<stdio.h>
//提示用户输入身高，然后将身高用英尺、英寸为单位显示，使用#define定义常量
#define CM_TO_INCH 2.54
#define CM_TO_FEET 30.48
int main(void)
{
    float height_cm,height_inch;
    int height_feet;
    printf("input your height in cm:");
    scanf("%f",&height_cm);
    while (height_cm > 0)
    {
        height_feet = height_cm / CM_TO_FEET;
        height_inch = (height_cm - height_feet * CM_TO_FEET) / CM_TO_INCH;
        printf("your height is %d feet and %.1f inch\n",height_feet,height_inch);
        printf("input your height in cm:");
        scanf("%f",&height_cm);
    }
    printf("input error,exit");
}














