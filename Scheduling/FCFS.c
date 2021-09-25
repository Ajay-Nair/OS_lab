#include<stdio.h>
struct Process
{
    char name[10];
    int arrival;
    int burst;
    int complete;
    int start;
    int tt;
    int wt;
}p[10],temp;

void main()
{
    int n;
    printf("enter number of process:");
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
    {
        printf("Enter process name: ");
        scanf("%s",p[i].name);
        printf("\nEnter arrival time: ");
        scanf("%d",&p[i].arrival);
        printf("\nEnter burst time: ");
        scanf("%d",&p[i].burst);
    }
    //Sorting according to arrival time
    for(int i = 0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(p[i].arrival>p[j].arrival)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;

            }
        }
    }
    //Find completion time and start of each process
    int m = 0;
    for(int i = 0;i<n;i++)
    {
        if(p[i].arrival<m)
        {
            p[i].complete =  p[i].burst + m ;
        }
        else
        {
            p[i].complete = p[i].burst + p[i].arrival;
        }
        m = p[i].complete;

        p[i].start = p[i].complete - p[i].burst; 
    }

    //Find turnaroundtime and waiting  time
    int sum_wt=0,sum_tt=0;
    for(int i=0;i<n;i++)
    {
        p[i].tt = p[i].complete - p[i].arrival;
        p[i].wt = p[i].tt - p[i].burst;
        sum_wt = sum_wt + p[i].wt;
        sum_tt = sum_tt + p[i].tt;
    }
    
    //Printing
    printf("| Name | Arrival Time | Burst Time | Waiting Time | Turn Around Time | Completion Time \n");
    for(int i = 0;i<n;i++)
    {
        printf("|%s    |%d             |%d           |%d               |%d               |%d               \n",p[i].name,p[i].arrival,p[i].burst,p[i].wt,p[i].tt,p[i].complete);
    }

    /*
    printf("Gantt Chart");
    for(int i =0;i<n;i++)
    {
        printf("|%s",p[i].name);
        for(int j = 0;j<p[i].complete;j++)
        {
            if(j == p[i].start)
            {
                printf("|%d-",p[i].start);
            }
            else
            {
                printf("-");
            }
        }
        printf("-%d|",p[i].complete);
    }
    printf("Average waiting time = %f",(float)(sum_wt/n));
    printf("Average turnaround time = %f",(float)(sum_tt/n));                                    
}
*/
    printf("GANTT CHART\n");
    printf("----------------------------------------------------------------------------\n");
    for(int i=0;i<n;i++)
    {
        if(p[i].arrival==0 || p[i].arrival<=p[i-1].complete)
        {
            printf("| %s  ",p[i].name);
        }
        else
        {
            printf("| idle ");
            printf("| %s  ",p[i].name);
        }
    }
    printf("|");
    printf("\n");
    printf("----------------------------------------------------------------------------\n");
    printf("0");
    for(int i=0;i<n;i++)
    {
        if(p[i].arrival==0)
        {
            printf("      %d",p[i].burst);
        }
        else if(p[i].arrival<=p[i-1].complete)
        {
            printf("      %d",p[i-1].complete+p[i].burst);
        }
        else
        {
            printf("     %d",p[i].arrival);
            printf("     %d",p[i].complete);
        }
    }    
    printf("\n");
}
