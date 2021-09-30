//98 183 37 122 14 124 65 67

#include<stdio.h>
#include<stdlib.h>

void main()
{
	int current_pos,number_tracks,maxsize;
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

	int res = 0;
	res = res + abs(tracks[index]-tracks[number_tracks-1]);
	res = res + tracks[number_tracks-1];
	res = res + tracks[index-1];
	printf("%d",res);
	
	
}
