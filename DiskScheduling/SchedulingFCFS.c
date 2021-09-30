//98 183 37 122 14 124 65 67

#include<stdio.h>

void main()
{
	int current_pos,number_tracks,res[10];
	printf("Enter number of tracks: ");
	scanf("%d",&number_tracks);
	printf("\nEnter current pos: ");
	scanf("%d",&current_pos);
	printf("\nEnter tracks: ");
	int tracks[number_tracks];
	for(int i = 0;i<number_tracks;i++)
	{
		scanf("%d",&tracks[i]);
	}
	res[0] = current_pos-tracks[0];
	if(res[0]<0)
	{
		res[0] = res[0] * -1;	
	}
	for(int i = 0;i<number_tracks-1;i++)
	{
		if(tracks[i]-tracks[i+1]<0)
		{
			res[i+1] = (tracks[i+1]-tracks[i]);
		}
		else
		{
			res[i+1]=(tracks[i]-tracks[i+1]);
		}
	}
	int sum = 0;
	for (int i = 0;i<number_tracks;i++)
	{
		sum = sum + res[i];
	}
	printf("\n %d",sum);
	
}
