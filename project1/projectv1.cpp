#include<iostream>
using namespace std;
#include<stdlib.h>
#include<pthread.h>


int n_sq[1000],n[1000],lazy[100];
long int catalan[100];

int fact(int n)
{
	int f=1;
	for(int i=1;i<=n;i++)
		f*=i;
		
	return f;
}

void * lazy_caterer(void * param)
{
	int n1=*(int* )param;
	n_sq[n1]=n1*n1;
	n[n1]=n1;
}

void * _catalan_(void * param)
{
	
	long int x=*(long 	int*)param;
	
	long int y=fact(2*x);
	cout<<" :: "<<x<<" ** "<<y<<endl;
	long int z=fact(x);
	long int w=fact(x+1);
	long int q=y/z;
	q=q/w;
	catalan[x]=q;	
}

int sq[40],tri[40],pen[40],hexo[40];

void *sqpr (void *parameter)
{
	int i=*(int*)parameter;
	int it=i*i;
	sq[i]=it;
	pthread_exit(0);
}


void *Square (void *parameter)
{
	int n=*(int*)parameter;
	
	pthread_t sid[20];
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	for(int i=0;i<=n;i++)
	{
		int *local=(int*)malloc(sizeof(int*));
		*local=i;
		pthread_create(&sid[i], &attr,sqpr,local);
		//sleep(1);
	}

	for(int i=0;i<=n;i++)
		pthread_join(sid[i],NULL);

	pthread_exit(0);

}


void *trpr (void *parameter)
{
	int i=*(int*)parameter;
	
	tri[i]=(i*(i+1))/2;
	pthread_exit(0);
}


void *Triangle (void *parameter)
{
	int n=*(int*)parameter;
	
	pthread_t tid[20];
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	for(int i=1;i<=n;i++)
	{
		int *local=(int*)malloc(sizeof(int*));
		*local=i;
		pthread_create(&tid[i], &attr,trpr,local);
		//sleep(1);
	}

	for(int i=0;i<=n;i++)
		pthread_join(tid[i],NULL);

	pthread_exit(0);

}


void *pnpr (void *parameter)
{
	int i=*(int*)parameter;
	
	pen[i]=(i*((3*i)-1))/2;
	pthread_exit(0);
}


void *Pentagon (void *parameter)
{
	int n=*(int*)parameter;
	
	pthread_t peid[20];
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	for(int i=1;i<=n;i++)
	{
		int *local=(int*)malloc(sizeof(int*));
		*local=i;
		pthread_create(&peid[i], &attr,pnpr,local);
		//sleep(1);
	}

	for(int i=0;i<=n;i++)
		pthread_join(peid[i],NULL);

	pthread_exit(0);

}

void *hxpr (void *parameter)
{
	int i=*(int*)parameter;
	
	hexo[i]=((2*i)*((2*i)-1))/2;
	pthread_exit(0);
}


void *Hexagon (void *parameter)
{
	int n=*(int*)parameter;
	
	pthread_t hid[20];
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	for(int i=1;i<=n;i++)
	{
		int *local=(int*)malloc(sizeof(int*));
		*local=i;
		pthread_create(&hid[i], &attr,hxpr,local);
		//sleep(1);
	}

	for(int i=0;i<=n;i++)
		pthread_join(hid[i],NULL);

	pthread_exit(0);

}


int main()
{
	int N;
	long int i;
	pthread_t tid1[100];
	pthread_t tid2[100],tid3,tid4,tid5,tid6;
	pthread_attr_t attr;
	pthread_attr_init(&attr);


	scanf("%d",&N);
	int *lo=(int*)malloc(sizeof(int*));
	*lo=N;
	for(i=1;i<=N;i++)
	{
		long int *local=(long int*)malloc(sizeof(int*));
		*local=i;
		pthread_create(&tid1[i],&attr,lazy_caterer,local);
		pthread_create(&tid2[i],&attr,_catalan_,local);	
	}
	pthread_create(&tid3, &attr, Square, lo);
	pthread_create(&tid4, &attr, Triangle, lo);
	pthread_create(&tid5, &attr, Pentagon, lo);
	pthread_create(&tid6, &attr, Hexagon, lo);
	
	pthread_join(tid3,NULL);
	pthread_join(tid4,NULL);
	pthread_join(tid5,NULL);
	pthread_join(tid6,NULL);
	
	for(i=1;i<=N;i++)
	{	
		pthread_join(tid1[i],NULL);
		pthread_join(tid2[i],NULL);
	}
		
printf("\nlazy  ");
	for(i=1;i<=N;i++)
		{
		lazy[i]=(n_sq[i]+n[i]+2)/2;
		printf("%d ",lazy[i]);
		}
	//catalan
	printf("\ncatalan  ");
	for(i=1;i<=N;i++)
		{
		printf("%ld ",catalan[i]);
		}
	
	cout<<"\nSquare: ";
	for(int i=1;i<N;i++)
		cout<<" "<<sq[i];
	
	cout<<endl;
	cout<<"Triangle: ";
	
	for(int i=1;i<N;i++)
		cout<<" "<<tri[i];
	cout<<endl;

	cout<<"Pentagon: ";
	
	for(int i=1;i<N;i++)
		cout<<" "<<pen[i];
	cout<<endl;
	
	cout<<"Hexagonal: ";
	
	for(int i=1;i<N;i++)
		cout<<" "<<hexo[i];		
	cout<<endl;
	
	
	return 0;
}
