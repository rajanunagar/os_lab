#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;
int main(){
	pid_t q = fork();
	if(0<q){
		cout<<"parent ID:- "<<getpid()<<endl;
	}
	if(0==q){
		cout<<"child ID:- "<<getpid()<<endl;
		cout<<"child parent ID:- "<<getppid()<<endl;
	}
	cout<<"common child for both :- "<<getpid<<endl;
	cout<<"common parent for both :- "<<getpid<<endl;
	return 0;
}
