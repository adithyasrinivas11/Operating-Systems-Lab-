#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>

int mark[10];
int thread_count=0,count1=0,count2=0;
int x,c,f=0,f1;
void * Bsearch(void * arg)
{
	int *a=arg;
	int part = thread_count++;
	int beg;
	int end;
	
	if(c%4==0)
	{
		beg=c/4*part;
		end=beg+(c/4);
		end-=1;
	}
	else
	{
		beg=((c/4)+1)*part;
		end=beg+(c/4);	
	}	
	
	
	int mid,i;
	//printf("%d %d ---> \n", beg,end);
	while(beg<=end)
	{
		mid=(beg+end)/2;
		count1++;
		if(x==a[mid])
		{
			f=1;
			break;
		}
		else if(x<a[mid])
			end=mid-1;		
		
		else
			beg=mid+1;
	
		/*for(i=beg;i<=end;i++)
			printf(" %d ",a[i]);
		printf("\n");*/
	}
	pthread_exit(0);
}
int thread_count1=0;

void * Esearch(void* param)
{
	int *a=param;
	int i;int k;
	int beg;
	int end;
	int 	part=thread_count1++;
	if(c%4==0)
	{
		beg=c/4*part;
		end=beg+(c/4);
		end-=1;
	}
	else
	{
		beg=((c/4)+1)*part;
		end=beg+(c/4);	
	}	
	
	//printf("beg-->%d,end-->%d\n",beg,end);
	
	if(a[beg]==x)
	{
		f1=1;
		count2++;
	}
	else
	{
		i=beg+1;
		while(i<end && a[i]<=x)
		{
			i*=2;
		}
		if(i<end)
		{
			//printf("search going to happen between %d and %d\n",a[i/2],a[i]);
			//for(k=i/2;k<=i;k++)
				//printf(" %d ",a[k]);
			//printf("\n");	
			f1=bi(a,i/2,i);
		}
		else
		{
			//printf("search going to happen between %d and %d\n",a[i/2],a[end]);
			//for(k=i/2;k<=c-1;k++)
				//printf(" %d ",a[k]);
			//printf("\n");
			f1=bi(a,i/2,end);
			
		}

	}
	pthread_exit(0);
}

int bi(int a[],int beg,int end)
{
	int mid,q;
	while(beg<=end)
	{
		mid=(beg+end)/2;
		count2++;
		if(x==a[mid])
		{
			q=1;
			break;
		}
		else if(x<a[mid])
			end=mid-1;
		
		else
			beg=mid+1;

		
	
	}
return q;
}

int A[10],B[100],C[1000],D[10000],E[100000],F[600],G[700],H[800],I[900],J[1000];
int main(int argc,char** argv)
{
	clock_t t1[10], t2[10],t3[10],t4[10];
	int compb[10];
	int compe[10];
	pthread_t tid[4];	
	pthread_t ttid[4];
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	int i = 0;
	c=argc-1;
	int b[argc];
	for(i=0;i<600;i++)
	{
		if(i<10)
		{
			compb[i]=0;
			compe[i]=0;
		}
		if(i<10)
			A[i]=i;
		if(i<100)
			B[i]=i+2;
		if(i<1000)
			C[i]=i*2;
		if(i<10000)
			D[i]=i;
		if(i<100000)
			E[i]=i+1;
		/*if(i<600)	
			F[i]=i+3;*/
	}
	
	for(i=1;i<argc;i++)
		b[i-1]=atoi(argv[i]);
	printf("enter the no to be searched?:");
	scanf("%d",&x);
	
	for(i=0;i<4;i++)
	{
		c=10;
		t1[0]=clock();
		pthread_create(&tid[i],&attr,Bsearch,A);
		t3[0]=clock();
		pthread_create(&ttid[i],&attr,Esearch,A);
	}
	compb[0]=count1;
	compe[0]=count2;
	count1=0;
	count2=0;
	for(i=0;i<4;i++)
	{	
		pthread_join(tid[i],NULL);
		t2[0]=clock();
		pthread_join(ttid[i],NULL);
		t4[0]=clock();
	}
	
	
	for(i=0;i<4;i++)
	{
		c=100;
		t1[1]=clock();
		pthread_create(&tid[i],&attr,Bsearch,B);
		t3[1]=clock();
		pthread_create(&ttid[i],&attr,Esearch,B);
	}
	compb[1]=count1;
	compe[1]=count2;
	count1=0;
	count2=0;
	for(i=0;i<4;i++)
	{	
		pthread_join(tid[i],NULL);
		t2[1]=clock();
		pthread_join(ttid[i],NULL);
		t4[1]=clock();
	}
	
	
	for(i=0;i<4;i++)
	{
		c=1000;
		t1[2]=clock();
		pthread_create(&tid[i],&attr,Bsearch,C);
		t3[2]=clock();
		pthread_create(&ttid[i],&attr,Esearch,C);
	}
	compb[2]=count1;
	compe[2]=count2;
	count1=0;
	count2=0;
	for(i=0;i<4;i++)
	{	
		pthread_join(tid[i],NULL);
		t2[2]=clock();
		pthread_join(ttid[i],NULL);
		t4[2]=clock();
	}	
	
	
	
	for(i=0;i<4;i++)
	{
		c=10000;
		t1[3]=clock();
		pthread_create(&tid[i],&attr,Bsearch,D);
		t3[3]=clock();
		pthread_create(&ttid[i],&attr,Esearch,D);
	}
	compb[3]=count1;
	compe[3]=count2;
	count1=0;
	count2=0;
	for(i=0;i<4;i++)
	{	
		pthread_join(tid[i],NULL);
		t2[3]=clock();
		pthread_join(ttid[i],NULL);
		t4[3]=clock();
	}
	
	
	for(i=0;i<4;i++)
	{
		c=100000;
		t1[4]=clock();
		pthread_create(&tid[i],&attr,Bsearch,E);
		t3[4]=clock();
		pthread_create(&ttid[i],&attr,Esearch,E);
	}
	compb[4]=count1;
	compe[4]=count2;
	count1=0;
	count2=0;
	for(i=0;i<4;i++)
	{	
		pthread_join(tid[i],NULL);
		t2[4]=clock();
		pthread_join(ttid[i],NULL);
		t4[4]=clock();
	}
	
	/*
	for(i=0;i<4;i++)
	{
		c=600;
		t1[5]=clock();
		pthread_create(&tid[i],&attr,Bsearch,F);
		t3[5]=clock();
		pthread_create(&ttid[i],&attr,Esearch,F);
	}
	compb[5]=count1;
	compe[5]=count2;
	count1=0;
	count2=0;
	
	for(i=0;i<4;i++)
	{	
		pthread_join(tid[i],NULL);
		t2[5]=clock();
		pthread_join(ttid[i],NULL);
		t4[5]=clock();
	}
	*/
	
	printf("\nsize of array|Comp in BS|  time BS  |Comp in ES|  time ES  |\n");
	for(i=0;i<6;i++)
		printf("%5d %15d     %lf %10d     %lf\n",pow(10,i+1),compb[i],(t2[i]-t1[i])/(double)CLOCKS_PER_SEC,compe[i],(t4[i]-t3[i])/(double)CLOCKS_PER_SEC);
	
	
return 0;
}
