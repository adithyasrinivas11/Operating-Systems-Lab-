#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
int main()
{
int fd1[2],fd2[2],pid,x1,x2;
char msg1[]="from parent:hello child!\n"; char msg2[]="from child: hello parent\n";
char buf[20];
x1=strlen(msg1);
x2=strlen(msg2);

pipe(fd1);
pipe(fd2);
pid=fork();
if(pid==0)//from parent to child
{
close(fd1[1]);
read(fd1[0],buf,x1);
printf("\nchild recieved is %s",buf);
}
else if(pid>0)
{
close(fd1[0]);
write(fd1[1],msg1,x1);
}

if(pid==0)//from child to parent
{
close(fd2[0]);
write(fd2[1],msg2,x2);
}
else if(pid>0)
{
close(fd2[1]);
read(fd2[0],buf,x2); 
printf("\nparent recieved is %s",buf);
}

return 0;
}
