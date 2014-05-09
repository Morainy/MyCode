/*************************************************************************
    > File Name: swap.c
    > Author: Morain
    > Mail: morainchen135@gmail.com
    > Created Time: 2014年05月09日 星期五 14时56分57秒
 ************************************************************************/

#include<stdio.h>

void swap1(int *a,int *b)
{
	if(*a!=*b)
	{
		*a=*a^*b;
		*b=*b^*a;
		*a=*a^*b;
	}
}
void swap2(int *a,int *b)
{
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
}
int main(int argc,char * crgv[])
{
	int a=1,b=1;
	printf("a=%d,b=%d\n",a,b);
	swap1(&a,&b);
	printf("a=%d,b=%d\n",a,b);
	swap2(&a,&b);
	printf("a=%d,b=%d\n",a,b);
}
