/*************************************************************************
    > File Name: shmprocess1.c
    > Author: Morain
    > Mail: morainchen135@gmail.com
    > Created Time: 2014年07月16日 星期三 09时42分40秒
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
	int * p_map;

	char pathname[30] ;
	strcpy(pathname,"/tmp") ;
	key = ftok(pathname,0x03);

	//key = ftok("." , 1);
	id = shmget(key , N*sizeof(int) , IPC_CREAT|IPC_EXCL|0600);
	if(id == -1)
	{
		printf("shmget error\n");
		return -1;
	}
	p_map = (int*) shmat(id , NULL , 0);
	memset(p_map , 0x0 , N*sizeof(int));
	for(i = 0 ; i< N ; i++)
	{
		p_map[i] = i;
	}

	if((shmdt(p_map)) == -1)
	{
		printf("shmdt error\n");
		return -1;
	}
	return 0;
}