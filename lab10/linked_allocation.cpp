#include<bits/stdc++.h>
using namespace std;
int block_size;
int num_blocks;
int blocks[100];

int cal_idx(int sidx,int size){
	if(size%block_size==0)
		return sidx+size/block_size;
	else
		return sidx+size/block_size+1;
}


void print_blocks(){
	printf("\nblock id\t\tblock status\n");
	for(int i=0;i<num_blocks;++i){
		if(blocks[i]==0)
			printf("%d\t\t\tEmpty\n",i);
		else
			printf("%d\t\t\t%d\n",i,blocks[i]);
	}
}

void allocate(int id,int size){
	int arr[100],rem_size=size;
	int i=0;
	while(i<num_blocks&&rem_size>0){
		if(blocks[i]==0){
			rem_size=rem_size-block_size;
		}
		++i;
	}
	// printf("%d\n", i);
	if(i>=num_blocks&&rem_size>0){
		printf("Block cannot be allocated\n");
		print_blocks();
	}
	else{
		while(size>0){
			int idx=rand()%num_blocks;
			if(blocks[idx]==0){
				blocks[idx]=id;
				size=size-block_size;
				// printf("Block is being allocated %d %d\n",size,idx);
			}
		}
		printf("Block is allocated succesfully\n");
		print_blocks();
	}
}



int main(){
	printf("Enter block size\n");
	cin>>block_size;
	printf("Enter Number of blocks\n");
	cin>>num_blocks;
	while(true){
		printf("\nEnter file id and  file size\n");
		int id,size;
		cin>>id>>size;
		allocate(id,size);
	}
}