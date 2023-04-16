#include <stdio.h>
#include <string.h>
struct Stu
{
    char name[20];
    int age;
    double score;
};
void getStu(struct Stu a)
{
    //a.name = "hk";错误,name是地址，不能将字符串复制给地址
    strcpy()
    a.age = 6;
    a.score = 1.2;
    printf("name:%s,age:%d.score:%lf", a.name, a.age, a.score);
}

int main()
{

    struct Stu s = {0};
    getStu(s);
    // printf("name:%s,age:%d.score:%lf",s.name,s.age,s.score);
}