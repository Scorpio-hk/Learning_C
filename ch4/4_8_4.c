#include<stdio.h>
int main(void){
    float tall;
    char name[40];
    printf("input your name\n");
    scanf("%s",name);
    printf("input your tall\n");
    scanf("%f",&tall);
    printf("%s,you r %.2fM tall",name,tall/100);
}