// reader have priority

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <pthread.h>
#include <semaphore.h>
#include <bits/stdc++.h>
using namespace std;

sem_t write_mutex, read_mutex;
int reader_count;

void *Writer(void *t)
{
    sem_wait(&write_mutex);

    cout << "Writer is Writing" << endl;

    sem_post(&write_mutex);
}

void *Reader(void *t)
{

    sem_wait(&read_mutex);
    reader_count++;
    if (1 == reader_count)
        sem_wait(&write_mutex);
    sem_post(&read_mutex);

    cout << "Reader is Reading " << endl;

    sem_wait(&read_mutex);
    reader_count--;
    if (0 == reader_count)
        sem_post(&write_mutex);
    sem_post(&read_mutex);
}

int main()
{
    reader_count = 0;
    sem_init(&write_mutex, 0, 1);
    sem_init(&read_mutex, 0, 1);

    pthread_t reader1, reader2, reader3, reader4;
    pthread_t writer1, writer2, writer3, writer4;

    pthread_create(&reader1, NULL, Reader, NULL);
    pthread_create(&reader2, NULL, Reader, NULL);
    pthread_create(&reader3, NULL, Reader, NULL);
    pthread_create(&reader4, NULL, Reader, NULL);

    pthread_create(&writer1, NULL, Writer, NULL);
    pthread_create(&writer2, NULL, Writer, NULL);
    pthread_create(&writer3, NULL, Writer, NULL);
    pthread_create(&writer4, NULL, Writer, NULL);

    pthread_join(reader1, NULL);
    pthread_join(reader2, NULL);
    pthread_join(reader3, NULL);
    pthread_join(reader4, NULL);

    pthread_join(writer1, NULL);
    pthread_join(writer2, NULL);
    pthread_join(writer3, NULL);
    pthread_join(writer4, NULL);

    return 0;
}