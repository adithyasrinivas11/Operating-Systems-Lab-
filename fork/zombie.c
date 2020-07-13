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
		printf("ppid:%d",getppid());
		sleep(5);
		printf("orphan process!\n");
		printf("ppid:%d",getppid());
	}
	else if(pid>0)
	{
		printf("parent\n");

	}

	return 0;
}
