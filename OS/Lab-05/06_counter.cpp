#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <pthread.h>
#include<bits/stdc++.h>
using namespace std;
int counter=0;
void *f1(void *t){
	counter ++;
	cout<<"Thread Started :-\n";
	cout<<counter<<endl;
	cout<<"Thread Terminated :-\n";
}

int main(int argc, char *argv[] ){
	counter = 0;
	pthread_t t1,t2,t3,t4,t5,t6;
	pthread_create(&t1,NULL,f1,NULL);
	pthread_create(&t2,NULL,f1,NULL);
	pthread_create(&t3,NULL,f1,NULL);
	pthread_create(&t4,NULL,f1,NULL);
	pthread_create(&t5,NULL,f1,NULL);
	pthread_create(&t6,NULL,f1,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	pthread_join(t4,NULL);
	pthread_join(t5,NULL);
	pthread_join(t6,NULL);

	cout<<"Hello from main"<<endl;
	return 0;
}


