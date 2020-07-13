#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{

	int n,j,i;
	char *a[]={"ls","-a"};
	//printf("enter the command\n");
	int pid=fork();
		
	if(pid==0)
	{
		
		printf("zombie process!\n");
		printf("ppid:%d",getppid());
	}
	else if(pid>0)
	{
		
		sleep(5);
		printf("parent\n");
		
	}

	return 0;
}
