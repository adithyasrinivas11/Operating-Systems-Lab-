#include <pthread.h>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int c;
float me=0,med=0;
int mod;
void *mean(void *arg)
{
	int *a=arg;
	printf("MEAN\n");
	int i = 0;
	float s=0;
	for(i=0;i<c-1;i++)
		{
		s+=a[i];
		}
	s/=c;
	me=s;
	return NULL;
}

void *median(void *arg)
{
	
	printf("MEDIAN\n");
	int *a=arg;
	int i=0 , j=0 , temp=0;
	for(i=0 ; i<c-1 ; i++)
    	{
      	for(j=0 ; j<c-i-2 ; j++)
      	{
            	if(a[j]>a[j+1])
            	{
                		temp= a[j];
                		a[j]= a[j+1];
                		a[j+1]= temp;
            	}
        	}
    }
	
	//printf("%d",c);
	
    	if((c-1)%2 == 0)
      	med = (a[(c-2)/2] + a[(c-1)/2])/2.0;
	else
      	med = a[(c-1)/2];
	
	
		
	return NULL;
}

void *mode(void *arg)
{
	int *a=arg;
	int b[c-1];
	int i,j,k,f;
	printf("MODE\n");
	
	for(i=0;i<c-1;i++)
		b[i]=0;
		
		
		
	for(i=0;i<c-1;i++)
	{
		for(j=0;j<c-1;j++)
			if(a[i]==a[j])
				b[i]++;
	}
	int max=b[0];
	j=0;
	for(i=0;i<c-1;i++)
		if(max<b[i])
			{	
			max=b[i];
			j=i;
			}
			
	mod=max;	
	return NULL;
}

int main(int argc,char **argv)
{
	c=argc;
	pthread_t tid;	// this is our thread identifier
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	int i = 0,a[argc];
	for(i=1;i<argc;i++)
		a[i-1]=atoi(argv[i]);
	
	pthread_create(&tid,&attr,mean,a);
	pthread_create(&tid,&attr,median,a);
	pthread_create(&tid,&attr,mode,a);
	
	pthread_join(tid,NULL);

	printf("Mean= %f\nMedian= %f\nMode= %d\n",me,med,mod);
	return 0;
}

