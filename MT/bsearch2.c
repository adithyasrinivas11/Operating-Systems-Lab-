#include <pthread.h>
#include <stdio.h>
#include<stdlib.h>

int K,Q;
int thread_count=0;
int x,c,f=0,occ[10];
int y=0;
void * Bsearch(void * arg)
{
	int *a=arg;
	int k;
	int part = thread_count++;
	int C=0;
	int beg=c/4*part;
	int end=c/4*(part+1);
	end=end-1;
	int mid;
	printf("%d %d ---> \n", beg,end);
	while(beg<=end)
	{
		mid=(beg+end)/2;
		if(x==a[mid])
		{
			f=1;
			occ[y]=mid+1;
			y++;
			for(k=mid;k>=0;k--)
				if(a[k]!=a[mid])
					break;
			K=k+1;	
			for(k=mid+1;k<c;k++)
				if(a[k]!=a[mid])
					break;
			Q=k-1;		
			break;
		}
		else if(x<a[mid])
			end=mid-1;
		else
			beg=mid+1;
	
	}
	
}

int main(int argc,char **argv)
{
	pthread_t tid[4];	// this is our thread identifier
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	int i = 0;
	c=argc-1;
	int b[argc];
	for(i=0;i<10;i++)
		occ[i]=-1;
	for(i=1;i<argc;i++)
		b[i-1]=atoi(argv[i]);
	printf("enter the no to be searched?:");
	scanf("%d",&x);
	
	for(i=0;i<4;i++)
		pthread_create(&tid[i],&attr,Bsearch,b);
	
	for(i=0;i<4;i++)
		pthread_join(tid[i],NULL);
	
	if(f==1)
	{
		printf("present in the array!\n occurence: ");
		for(i=0;i<10;i++)
		{
			if(Q!=K)
				printf("present in the array! from %d to %d \n occurence: ",K,Q);
		}
		
	}
	
	else
		printf("not present in the array!\n");	
	
	
	return 0;
}

