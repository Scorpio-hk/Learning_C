#include <stdio.h>
/* int main()
{
    int arr[10] = {0};
    int i = 0;
    int *p = arr;
    for (i = 0; i < 10; i++)
    {
        *p = 1;
        p++;
        printf("%d\n", arr[i]);
    }
} */
 int main()
{
    int arr[10] = {0};
    printf("%lld",&arr[8]-&arr[1]);
}    