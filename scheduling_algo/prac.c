#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int c=0;
int main()
{
int fd[2];
int p;
pipe(fd);
p=fork();

if(p==0)
{
dup2(fd[1],1);
execlp("ls","ls",NULL);
exit(0);
}

if(p>0)
{
dup2(fd[0],0);
execlp("tr","tr","a-z","A-Z",NULL);
exit(0);
}

return 0;
}
