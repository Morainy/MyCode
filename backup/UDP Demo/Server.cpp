/*************************************************************************
    > File Name: Server.cpp
    > Author: Morain
    > Mail: morainchen135@gmail.com 
    > Created Time: 2014年11月26日 星期三 15时41分39秒
 ************************************************************************/

#include <iostream>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>

using namespace std;

typedef struct sockaddr SA;
typedef unsigned socklen_t;
#define MAXLINE 1024

void err_quit(const char * str)
{
	cout<<str<<endl;
	exit(-1);
}
void process(int sockfd , SA * pcliaddr , socklen_t clilen)
{
	int n;
	socklen_t len;
	char mesg[MAXLINE];
	char respMessage[] = "OK";
	for( ; ; )
	{
		len = clilen;
		n = recvfrom(sockfd , mesg , MAXLINE , 0 , pcliaddr , &len);
		cout<<"received "<<n<<" Bytes data"<<endl;
		cout<<"n's ascii:"<<(char)n<<endl;
		sendto(sockfd , respMessage , strlen(respMessage) , 0 , pcliaddr , len);
	}
}
int main(int argc, char const *argv[])
{
	if(argc != 2)
	{
		cout<<"usage: "<<argv[0]<<"<PortNum>"<<endl;
		exit(-1);
	}
	int sockfd;
	struct sockaddr_in servaddr , cliaddr;
	if( (sockfd = socket(AF_INET , SOCK_DGRAM , 0) ) < 0)
		err_quit("socket error");
	bzero(&servaddr , sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(atoi(argv[1]));

	if (bind(sockfd , (SA*)&servaddr , sizeof(servaddr) ) < 0)
		err_quit("bind error");

	process(sockfd , (SA *) &cliaddr , sizeof(cliaddr));
	return 0;
}