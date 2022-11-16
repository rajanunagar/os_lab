#include <bits/stdc++.h>
using namespace std;

void allocationInput(vector<vector<int> > &allocation,int np,int nr){
    for(int i=0;i<np;i++)
        for(int j=0;j<nr;j++)
            cin>>allocation[i][j];
}

void mxrequiredInput(vector<vector<int> > &mxrequired,int np,int nr){
    for(int i=0;i<np;i++)
        for(int j=0;j<nr;j++)
            cin>>mxrequired[i][j];
}

void needInput(vector<vector<int> > &need,vector<vector<int> > &a,vector<vector<int> > &mr,int np,int nr){
    for(int i=0;i<np;i++)
        for(int j=0;j<nr;j++)
            need[i][j] = mr[i][j]-a[i][j];
}

void findAvailable(vector<int> &avb,vector<vector<int> > &alloc,int np,int nr){
    for(int i=0;i<np;i++){
        for(int j=0;j<nr;j++){
            avb[j] -= alloc[i][j];
        }
    }
}

int main(){

    int np; // total proceses
    int nr; // total resources
    cin>>np>>nr;
    vector<int> ri(nr); // initially total instances of resource
    for(int i=0;i<nr;i++){
        cin>>ri[i];
    }
    vector<vector<int> > allocation(np,vector<int>(nr,0));
    vector<vector<int> > mxrequired(np,vector<int>(nr,0));
    vector<vector<int> > need(np,vector<int>(nr,0));
    allocationInput(allocation,np,nr);
    mxrequiredInput(mxrequired,np,nr);
    needInput(need,allocation,mxrequired,np,nr);
    
    vector<int> available = ri;
    findAvailable(available,allocation,np,nr);
    
    vector<int> sequence;

    vector<bool> visited(np,false);
    
    while(true){
        int p = -1;
        for(int i=0;i<np;i++){
            if(!visited[i]){
                int j = 0;
                for(j=0;j<nr;j++){
                    if(need[i][j]>available[j]){
                        break;
                    }
                }
                if(nr==j){
                    p = i;
                    break;
                }
            }
        }
        if(-1 == p){
            break;
        }
        visited[p] = true;
        sequence.push_back(p);
        for(int i=0;i<nr;i++){
            available[i] += need[p][i];
        }
    }

    cout<<"output:"<<endl;
    if(sequence.size()==np){
        cout<<"Deadlock not occured"<<endl;
    }else{
        cout<<"Deadlock occured"<<endl;
    }
    for(int i=0;i<sequence.size();i++){
        cout<<"P"<<sequence[i]+1<<" ";
    }
    cout<<endl;
    return 0;
}

//input:
/*
5 3
10 5 7
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
*/
/*
output:
Deadlock not occured
P2 P4 P5 P1 P3 
*/