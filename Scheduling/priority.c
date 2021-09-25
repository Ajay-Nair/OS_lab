#include<stdio.h>
#include<string.h>
#include<stdbool.h>
struct Process
{
    char name[10];
    int arrival;
    int burst;
    int complete;
    int start;
    int tt;
    int pt;
    int wt;
    int in_pb;
}p[10],temp,pb[10],t;

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
        printf("\nEnter priority: ");
        scanf("%d",&p[i].pt);
        p[i].in_pb=0;
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
    //Sorting according to priority time
    int m_pt = 0;
    int i = 0;
    while(i < n)
    {
        if(m_pt >= p[i].arrival)
        {
            int j = 0;
            while(j<n)
            {
                if(m_pt >= p[j].arrival)
                {
                    if(p[j].in_pb == 0 && p[j].pt < p[i].pt)
                    {
                        t = p[i];
                        p[i] = p[j];
                        p[j] = t;
                    }
                }
                else
                {
                    break;
                }
                j++;
            }
            
            m_pt = m_pt + p[i].pt;
            p[i].in_pb = 1;

            i++;
        }
        else
        {
            m_pt = p[i].arrival;
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
    printf("\n Average waiting time = %f",(float)(sum_wt/n));
    printf("\n Average turnaround time = %f",(float)(sum_tt/n));

    
}
