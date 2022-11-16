#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <pthread.h>
#include<bits/stdc++.h>
using namespace std;

void *f1(void *t){
	cout<<(char *)t<<"\n";
}

int main(int argc, char *argv[] ){
	char s1[] = "Hello from s1";
	char s2[] = "Hello from s2";

	pthread_t t1,t2;
	pthread_create(&t1,NULL,f1,(void*)s1);
	pthread_create(&t2,NULL,f1,(void*)s2);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	cout<<"Hello from main"<<endl;
	return 0;
}
