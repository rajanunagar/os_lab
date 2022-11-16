// Question :- WAP a program to pass the file name from parent process to child process through a pipe, child process should display the content of the file.

#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;
int main(){
	char message[100];
	int fd[2];
	int p1 = pipe(fd);
	pid_t process = fork();
	if(0<process){
		write(fd[1],"Hello\n",6);
	}
	if(0==process){
		int readed_byte = read(fd[0],message,sizeof(message));
		write(1,message,readed_byte);
	}
	return 0;
}

