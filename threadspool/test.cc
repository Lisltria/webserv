#include "threadspool.h"
#include <iostream>
using namespace std;
void fun(void *arg){
	cout<<"fun0 running!"<<endl;
}
void fun1(void *arg){
	cout<<"fun1 running!"<<endl;
}
void fun2(void *arg){
	cout<<"fun2 running!"<<endl;
}
int main(){
	threadpool *poolx = new threadpool(3, 10, true);
	if(!poolx->threadpool_add(&fun, NULL, true))
		cout << "fail1" << endl;
	if(!poolx->threadpool_add(&fun1, NULL, true))
		cout << "fail2" << endl;
	if(!poolx->threadpool_add(&fun2, NULL, true))
		cout << "fail3" << endl;
	sleep(1);
	poolx->~threadpool();	
	delete poolx;
	poolx = NULL;
	
	return 0;
}
