#include<stdio.h>
#include<stdlib.h>

void main()
{
	int number_frames,number_pages;
	printf("\nEnter number of Frames: ");
	scanf("%d",&number_frames);
	printf("\nEnter number of Pages: ");
	scanf("%d",&number_pages);
	
	int pages[number_pages];
	
	for(int i = 0;i<number_pages;i++)
	{
		printf("Enter page %d: ",i);
		printf("\n");
		scanf("%d",&pages[i]);
	}
	
	//Initialising Frames array with values -1
	int frames[number_frames];
	
	for(int i = 0 ; i<number_frames;i++)
	{
		frames[i]=-1;
	}
	
	//Page replacement
	int ptr = 0,hit = 0,flag = 0;
	for(int i = 0;i<number_pages;i++)
	{
		flag = 0;
		for(int j = 0;j<number_frames;j++)
		{
			if(pages[i]==frames[j])
			{
				flag = 1;
				break;
			}
		}
		if(flag==0)
		{
			int temp = 0;
			temp = pages[i];
			frames[ptr] = temp;
			ptr = (i+1)%(number_frames);
			printf("page %d:",pages[i]);
			for(int j = 0;j<number_frames;j++)
			{
				printf(" %d ",frames[j]);
			}
			printf("\n");
		}
		else
		{	hit  = hit+1;
			printf("page %d ,hit",pages[i]);
		}
	printf("\nPage faults = %d",number_pages-hit);
		
	}
}