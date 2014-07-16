/*************************************************************************
    > File Name: shmprocess2.c
    > Author: Morain
    > Mail: morainchen135@gmail.com
    > Created Time: 2014年07月16日 星期三 09时42分46秒
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <memory.h>
#define N 1024

int main(int argc, char const *argv[])
{
	key_t key;
	int id , i;
	int * p_buf;

	char pathname[30] ;
	strcpy(pathname,"/tmp") ;
	key = ftok(pathname,0x03);
	
	//key = ftok("." , 1);
	id = shmget(key , 0 ,0);
	p_buf = (int*)shmat(id , NULL ,0);
	for(i = 0 ; i<N ; i++)
	{
		printf("%d ",p_buf[i]);
	}
	printf("\n");
	if((shmdt(p_buf)) == -1 )
	{
		printf("shmdt error \n");
		return -1;
	}
	return 0;
}