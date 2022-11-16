#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <pthread.h>
#include <semaphore.h>
#include<bits/stdc++.h>
using namespace std;

sem_t s,empty,full;
int n,in,out;
vector<int> buffer;
void *producer(void *t){
    while(true){
        sem_wait(&empty);
        sem_wait(&s);
        buffer[in] = 1;
        in ++;
        in %= n;
        cout<<in<<" producer in critical Section"<<endl;
        sleep(1);
        sem_post(&s);
        sem_post(&full);
    }
}

void *consumer(void *t){
    while(true){
        sem_wait(&full);
        sem_wait(&s);
        buffer[out] = 0;
        out ++;
        cout<<out<<" Consumer in critical Section"<<endl;
        sleep(1);
        out %= n;
        sem_post(&s);
        sem_post(&empty);
    }
}

int main(){
    n=5;
    in = out = 0;
    sem_init(&s,0,1);
    sem_init(&empty,0,n);
    sem_init(&full,0,0);
    
    buffer = vector<int>(n,0);

    pthread_t p;
    pthread_t c;
    
    pthread_create(&p,NULL,producer,NULL);
    pthread_create(&c,NULL,consumer,NULL);
    pthread_join(p,NULL);
    pthread_join(c,NULL);    
    return 0;
}