#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[] ){
	char buff[60];
	cout<<getcwd(buff,sizeof(buff))<<endl;
	return 0;
}
