// 4. Write a program to implement ls | sort functionality.

// 3. Write a program to create a child process that should run pwd command and the parent process should run ls command.


#include <bits/stdc++.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;
int main(){
    pid_t process = fork();
    int fd[2];
    int p1 = pipe(fd);
    if(p1==-1){
        cout<<"Not created"<<endl;
        return 0;
    }
    if(0<process){
        close(fd[1]);
        wait(NULL);
        int rd = dup2(fd[0],0);
        execl("/bin/sort","",NULL);
    }
    if(0==process){
        close(fd[0]);
        int fd2 = dup2(fd[1],1);
        execl("/bin/ls","-l",NULL);
    }
    return 0;
}
  