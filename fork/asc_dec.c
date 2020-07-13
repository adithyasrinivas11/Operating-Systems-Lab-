#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>


int main()
{

	int n,j,i;
	printf("enter the number\n");
	scanf("%d",&n);
	int a[100];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int pid=fork();
		
	if(pid==0)
	{
		int t;
		printf("in child !\nascending order :\n");
		for(i=0;i<n-1;i++)
		{	
			for(j=0;j<n-i-1;j++)
			{
				if(a[j]>a[j+1])
				{
					t=a[j];
					a[j]=a[j+1];
					a[j+1]=t;
				}
			}
		}
		
			
		for(i=0;i<n;i++)	
			printf("%d  ",a[i]);
	}
	else if(pid>0)
	{
		
		int t;
		printf("in parent!\ndescending order :\n ");			
		for(i=0;i<n-1;i++)
		{	
			for(j=0;j<n-i-1;j++)
			{
				if(a[j]<a[j+1])
				{
					t=a[j];
					a[j]=a[j+1];
					a[j+1]=t;
				}
			}
		}
		for(i=0;i<n;i++)	
			printf("%d  ",a[i]);
	}

	return 0;
}
