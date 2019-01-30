#include<bits/stdc++.h>
using namespace std;
int semaphore,full,empty=5;
int num_p,num_c;

int wait(int s){
	return --s;
}
int signal(int s){
	return ++s;
}

void produce(){
	if(empty==0)
		printf("Buffer full\n");
	else{
		printf("An item produce\n");
		empty--;
		full++;
	}
}
void consume(){
	if(full==0)
		printf("Buffer empty\n");
	else{;
		printf("An item cosume\n");
		full--;
		empty++;

	}
}

int main()
{
	int d,active_p=0,active_c=0;
	cout<<"1) starting a producer process\n2) to produce\n3) to stop recently started producer process\n4) start a consumer process\n5) to consume\n6)stop a recent consumer\n";
	while(1){
		cin>>d;
		// printf("semaphore=%d\n",semaphore);
		if(d==1){
			if(active_c==0){
				active_p++;
				printf("%d producers are running\n",active_p);
			}
			else
				printf("A consumer process is alreay running\n");
		}
		if(d==2){
			if(active_p>0)
				produce();
			else
				printf("cannot produce\n");
		}
		if(d==3){
			if(active_p==0)
				printf("No process to terminate");
			else{
				active_p--;
				printf("%d producers are running\n",active_p);
			}
		}
		if(d==4){
			if(active_p==0)
			{
				active_c++;
				printf("%d consumers are running\n",active_c);
			}
			else{
				printf("A producer process is already running\n");
			}
		}
		if(d==5){
			if(active_c>0)
				consume();
			else
				printf("cannot consume\n");
		}
		if(d==6){
			if(active_c>0)
			{
				active_c--;
				printf("%d consumers are running\n",active_c);
			}
			else{
				printf("No process to terminate\n");
			}
		}
	}
}