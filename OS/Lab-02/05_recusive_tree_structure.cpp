#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include<bits/stdc++.h>
using namespace std;

void printDirectory(struct dirent *dirptr){
	if(NULL==dirptr) return;
	
	if(DT_DIR==dirptr->d_type){
		DIR *pt = opendir(dirptr->d_name);
		printDirectory(readdir(pt));
	}else{
		cout<<dirptr->d_name<<endl;
	}
}

int main(int argc, char *argv[] ){
	DIR *pt = opendir("../Lab-01");
	//DIR *pt = opendir(argv[1]);
	if(NULL!=pt){
		struct dirent *dirptr;
		printDirectory(readdir(pt));
	}else{
		cout<<"Path NOT FOUND!!"<<endl;
	}
	return 0;
}
