#include<stdio.h>
#include<pthread.h>
#include<stdbool.h>

bool enter[2];
int turn;
void * process(void * arg)
{
	do
	{
	int i=(int)arg;
	enter[i]=true;
	{
		if(turn !=i)
		{
		   enter[i]=false;
		   while (turn !=i);    // busy wait
		  
		   enter[i]=true;
		}
	}

	// critical section
	printf("CS %d\n ",i);

	turn=1-i;
	enter[i]=false;
	// remainder section
	}
	while(1);
}


int main()
{
	pthread_t tid[2];
	int i;

for(i=0;i<2;i++)
	pthread_create(&tid[i],NULL,process,i);

for(i=0;i<2;i++)
	pthread_join(tid[i],NULL);



return 0;
}


