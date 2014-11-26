/*************************************************************************
    > File Name: server.cpp
    > Author: Morain
    > Mail: morainchen135@gmail.com 
    > Created Time: 2014年11月26日 星期三 12时10分18秒
 ************************************************************************/

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include "RIO.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <arpa/inet.h>

using namespace std;

#define MAXLINE 1024
#define LISTENQ 1024

typedef struct sockaddr SA;

void err_quit(const char * str)
{
	cout<<str<<endl;
	exit(-1);
}
void sig_child(int signo)
{
	pid_t pid;
	int stat;
	while( (pid = waitpid(-1 , &stat , WNOHANG)) > 0)
		cout<<"child "<<pid<<" terminated"<<endl;
	return;
}
int main(int argc, char const *argv[])
{
	int listenfd , connfd;
	pid_t childPid;
	struct sockaddr_in servaddr;
	
	if(argc != 2)
	{
		cout<<"usage: "<<argv[0]<<" <portNum>"<<endl;
		exit(-1);
	}
	if( (listenfd = socket(AF_INET , SOCK_STREAM , 0) ) < 0)
		err_quit("socket error");
	bzero(&servaddr , sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(atoi(argv[1]));

	if(bind(listenfd , (SA *) &servaddr , sizeof(servaddr)) < 0)
		err_quit("bind error");
	if(listen(listenfd , LISTENQ) < 0)
		err_quit("listen error");
	signal(SIGCHLD , sig_child);

	for( ; ; )
	{
		connfd = accept(listenfd , (SA*) NULL , NULL);
		if(connfd < 0)
			err_quit("accept error");

		if( (childPid = fork()) == 0 )   //child process
		{
			char buffer[MAXLINE];
			close(listenfd);
			size_t n = 0;
			char response[] = "OK";
			for( ; ; )
			{
				n = read(connfd , buffer , MAXLINE);
				if(n <= 0)
					break;
				else
				{
					cout<<"received "<<n<<" Bytes data:"<<endl;
					cout<<"n's ascii: "<<(char)n<<endl;
					n = rio_writen(connfd , response , strlen(response));
					//cout<<"response "<<n<<" Bytes data"<<endl;
				}
			}
			close(connfd);
			exit(0);
		}
		close(connfd);   // parent process
	}
	return 0;
}