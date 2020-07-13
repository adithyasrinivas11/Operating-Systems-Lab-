#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{

	int n,j,i;
	char *a[]={"root"};
	//printf("enter the command\n");
	int pid=fork();
		
	if(pid==0)
	{
		execle("/bin/ls","ls",a,NULL);
	}
	else if(pid>0)
	{
		wait(NULL);
		printf("parent\n");

	}

	return 0;
}
