#include <bits/stdc++.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;
int main(){
	pid_t q = fork();
	if(0<q){
		wait(NULL);

		pid_t ch1 = fork();
		if(0==ch1){
			sleep(4);
			cout<<"child1 ID:- "<<getpid()<<endl;
		}else{
			pid_t ch2 = fork();
			if(0==ch2){
				sleep(3);
				cout<<"child2 ID:- "<<getpid()<<endl;
			}else{
				pid_t ch3 = fork();
				if(0==ch3){
					sleep(2);
					cout<<"child3 ID:- "<<getpid()<<endl;
				}else{
					pid_t ch4 = fork();
					if(0==ch4){
						sleep(1);
						cout<<"child4 ID:- "<<getpid()<<endl;
					}
				}
			}
			
		}
		
	}else{
		cout<<"parent ID:- "<<getppid()<<endl;
	}
	
	return 0;
}
