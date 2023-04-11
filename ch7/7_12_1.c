#include<stdio.h>
int main()
{
    char ch;
    int kg,hh,zm;
    kg=hh=zm=0;
    while ((ch=getchar()) != '#')
    {
        switch (ch)
        {
        case ' ':
            kg++;
            break;
        case '\n':
            hh++;
            break;
        default:
            zm++;
            break;
        }
    }
    printf("%d个空格 %d个换行 %d字母",kg,hh,zm);
    return 0;
    
}