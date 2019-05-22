#ifndef _HELPER_H_
#define _HELPER_H_

#include <unistd.h>
#define LISTENQ 	(1024)

ssize_t Readline(int fd, void *vptr, size_t maxlen);
ssize_t Writeline(int fc, const void *vptr, size_t maxlen);


#endif


