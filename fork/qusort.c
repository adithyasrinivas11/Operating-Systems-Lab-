#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

void qusort(int a[30],int beg,int end);
int i,j, p, t;
int part(int a[30],int beg, int end)
{
			p=beg;
			i=beg;j=end;
			while(i<j)
			{
				while(a[i]<=a[p] && i<=end ) 
					i++;
				while(a[j]>a[p] && j>beg)
					j--;
					
				if(i<j)
				{
					t=a[i];
					a[i]=a[j];
					a[j]=t;
				}		
			}
			if(a[p]>a[j])
			{
				t=a[j];
				a[j]=a[beg];
				a[beg]=t;
			}
	return j;
}
void qusort(int a[30],int beg,int end)
	{
		if(beg<end)
		{
			j=part(a,beg,end);	
			int pid=vfork();	
			
			if(pid==0)
			{
				qusort(a,j+1,end);
				exit(1);
			}
			else if(pid>0)
			{
				
				
				//wait(NULL);
				qusort(a,beg,j-1);

			}
		}
	}

int main()
{
	int k,n,beg=0,end;
	int a[30];
	printf("enter the number\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	end=n-1;
	
	qusort(a,beg, end);
	
	for(i=0;i<n;i++)
		printf("%d  ",a[i]);
	
		printf("\n");	
	return 0;
}
