#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{

	int n,j,i;
	char *a[]={"ls","-latr",NULL};
	//printf("enter the command\n");
	int pid=fork();
		
	if(pid==0)
	{
		printf("2vhjg");
		printf("3vhjg");
		printf("v4hjg");
		//execvp(a[0],a);
	}
	else if(pid>0)
	{
		//wait(NULL);
		printf("1parent");
		printf("2parent");
		printf("3parent");

	}

	return 0;
}
