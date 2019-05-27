#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>

#include <vector>
#include <algorithm>
#include <sys/epoll.h>

#include "helper.h"
#include "activeblock.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fcntl.h>
#define ECHO_PORT 	(2002)
#define MAX_LINE	(1000)

typedef std::vector<struct epoll_event> Eventlist;

int main(int argc, char* argv[]){
	int 	list_s;					//监听socket,套接字描述符
	short 	port;					//端口
	struct 	sockaddr_in servaddr;	//地址格式
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

	std::vector<int> clients;
	int epollfd;
	epollfd = epoll_create1(EPOLL_CLOEXEC);
	struct epoll_event event;
	event.data.fd = list_s;
	event.events = EPOLLIN | EPOLLET;
	epoll_ctl(epollfd, EPOLL_CTL_ADD, list_s, &event);

	Eventlist events(16);
	struct sockaddr_in peeraddr;
	socklen_t peerlen;
	int conn;
	int i;
	int count = 0;
	int nready;


	while(1){
		nready = epoll_wait(epollfd, &*events.begin(), static_cast<int>(events.size()),-1);
		if(nready == -1){
			if(errno == EINTR){
				continue;
			}
			else exit(EXIT_FAILURE);
		}
		if(nready == 0){
			continue;
		}

		if(size_t(nready) == events.size()){
			events.resize(nready * 2);
		}

		for(i = 0; i < nready; i++){
			if(events[i].data.fd == list_s){
				peerlen = sizeof(peeraddr);
			
				conn = accept(list_s, (struct sockaddr *)&peeraddr, &peerlen);
				if(conn == -1) exit(EXIT_FAILURE);
				printf("ip = %s, port = : %d\n", inet_ntoa(peeraddr.sin_addr), 
												 ntohs(peeraddr.sin_port));
				printf("cnt = :%d\n", ++count);
				clients.push_back(conn);
				activate_nonblock(conn);
				event.data.fd = conn;
				event.events = EPOLLIN | EPOLLET;
				epoll_ctl(epollfd, EPOLL_CTL_ADD, conn, &event);
			}
			else if(events[i].events & EPOLLIN){
				conn = events[i].data.fd;
				if( conn < 0)continue;

				char recvbuf[1024] = {0};
				int ret = Readline(conn, recvbuf, 1024);
				if(ret == -1){
					ERR_EXIT("readline\n");
				}
				if(ret == 0){
					printf("Client close\n");
					close(conn);

					event = events[i];
					epoll_ctl(epollfd, EPOLL_CTL_DEL, conn, &event);
					clients.erase(
							std::remove(clients.begin(), clients.end(), conn), 
							clients.end());
				}

				fputs(recvbuf, stdout);
				Writeline(conn, recvbuf, strlen(recvbuf));
			}
		}

	}
/*

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
	}*/
	return 1;
}
