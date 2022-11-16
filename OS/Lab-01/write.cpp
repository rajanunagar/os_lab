#include <unistd.h>
#include <bits/stdc++.h>
using namespace std;
int main(){

	int total_bytes = write(1,"hello",5);
	cout<<"\ntotal bytes :- "<<total_bytes<<endl;
	return 0;
}
