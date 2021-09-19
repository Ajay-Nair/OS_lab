#include<stdio.h>
struct Process
{
    char name[10];
    int arrival;
    int burst;
    int count;
    int reminder;
}p[10],temp;

void main()
{
    int n,timeslice,total_count = 0 ,total_reminder = 0;
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
    printf("\nEnter time slice: ");
    scanf("%d",&timeslice);
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
    //finding count and reminder
    for(int i = 0;i<n;i++)
    {
        p[i].count = (p[i].burst/timeslice);
        p[i].reminder = (p[i].burst%timeslice);
        total_count = total_count + p[i].count;
        total_reminder = total_reminder + p[i].reminder;
    }
    
    //Printing
    int st = 0;
    int flag = 1;
    while(total_count!=0 || total_reminder!=0)
    {
        for(int i = 0;i<n;i++)
        {
            if(st>=p[i].arrival)
            {
                if(p[i].count!=0)
                {
                    printf("| %s |",p[i].name);
                    p[i].count = p[i].count - 1;
                    total_count = total_count - 1;
                    st = st + timeslice;
                }
                else
                {
                    if(p[i].reminder!=0)
                    {
                        printf("| reminder%d %s|",p[i].reminder,p[i].name);
                        total_reminder = total_reminder - p[i].reminder;
                        p[i].reminder = 0;
                        st = st + p[i].reminder;
                    }
                }

            }
            else
            {
                printf("|idle|");
                st = st + timeslice;
                i = i-1;
            }
    
        }
    }              
}
