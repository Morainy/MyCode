/*************************************************************************
    > File Name: client.cpp
    > Author: Morain
    > Mail: morainchen135@gmail.com 
    > Created Time: 2014年11月26日 星期三 12时10分03秒
 ************************************************************************/

#include <iostream>
#include "RIO.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
using namespace std;

#define MAXLINE 1024
typedef struct sockaddr SA;

void err_quit(const char * str)
{
	cout<<str<<endl;
	exit(-1);
}
int main(int argc, char const *argv[])
{
	int sockfd , n;
	int portNum;
	char buffer[MAXLINE];
	struct sockaddr_in servaddr;

	char hidingMessage[] = "Hello World";
	char sendMessage[MAXLINE];
	memset(sendMessage , 't' , MAXLINE);

	if(argc != 3)
	{
		cout<<"uasge:"<<argv[0]<<"<IPaddress>"
		<<"<portNum>"<<endl;
		exit(-1);
	}
	if( (sockfd = socket(AF_INET , SOCK_STREAM , 0)) < 0)
		err_quit("socket error");

	bzero(&servaddr , sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(atoi(argv[2]) );
	if(inet_pton(AF_INET , argv[1] , &servaddr.sin_addr) <= 0)
		err_quit("inet_pton error");
	
	if(connect(sockfd , (SA*)&servaddr , sizeof(servaddr)) < 0)
		err_quit("connect error");

	cout<<"connect success!!!"<<endl;
	
	char ch;
	char response[10];
	memset(response , 't' , strlen(response) );
	for(int i = 0 ; i < strlen(hidingMessage) ; i++)
	{
		ch = hidingMessage[i];
		n = rio_writen(sockfd , sendMessage , (int)ch);
		//cout<<"write "<<n<<" Bytes data"<<endl;
		n = read(sockfd , response , strlen(response) );
		/*if(strcmp(response , "OK") == 0)
			continue;
		else
			break;*/
		//cout<<"response: "<<n<<" Bytes data:"<<response<<endl;  
	}
	cout<<"Done!"<<endl;
	return 0;
}
