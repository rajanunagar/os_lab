#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[] ){
/*
	int fd = open("temp.txt",0);
	char buff[15];
	read(fd,buff,sizeof(buff));
	write(1,buff,15);
*/

// taking file name from console
	
	int fd = open(argv[1],0);
	cout<<argv[1]<<endl;
	char buff[15];
	read(fd,buff,sizeof(buff));
	write(1,buff,15);
	return 0;
}
