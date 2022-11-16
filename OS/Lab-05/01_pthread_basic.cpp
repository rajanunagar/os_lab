#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <pthread.h>
#include<bits/stdc++.h>
using namespace std;

void *f1(void *){
	cout<<"Hello from thread!!"<<endl;
}

int main(int argc, char *argv[] ){
	pthread_t t1;
	int n = pthread_create(&t1,NULL,f1,NULL);
//	cout<<n;
	cout<<"Hello from main"<<endl;
	return 0;
}

// here first main thread will terminated, so when thread t1 try to print but main thread is terminated so that we are not getting output from thread.
