#include<stdio.h> 
#include<stdlib.h>
void findWaitingTime(int processes[], int n,  
                          int bt[], int wt[]) 
{ 
    for (int  i = 1; i < n ; i++ ) 
        wt[i] =  bt[i-1] + wt[i-1] ; 
} 
void findTurnAroundTime( int processes[], int n,  
                  int bt[], int wt[], int tat[]) 
{ 
    for (int  i = 0; i < n ; i++) 
        tat[i] = bt[i] + wt[i]; 
} 
void findavgTime( int processes[], int n, int bt[]) 
{ 
     int*wt =(int*)malloc (n*sizeof(int));
      int*tat =(int*)malloc (n*sizeof(int));
       int total_wt =0,total_tat =0;
       
       findWaitingTime(processes,n,bt,wt);
       findTurnAroundTime(processes,n,bt,wt,tat);
    printf("Processes   Burst time   Waiting time   Turn around time\n"); 
  for (int  i=0; i<n; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        printf("   %d ",(i+1));
        printf("       %d ", bt[i] );
        printf("       %d",wt[i] );
        printf("       %d\n",tat[i] ); 
    } 
    float s=(float)total_wt / (float)n;
    float t=(float)total_tat / (float)n;
    printf("Average waiting time = %f",s);
    printf("Average turn around time = %f ",t); 
    free (wt);
    free(bt);
} 
int main() 
{
    int n;
    printf ("enter the processes :");
    scanf("%d,&n");
    int*burst_time =(int*)malloc (n*sizeof(int));
    int*processes=(int*)malloc(n*sizeof(int));
    
    printf("enter the burst time of each processes:\n");
    for (int i = 0; i <n; i++) 
    {
     processes[i]=i+1;
     printf("Burst time for processes %d :",i+1);
     scanf("%d",&burst_time);
     
    }
    findavgTime(processes,n,burst_time);
       free(burst_time);
       free(processes);
  
    return 0; 
} 
