#include<bits/stdc++.h>
using namespace std;

bool runed[100];
int findminburst(int completion_time,int n,pair< int,pair<int,int> >  arrivalBurstpid[])
{
	int min_j=-1,min_burst=INT_MAX;
	for(int k=1;k<=n;++k)
	{
		if(runed[k]==false&&arrivalBurstpid[k].first<=completion_time&&arrivalBurstpid[k].second.first<min_burst)
		{
			min_burst=arrivalBurstpid[k].second.first;
			min_j=arrivalBurstpid[k].second.second;
		}
	}
	// printf("min_j=%d\n",min_j);
	runed[min_j]=true;
	return min_j;
}

int min_arrival(int n,pair< int,pair<int,int> >   arrivalBurstpid[])
{
	int min_j=-1,minarrival=INT_MAX;
	for(int k=1;k<=n;++k)
	{
		if(runed[k]==false&&arrivalBurstpid[k].first<minarrival)
		{
			minarrival=arrivalBurstpid[k].first;
			min_j=arrivalBurstpid[k].first;
		}
	}
	return min_j;
}

void printall(int n, pair<int ,pair<int,int> >  arrivalBurstpid[])
{
	sort(arrivalBurstpid+1,arrivalBurstpid+n+1);
	int wait[n+1],completion[n+1];
	int current_time=0;
	int tat[n+1];
	float twt=0,ttat=0;
	int i=0;
	while(i!=n)
	{	
		int j=findminburst(current_time,n,arrivalBurstpid);
		if(j!=-1)
		{
			// printf("j=%d\n",j);
			completion[j]=current_time+arrivalBurstpid[j].second.first;
			tat[j] = completion[j]-arrivalBurstpid[j].first;
			wait[j] = tat[j]-arrivalBurstpid[j].second.first;
			ttat += tat[j];
			twt += wait[j];
			current_time=completion[j];
			i++;
		}
		else
		{
			j=min_arrival(n,arrivalBurstpid);
			current_time=arrivalBurstpid[j].first;
		}

	}
	ttat =(float)ttat/n;
	twt =(float)twt/n;
	cout<<"process no\t"<<"arrival no\t"<<"burst time\t"<<"completion time\t\t"<<"turn around time\t"<<"waiting time\n";	
	
	for(int i=1;i<=n;++i)
	{
		if(arrivalBurstpid[i].first>completion[i-1])
			printf("ideal\n");
			cout<<i<<"\t\t"<<arrivalBurstpid[i].first<<"\t\t"<<arrivalBurstpid[i].second.first<<"\t\t"<<completion[i]<<"\t\t\t"<<tat[i]<<"\t\t\t"<<wait[i]<<"\n";
	}
	cout<<"average waiting time is:"<<twt<<"\n average turn around time is:"<<ttat<<"\n";
}
int main()
{
	int n,arrival,burst;
	cout<<"Enter number of processes:";
	cin>>n;
	// int processes[n];
	// f(i,0,n)
	// {
	// 	processes[i] = i+1;
	// }
	cout<<"Enter arrival time and burst time\n";
	// int burst[n];
	// int arrival[n];
	pair<int ,pair<int,int> >  arrivalBurstpid[n+1];
	for(int i=1;i<=n;++i)
	{
		cin>>arrival>>burst;
		arrivalBurstpid[i].first = arrival;
		arrivalBurstpid[i].second.first = burst;
		arrivalBurstpid[i].second.second=i;
	}
	printall(n,arrivalBurstpid);
}
