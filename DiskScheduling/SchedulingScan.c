//98 183 37 122 14 124 65 67

#include<stdio.h>

void main()
{
	int current_pos,number_tracks,maxsize,res[20];
	printf("Enter max size: ");
	scanf("%d",&maxsize);
	printf("Enter number of tracks: ");
	scanf("%d",&number_tracks);
	printf("\nEnter current pos: ");
	scanf("%d",&current_pos);
	
	number_tracks = number_tracks + 2;

	printf("\nEnter tracks: ");
	int tracks[number_tracks];
	tracks[0] = current_pos;
	tracks[1] = maxsize-1;

	for(int i = 2;i<number_tracks;i++)
	{
		scanf("%d",&tracks[i]);
	}

	//sorting tracks
	int temp = 0;
	for(int i = 0;i<number_tracks;i++)
	{
		for(int j =i+1;j<number_tracks;j++)
		{
			if(tracks[i]>tracks[j])
			{
				temp = tracks[i];
				tracks[i] = tracks[j];
				tracks[j] = temp;	
			}	
		}
	}
	//Finding Index of current_pos
	int index , c=0;
	for(int i = 0;i<number_tracks;i++)
	{
		if(tracks[i] == current_pos)
		{
			index = i;
			break;
		}
	}
	//Schedule scan

	for(int i = 0;i<number_tracks;i++)
	{
		printf("  %d",tracks[i]);
	}	
	
	for(int j = index;j<number_tracks-1;j++)
	{
		if(tracks[j]-tracks[j+1]<0)
		{
			res[c]=tracks[j+1]-tracks[j];
		}
		else
		{
			res[c]=tracks[j]-tracks[j+1];
		}
		printf(" ( %d - %d) = %d ",tracks[j],tracks[j+1],res[c]);
		c = c+1;
	}

	if(tracks[number_tracks-1]-tracks[index-1]<0)
	{
		res[c] = tracks[index-1]-tracks[number_tracks-1];
	}
	else
	{
		res[c] = tracks[number_tracks-1]-tracks[index-1];
	}
	printf(" ( %d - %d) = %d ",tracks[index-1],tracks[number_tracks-1],res[c]);
	c = c+1;

	for(int k = index-1;k>0;k--)
	{
		if(tracks[k]-tracks[k-1]<0)
		{
			res[c]=tracks[k-1]-tracks[k];
		}
		else
		{
			res[c]=tracks[k]-tracks[k-1];
		}
		printf(" ( %d - %d) = %d ",tracks[k],tracks[k-1],res[c]);
		c = c + 1;
	}
	
	int sum = 0;
	for (int i = 0;i<number_tracks-1;i++)
	{
		printf(" %d ",res[i]);
		sum = sum + res[i];
	}
	printf("\n %d",sum);
	
}
