#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include<bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[] ){
	DIR *p = opendir("../Lab-01" );
	if(NULL==p){
		cout<<"Directory NOT FOUND"<<endl;
	}else{
		cout<<"Directory open!!"<<endl;
	}
	return 0;
}
