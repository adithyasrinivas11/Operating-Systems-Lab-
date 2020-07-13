#include<stdio.h>

int main()
{
	int a[5],at[5],AT[5],b[5],bt[5],BT[5],ct[5],tat[5],wt[5];
	int i,j,min,imin,s=0;
	float h[5];
	int temp1,temp2;
	
	AT[0]=0;
	AT[1]=2;
	AT[2]=4;
	AT[3]=6;
	AT[4]=8;
	
	BT[0]=3;
	BT[1]=6;
	BT[2]=4;
	BT[3]=5;
	BT[4]=2;
	
	int x=-1;
	float max=-1;  
	int time=0;
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<5-i-1;j++)
		{
			if(AT[j]>AT[j+1])
			{
				temp2=AT[j];
				AT[j]=AT[j+1];
				AT[j+1]=temp2;
				
				temp1=BT[j];
				BT[j]=BT[j+1];
				BT[j+1]=temp1;
			}
		}
	}
	for(i=0;i<5;i++)
	{
		at[i]=AT[i];
		bt[i]=BT[i];
		h[i]=-1;
	}
	
	if(at[0]!=0)
		time+=at[0];
	
	time+=bt[0];
	bt[0]=0;
	ct[0]=time;
	b[0]=1;
	
	while(1)
	{
		x=-1;
		max=-1;
		for(i=0;i<5;i++)
		{
			if(at[i]<=time)
			{
				if(a[i]!=1)
					a[i]=1;
				
				wt[i]=time-AT[i];
			}
			
		}
		
		for(i=0;i<5;i++)
		{
			if(a[i]==1 && b[i]!=1)
			{
				h[i]=(float)(wt[i]+BT[i])/(float)BT[i];
				//printf("h[i]= %f  ",h[i]);
			}		
		}

		for(i=0;i<5;i++)
		{
			if(a[i]==1 && b[i]!=1 && h[i]!=-1)
				{
					if(max<h[i])
					{
						max=h[i];
						x=i;
					}
				}		
		}
		
		//printf("wt= %d  time=%d \n",max,x,wt[x],time);
		if(x!=-1)
		{
			time+=bt[x];
			bt[x]=0;
			ct[x]=time;
			b[x]=1;	
		}
		else
			time++;
		
		if(bt[0]+bt[1]+bt[2]+bt[3]+bt[4]==0)
			break;
	}
	
	for(i=0;i<5;i++)
	{
		tat[i]=ct[i]-AT[i];
		wt[i]=tat[i]-BT[i];
	}
	
	printf("  AT   BT   CT  TAT   WT\n");
	for(i=0;i<5;i++)
		printf("%4d %4d %4d %4d %4d \n",AT[i],BT[i],ct[i],tat[i],wt[i]);

	return 0;
}
