#include<bits/stdc++.h>
using namespace std;

struct node
{
	int idx;
	int arrival;
	int burst;
};

bool done[100];
bool check(int n)
{
	bool com=true;
	for(int i=1;i<=n;++i)
		com=com&&done[i];
	return com;
}

void round_robin(int n,struct node arrivalBurst)
{
	Queue<struct node> q;
	vector<struct node> v;
	int t=0;
	do{
		int check=false;
		for(int i=1;i<=n;++i)
		{
			if(done[i]==false&&arrivalBurst[i].arrivalBurst<=t)
			{
				check=true;
				v.push_back(arrivalBurst[i]);
			}
		}
		if(!check)
			t++;
		else
		{
			sort(v.begin(),v.end());
			for(vector<int>::iterator itr=v.begin();itr!=v.end();itr++)
			{
				q.push(*itr);
			}
		}

	}
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
	cout<<"Enter arrival time ,burst time \n";
	// int burst[n];
	// int arrival[n];
	struct node arrivalBurst[n+1];
	for(int i=1;i<=n;++i)
	{
		cin>>arrival>>burst;
		arrivalBurst[i].arrival=arrival;
		arrivalBurst[i].burst=burst;
	}
	round_robin(n,arrivalBurst);
}