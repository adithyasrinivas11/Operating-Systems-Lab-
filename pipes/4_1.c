
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int pid,i;
	int c1=0,c2=0,c3=0;
	char a[20];
	printf("enter a string:\n");
	scanf("%s",a);
	char b[20];
	char c[20];
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
		int x=strlen(b);
		int j;
		for(i=0,j=x-1;i<x;i++,j--)
			{c[i]=b[j];
			printf("%c",c[i]);
			}
		if(strcmp(c,b)==0)	
			printf("\npallindrome \n");
		else
			printf("\nnot a pallindrome \n");
			
			printf(":::::::::   %s",c);
	}
	return 0;
}
