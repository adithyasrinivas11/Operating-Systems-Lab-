#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<math.h>

int prime(int n)
{
	int f=0;
	for(int i=2;i<=sqrt(n);i++)
		if(n%i==0)
			f=1;
	return f;		
}

int main()
{

	int n,j,i;
	printf("enter the number\n");
	scanf("%d",&n);
	int pid=fork();
		
	if(pid==0)
	{
		int a[100];
		printf("in child %d!\nfibonachi series :\n",n);
		a[0]=0;
		a[1]=1;
		for(i=2;i<=n;i++)
			a[i]=a[i-1]+a[i-2];
			
		printf("Fibo(%d)=%d",n,a[n]);
	}
	else if(pid>0)
	{
		int x;
		printf("in parent!primre generation\n :\n ");			
		for(i=2;i<=n;i++)
		{	
		x=prime(i);
		if(x==0)
			printf("%d ",i);
		}
		printf("\n");
	}

	return 0;
}
