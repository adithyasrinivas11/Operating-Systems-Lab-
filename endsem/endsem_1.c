#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <time.h>
#include <string.h>
#include <errno.h>

#define MAX 128

int _heathensCounter = 0;
int _prudesCounter = 0;

pthread_mutex_t _mutex = PTHREAD_MUTEX_INITIALIZER;

sem_t _heathenTurn;
sem_t _prudesTurn;


void *heathens(void *param)
{
	_heathensCounter++;
	printf("\n-- Heathens has arrived\nPrudes: %d\t\t\t\tHeathens: %d\n", _prudesCounter, _heathensCounter);

	sem_wait(&_heathenTurn);

	pthread_mutex_lock(&_mutex);


	_heathensCounter--;
	printf("\nHEATHENS PASSED\nMissing %d Prudes\t\t\t%d Heathens\n", _prudesCounter, _heathensCounter);

	sleep(1);
	if(_prudesCounter > _heathensCounter)
	{
		sem_post(&_prudesTurn);
		printf("[%d] > [%d]\n", _prudesCounter, _heathensCounter);
		printf("\n[More Prudes. Changing the turn to Prudes]\n\n");
	}
	else 
	{
		if(_heathensCounter)
		{
			sem_post(&_heathenTurn);
		}
		else
		{
		printf("\n[The Heathens are over. Changing the turn to Prudes]\n\n");
		sem_post(&_prudesTurn);
		}
	}

	pthread_mutex_unlock(&_mutex);
	pthread_exit(0);

}

void *prudes(void *param)
{

	_prudesCounter++;
	printf("\n-- Prudes arrived\nPrudes: %d\t\t\t\tHeathens: %d\n", _prudesCounter, _heathensCounter);

	sem_wait(&_prudesTurn);

	pthread_mutex_lock(&_mutex);

	_prudesCounter--;
	printf("\nPRUDES PASSED\nmissing %d Prudes\t\t\t%d Heathens\n", _prudesCounter, _heathensCounter);

	sleep(1);
	if(_heathensCounter > _prudesCounter)
	{
		sem_post(&_heathenTurn);
		printf("[%d] > [%d] \n", _heathensCounter,_prudesCounter);
		printf("\nMore Heathens. Changing the turn to Heathens\n\n");
	}
	else
	{
		if(_prudesCounter)
		{
			sem_post(&_prudesTurn);
		}
		else
		{
			printf("\n[The Prudes are over. Changing the turn to Heathens]\n\n");
			sem_post(&_heathenTurn);
		}
	}

	pthread_mutex_unlock(&_mutex);
	pthread_exit(0);
}

int main()
{
	char err_msg[MAX];
	int num_of_Heathens, num_of_Prudes;

	pthread_t *_tidPrudes;
	pthread_t *_tidHeathens;

	printf("How much Heathens? (at least 1)\n");
	scanf("%d", &num_of_Heathens);
	
	if(num_of_Heathens < 1) 
		num_of_Heathens = 20;

	printf("How Much Prudes? (at least 1)\n");
	scanf("%d", &num_of_Prudes);

	if(num_of_Prudes < 1) 
		num_of_Prudes = 20;

	_tidHeathens = (pthread_t *) malloc(num_of_Heathens * sizeof(pthread_t));
	_tidPrudes = (pthread_t *) malloc(num_of_Prudes * sizeof(pthread_t));

	//Heathens have the preference to pass
	if (sem_init(&_heathenTurn, 0, 1) < 0)
	{
		strerror_r(errno, err_msg, MAX);
		printf("Error in sem_init: %s\n", err_msg);
		exit(1);
	}

	if (sem_init(&_prudesTurn, 0, 0) < 0)
	{
		strerror_r(errno, err_msg, MAX);
		printf("Error in sem_init: %s\n", err_msg);
		exit(1);
	}

	printf("\n--------------------- start ----------------------\n");

	//Checks to support different thread numbers

	if(num_of_Heathens > num_of_Prudes)
	{
		for (int i = 0; i < num_of_Heathens; i++)
		{
			pthread_create(&_tidHeathens[i], NULL, &heathens, NULL);
			sleep(1);
			
			if(i<num_of_Prudes)
			 	pthread_create(&_tidPrudes[i], NULL, &prudes, NULL);
		}

		for (int j = 0; j < num_of_Heathens; j++)
		{
			pthread_join(_tidHeathens[j], NULL);
			
			if(j<num_of_Prudes)
				pthread_join(_tidPrudes[j], NULL);
		}
	}
	else
	{
		if(num_of_Prudes > num_of_Heathens)
		{
			for (int i = 0; i < num_of_Prudes; i++)
			{
				pthread_create(&_tidPrudes[i], NULL, &prudes, NULL);
				sleep(1);
				
				if(i<num_of_Heathens) 
					pthread_create(&_tidHeathens[i], NULL, &heathens, NULL);
			}

			for (int j = 0; j < num_of_Prudes; j++)
			{
				pthread_join(_tidPrudes[j], NULL);
				
				if(j<num_of_Heathens) 
					pthread_join(_tidHeathens[j], NULL);
			}
		}
		else
		{
			for (int i = 0; i < num_of_Heathens; i++)
			{
				pthread_create(&_tidPrudes[i], NULL, &prudes, NULL);
				sleep(1);
				pthread_create(&_tidHeathens[i], NULL, &heathens, NULL);
			}

			for (int j = 0; j < num_of_Heathens; j++)
			{
				pthread_join(_tidHeathens[j], NULL);
				pthread_join(_tidPrudes[j], NULL);
			}
		}
	}

	printf("\n---------------------- end -----------------------\n");

	return 0;
}
