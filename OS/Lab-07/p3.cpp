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

    if(0<process){
        wait(NULL);
        execl("/bin/pwd","",NULL);
    }
    if(0==process){
        execl("/bin/ls","-l",NULL);
    }
    return 0;
}
  