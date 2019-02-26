#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<iostream>
using namespace std;
#define MAX_SEC 1000000
sem_t S[100];
int n;
int tim;

void thiking(int idx){
	printf("philopher %d is thinking\n",idx);
	tim=rand()%MAX_SEC;
	usleep(tim);
}

void eating(int idx){
	printf("philopher %d is eating\n",idx);
	tim=rand()%MAX_SEC;
	usleep(tim);
} 


void *philosiphy(void *id){
	int loop=rand()%3+1;
	for(int i=0;i<loop;++i){
		tim=rand()%MAX_SEC;
		usleep(tim);
		int idx=*(int *)id;
		thiking(idx);
		if(idx!=n-1){
			sem_wait(&S[idx]);
			sem_wait(&S[(idx+1)%n]);
		}
		else{
			sem_wait(&S[(idx+1)%n]);
			sem_wait(&S[idx]);
		}
		eating(idx);
		sem_post(&S[idx]);
		sem_post(&S[(idx+1)%n]);
		thiking(idx);
	}

}

int main(){
	printf("Enter number of philophers:");
	cin>>n;
	pthread_t philosphers[n];
	int id[n];
	for(int i=0;i<n;++i){
		sem_init(&S[i],0,1);
		id[i]=i;
	}
	for(int i=0;i<n;++i){
		pthread_create(&philosphers[i],NULL,philosiphy,&id[i]);
	}

	for(int i=0;i<n;++i){
		pthread_join(philosphers[i],NULL);
	}
	for(int i=0;i<n;++i){
		sem_destroy(&S[i]);
	}

}