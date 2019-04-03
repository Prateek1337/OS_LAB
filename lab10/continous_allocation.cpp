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

void allocate(int id,int sidx,int size){
	int arr[100];
	int s=sidx,f=cal_idx(sidx,size);
	bool  can_allocate=true;
	for(int i=s;i<f;++i){
		if(i>num_blocks||blocks[i]!=0){
			can_allocate=false;
			break;
		}
	}
	if(can_allocate==true){
		for(int i=s;i<f;++i)
			blocks[i]=id;
		printf("File allocated succesfully\n");
		print_blocks();
	}
	else{
		printf("Block cannot be allocated\n");
		print_blocks();
	}
}



int main(){
	printf("Enter block size\n");
	cin>>block_size;
	printf("Enter Number of blocks\n");
	cin>>num_blocks;
	while(true){
		printf("\nEnter file id and starting index and file size\n");
		int id,sidx,size;
		cin>>id>>sidx>>size;
		allocate(id,sidx,size);
	}
}