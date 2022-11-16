#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <pthread.h>
#include <semaphore.h>
#include<bits/stdc++.h>
using namespace std;

int counter=0;
sem_t s;
void *f1(void *t){
    sem_wait(&s);
    counter ++;
	cout<<"Thread Started :-\n";
	cout<<counter<<endl;
	cout<<"Thread Terminated :-\n";
    sem_post(&s);
}

int main(int argc, char *argv[] ){
    sem_init(&s,0,1);
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