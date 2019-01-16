#include<bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<b;++i)

using namespace std;


void printall(int n, vector< pair<int,int> > arrivalBurst)
{
	sort(arrivalBurst.begin(),arrivalBurst.end());
	int wait[n],completion[n],wait1[n];
	completion[0] = 0;
	int tat[n];
	wait1[0] = arrivalBurst[0].first;
	tat[0]=arrivalBurst[0].second;
	float twt=0,ttat=0;
	f(i,1,n+1)
	{	
		completion[i] = completion[i-1]+arrivalBurst[i].second;
		if(arrivalBurst[i].first>completion[i-1])
			completion[i]+=arrivalBurst[i].first-completion[i-1];
		tat[i] = completion[i]-arrivalBurst[i].first;
		wait1[i] = tat[i]-arrivalBurst[i].second;
		ttat += tat[i];
		twt += wait1[i];

	}
	ttat =(float)ttat/n;
	twt =(float)twt/n;
	cout<<"process no\t"<<"arrival no\t"<<"burst time\t"<<"completion time\t\t"<<"turn around time\t"<<"waiting time\n";	
	
	for(int i=1;i<=n;++i)
	{
		if(arrivalBurst[i].first>completion[i-1])
			printf("ideal\n");
			cout<<i<<"\t\t"<<arrivalBurst[i].first<<"\t\t"<<arrivalBurst[i].second<<"\t\t"<<completion[i]<<"\t\t\t"<<tat[i]<<"\t\t\t"<<wait1[i]<<"\n";
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
	vector< pair<int ,int> > arrivalBurst(n+1);
	f(i,1,n+1)
	{
		cin>>arrival>>burst;
		arrivalBurst[i].first = arrival;
		arrivalBurst[i].second = burst;
	}
	printall(n,arrivalBurst);
}
