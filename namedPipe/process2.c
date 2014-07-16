/*************************************************************************
    > File Name: process2.c
    > Author: Morain
    > Mail: morainchen135@gmail.com
    > Created Time: 2014年07月16日 星期三 08时47分34秒
 ************************************************************************/

#include <stdio.h>
#include <fcntl.h>
#define N 1024

int main(int argc, char const *argv[])
{
	int buf[N];
	int fd , i;
	fd = open("Myfifo" , O_RDONLY);
	read(fd , buf , N*sizeof(int));
	for(i = 0; i <N ; ++i )
	{
		printf("%d " , buf[i]);
	}
	return 0;
}