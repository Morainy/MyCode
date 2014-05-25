/*************************************************************************
    > File Name: permutation.c
    > Author: Morain
    > Mail: morainchen135@gmail.com
    > Created Time: 2014年05月25日 星期日 19时12分25秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

unsigned int  factorical(int n)
{
	int i;
	unsigned int  result = 1;
	for(i =1 ; i<=n ; i++)
	{
		result = result * i;
	}
	return result;
}
int searchI (int *a ,int n)
{
	int k ,i = 1;
	for(k=2 ; k<=n ;k++)
	{	
		if(a[k]>a[k-1] && (i<k))
		{
			i = k;
		}
	}
	return i;
}
int searchJ (int * a ,int i, int n)
{
	int k , j =1;
	for(k=1 ; k<=n ;k++)
	{
		if((a[i-1] <a[k]) && (j<k) )
		{
			j = k;
		}
	}
	return j;
}

void swap(int *a,int *b)
{
	if(*a!=*b)
	{
		*a=*a^*b;
		*b=*b^*a;
		*a=*a^*b;
	}
}
void reverse (int *a , int start ,int end)
{
	int i = start;
	int j = end;
	while (j > i)
	{
		swap(&a[i] , &a[j]);
		i++;
		j--;
	}

}
void permutation(int n)
{
	int *a = (int *)malloc(sizeof(int) * (n+1)) ;
	int i , j;
	int itemp , jtemp;
	for(i = 0 ; i<=n ;i++)
	{
		a[i]=i;
	}

	for(i = 1 ; i<= factorical(n) ;i++)
	{
		for(j =1 ; j<= n; j++)
		{
			printf("%d ",a[j]);
		}
		printf("\n");
		itemp = searchI(a , n);
		jtemp = searchJ(a , itemp , n);
		swap(&a[itemp-1] , &a[jtemp]);
		reverse(a , itemp , n);
	}
	free(a);
}
int main(int argc ,char *argv[])
{

	permutation(4);
	return 0;
}
