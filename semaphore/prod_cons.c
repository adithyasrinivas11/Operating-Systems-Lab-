#include<stdio.h>
#include<pthread.h>
#define BS 20;

int itemcount = 0;
int buf[]

void * producer(void *arg) 
{
    while (true) 
    {
        while( ctr==BS )
        {
        
        }
    }
}

void * consumer(void * arg) 
{
    while (true) 
    {

        if (itemcount == 0) 
        {
            sleep();
        }

        item =buf[] ;//removeItemFromBuffer();
        itemcount = itemcount - 1;

        if (itemcount == BUFFER_SIZE - 1) 
        {
            wakeup(producer);
        }

        consumeItem(item);
    }
}
