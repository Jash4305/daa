#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

struct process_struct
{
  int pid;
  int at;
  int bt;
  int ct,wt,tat;
}ps[100];

int findmax(int a, int b)
{
    return a>b?a:b;
}

int findmin(int a, int b)
{
    return a<b?a:b;
}

int main()
{
    int n;
    float bt_remaining[100];
    bool is_completed[100]={false};
    int current_time = 0;
    int completed = 0;;
    float sum_tat=0,sum_wt=0;
    int max_completion_time,min_arrival_time;

    printf("Enter total number of processes: ");
    scanf("%d",&n);   
    for(int i=0;i<n;i++)
    {
        printf("\nEnter Process %d Arrival Time: ",i);
        scanf("%d",&ps[i].at);
        ps[i].pid = i ;
    }
    
    for(int i=0;i<n;i++)
    {
        printf("\nEnter Process %d Burst Time: ",i);
        scanf("%d",&ps[i].bt);
        bt_remaining[i]= ps[i].bt;
    }
   
    while(completed!=n)
    {
        //find process with min. burst time in ready queue at current time
        int min_index = -1;
        int minimum = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(ps[i].at <= current_time && is_completed[i] == false) {
                if(bt_remaining[i] < minimum) {
                    minimum = bt_remaining[i];
                    min_index = i;
                }
                if(bt_remaining[i]== minimum) {
                    if(ps[i].at < ps[min_index].at) {
                        minimum= bt_remaining[i];
                        min_index = i;
                    }
                }
            }
        }
  
        if(min_index==-1)
        {
            current_time++;
        }
        else
        {
            bt_remaining[min_index] -= 1;
            current_time++; 
            if(bt_remaining[min_index] == 0)
            {
                ps[min_index].ct = current_time;
                ps[min_index].tat = ps[min_index].ct - ps[min_index].at;
                ps[min_index].wt= ps[min_index].tat - ps[min_index].bt;
             
                sum_tat +=ps[min_index].tat;
                sum_wt += ps[min_index].wt;
                completed++;
                is_completed[min_index]=true;
            }
        }
    }
    
    //Output
    printf("\nProcess No.\tAT\tCPU Burst Time\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
     printf("%d\t\t%d\t%d\t\t%d\t%d\t%d\n",ps[i].pid,ps[i].at,ps[i].bt,ps[i].ct,ps[i].tat,ps[i].wt);

    printf("\n");    
    
    printf("\nAverage Turn Around time= %f ",(float)sum_tat/n);
    printf("\nAverage Waiting Time= %f ",(float)sum_wt/n);

    return 0;
}   