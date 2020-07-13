#include <pthread.h>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int c;
float med=0,q1=0,q2=0;
int ma,mi;

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

void *qua_1(void *arg)
{
	
	
	int *a=arg;
	int s=(c-1)/2;
	int i=0 , j=0 , temp=0;
	for(i=0 ; i<s-1 ; i++)
    	{
      	for(j=0 ; j<s-i-1 ; j++)
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
	q1=0;
      	q1= a[(s)/2];
	
	
		
	return NULL;
}

void *qua_2(void *arg)
{
	
	int *a=arg;
	int s=(c-1)/2;
	int i=0 , j=0 , temp=0;
	for(i=s ; i<c-1 ; i++)
    	{
      	for(j=s ; j<c-i-2 ; j++)
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
	q2=0;
      q2 = a[s+(c-1-s)/2];
	
	
		
	return NULL;
}

void *max(void *arg)
{
	int *a=arg;
	int i;
	int max=a[0];
	for(i=0;i<c-1;i++)
	{
		if(max<a[i])
		{
			max=a[i];
		}
	}
	ma=max;

}
void *min(void *arg)
{
	int *a=arg;
	int i;
	int min=a[0];
	for(i=0;i<c-1;i++)
	{
		if(min>a[i])
		{
			min=a[i];
		}
	}
	mi=min;

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
	
	pthread_create(&tid,&attr,min,a);
	pthread_create(&tid,&attr,qua_1,a);
	pthread_create(&tid,&attr,median,a);
	pthread_create(&tid,&attr,qua_2,a);
	pthread_create(&tid,&attr,max,a);
	
	pthread_join(tid,NULL);

	printf("min = %d\nfirst quartile= %f\nmedian= %f\nsecond quartile= %f\n,max=%d\n",mi,q1,med,q2,ma);
	return 0;
}

