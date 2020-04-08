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
  

void avgTime(int processes[], int n, int bt[],int quantm) 
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
  
 
