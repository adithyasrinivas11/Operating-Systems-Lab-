#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<stdbool.h>
#define N 10

bool waiting[10];

//flag[1]=TRUE;
bool t_s(bool * target)
{
	bool rv=*target;
	*target=true;
	
	return rv;
}

int key;
bool lock=false;
int data=0;
void* process(void* arg)
{
	do
	{
		int i=(int)arg;
		waiting[i]=true;
		key=true;
		while(waiting[i]==true && key==true)
			key=t_s(&lock);
			
		if(i%2==0)
			data++;
		else
			data--;
				
		printf("CS %d data =%d\n ",i,data);
		
		sleep(1);
		waiting[i]=false;
		int j=(i+1)%N;
		while(j!=i && waiting[j]==false)
			j=(j+1)%N;
			
		if(j==i)
			lock=false;
		else
			waiting[j]=false;		
	}
	while(1);

}

int main()
{
pthread_t tid[10];
int i;

for(i=0;i<10;i++)
	pthread_create(&tid[i],NULL,process,i);

for(i=0;i<10;i++)
	pthread_join(tid[i],NULL);


return 0;
}
