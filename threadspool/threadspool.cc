#include <iostream>
#include "threadspool.h"
#include <pthread.h>

void *threadpool::
thread_worker(void *pool){
	threadpool 			* ptr = (threadpool* ) pool;
	threadpool_task_t 	task;
	for(;;){
		pthread_mutex_lock(&ptr->mutexlock);
		std::cout<<"working"<<std::endl;
		while(!ptr->shutdown && ptr->enqueue.empty()){
			pthread_cond_wait(&ptr->notify, &ptr->mutexlock);				
		}
		if(ptr->shutdown){
			std::cout<<"shutdown!"<<std::endl;
			break;
		}
		task.function 	= ptr->enqueue.front().function;
		task.args 		= ptr->enqueue.front().args;
		ptr->enqueue.pop();
		pthread_mutex_unlock(&ptr->mutexlock);

		(*(task.function))(task.args);
	}	

	pthread_mutex_unlock(&ptr->mutexlock);
	pthread_exit(NULL);
	return NULL;
}

bool threadpool::
threadpool_create(int thread_count, int queue_size, bool flag){
	if(thread_count < 3) thread_count = 3;
	threads.resize(thread_count);
	thread_cnt = thread_count;

	if(pthread_mutex_init(&mutexlock, NULL) != 0){
		std::cout<<"mutex init fail"<<std::endl;
		return false;
	}
	if(pthread_cond_init(&notify, NULL) != 0){
		std::cout<<"cond init"<<std::endl;
		return false;	
	}

	for(int i = 0 ; i < thread_count; i++){
		if(pthread_create(&(threads[i]), NULL, thread_worker ,(void*)this ) != 0 ){
			std::cout<<"pthread create fail"<<std::endl;
			return false;

		}
	}
	return true;
}

bool threadpool::threadpool_add(void (*function)(void *), void *argument, bool flag){
	bool ret = true;
	threadpool_task_t new_task;
	if(function == NULL)return false;
	if(pthread_mutex_lock(&mutexlock) != 0){
		return false;
	}
	do{
		if(enqueue.size() >= (size_t)queue_sz){
			ret = false;
			break;
		}
		if(shutdown){
			ret = false;
			break;
		}
		new_task.function 	= function;
		new_task.args 		= argument;
		enqueue.push(new_task);
		if(pthread_cond_signal(&notify) != 0){
			ret = false;
			break;
		}

	}while(0);

	if(pthread_mutex_unlock(&mutexlock) !=0){
		ret = false;
	}
	return ret;
}

bool threadpool::threadpool_destrory(bool flag){
	bool ret = true;
	if(pthread_mutex_lock(&mutexlock) != 0){
		return false;
	}
	do{
		if(shutdown){
			ret = false;
			return ret;
			break;
		}
		shutdown = true;
		if(	 pthread_cond_broadcast(&notify) != 0 
		   ||pthread_mutex_unlock(&mutexlock) != 0){
			ret = false;
			break;
		}
		for(size_t i = 0; i < threads.size(); i++){
			if(pthread_join(threads[i],NULL) != 0){
				ret = false;
			}
		}
	}while(0); 
	threads.clear();
	
	pthread_mutex_lock(&mutexlock);
	pthread_mutex_destroy(&mutexlock);
	pthread_cond_destroy(&notify);
	return ret;
}
