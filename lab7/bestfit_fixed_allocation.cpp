#include<bits/stdc++.h>
using namespace std;
int main(){
	int bnum,pnum;
	printf("Enter no. of blocks and no. of process:");
	cin>>bnum>>pnum;
	int bsize[bnum],psize[pnum],blockno[pnum],bstatus[bnum];
	printf("Enter block sizes:");

	for(int i=0;i<bnum;++i){
		cin>>bsize[i];
		bstatus[i]=0;
	}
	printf("Enter Process sizes:");
	for(int i=0;i<pnum;++i){
		cin>>psize[i];
		blockno[i]=0;
	}
	for(int i=0;i<pnum;++i){
		int min_block=INT_MAX,min_idx=-1;
			for(int j=0;j<bnum;++j){
				if(bstatus[j]==0){
					if(bsize[j]>=psize[i]&&bsize[j]<min_block){
						blockno[i]=j+1;
						min_block=bsize[j];
						min_idx=j;
					}
				}
				else{
					if(blockno[i]==0&&bsize[j]>=psize[i])
						blockno[i]=-1;
				}

			}
			if(min_idx>=0){
				bsize[min_idx]=bsize[min_idx]-psize[i];
				bstatus[min_idx]=1;
			}
		}
	printf("\nProcess No.\tProcess size\tBlock no.\tfragmentation\n");
	for(int i=0;i<pnum;++i){
		if(blockno[i]>0)
			cout<<i+1<<"\t\t"<<psize[i]<<"\t\t"<<blockno[i]<<"\t\tNone\n";
		else{
			if(blockno[i]==-1){
				cout<<i+1<<"\t\t"<<psize[i]<<"\t\t"<<"Not Allocated\t"<<"Internal fragmentation\n";
			}
			else
				cout<<i+1<<"\t\t"<<psize[i]<<"\t\t"<<"Not Allocated\t"<<"External fragmentation\n";
		}
	}
}