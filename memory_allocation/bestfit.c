#include<stdio.h>
int find_best(int b_p,int b_m[],int n)
{	
	int best[20], c = 0,b;
	for(int i = 0;i<n;i++)
	{
 		if(b_p<=b_m[i])
		{
			best[c] = b_m[i]-b_p; //i->c
			c = c+1;
		}
	}
	if(c==0)
	{
		b = -1;
	}
	else
	{
		b = best[0];
		for(int i = 0;i<c;i++)
		{
			if(best[i]<=b)
			{
				b = best[i];
			}
		}
	}
	return b;
	
}
void main()
{
	int m[10],p[10],num_m,num_p,b_value;
	printf("\nEnter number of memory blocks: ");
	scanf("%d",&num_m);
	printf("\nEnter number of process blocks: ");
	scanf("%d",&num_p);
	for(int i = 0;i<num_m;i++)
	{
		printf("\nEnter memory block %d: ",i);
		scanf("%d",&m[i]);
	}
	for(int i = 0;i<num_p;i++)
	{
		int flag = 0;
		printf("\nEnter process  %d: ",i);
		scanf("%d",&p[i]);
		b_value = find_best(p[i],m,num_m);
		if(b_value == -1)
		{
			printf("\n %d cannot be allocated",p[i]);
			break;
		}
		else
		{
			for(int j = 0;j<num_m;j++)
			{
				if(m[j]-p[i] == b_value)
				{
					printf("\n %d is stored in %d ",p[i],m[j]);
					m[j] = b_value;
					printf("\n free space is :%d",m[j]);
					break;
				}
			}
		}
	}

	
}
