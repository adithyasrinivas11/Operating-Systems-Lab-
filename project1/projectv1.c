#include<iostream>
using namespace std;
//#include<stdio.h>
#include<pthread.h>


int n_sq[1000],n[1000],lazy[1000],catalan[1000];

int fact(int n)
{
	int f=1;
	for(int i=1;i<=n;i++)
		f*=i;
		
	return f;
}

void * lazy_caterer(void * param)
{
	int n1=(int)param;
	n_sq[n1]=n1*n1;
	n[n1]=n1;
}

void * _catalan_(void * param)
{
	int x=(int)param;
	int y=fact(2*x);
	int z=fact(x);
	int w=fact(x+1);
	int q=y/z;
	q=q/w;
	catalan[x]=q;
	printf("xxx  x=%d y=%d z=%d w=%d q=%d\n",x,y,z,w,q);
}
int main()
{
int N,i;
pthread_t tid1[100];
pthread_t tid2[100];
pthread_attr_t attr;
pthread_attr_init(&attr);


scanf("%d",&N);

for(i=1;i<=N;i++)
{
	pthread_create(&tid1[i],&attr,lazy_caterer,i);
	pthread_create(&tid2[i],&attr,_catalan_,i);
}

for(i=1;i<=N;i++)
{	
	pthread_join(tid1[i],NULL);
	pthread_join(tid2[i],NULL);
}
	

for(i=1;i<=N;i++)
	{
	lazy[i]=(n_sq[i]+n[i]+2)/2;
	printf("%d-->%d\n",i,lazy[i]);
	}
//catalan
printf("catalan\n");
for(i=1;i<=N;i++)
	{
	printf("%d<-->>%d\n",i,catalan[i]);
	}

return 0;
}
