#include<stdio.h>

void main()
{
	int m[10],p[10],num_m,num_p;
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
		for(int j = 0;j<num_m;j++)
		{
			if(p[i]<=m[j])
			{
				printf("\n%d is stored in %d",p[i],m[j]);
				m[j] = m[j]-p[i];
				printf("\nFree space is :%d",m[j]);
				flag = 1;
				break;
			}
			if(flag==1)
			{
				printf("\n%d cannot be allocated:",p[i]);
			}
		}
	}

	
}
