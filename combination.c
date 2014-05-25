/*************************************************************************
    > File Name: combination.c
    > Author: Morain
    > Mail: morainchen135@gmail.com
    > Created Time: 2014年05月25日 星期日 20时55分51秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int check(int *c , int n , int r)
{
	int i =0 , j;
	for( j=1 ; j<=r ; j++)
	{
		if((c[j]<n-r+j) &&(i<j) )
		{
			i = j;
		}
	}
	return i;
}
void combination(int n , int r)
{
	int itemp;
	int * p = (int *)malloc(sizeof(int) * (n+1));
	int * c = (int *)malloc(sizeof(int) * (r+1));
	int i , j;
	for( i =1 ;i<=n ; i++)
	{
		p[i] = i;
	}
	for(i = 1 ; i<=r ; i++)
	{
		c[i] = p[i];
	}
	while(itemp = check(c , n , r))
	{
		for(j =1 ; j<=r ; j++)
		{
			printf("%d ", c[j]);
		}
		printf("\n");
		c[itemp] = c[itemp] +1;
		for(j = itemp +1 ; j<=r ;j++)
		{
			c[j] = c[j-1] +1;
		}
	}
	for(j =1 ; j<=r ; j++)
		{
			printf("%d ", c[j]);
		}
	printf("\n");
	free(p);
	free(c);
}
int main(int argc ,char * argv[])
{
	combination( 6 ,3 );
	return 0;
}
