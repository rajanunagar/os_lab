#include <bits/stdc++.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;
int main(){
    int fd = open("file1.txt",O_RDONLY); // fd is for file1.txt
    cout<<"Old FD: "<<fd<<endl;
    char content[100];
    int r = read(fd,content,sizeof(content));
    write(1,content,r);
    cout<<endl;

    int newFd1 = dup(fd); // newFd1 is also for file1.txt
    cout<<"New FD1: "<<newFd1<<endl;
    r = read(newFd1,content,sizeof(content));
    write(1,content,r);
    cout<<endl;

    int newFd2 = dup2(fd,3);
    cout<<"New FD2: "<<newFd2<<endl;
    return 0;
}
