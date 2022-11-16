// 1. Create a blank file: “Test.txt”.
//     Write a program to achieve following:
//     - Print “Hello” message on stdout.
//     - Use dup2 in such a way that file behaves as stdout.
//     - Print “Hello” again to ensure that this time the message goes to file, not to the stdout.

#include <bits/stdc++.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;
int main(){
    write(1,"Hello\n",6);

    int fd = open("Test.txt",O_WRONLY);
    int fd_write = dup2(fd,1);
    write(1,"Hello From Console\n",19);
    cout<<"Hello by cout\n";
    return 0;
}
