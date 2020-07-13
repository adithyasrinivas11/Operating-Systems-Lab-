#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{

	int n,j,i;
	printf("enter the number\n");
	scanf("%d",&n);
	int pid=fork();
		
	if(pid==0)
	{
		printf("in child %d!\neven series :\n ",n);
		for(i=0;i<n;i+=2)
			printf("%d ",i);
	}
	else if(pid>0)
	{
		wait(10);
		printf("in parent!\nodd series :\n ");			
		for(i=1;i<n;i+=2)
			printf("%d ",i);

	}

	return 0;
}
