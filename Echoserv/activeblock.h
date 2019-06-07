#ifndef _ACTIVEBLOCK_H_
#define _ACTIVEBLOCK_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define ERR_EXIT(m)\
	do{\
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

void activate_nonblock(int fd);
void deactivate_nonblock(int fd);

#endif
