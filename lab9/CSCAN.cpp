#include<bits/stdc++.h>
using namespace std;
pair<int,int> request[100];
int curr_head,last_head;


void CSCANF(int n){
	int moved;
	sort(request,request+n);
	for(int i=0;i<n;++i){
		if(request[i].first>=curr_head)
			printf("%d\t\t\t%d\n",request[i].second,request[i].first);
	}
	for(int i=0;i<n;++i){
		if(request[i].first<curr_head)
			printf("%d\t\t\t%d\n",request[i].second,request[i].first);
	}
	moved=2*last_head-curr_head;
	printf("Total distance moved by head=%d\n",moved );
}

void CSCANB(int n){
	int moved;
	sort(request,request+n);
	for(int i=n-1;i>=0;--i){
		if(request[i].first<curr_head)
			printf("%d\t\t\t%d\n",request[i].second,request[i].first);
	}
	for(int i=n;i>=0;--i){
		if(request[i].first>=curr_head)
			printf("%d\t\t\t%d\n",request[i].second,request[i].first);
	}
	moved=2*last_head-curr_head;
	printf("Total distance moved by head=%d\n",moved );
}


int main(){
	int n;
	printf("Enter Number of requests\n");
	cin>>n;
	printf("Enter Request's seek position\n");
	for(int i=0;i<n;++i){
		int t;
		cin>>t;
		request[i]=make_pair(t,i);
	}
	printf("Enter current head position and last head position\n");
	cin>>curr_head>>last_head;
	printf("Enter:\n1 for forward scan \n2 for backward scan\n");
	int type;
	cin>>type;
	printf("Request are handled in order\nId\t\tSeek position\n");
	if(type==1)
		CSCANF(n);
	else
		CSCANB(n);
}