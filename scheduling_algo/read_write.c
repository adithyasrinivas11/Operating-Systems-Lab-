#include<stdio.h>
#include<semaphore.h>

void * reader(void * param)
{
int f=int(param);
sem_wait(&mutex);
rcount+=1;

if(rcount>=1)
	sem_wait(&writeblock);
	
sem_post(&mutex);

printf("%d <--> %d"data,f);

sleep(5);
sem_wait(&mutex);

rcount--;

if(rcount==0)
	sem_post(&writeblock);
	
sem_post(&mutex);

}

void * writer(void * param)
{
int f=(int)arg;
sem_wait(&writeblock);
data++;
printf("%d<--->%d",f,data);
sleep(3);
sem_post(&writeblock);

}

int data=0;

int main()
{
pthread_t rtid[5],wtid[5];
for(i=0;i<5;i++)
{
	pthread_create(&wtid[i],NULL,writer,i);
	pthread_create(&rtid[i],NULL,reader,i);
}

for(i=0;i<5;i++)
{
	pthread_join(&wtid[i],NULL);
	pthread_join(&rtid[i],NULL);
}

return 0;
}
