#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include<bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[] ){
	DIR *pt = opendir("../Lab-01");
	//DIR *pt = opendir(argv[1]);
	if(NULL!=pt){
		struct dirent *dirptr;
		while(dirptr = readdir(pt)){
			cout<<dirptr->d_name<<endl;
		}
	}else{
		cout<<"Path NOT FOUND!!"<<endl;
	}
	return 0;
}
