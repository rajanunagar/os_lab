

#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;
int main(){
	int fd[2];
	int a = pipe(fd);
	cout<<"Value of File Descriptor :- "<<fd[0]<<" "<<fd[1]<<" "<<endl;
	return 0;
}
