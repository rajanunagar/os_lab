#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[] ){
	int fd1 = open(argv[1],O_RDONLY);
	int fd2 = open(argv[2],O_CREAT|O_WRONLY,S_IRWXG);
	
	char buff1[500];
	int readBytes = read(fd1,buff1,sizeof(buff1));
	cout<<"read bytes :-"<<readBytes<<endl;
	int writtenBytes = write(fd2,buff1,readBytes);
	cout<<"write bytes :-"<<writtenBytes<<endl;
	write(fd2,buff1,15);
	return 0;
}
