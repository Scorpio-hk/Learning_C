#include<stdio.h>
#include<string.h>
int main(void)
{
    char name[40];
    int len_name;
    printf("Input you name:");
    scanf("%s",name);
    len_name = strlen(name);
    printf("\nyour name is \"%s\"\n",name);
    printf("\"%20s\"\n",name);
    printf("\"%-20s\"\n",name);
    //比在name的宽度长3的字段中打印name, 带*修饰符，需要后面带两个变量，第一个变量指定宽度，第二个是输出的内容，如果输入andy，len_name就是4，不加3的话，输出的就是“andy”
    //加了3就是宽度为7，前三格宽度空出来，后四格显示andy，不加3的话，只有4格，全显示andy
    printf("\"%*s\"\n",len_name+3,name);
    //因为要打印“   andy”，其中的andy名字是字符串，所以用%s
}