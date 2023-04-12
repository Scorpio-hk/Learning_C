#include<stdio.h>
//设计一个函数cjline(ch,i,j),用户输入后，打印用户输入的字符j行i列
void cjline(char ch, int i, int j);
void cjline(char ch, int i, int j)
{
    int a, b;
    for (a = 0; a < j; a++)
    {
        for (b = 0; b < i; b++)
        {
            printf("%c", ch);
        }
        printf("\n");
    }
}
int main()
{
    char ch;
    int i, j;
    printf("请输入一个字符:");
    scanf("%c", &ch);
    printf("请输入行数:");
    scanf("%d", &j);
    printf("请输入列数:");
    scanf("%d", &i);
    cjline(ch, i, j);
    return 0;
}

