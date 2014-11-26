/*************************************************************************
    > File Name: Client.cpp
    > Author: Morain
    > Mail: morainchen135@gmail.com 
    > Created Time: 2014年11月26日 星期三 15时41分32秒
 ************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
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

void dg_cli(FILE * fp , int sockfd , const SA* pservaddr , socklen_t servlen)
{
	int n;
	char hidingMessage[] = "Hello World";
	char sendMessage[MAXLINE] , respMessage[10];
	memset(sendMessage ,'t' , MAXLINE);
	for(int i = 0 ;  i < strlen(hidingMessage) ; i++)
	{
		sendto(sockfd , sendMessage , (int)hidingMessage[i] , 0 , pservaddr , servlen); 
		n = recvfrom(sockfd , respMessage , strlen(respMessage) , 0 , NULL , NULL);
		respMessage[n] = 0;
		//cout<<"respMessage= "<<respMessage<<endl;
	}
	cout<<"Done!"<<endl;
}
int main(int argc, char const *argv[])
{
	int sockfd;
	struct sockaddr_in servaddr;

	if(argc != 3)
	{
		cout<<"usage:"<<argv[0]<<"<IPAddress>"<<"<portNum>"<<endl;
		exit(-1);
	}

	bzero(&servaddr , sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(atoi(argv[2]));
	inet_pton(AF_INET , argv[1] , &servaddr.sin_addr);

	sockfd = socket(AF_INET , SOCK_DGRAM , 0);
	if(sockfd < 0)
		err_quit("socket error");

	dg_cli(stdin , sockfd , (SA*)&servaddr , sizeof(servaddr));
	
	return 0;
}
