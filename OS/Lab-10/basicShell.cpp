#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

void printShellStarting(){
    char arr[50];
    getcwd(arr,sizeof(arr));
    cout<<"@adminPc~"<<arr<<">>> ";
}

vector<string> getArgs(string &input){
    vector<string> args;
    for(int i=0;i<input.size();i++){
        string word = "";
        while(i<input.size() and ' '!=input[i]){
            word.push_back(input[i]);
            i++;
        }
        args.push_back(word);
    }
    return args;
}

int main(){
    cout<<endl;
    string input = "";
    vector<string> history;

    while(true){
        printShellStarting();
        getline(cin,input);

        if('\n'==input[0]){
            continue;
        }else{

            vector<string> args = getArgs(input);
            if(1==args.size()){
                if('\n'==input[0]){
                    continue;
                }else if("exit"==args[0]){
                    return 0;
                }else{
                    history.push_back(input);
                    cout<<input<<endl;
                }
            }else{
                for(int i=0;i<args.size();i++){
                    cout<<args[i]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}