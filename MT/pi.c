#include<stdio.h>
#include<math.h>
#include<pthread.h>
float c=0,s=0;
double z;

void * circle(void * arg)
{



if(z<=1)
	{
	c++;
	s++;
	}
else
	s++;	




}

int main()
{
pthread_t tid;
pthread_attr_t attr;
pthread_attr_init(&attr);
for(long int i=0;i<999999;i++)
{
double x,y; 
 x=rand();
 y=rand();
//x=srand()/10;
while(x>1)
	x/=3;

while(y>1)
	y/=3;

z=x*x+y*y;
z=sqrt(z);

pthread_create(&tid,&attr,circle,NULL);
}
pthread_join(tid,NULL);
printf("%f",4*c/s);
return 0;
}
