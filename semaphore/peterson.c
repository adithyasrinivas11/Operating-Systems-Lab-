#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<stdbool.h>
bool flag[2];

//flag[1]=TRUE;

int turn;
void * process(void * arg)
{
	do
	{
		int i=(int)arg;
		flag[i]=true;
		turn=1-i;
		while(flag[1-i]==true && turn==1-i);
		printf("CS %d\n ",i);
		sleep(2);
		flag[i]=false;
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
