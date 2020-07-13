#include<stdio.h>
#include<semaphore.h>
#include<unistd.h>
#include<pthread.h>

int data=0;
int rcount=0;
sem_t writeblock,mutex;

void *reader (int *param)
{
	int f= param;
	sem_wait(&mutex);
	
	rcount+=1;

	if(rcount>=1)
		sem_wait(&writeblock);
		
	sem_post(&mutex);
	printf("read :: %d <--> %d\n",f,data);
	
	sem_wait(&mutex);
	rcount--;
	
	if(rcount==0)
		sem_post(&writeblock);
	
	sem_post(&mutex);
}

void *writer(void *param)
{
int f=param;
sem_wait(&writeblock);
data++;
printf("write :: %d<--->%d\n",f,data);
//sleep(2);
sem_post(&writeblock);

}


int main()
{
int i;
pthread_t rtid[5],wtid[5];
pthread_attr_t attr;
pthread_attr_init(&attr);
//printf("Starting to thread\n");
sem_init(&mutex,0,1);
sem_init(&writeblock,0,1);
for(i=0;i<5;i++)
{
	pthread_create(&wtid[i],&attr,writer,i);
	pthread_create(&rtid[i],&attr,reader,i);
}

for(i=0;i<5;i++)
{
	pthread_join(wtid[i],NULL);
	pthread_join(rtid[i],NULL);
}

return 0;
}
