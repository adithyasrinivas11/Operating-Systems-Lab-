#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{

	int n,j,i;
	//printf("enter the number\n");
	//scanf("%d",&n);
	int pid=fork();
		
	if(pid==0)
	{
		execlp("ls","ls",NULL);
	}
	else if(pid>0)
	{
		wait(NULL);
		printf("parent\n");

	}

	return 0;
}
