#include<stdio.h>
#include<string.h>
#include<pthread.h>

char a[1000][20];
int c;

void * palindrome (void * param)
{
	int n=(int)param;
	int l = 0; 
    	int h = strlen(a[n]) - 1; 
  	int f=0;
    // Keep comparing characters while they are same 
	while (h > l) 
	{ 
		if (a[n][l++] != a[n][h--]) 
		{ 
			f=1;  
		} 
	} 

	if(f!=1)
	printf("%s is palindrome\n", a[n]); 
		
}

int main()
{

int i=0,j,f;
FILE *fp;
fp=fopen("/home/adithya/Desktop/os_lab/endsem/test.txt", "r");

while( fscanf(fp,"%s",a[i])!=EOF )
	{
	//printf("%s ",a[i]);
	f=0;
	for(j=0;j<i;j++)
	{
		if(strcmp(a[i],a[j])==0)
		{
			f=1;
			break;
		}
	}
	if(f==0)
		i++;
	else if(f==1)
		bzero(a[i],sizeof(a[i]));	
	}
printf("\n");
c=i;
for(j=0;j<c;j++);
	//printf("*%s ,j= %d",a[j],j);
	
	
/////////////////////////////////////////////////////////////////////////////////
// finding palindrome or not!

pthread_t tid[50];

for(i=0;i<c;i++)
	pthread_create(&tid[i],NULL,palindrome,i);

for(i=0;i<c;i++)
	pthread_join(tid[i],NULL);

	
return 0;
}
