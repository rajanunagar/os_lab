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
		cout<<"child1 :- "<<getpid()<<endl;
		cout<<"parent of child1 :- "<<getppid()<<endl;

		pid_t q1 = fork();
		if(0<q1){
			wait(NULL);
		}
		if(0==q1){
			cout<<"child2 :- "<<getpid()<<endl;
			cout<<"parent of child2 :- "<<getppid()<<endl;

			pid_t q2 = fork();
			if(0<q2){
				wait(NULL);
			}
			if(0==q2){
				cout<<"child3 :- "<<getpid()<<endl;
				cout<<"parent of child3 :- "<<getppid()<<endl;

				pid_t q3 = fork();
				if(0<q3){
					wait(NULL);
				}
				if(0==q3){
					cout<<"child4 :- "<<getpid()<<endl;
					cout<<"parent of child4 :- "<<getppid()<<endl;
				}
			}
		}
	}
	return 0;
}

















