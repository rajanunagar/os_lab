#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <pthread.h>
#include<bits/stdc++.h>
using namespace std;

class Calculator{
	private:
	int x,y;
	public:
	Calculator(int x,int y){
		this->x = x;
		this->y = y;
	}
	
	int Addition(){
		return this->x+this->y;
	}
	int subtraction(){
		return this->x-this->y;
	}
	int multiplication(){
		return this->x*this->y;
	}
	int division(){
		return this->x/this->y;
	}
};

void *addition(void *t){
	Calculator *calc = (Calculator*)t;
	cout<<"Sum of two numbers is :- "<<calc->Addtion()<<endl;
}

void *subtraction(void *t){
	Calculator *calc = (Calculator*)t;
	cout<<"Subtraction of two numbers is :- "<<calc->subtraction()<<endl;
}
void *multiplication(void *t){
	Calculator *calc = (Calculator*)t;
	cout<<"Multiplication of two numbers is :- "<<calc->multiplication()<<endl;
}
void *division(void *t){
	Calculator *calc = (Calculator*)t;
	cout<<"Division of two numbers is :- "<<calc->division()<<endl;
}


int main(int argc, char *argv[] ){
	
	Calculator *calc = new Calculator(50,20);

	pthread_t add,sub,mul,div;
	pthread_create(&add,NULL,addition,(void*)calc);
	pthread_create(&sub,NULL,subtraction,(void*)calc);
	pthread_create(&mul,NULL,multiplication,(void*)calc);
	pthread_create(&div,NULL,division,(void*)calc);
	pthread_join(add,NULL);
	pthread_join(sub,NULL);
	pthread_join(mul,NULL);
	pthread_join(div,NULL);

	cout<<"Hello from main"<<endl;
	return 0;
}


