#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;
int main(){
	pid_t q = fork();
	pid_t q1 = fork();
	if(0<q){
		cout<<"Hello parent"<<endl;
	}
	if(0==q){
		cout<<"Hello child"<<endl;
	}
	return 0;
}
