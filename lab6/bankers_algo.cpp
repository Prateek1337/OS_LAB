#include<bits/stdc++.h>
using namespace std;
int processes[] = {0, 1, 2, 3, 4};
int avail[] = {3, 3, 2}; 
int maxr[][3] = {{7, 5, 3}, 
                     {3, 2, 2}, 
                     {9, 0, 2}, 
                     {2, 2, 2}, 
                     {4, 3, 3}}; 
int alloc[][3] = {{0, 1, 0}, 
                      {2, 0, 0}, 
                      {3, 0, 2}, 
                      {2, 1, 1}, 
                      {0, 0, 2}}; 
int need[10][10];
int safe[10];
int request[10][10];
bool allfinish(bool finish[],int n){
	int is=true;
	for(int i=0;i<n;++i)
		is=is&&finish[i];
	return is;

}


void safe_sequence(int n,int m){
	int work[m],k=0,maxr_itr=20;
	bool finish[n];
	for(int i=0;i<m;++i)
		work[i]=avail[i];
	for(int i=0;i<n;++i)
		finish[i]=false;
	int i=0,j;
	while((!allfinish(finish,n))&&maxr_itr){
		if(!finish[i]){
			for(j=0;j<m;++j){
				if(need[i][j]>work[j])
					break;
			}
			if(j==m){
				safe[k++]=i;
				finish[i]=true;
				// cout<<"i="<<i<<endl;
				for(j=0;j<m;++j){
					// cout<<need[i][j]<<" "<<work[j]<<endl;
					work[j]+=alloc[i][j];
				}
				// cout<<endl;
			}
		}
		maxr_itr--;
		i++;
		i=i%n;
	}
	cout<<"safe sequence:";
	for(int i=0;i<n;++i)
		cout<<safe[i]<<" ";
	cout<<endl;
}

void handle_request(int n,int m){

	while(true){
		printf("Enter process number \n");
		int i;
		cin>>i;
		printf("Enter process request\n");
		for(int j=0;j<m;++j){
			cin>>request[i][j];
		}
		int j;
			for(j=0;j<m;++j){
				if(request[i][j]>need[i][j]){
					break;
				}
			}
			if(j!=m){
				printf("the process has exceeded its"
					"maximum claim.\n");
				continue;
			}
			
			for(j=0;j<m;++j){
				if(request[i][j]>avail[j]){
					break;
				}
			}
			if(j!=m){
				printf("the process cannot be allocaed memory now.\n");
				continue;
			}
			printf("the process has allocated memory\n");
			for(j=0;j<m;++j){
				avail[j]=avail[j]-request[i][j];
				alloc[i][j]+=request[i][j];
				need[i][j]-=request[i][j];
			}
	}
}



int main(){
	printf("Enter number of process and resourses\n");
	int n,m;
	cin>>n>>m;
	// printf("Enter avaialble for resources\n");
	// for(int i=0;i<m;++i)
	// 	cin>>avail[i];
	// for(int i=0;i<n;++i){
	// 	printf("Enter maxr demand  for process %d\n",i);
	// 	for(int j=0;j<m;++j)
	// 		cin>>maxr[i][j];
	// }
	// for(int i=0;i<n;++i){
	// 	printf("Enter allocated resources  for process %d\n",i);
	// 	for(int j=0;j<m;++j)
	// 		cin>>alloc[i][j];
	// }
	// for(int i=0;i<n;++i){
	// 	for(int j=0;j<m;++j)
	// 		need[i][j]=maxr[i][j]-alloc[i][j];
	// }
	safe_sequence(n,m);

	handle_request(n,m);


}