#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int pid,i;
	char a[20]="IiItDm";
	char b[20];
	int fd[2];
	pipe(fd);
	pid=fork();
	if(pid>0)
	{
		close(fd[0]);
		write(fd[1],a,strlen(a)+1);
		close(fd[1]);
		
	}
	if(pid==0)
	{
		close(fd[1]);
		read(fd[0],b,strlen(a)+1);
		close(fd[0]);
		for(i=0;i<strlen(b);i++)
			if((int)b[i] >=97 && (int)b[i]<=123)
				b[i]-=32;
		printf("%s",b);	
	}
	return 0;
}
