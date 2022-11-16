// Question :- create another pipe and the print the values of their file descreptor

#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;
int main(){
	int fd1[2],fd2[2];
	int a1 = pipe(fd1);
	int a2 = pipe(fd2);
	cout<<"Value of File Descriptor 1:- "<<fd1[0]<<" "<<fd1[1]<<" "<<endl;
	cout<<"Value of File Descriptor 2:- "<<fd2[0]<<" "<<fd2[1]<<" "<<endl;
	return 0;
}

