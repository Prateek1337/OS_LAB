#include<bits/stdc++.h>
using namespace std;
int ref[20];
int ispage[100];

void opr(int n,int slots){
	int faults=0;
	int hit=0;
	if(n>slots){
		faults=slots;
		for(int i=0;i<slots;++i)
			ispage[ref[i]]=true;
		printf("Initially all slots are empty —> %d Page faults\n",slots);
		for(int i=slots;i<n;++i){
			int curr=ref[i];
			if(ispage[curr]){
				printf("%d is already there —> 1 hit\n",curr);
				hit++;
			}
			else{
				int occur[100];
				for(int j=0;j<n;++j){
					occur[ref[j]]=0;
				}
				for(int j=0;j<n;++j){
					occur[ref[j]]=INT_MAX;
				}
				for(int j=i+1;j<n;++j){
					if(occur[ref[j]]==INT_MAX)
						occur[ref[j]]=j;
				}
				int max_occur=0;
				int max_occur_idx=-1;
				for(int j=0;j<n;++j){
					// cout<<ref[j]<<" "<<occur[ref[j]]<<endl;
					if(ispage[ref[j]]==true&&occur[ref[j]]>max_occur){
						max_occur=occur[ref[j]];
						max_occur_idx=ref[j];
					}
				}
				printf("%d is replaced by %d —> 1 Page faults\n",curr,max_occur_idx);
				ispage[curr]=true;
				ispage[max_occur_idx]=false;
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