#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "helper.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ECHO_PORT 	(2002)
#define MAX_LINE	(1000)

int main(int argc, char* argv[]){
	int 	list_s;					//监听socket,套接字描述符
	int 	conn_s;					//链接socket
	short 	port;					//端口
	struct 	sockaddr_in servaddr;	//地址格式
	char 	buffer[MAX_LINE];		//缓存
	char 	*endptr;
	
	if( argc == 2){
		port = strtol(argv[1], &endptr, 0);
		if( *endptr ){
			fprintf(stderr, "Error: Invalid port number.\n");
			exit(EXIT_FAILURE);
		}
	}
	else if( argc < 2){
		port = ECHO_PORT;
	}
	else{
		fprintf(stderr, "Error: Invalid arguments.\n");
		exit(EXIT_FAILURE);
	}

	//创建监听socket
	//IPv4, 有序、可靠、双向、面向连接的字节流
	if( ( list_s = socket(AF_INET, SOCK_STREAM, 0) ) < 0 ){
		fprintf(stderr, "Error: Creating listening socket error.\n");
		exit(EXIT_FAILURE);
	}

	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family 		= AF_INET;				//IPv4
	servaddr.sin_addr.s_addr 	= htonl(INADDR_ANY);	//
	servaddr.sin_port 			= htons(port);			//
	
	//Bind socket address to the listening socket and call listen()
	if( bind(list_s, (struct sockaddr* ) &servaddr, sizeof(servaddr)) < 0){
		fprintf(stderr, "Error:Error bind().\n");
		exit(EXIT_FAILURE);
	}

	if( listen(list_s, LISTENQ) < 0){
		fprintf(stderr, "Error:Error listen().\n");
		exit(EXIT_FAILURE);
	}
	int pid;
	while(1){
		// Wait for a connetion, then accept() it
		
		if( (conn_s = accept(list_s, NULL, NULL)) < 0){
			fprintf(stderr, "Error:Error accept().\n");
			exit(EXIT_FAILURE);
		}
		//为每个accept打开一个新进程
		if( ( pid = fork() ) == 0){
			printf("Now pid is: %d\n",getpid());
			Readline(conn_s, buffer, MAX_LINE - 1);
			Writeline(conn_s, buffer, strlen(buffer));

			if(close(conn_s) < 0){
				fprintf(stderr, "Error: Error close().\n");
				exit(EXIT_FAILURE);
			}
		}
		else continue;
	}
	return 1;
}
