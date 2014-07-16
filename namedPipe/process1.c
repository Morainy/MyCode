/*************************************************************************
    > File Name: process1.c
    > Author: Morain
    > Mail: morainchen135@gmail.com
    > Created Time: 2014年07月16日 星期三 08时47分24秒
 ************************************************************************/

#include <stdio.h>
#include <fcntl.h>
#define N 1024

int main(int argc, char const *argv[])
{
	int buf[N];
	int i;
	for(i = 0; i<N ;i++)
	{
		buf[i] = i;
	}
	int fd = open("Myfifo" , O_WRONLY);
	if(fd < 0)
	{
		printf("open error\n");
		return 0;
	}
	write(fd , buf , N*sizeof(int));
	return 0;
}