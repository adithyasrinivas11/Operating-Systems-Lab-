#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n,j,i;
	char a[20][20];
	char x[20][20];
	int c=1;
	int t;
	t=0;	
	while(c==1)
	{
	int pid=vfork();
		
	if(pid<0)
		printf("no!");
	if(pid>0)
	{
		wait(NULL);
		strcpy(x[t],a[t]);
		t++; 
		
		printf("enter the rep\n");
		scanf("%d",&c);
		
	}
	else if(pid==0)
	{
		
		
		printf("adithya@adithya-fork:~$ ");
		scanf("%s",a[t]);
		//printf("a[i]=%s",a[t]);
		if(!strcmp(a[t],"history"))
			for(i=0;i<t;i++)
			{
				printf("%s\n",x[i]);
			}
		execlp(a[t],a[t],NULL);
		exit(1);
		//sleep(2);
		
		
	}
	
	}

	return 0;
}
