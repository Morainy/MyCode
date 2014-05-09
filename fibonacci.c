/*************************************************************************
    > File Name: fibonacci.c
    > Author: Morain
    > Mail: morainchen135@gmail.com
    > Created Time: 2014年05月09日 星期五 10时24分52秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


unsigned int f1(int n)
{
	if(1==n)
	{
		return 1;
	}
	if(2==n)
	{
		return 1;
	}
	unsigned int result;
	int *c = (int *)malloc(sizeof(int)*(n));
	int i;
	int num1=1;
	int num2=1;
	c[0]=num1;
	c[1]=num2;
	for(i=2;i<n;i++)
	{
		c[i]=num1+num2;
		num1=num2;
		num2=c[i];
	}
	result=c[n-1];
	free(c);
	return result;
}
unsigned int f2(int n)
{
	if(1==n)
	{
		return 1;
	}
	if(2==n)
	{
		return 1;
	}
	else
		return f2(n-1)+f2(n-2);
}
int main(int argc,char* argv[])
{
	int n;
	clock_t start,end;
	printf("Please input the number N:");
	while(scanf("%d",&n))
	{
		start = clock();
		printf("result=%d \n",f1(n));
		end=clock();
		printf("time= %f \n",(double)(end-start)/CLOCKS_PER_SEC);
		start = clock();
		printf("result=%d \n",f2(n));
		end=clock();
		printf("time= %f \n",(double)(end-start)/CLOCKS_PER_SEC);
		printf("Please input the number N:");
	}
}
