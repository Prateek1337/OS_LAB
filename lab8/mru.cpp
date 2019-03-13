#include<bits/stdc++.h>
using namespace std;
int ref[20];
int ispage[100];


void print(int slots,int n){
	bool done[100];
	for(int i=0;i<n;++i){
		done[ref[i]]=false;
	}
	for(int i=0;i<n;++i){
		if(ispage[ref[i]]&&done[ref[i]]==false){
			cout<<ref[i]<<" ";
			done[ref[i]]=true;
		}
	}
	cout<<": ";
}

void opr(int n,int slots){
	int faults=0;
	int hit=0;
	int time[100];
	if(n>slots){
		faults=slots;
		for(int i=0;i<slots;++i){
			time[ref[i]]=i;
			ispage[ref[i]]=true;
		}
		printf("Initially all slots are empty —> %d Page faults\n",slots);
		for(int i=slots;i<n;++i){
			print(slots,n);
			int curr=ref[i];
			if(ispage[curr]){
				time[curr]=i;
				printf("%d is already there —> 1 hit\n",curr);
				hit++;
			}
			else{
				int max_time=0;
				int value=-1;
				for(int j=0;j<n;++j)
					if(ispage[ref[j]]&&time[ref[j]]>max_time){
						max_time=time[ref[j]];
						value=ref[j];
					}
				printf("%d is replaced by %d —> 1 Page faults\n",curr,value);
				ispage[curr]=true;
				ispage[value]=false;
				time[curr]=i;
				faults++;
			}
		}
	}
	else
		printf("Initially all slots are empty —> %d Page faults\n",n);

	printf("faults:%d\nhit:%d\n",faults,hit);
}

int main(){
	printf("enter number of slots\n");
	int slots;
	cin>>slots;
	printf("enter number of pages\n");
	int n;
	cin>>n;
	printf("enter page refrences\n");
	for(int i=0;i<n;++i)
		cin>>ref[i];
	opr(n,slots);
}