#include<stdio.h>
void main()
{
    int f , p ;
    printf("Enter number of frames: ");
    scanf("%d",&f);
    printf("\nEnter number of pages: ");
    scanf("%d",&p);

    int frames[f];
    int pages[p];

    //initialising frames

    for(int i = 0;i<f;i++)
    {
        frames[i]=-1;
    }

    //Getting pages

    printf("\nEnter pages:");
    for(int i = 0;i<p;i++)
    {
        scanf("%d",&pages[i]);
    }

    //LRU
    int empty = 0,hit = 0,miss = 0,flag = 0,index,hit_index;
    int time[f];
    for (int  t = 0; t < f; t++)                        //Initialising time array as 0
    {
        time[t] = 0;
    }
    
    for(int i = 0;i<p;i++)                              //looping through pages
    {
        flag = 0;
        for(int j = 0;j<f;j++)
        {
            if(pages[i] == frames[j])                   //loop for finding hit and hit_index
            {
                hit_index = j;
                flag = 1;
                break;
            }
        }
        if(flag == 0)                                   //Condition for not hit
        {
            if(empty<f)                                 //inserting starting elements till frames are full 
            {
                frames[i] = pages[i];
                empty++;
                for(int k = 0;k<=i;k++)                 //increasing time
                {
                    time[k] = time[k]+1;
                }
            }
            else
            {
                 int m = 0;
                 index = 0;
                for (int k = 0; k < f; k++)             //finding biggest time
                {
                    if(m<=time[k])
                    {
                        m = time[k];
                        index = k;
                    }
                    
                }

                frames[index] = pages[i];               //replacing pages with frame which has biggest time
                time[index] = 0;                        //making time of replaced index into 0

                for(int k = 0;k<f;k++)                  //increasing time
                {
                    time[k] = time[k]+1;
                }
            }
             for(int k = 0;k<f;k++)                  //printing frames
                {
                    printf(" %d ",frames[k]);
                }
            printf("\n");
        }
        else                                            //hit condition
        {
            printf("\nHit\n");
            time[hit_index] = 0;                        //restarting time of hit element
            for(int k = 0;k<f;k++)
                {
                    time[k] = time[k]+1;                //increasing time
                }
        }
    }
}