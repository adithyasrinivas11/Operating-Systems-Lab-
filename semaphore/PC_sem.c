#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include <stdbool.h>
#include <unistd.h>

#define N 5

int data=1;
int flag=1;

	sem_t mutex;

void * sema(void * param)
{

	int i=(int)param;
	do
	{
		while(flag ==0);
		sem_wait(&mutex);

		flag=1;

		if(i%2 == 0)
			data++;
		else
			data--;

		printf("Process %d: CS %d\n",i, data);
		fflush(stdout);
		sleep(1);

		sem_post(&mutex);

		flag=0;

	} while(true);

	pthread_exit(0);
}

int main()
{

	pthread_t tid[100];
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	sem_init(&mutex,0,1);
	
	for(int i=0; i<N; i++)
	{
		pthread_create(&tid[i], &attr, sema, i);
	}

for(int i=0; i<N; i++)
pthread_join(tid[i], NULL);

	
return 0;
}
