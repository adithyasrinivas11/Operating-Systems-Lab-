#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

struct dat
{
	int i;
};

int flag=1;
bool Interested[100],pass[100];
int K;
int x=5;
int N;

void *dijkstra(void *param)
{
	struct dat *v = (struct dat *)param;
	bool done;
	do
	{
		while (flag==0);
		Interested[v->i] = true;
		do
		{
			
			while(1)
			{
				if(K==v->i)
					break;
				if(!Interested[K])
					K = v->i;
			}
			flag=1;
			pass[v->i] = true;
			done  =true;
			for(int j=0;j<N;j++)
			{
				if(j!=v->i)
				{
					if(pass[j])
					{	
						pass[v->i] = false;
						done = false;
					}
				}
			}
			if(done)
				break;
		}while(1);

		//CS
		if((v->i) %2==0)
			x++;
		else
			x--;

		printf("P: %d %d\n",v->i, x);
		sleep(1);
		//CS ENDS


		pass[v->i] = false;
		Interested[v->i] = false;
		flag=0;


	}while(1);
	pthread_exit(0);
}



int main() 
{
	printf("Enter val of N\n");
	scanf("%d",&N);
	pthread_t t[100];
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	struct dat d[N];
	for(int i=0;i<N;i++)
	{
		d[i].i = i;
		pthread_create(&t[i],&attr,dijkstra,&d[i]);
	}
	//pthread_create(&t1,&attr,run2,NULL);
	for(int i=0;i<N;i++)
		pthread_join(t[i],NULL);

	return 0;

}


