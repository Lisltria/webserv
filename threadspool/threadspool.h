#ifndef _THREADSPOLL_H_
#define _THREADSPOLL_H_


#include <iostream>

#include <unistd.h>
#include <pthread.h>

#include <vector>
#include <queue>

class threadpool{
	typedef struct{
		void 	(*function)(void *);
		void 	*args;
	}threadpool_task_t;

	pthread_mutex_t 		mutexlock;
	pthread_cond_t 			notify;
	std::vector<pthread_t> 	threads;
	std::queue<threadpool_task_t> enqueue;

	int thread_cnt;
	int queue_sz;
	
	bool shutdown;

	bool threadpool_create(int , int , bool );
	static void *thread_worker(void *pool);
		
public:
	threadpool():shutdown(false){
		if(threadpool_create(3, 10, false) == false)
			std::cout << "pthread create fail" << std::endl;
		thread_cnt = 3;
		queue_sz = 10;
	}
	threadpool(int thread_count = 3, int queue_size = 10, bool flag = false):shutdown(false){
		if(threadpool_create(thread_count, queue_size, flag) == false)
			std::cout << "pthread create fail" << std::endl;
		thread_cnt = thread_count;
		queue_sz = queue_size;
	}
	
	bool threadpool_add(void (*function)(void *), void *argument, bool flag);
	bool threadpool_destrory(bool flag);
	~threadpool(){
		if(threadpool_destrory(true)){
			std::cout<<"Thread pool destroy!"<<std::endl;
		}else
			std::cout<<"Fail to destroy!"<<std::endl;

	}



};


#endif
