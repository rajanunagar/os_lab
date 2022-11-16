#include<bits/stdc++.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>
using namespace std;

int main()
{
    int fd[2];
    int p = pipe(fd);

   if(p == -1)
   {
       printf("Error while creating pipe");
   }
   else
   {
        pid_t q = fork();

        if(q > 0)
        {
            write(fd[1], "test.txt", 11);
            wait(NULL);
            close(fd[1]);
            dup2(fd[0], 0);
            execl("/bin/sort", "", NULL);
        }

        if(q == 0)
        {
            char fbuff[100];
            int frd = read(fd[0], fbuff, sizeof(fbuff));
			cout<<*fbuff<<endl;
            close(fd[0]);
            int file_fd = open(fbuff, O_RDWR);
            char buff[100];
            int rd = read(file_fd, buff, sizeof(buff));
            dup2(fd[1], 1);
            write(1,buff, rd);
            
        }
   }

    return 0;
}
