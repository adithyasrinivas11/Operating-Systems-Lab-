#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

#define BS 20

int main()
{
char wm[BS];
char rmm[BS];

int fd[2];

pipe(fd);

int pid=vfork();

if(pid==0)
{
	/*
	close(fd[1]);
	read(fd[0],rm,BS);
	close(fd[0]);
	printf("r=%s",rm);
	*/
	close(fd[0]);
	printf("sss\n");
	scanf("%s",wm);
	write(fd[1],wm,strlen(wm)+1);
	close(fd[1]);	
}
else if(pid>0)
{

	
	//close(fd[1]);
	read(fd[0],rmm,BS);
	printf("%s",rmm);
	dup2(fd[1],1);
	execlp(rmm,rmm,NULL);
	exit(1);

}
return 0;
}
