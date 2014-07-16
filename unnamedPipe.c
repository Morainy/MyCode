#include <unistd.h>
#include <stdio.h>
#define N 1024
#define INPUT 0
#define OUTPUT 1

int main(int argc, char const *argv[])
{
	int buf[N];
	int rtn;
	int i;
	pid_t pid;
	int fileDescribe[2];
	pipe(fileDescribe);
	if((pid = fork()) == -1 )
	{
		printf("fork error\n");
		return 0;
	}
	if(pid  == 0)
	{
		for(i = 0; i<N ; ++i)
		{
			buf[i] = i;
		}
		close(fileDescribe[INPUT]);
		write(fileDescribe[OUTPUT] , buf , N*sizeof(int));
		return 0;
	}
	else
	{
		close(fileDescribe[OUTPUT]);
		read(fileDescribe[INPUT] , buf , N*sizeof(int));
		for(i =0 ; i<N ; i++)
		{
			printf("%d ", buf[i]);
		}
		printf("\n");
	}
	return 0;
}