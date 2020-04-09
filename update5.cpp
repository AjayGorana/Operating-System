#include<iostream> 
using namespace std; 

void WaitingTime(int processes[], int n,int bt[], int wt[], int quantm) 
{ 
     
    int left_bt[n],i; 
    for ( i = 0 ; i <= n-1 ; i++) 
        left_bt[i] =  bt[i]; 
  
    int t = 0; 

    while (1) 
    { 
        bool done = true; 
  
    
        for (i = 0 ; i <=n-1; i++) 
        { 
            
            if (left_bt[i] > 0) 
            { 
                done = false;
  
                if (left_bt[i] > quantm) 
                { 
                   
                    t =t+ quantm; 
  
                    
                    left_bt[i] =left_bt[i]- quantm; 
                } 
  
           


           
                else
                { 
                   
                    t  += left_bt[i]; 
  
                   
                    wt[i] = t - bt[i]; 
  
              
                    left_bt[i] = 0; 
                } 
            } 
        } 
  
 
        if (done == true) 
          break; 
    } 
} 



void TurnAroundTime(int processes[], int n,int bt[], int wt[], int tat[]) 
{ int i;

    for ( i = 0; i <= n-1 ; i++) 
        tat[i] = bt[i] + wt[i]; 
} 
  


 
{ 
    int wt[n], tat[n], total_wt = 0, total_tat = 0; 
  

    WaitingTime(processes, n, bt, wt, quantm); 
  
    
    TurnAroundTime(processes, n, bt, wt, tat); 
  
     
    cout << "Processes "<< " Burst time "
         << " Waiting time " << " Turn around time\n"; 
  
    int i; 
    for ( i=0; i<=n-1; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
             << wt[i] <<"\t\t " << tat[i] <<endl; 
    } 
  
    cout << "average waiting time : "
         << (float)total_wt / (float)n; 
    cout << "\naverage turnaround time : "
         << (float)total_tat / (float)n; 
} 
  
 


int main() 
{   /*process 1= a ,process 2=b,process 3= a ,process 4=b,process 5= a ,process 6=b,
process 7= a ,process 8=b,process 9= a ,process 10=b,*/
   
    int processes[] = {1,2,3,4,5,6,7,8,9,10}; 
    int n = sizeof processes / sizeof processes[0]; 
  
    int burstTime[10]; 
    for(int i=0;i<10;i++)
    {cout<<"enter the burst time of process "<<i+1<<":";
	cin>>burstTime[i];
	}
    int quantm = 2; 
    avgTime(processes, n, burstTime, quantm); 
    return 0; 
} 
