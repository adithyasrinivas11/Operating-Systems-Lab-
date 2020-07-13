#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int pid,i;
	int c1=0,c2=0,c3=0,c4=0;
	char a[20];
	printf("enter a string:\n");
	scanf("%[^\t]",a);
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
			if(b[i]==' ')
				{
					c2++;
				}	
			else if(b[i]=='\n')
				{c3++;
				c2++;}
			else if(b[i]=='.')
				c4++;
			
			else
				c1++;	
			
			c2++;			
		printf("char count:%d \nline count:%d\nsentence count:%d\n",c1,c3,c4);	
	}
	return 0;
}
