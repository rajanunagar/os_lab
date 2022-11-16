#include <bits/stdc++.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;
int main(){
	pid_t q = fork();
	if(0<q){
		wait(NULL);
		cout<<"parent ID:- "<<getpid()<<endl;
	}
	if(0==q){
		sleep(3);
		cout<<"child ID:- "<<getpid()<<endl;
		cout<<"child parent ID:- "<<getppid()<<endl;
	}
	return 0;
}
