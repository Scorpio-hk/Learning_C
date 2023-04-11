#include<stdio.h>
#include<string.h>
int main(void)
{
    char firstName[40];
    char lastName[40];
    int len_firstName;
    int len_lastName;

    printf("Input your first name:\n");
    scanf("%s",firstName);
    printf("Input your lastName:\n");
    scanf("%s",lastName);
    len_firstName = strlen(firstName);
    len_lastName = strlen(lastName);

    printf("%s %s\n",firstName,lastName);
    printf("%*d %*d\n",len_firstName,len_firstName,len_lastName,len_lastName);//第一个len_firstName传入总的宽度，第二个len_firstName传入字符串
    printf("%s %s\n",firstName,lastName);
    printf("%*d %*d\n",-len_firstName,len_firstName,-len_lastName,len_lastName);
    ////因为要打印“   数字”，其中的数字是十进制整数，所以用%d
}