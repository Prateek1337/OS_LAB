#include<bits/stdc++.h>
using namespace std;
int main(){
	int bnum,pnum;
	printf("Enter no. of blocks and no. of process:");
	cin>>bnum>>pnum;
	int bsize[bnum],psize[pnum],blockno[pnum],bstatus[bnum];
	printf("Enter block sizes and block status\n");
	for(int i=0;i<bnum;++i){
		cin>>bsize[i];
		cin>>bstatus[i];
	}
	printf("Enter Process sizes:");
	for(int i=0;i<pnum;++i){
		cin>>psize[i];
		blockno[i]=0;
	}
	for(int i=0;i<pnum;++i){
		int min_block=INT_MAX,min_idx=-1;
			for(int j=0;j<bnum;++j){
				if(bstatus[j]==0&&bsize[j]>=psize[i]&&bsize[j]<min_block){
					blockno[i]=j+1;
					min_block=bsize[j];
					min_idx=j;
				}
			}
			if(min_idx>=0){
				bsize[min_idx]=bsize[min_idx]-psize[i];
			}
		}
	printf("\nProcess No.\tProcess size\tBlock no.\tfragmentation\n");
	for(int i=0;i<pnum;++i){
		if(blockno[i])
			cout<<i+1<<"\t\t"<<psize[i]<<"\t\t"<<blockno[i]<<"\t\t"<<"None"<<endl;
		else
			cout<<i+1<<"\t\t"<<psize[i]<<"\t\t"<<"Not Allocated\t"<<"external fragmentation"<<endl;
	}
}