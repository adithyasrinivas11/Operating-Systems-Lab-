
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int pid,i;
	int c1=0,c2=0,c3=0;
	char a[20];
	//printf("enter a string:\n");
	//scanf("%s",a);
	char b[20];
	char c[20];
	int fd[2];
	pipe(fd);
	pid=fork();
	if(pid>0)
	{
		printf("executing ls command:\n");
		close(fd[0]);
		dup2(fd[1],1);
		execlp("ls","ls",NULL);
		close(fd[1]);
		
	}
	if(pid==0)
	{
		int n,w[4];
		w[0]=0;
		w[1]=0;
		w[2]=0;
		//char *a[]={"wc","wc -w",NULL};
		close(fd[1]);
		while((n=read(fd[0],b,strlen(a)+1))>0)
		{
			for(i=0;i<n;i++)
				{printf("%c",b[i]);
				if(b[i]==' ')
					printf("*");
				}
			printf("\n");
			if(b[0]!='\n')
			for(i=0;i<n;i++)
			{
				if(i!=0)
					{
					if(b[i]==' ' && b[i+1]!=' ' && b[i+1]!='\n')
						w[0]++;	
					}
				if(b[i]=='\n')
					w[1]++;	
				if(b[i]!='\n' && b[i]!=' ')
					w[2]++;		
			}
		}
		close(fd[0]);
		printf("char count: %d\nline count: %d \n",w[2],w[1]);
		//execvp(a[0],a);
	}
	return 0;
}
