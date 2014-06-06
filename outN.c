#include <stdio.h>

int f1(int n)
{
	int i =1;
	i <= n && printf("%d ", n) && f1(n-1);
	return 0;
}
int f2(int n)
{
	int i = 1;
	i<=n?printf("%d ",n),f2(n-1):0;
	return 0;
}
int main(int argc, char const *argv[])
{
	int n ;
	scanf("%d", &n);
	f2(n);
	printf("\n");
	return 0;
}