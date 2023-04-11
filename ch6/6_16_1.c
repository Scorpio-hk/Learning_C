#include<stdio.h>
#define SIEZ 26
int main(void)
{
    char zimu[SIEZ];//char存储字符，赋值一个字母要加单引号:char zimu='a'，不加单引号的数字,如char zimu=65；会显示A，65 是A的ASCII码
    int i;
    for(i=0;i < SIEZ;i++)
        zimu[i] = 'a' + i;//给数组zimi[i]赋值，第一次，i=0，a+0还是a，第二次i=1，a+1=b，循环26次，给数组中的26格填入26个字母
    for(i=0;i < SIEZ ;i++)
        printf("%c",zimu[i]);//依次打印出数组中的每个字符
    return 0;
}