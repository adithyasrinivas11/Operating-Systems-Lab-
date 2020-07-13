#include <pthread.h>
#include <stdio.h>
#include<stdlib.h>



void *prime(void *arg)
{
	int n=arg;
	int f=0;
	for(int i=2;i<n;i++)
		if(n%i==0)
			f=1;
	if(f==0)
		printf("%d\n",n);
	return NULL;
}

int main(int argc,char **argv)
{
	pthread_t tid;	// this is our thread identifier
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	int i = 0;
	int n=atoi(argv[1]);
	for(i=2;i<n;i++)
	{
	pthread_create(&tid,&attr,prime,i);
	}
	
	pthread_join(tid,NULL);

	return 0;
}

