
#include <bits/stdc++.h> 
using namespace std; 
  
struct Process { 
    int pid; // Process ID 
    int bt; // Burst Time 
    int art; // Arrival Time 
}; 
int wt[100],tat[100];

void findWaitingTime(Process proc[], int n) 
{ 
    int rt[n]; 
  
    for (int i = 0; i < n; i++) 
        rt[i] = proc[i].bt; 
  
    int complete = 0, t = 0, minm = INT_MAX; 
    int shortest = 0, finish_time; 
    bool check = false; 
  
    while (complete != n) { 

        for (int j = 0; j < n; j++) { 
            if ((proc[j].art <= t) && 
            (rt[j] < minm) && rt[j] > 0) { 
                minm = rt[j]; 
                shortest = j; 
                check = true; 
            } 
        } 
  
        if (check == false) { 
            t++; 
            continue; 
        } 
  
        rt[shortest]--; 
  
        minm = rt[shortest]; 
        if (minm == 0) 
            minm = INT_MAX; 
        if (rt[shortest] == 0) { 
  
            complete++; 
            check = false; 
  
            // Find finish time of current 
            // process 
            finish_time = t + 1; 
  
            // Calculate waiting time 
            wt[shortest] = finish_time - 
                        proc[shortest].bt - 
                        proc[shortest].art; 
  
            if (wt[shortest] < 0) 
                wt[shortest] = 0; 
        } 
        // Increment time 
        t++; 
    } 
} 
  
// Function to calculate turn around time 
void findTurnAroundTime(Process proc[], int n) 
{ 
    // calculating turnaround time by adding 
    // bt[i] + wt[i] 
    for (int i = 0; i < n; i++) 
        tat[i] = proc[i].bt + wt[i]; 
} 
  
// Function to calculate average time 
void findavgTime(Process proc[], int n) 
{ 
    int  total_wt = 0, total_tat = 0; 
  
    findWaitingTime(proc, n); 
  
    // Function to find turn around time for 
    // all processes 
    findTurnAroundTime(proc, n); 
  
    // Display processes along with all 
    // details 
    cout << "Processes "<<" Arrival time "
        << " Burst time "<<" completion time "
        << " Waiting time "
        << " Turn around time\n"; 
  
    // Calculate total waiting time and 
    // total turnaround time 
    for (int i = 0; i < n; i++) { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        cout << " " << proc[i].pid << "\t\t"<<proc[i].art<<"\t\t"
            << proc[i].bt << "\t\t " <<proc[i].art+tat[i]<<"\t\t"<< wt[i] 
            << "\t\t " << tat[i] << endl; 
    } 
  
    cout << "\nAverage waiting time = "
        << (float)total_wt / (float)n; 
    cout << "\nAverage turn around time = "
        << (float)total_tat / (float)n; 
} 
  
// Driver code 
int main() 
{ 
    int n;
    cout<<"Enter number of processes:";
    cin>>n;
    Process proc[n];
    cout<<"Enter process id,arrival time and burst time\n";
    for(int i=0;i<n;++i)
    {
        cin>>proc[i].pid>>proc[i].art>>proc[i].bt;

    } 
    findavgTime(proc, n); 
    return 0; 
} 
