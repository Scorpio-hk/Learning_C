/*
#include <stdio.h>
int main()
{
    int i = 1;
    do
    {
        if (5 == i)
            break;//i==5时直接跳出循环，打印 1 2 3 4
        printf("%d ", i);
        i = i + 1;
    } while (i <= 10);

    return 0;
}
*/
#include <stdio.h>
int main()
{
    int i = 1;

    do
    {
        if (5 == i)
            continue;//i==5时continue到do，死循环。打印 1 2 3 4 
        printf("%d ", i);
        i = i + 1;
    } while (i <= 10);

    return 0;
}