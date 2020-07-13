#include <pthread.h>
#include <stdio.h>
#include<stdlib.h>

int n=0;
int part(int a[30],int beg, int end)
{
			p=beg;
			i=beg;j=end;
			while(i<j)
			{
				while(a[i]<=a[p] && i<=end ) 
					i++;
				while(a[j]>a[p] && j>beg)
					j--;
					
				if(i<j)
				{
					t=a[i];
					a[i]=a[j];
					a[j]=t;
				}		
			}
			if(a[p]>a[j])
			{
				t=a[j];
				a[j]=a[beg];
				a[beg]=t;
			}
	return j;
}


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
	for(i=1;i<argc;i++)
		{
		a[i-1]=atoi(argv[i]);
		n++;
		}
	for(i=2;i<n;i++)
	{
	pthread_create(&tid,&attr,prime,i);
	}
	
	pthread_join(tid,NULL);

	return 0;
}

