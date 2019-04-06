#include<bits/stdc++.h>
using namespace std;

float twt=0,ttat=0;


bool done[100];

bool check(int n)
{
	bool com=true;
	for(int i=1;i<=n;++i)
		com=com&&done[i];
	return com;
}

void PS(int n,vector <pair<int, pair<int ,int> > > arrivalBurst)
{
	// sort(arrivalBurst.begin()+1,arrivalBurst.begin()+n+1,greater<pair<int, pair<int ,int> > >() );
	int t=0;
	int completion[n+1],tat[n+1],wait[n+1];
	int k=15;
	while(!check(n))
	{
		int max_p_index=-1,max_p=0;
		for(int i=1;i<=n;++i)
		{
			// printf("done[i]=%d arrivalBurst[i].first=%d arrivalBurst[i].second.first=%d \n",done[i],arrivalBurst[i].first,arrivalBurst[i].second.first);
			if(done[i]==false&&arrivalBurst[i].first<=t&&arrivalBurst[i].second.first>=max_p)
			{
				max_p=arrivalBurst[i].second.first;
				max_p_index=i;
			}
		}
		// printf("max_p_index=%d  t=%d \n",max_p_index,t);
		if(max_p_index!=-1)
		{
			done[max_p_index]=true;
			t=t+arrivalBurst[max_p_index].second.second;
			completion[max_p_index]=t;
			tat[max_p_index]=completion[max_p_index]-arrivalBurst[max_p_index].first;
			wait[max_p_index]=tat[max_p_index]-arrivalBurst[max_p_index].second.second;
			ttat+=tat[max_p_index];
			twt+=wait[max_p_index];
		}
		else
			t++;
		k--;
	}
	twt=twt/n;
	ttat=ttat/n;
	cout<<"process no\t"<<"arrival no\t"<<"burst time\t"<<"completion time\t\t"<<"turn around time\t"<<"waiting time\n";
	for(int i=1;i<=n;++i)
	{
		cout<<i<<"\t\t"<<arrivalBurst[i].first<<"\t\t"<<arrivalBurst[i].second.second<<"\t\t"<<completion[i]<<"\t\t\t"<<tat[i]<<"\t\t\t"<<wait[i]<<"\n";
	}
	cout<<"average waiting time is:"<<twt<<"\n average turn around time is:"<<ttat<<"\n";
}

int main()
{
	int n,arrival,burst,p;
	cout<<"Enter number of processes:";
	cin>>n;
	// int processes[n];
	// f(i,0,n)
	// {
	// 	processes[i] = i+1;
	// }
	cout<<"Enter arrival time ,burst time and priority\n";
	// int burst[n];
	// int arrival[n];
	vector< pair<int, pair<int ,int> > > arrivalBurst(n+1);
	for(int i=1;i<=n;++i)
	{
		cin>>arrival>>burst>>p;
		arrivalBurst[i].first=arrival;
		arrivalBurst[i].second.first = p;
		arrivalBurst[i].second.second = burst;
	}
	PS(n,arrivalBurst);
}