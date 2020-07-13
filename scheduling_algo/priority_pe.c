#include<stdio.h>
int main()
{

int a[6],at[6],AT[6],b[6],bt[6],BT[6],ct[6],tat[6],wt[6],p[6];
	int i,j,min,imin,s=0;

	AT[0]=1;
	AT[1]=2;
	AT[2]=2;
	AT[3]=3;
	AT[4]=3;
	AT[5]=4;
	
	
	
	BT[0]=4;
	BT[1]=2;
	BT[2]=3;
	BT[3]=5;
	BT[4]=1;
	BT[5]=2;
	
	
	p[0]=4;
	p[1]=5;
	p[2]=7;
	p[3]=8;
	p[4]=5;
	p[5]=6;
	
	for(i=0;i<6;i++)
	{
		at[i]=AT[i];
		bt[i]=BT[i];
	}
	
	int x=-1,max=-1;  
	int time=0;
	
	while(1)
	{
		x=-1;
		max=-1;
		for(i=0;i<6;i++)
		{
			if(at[i]<=time)
			{
				if(a[i]!=1)
					a[i]=1;
			}
		}
		
		for(i=0;i<6;i++)
		{
			if(a[i]==1 && b[i]!=1)
			{
				if(max<p[i])
				{
					max=p[i];
					x=i;
				}
			}		
		}

		if(x!=-1)
		{
			time+=1;
			bt[x]--;
				
			if(bt[x]==0)
				{
				ct[x]=time;
				b[x]=1;
				}
		}
		else
			time++;
		
		if(bt[0]+bt[1]+bt[2]+bt[3]+bt[4]==0)
			break;
	}
	
	for(i=0;i<6;i++)
	{
		tat[i]=ct[i]-AT[i];
		wt[i]=tat[i]-BT[i];
	}
	
	printf("  AT   BT  PR   CT  TAT   WT\n");
	for(i=0;i<6;i++)
		printf("%4d %4d %4d %4d %4d %4d \n",AT[i],BT[i],p[i],ct[i],tat[i],wt[i]);
return 0;
}
