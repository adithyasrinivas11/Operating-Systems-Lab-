// C++ program to find adjoint and inverse of a matrix 


#include<stdio.h> 
#include<pthread.h>

#define N 4 

/*
// Function to get cofactor of A[p][q] in temp[][]. n is current 
// dimension of A[][] 
void getCofactor(int A[N][N], int temp[N][N], int p, int q, int n) 
{ 
	int i = 0, j = 0; 

	// Looping for each element of the matrix 
	for (int row = 0; row < n; row++) 
	{ 
		for (int col = 0; col < n; col++) 
		{ 
			// Copying into temporary matrix only those element 
			// which are not in given row and column 
			if (row != p && col != q) 
			{ 
				temp[i][j++] = A[row][col]; 

				// Row is filled, so increase row index and 
				// reset col index 
				if (j == n - 1) 
				{ 
					j = 0; 
					i++; 
				} 
			} 
		} 
	} 
} 
*/

int det(int int A[100][100], int n)
int n=3;
int matrix[3][3];
int det;
void* determinant(void * param)//int A[N][N], int n) 
{ 
	int Minor[100][100];
    int i,j,k,c1,c2;
    
    int c[100];
    int O=1;
	det = 0;
    if(n == 2)
    {
        
        det = A[0][0]*A[1][1]-A[0][1]*A[1][0];
        
    }
    else
    {
        for(i = 0 ; i < n ; i++)
        {
            c1 = 0, c2 = 0;
            for(j = 0 ; j < n ; j++)
            {
                for(k = 0 ; k < n ; k++)
                {
                    if(j != 0 && k != i)
                    {
                        Minor[c1][c2] = A[j][k];
                        c2++;
                        if(c2>n-2)
                        {
                            c1++;
                            c2=0;
                        }
                    }
                }
            }
            det = det + O*(A[0][i]*det(Minor,n-1));
            O=-1*O;
        }
    }
    
} 
/*
// Function to get adjoint of A[N][N] in adj[N][N]. 
void adjoint(int A[N][N],int adj[N][N]) 
{ 
	if (N == 1) 
	{ 
		adj[0][0] = 1; 
		return; 
	} 

	// temp is used to store cofactors of A[][] 
	int sign = 1, temp[N][N]; 

	for (int i=0; i<N; i++) 
	{ 
		for (int j=0; j<N; j++) 
		{ 
			// Get cofactor of A[i][j] 
			getCofactor(A, temp, i, j, N); 

			// sign of adj[j][i] positive if sum of row 
			// and column indexes is even. 
			sign = ((i+j)%2==0)? 1: -1; 

			// Interchanging rows and columns to get the 
			// transpose of the cofactor matrix 
			adj[j][i] = (sign)*(determinant(temp, N-1)); 
		} 
	} 
} 

// Function to calculate and store inverse, returns false if 
// matrix is singular 
bool inverse(int A[N][N], float inverse[N][N]) 
{ 
	// Find determinant of A[][] 
	int det = determinant(A, N); 
	if (det == 0) 
	{ 
		cout << "Singular matrix, can't find its inverse"; 
		return false; 
	} 

	// Find adjoint 
	int adj[N][N]; 
	adjoint(A, adj); 

	// Find Inverse using formula "inverse(A) = adj(A)/det(A)" 
	for (int i=0; i<N; i++) 
		for (int j=0; j<N; j++) 
			inverse[i][j] = adj[i][j]/float(det); 

	return true; 
} 

// Generic function to display the matrix. We use it to display 
// both adjoin and inverse. adjoin is integer matrix and inverse 
// is a float. 
template<class T> 
void display(T A[N][N]) 
{ 
	for (int i=0; i<N; i++) 
	{ 
		for (int j=0; j<N; j++) 
			cout << A[i][j] << " "; 
		cout << endl; 
	} 
} 
*/
// Driver program 
int main() 
{ 
	matrix [0][1] =6;
	matrix [0][2] =1;
	matrix [0][3] =1;
	
	matrix [1][1] =4;
	matrix [1][2] =-2;
	matrix [1][3] =5;
	
	matrix [2][1] =2;
	matrix [2][2] =8;
	matrix [2][3] =7;
	 
	//int adj[N][N]; // To store adjoint of A[][] 

	//float inv[N][N]; // To store inverse of A[][] 

	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	
	pthread_create(&tid,&attr,determinant,NULL);
	pthread_join(tid,NULL);
	printf("det=%f\n",det);
	return 0; 
} 

