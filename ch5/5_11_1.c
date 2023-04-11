#include<stdio.h>
#define TTT 60
int main(void)
{
    int input,min,hour;
    printf("input fen:\n");
    scanf("%d",&input);
    while (input >0 )
    {
        min = input % TTT;//取模，如果是91分钟，由于int类型只能是整数，hour:91/60=1，剩下的31分钟，用%取模
        hour =  input / TTT;
        printf("%d fen is %d hour and %d min\n",input,hour,min);
        scanf("%d",&input);
    }
    
}