#include<stdio.h>
void main()
{
    int n,arrival[10],burst[10];
    char p[10];
    printf("\nEnter number of process:");
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
    {
        printf("\n Enter process name , arrival time and burst time: ");
        scanf("%s %d %d",&p[i],&arrival[i],&burst[i]);
    }
    for(int j = 0;j<n;j++)
    {
        for(int k = j+1;k<n;k++)
        {
            if(arrival[j]>arrival[k])
            {
                int temp;
                char t2; 
                temp = arrival[j];
                arrival[j] = arrival[k];
                arrival[k] = temp;

                t2 = p[j];
                p[j] = p[k];
                p[k] = t2;

                temp = burst[j];
                burst[j] = burst[k];
                burst[k] = temp;

            }
        }
    }
    for(int i=0;i<n;i++)
    {
        __fpurge(stdin);
        printf("%d",arrival[i]);
        gets(p[i]);
    }
}