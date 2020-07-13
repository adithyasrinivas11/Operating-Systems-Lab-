#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
# define N 4

int adj[N][N];
float inv[N][N];
int A[N][N];

struct DT
{
	int i;
	int j;
};

void cofactor(int mat[N][N], int temp[N][N], int p, int q, int n)
{

	int i=0, j=0;

	for(int row= 0; row<n; row++)
	{
		for(int col=0; col<n; col++)
		{
			if(row!=p && col!=q)
			{
				temp[i][j++] = mat[row][col];
				if(j==n-1)
				{
					j=0;
					i++;
				}
			}
		}
	}
}

int determinant(int mat[N][N], int n)
{
	
	int D=0;

	if(n==1)
		return mat[0][0];

	int temp[N][N];
	int sign=1;


	for(int f=0; f<n; f++)
	{
		cofactor(mat, temp, 0, f, n);
		D += sign * mat[0][f] * determinant(temp, n-1);

		sign=-sign;
	}
	return D;
}

void* runnercofacval(void *param)
{

	int temp[N][N];
	int sign=1;

	struct DT *data = param;
	cofactor(A, temp, data->i, data->j, N);
	sign = ((data->i + data->j)%2==0) ? 1: -1;
	adj[data->j][data->i] = sign * (determinant(temp, N-1));

	pthread_exit(0);
}

int main()
{
	
	printf("Enter the %d x %d matrix:\n",N,N);
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			scanf("%d",&A[i][j]);
		}
	}


	pthread_t tid[N*N];
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	if(N==1)
	{
		adj[0][0]=1;
	}
	
	else
	{

		int k=0;
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				struct DT *data = (struct DT *) malloc(sizeof(struct DT));

				data->i = i;
				data->j = j;

				pthread_create(&tid[k],&attr, runnercofacval, data);
				k++;
			}
		}
		for(int i=0; i<k; i++)
			pthread_join(tid[i],NULL);

	}
	printf("Adjoint:\n");
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
			printf("%d ",adj[i][j]);
		printf("\n");
	}

	int det = determinant(A, N);
	if(det==0)
	{
		printf("Inverse doesn't exist\n");
		return 0;
	}

	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			inv[i][j]= adj[i][j]/((float)det);

	printf("Inverse:\n");
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
			printf("%f ",inv[i][j]);
		printf("\n");
	}

	return 0;
}