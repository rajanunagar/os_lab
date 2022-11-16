#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include<bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[] ){
	DIR *pt = opendir("/proc");
	//DIR *pt = opendir(argv[1]);
	if(NULL!=pt){
		struct dirent *dirptr;
		while(dirptr = readdir(pt)){
			if(atoi(dirptr->d_name)>0){
				string dirname = dirptr->d_name;
				string path = "/proc/"+dirname+"/stat";
				//cout<<path<<endl;

				// reading file
				ifstream fin;
				char paths[path.size()];
				for(int i=0;i<path.size();i++){
					paths[i] = path[i];
				}

				fin.open(paths);
				string line;
				vector<string> info;
				while(fin){
					getline(fin, line);
					break;
				}
				//cout<<line<<endl;
				fin.close();
				string temp;
				for(int i=0,j=0;i<line.length() && j<2;i++)
        		{
            		if(temp[0]=='(' && line[i]==')'){
						temp.push_back(line[i]);
						info.push_back(temp);
						break;
					}else if(line[i]==' '){
						info.push_back(temp);
						temp = "";
						break;
            		}else{
						temp.push_back(line[i]);
					}
        		}
				if(info.size()>=2){
					cout<<"PATH => "<<path<<endl;
					cout<<"PROCESS ID : "<<info[0]<<endl;
					cout<<"PROCESS NAME : "<<info[1]<<endl;
					cout<<"---------------------------------"<<endl;
				}
				
			}
		}
	}else{
		cout<<"Path NOT FOUND!!"<<endl;
	}
	return 0;
}
    
