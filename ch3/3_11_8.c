#include<stdio.h>
int main(void)
{
    float cup,pt,as,ts,cs;
    printf("Input how many cpus:");
    scanf("%f",&cup);
    pt=cup/2;
    as=cup*8;
    ts=as*2;
    cs=ts*3;
    printf("\nYou input %.1f cup(s),is%.1fpt,is%.1fas,is%.1fts,is%.1fcs",cup,pt,as,ts,cs);
    getchar();
}