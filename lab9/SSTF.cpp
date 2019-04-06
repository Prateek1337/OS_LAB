#include<bits/stdc++.h>
using namespace std;
int request[100],dis[100];
bool isdone[100];
int head;

void cal_distance(int n){
	for(int i=0;i<n;++i)
		dis[i]=abs(request[i]-head);
}


int find_min(int n){
	int min_dis=INT_MAX,min_idx=-1;
	for(int i=0;i<n;++i){
		if(isdone[i]==false&&dis[i]<min_dis){
			min_dis=dis[i];
			min_idx=i;
		}
	}
	return min_idx;
}

void SSTF(int n){
	int count=0,td=0;
	while(count!=n){
		cal_distance(n);
		int min_distance_idx=find_min(n);
		isdone[min_distance_idx]=true;
		count++;
		td+=abs(head-request[min_distance_idx]);
		head=request[min_distance_idx];
		printf("%d\t\t\t%d\n",min_distance_idx,request[min_distance_idx]);
	}
	printf("Total distance moved by head=%d\n",td);

}


int main(){
	int n;
	printf("Enter Number of requests\n");
	cin>>n;
	printf("Enter Request's seek position\n");
	for(int i=0;i<n;++i)
		cin>>request[i];
	printf("Enter head position\n");
	cin>>head;
	printf("Request are handled in order\nId\t\tSeek position\n");
	SSTF(n);
}