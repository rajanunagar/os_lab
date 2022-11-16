#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <pthread.h>
#include<bits/stdc++.h>
using namespace std;

void *f1(void *t){
	cout<<"Hello from thread!!"<<endl;
}

int main(int argc, char *argv[] ){
	pthread_t t1,t2;
	pthread_create(&t1,NULL,f1,NULL);
	pthread_create(&t2,NULL,f1,NULL);
	pthread_join(t1,NULL);
//	pthread_join(t2,NULL);
//	cout<<n;
	cout<<"Hello from main"<<endl;
	return 0;
}

