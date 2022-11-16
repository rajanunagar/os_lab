#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <pthread.h>
#include<bits/stdc++.h>
using namespace std;

class MyClass{
	public:
	int x,y;
	MyClass(int x,int y){
		this->x = x;
		this->y = y;
	}

};

void *f1(void *t){
	MyClass *mc = (MyClass*)t;
	cout<<mc->x<<" "<<mc->y<<endl;
}

int main(int argc, char *argv[] ){
	
	MyClass *mc = new MyClass(10,20);

	pthread_t t1;
	pthread_create(&t1,NULL,f1,(void*)mc);
	pthread_join(t1,NULL);

	cout<<"Hello from main"<<endl;
	return 0;
}


