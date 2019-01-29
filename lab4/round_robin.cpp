#include<bits/stdc++.h>
using namespace std;

struct node
{
	int idx;
	int arrival;
	int burst;
};

bool inq[100];
queue<struct node> q;
int burstarr[100],completed[100],tat[100],wait[100];
float twt,ttat;
bool check(int n)
{
	bool com=true;
	for(int i=1;i<=n;++i)
		com=com&&inq[i];
	return com&&q.empty();
}
bool compare(const struct node &a, const struct node &b)
{
    return a.arrival < b.arrival;
}
void print(queue<struct node> sq){
	while(!sq.empty())
	{
		cout<<sq.front().idx<<" ";
		sq.pop();
	}
	cout<<endl;
}

void round_robin(int n,struct node arrivalBurst[],int quantum)
{
	vector<struct node> v;
	int t=-1;
	do{
		bool over=false,qcheck=false;
		struct node current;
		// print(q);
		if(!q.empty()){
			qcheck=true;
			current=q.front();
			q.pop();
			if(current.burst<=quantum){
				t=t+current.burst;
				completed[current.idx]=t;
				over=true;
				current.burst=0;
			}
			else{
				current.burst=current.burst-quantum;
				t=t+quantum;
			}
		}
		else
			t++;
		for(int i=1;i<=n;++i)
		{
			if(inq[i]==false&&arrivalBurst[i].arrival<=t)
			{
				v.push_back(arrivalBurst[i]);
				inq[i]=true;
			}
		}
		sort(v.begin(),v.end(),compare);
		for(vector<struct node>::iterator itr=v.begin();itr!=v.end();itr++){
			q.push(*itr);
		}
		// if(!qcheck)
		// 	t++;
		if((!over)&&qcheck){
			q.push(current);
		}
		v.clear();
	}while(!check(n));

	for(int i=1;i<=n;++i)
		{
			tat[i]=completed[i]-arrivalBurst[i].arrival;
			ttat+=tat[i];
			wait[i]=tat[i]-arrivalBurst[i].burst;
			twt+=wait[i];
		}
		ttat/=n;
		twt/=n;
	cout<<"process no\t"<<"arrival no\t"<<"burst time\t"<<"completion time\t\t"<<"turn around time\t"<<"waiting time\n";
	for(int i=1;i<=n;++i)
	{
		cout<<i<<"\t\t"<<arrivalBurst[i].arrival<<"\t\t"<<burstarr[i]<<"\t\t"<<completed[i]<<"\t"<<"\t\t\t"<<tat[i]<<"\t\t\t"<<wait[i]<<"\n";
	}
	cout<<"average waiting time is:"<<twt<<"\n average turn around time is:"<<ttat<<"\n";
}




int main()
{
	int n,arrival,burst,q;
	cout<<"Enter number of processes and time quantum:";
	cin>>n>>q;
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
		arrivalBurst[i].idx=i;
		arrivalBurst[i].arrival=arrival;
		arrivalBurst[i].burst=burst;
		burstarr[i]=burst;
	}
	round_robin(n,arrivalBurst,q);
}