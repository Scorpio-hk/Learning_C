#include <stdio.h>
#include <string.h>
/* int pstrlen(char *p)
{
    int count=0;
    while (*p != '\0')
    {
        count++;
        p++;
    }
    return count;
}
 */

int main()
{
    int a = 0;
    char c[20];
    scanf("%s", c); //im sb
    a = strlen(c);
    printf("%d", a);
}