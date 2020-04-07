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
  
