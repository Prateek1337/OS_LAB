#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <bits/stdc++.h>
using namespace std; 
#define MAX_SEC 1000000
int readcount;
sem_t mutex,wrt;
void *myread(void *id){
	int temp=rand()%3+1;
	for(int i=0;i<temp;++i){
		int tim=rand()%MAX_SEC;
		usleep(tim);
		sem_wait(&mutex);
		readcount++;
		if(readcount==1)
			sem_wait(&wrt);
		sem_post(&mutex);
		printf("Reader %d is reading...\n",*(int *)id);
		tim=rand()%MAX_SEC;
		usleep(tim);
		sem_wait(&mutex);
		readcount--;
		printf("Reader %d is idle\n",*(int *)id);
		if(readcount==0)
			sem_post(&wrt);
		sem_post(&mutex);
	}
}

void *mywrite(void *id){
	int temp=rand()%3+1;
		for(int i=0;i<temp;++i){
		int tim=rand()%MAX_SEC;
		usleep(tim);
		sem_wait(&wrt);
		printf("Writer %d is writing..\n",*(int *)id);
		tim=rand()%MAX_SEC;
		usleep(tim);
		sem_post(&wrt);
		printf("Writer %d is idle\n",*(int *)id);
	// 	printf("Writer %d is idle\n",*(int *)id);
	}
}

int main(){
	int n,m;
	printf("Enter number of readers and  writers:");
	cin>>n>>m;
	pthread_t reader[n],writer[m];
	int id[100];
	for(int i=0;i<100;++i)
		id[i]=i+1;
	sem_init(&mutex,0,1);
	sem_init(&wrt,0,1);
	for(int i=0;i<n;++i){
		pthread_create(&reader[i],NULL,myread,&id[i]);
	}
	for(int i=0;i<m;++i){
		pthread_create(&writer[i],NULL,mywrite,&id[i]);
	}
	for(int i=0;i<n;++i){
		pthread_join(reader[i],NULL);
	}
	for(int i=0;i<m;++i){
		pthread_join(writer[i],NULL);
	}
	sem_destroy(&mutex);
	sem_destroy(&wrt);
}