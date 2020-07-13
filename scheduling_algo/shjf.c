#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>

#define FILE_READ1 "a.txt"
#define FILE_READ2 "b.txt"
#define FILE_READ3 "c.txt"
#define FILE_READ4 "d.txt"
#define FILE_READ5 "e.txt"

int b[5];

int min(int a[5],int n)
{
printf("**");
int q,mini,imin;
mini=a[0];
imin=0;

for(q=0;q<n;q++)
	{if(mini>a[q] && b[q]!=1)
		{
		mini=a[q];
		imin=q;
		}
	}
printf("!@#$");	
	
return (mini);
}


void main()
{
//process p[10];
int n,i,j;
int k,k1,kk,kk1,s=0;
int t1,t2,t3,t4,t5;
int w1,w2,w3,w4,w5;
int w[5],t[5],a[5];

for(i=0;i<5;i++)
	b[i]=0;
	
	
struct tm* clock1,clock2;               // create a time structure

struct stat attrib1,attrib2;         // create a file attribute structure

stat("a.txt", &attrib1);     // get the attributes of afile.txt

clock1 = gmtime(&(attrib1.st_mtime));
t1=clock1->tm_hour*3600+clock1->tm_min*60+clock1->tm_sec;
t[0]=t1;
//printf("%d \n",t1);
/////////////////////////////////

stat("b.txt", &attrib2);     // get the attributes of afile.txt
clock1 =gmtime(&(attrib2.st_mtime));
t2=clock1->tm_hour*3600+clock1->tm_min*60+clock1->tm_sec;
t[1]=t2;
//printf("%d \n",t2);

/////////////////////////////////

stat("c.txt", &attrib2);     // get the attributes of afile.txt
clock1 =gmtime(&(attrib2.st_mtime));
t3=clock1->tm_hour*3600+clock1->tm_min*60+clock1->tm_sec;
t[2]=t3;
//printf("%d \n",t3);

/////////////////////////////////

stat("d.txt", &attrib2);     // get the attributes of afile.txt
clock1 =gmtime(&(attrib2.st_mtime));
t4=clock1->tm_hour*3600+clock1->tm_min*60+clock1->tm_sec;
t[3]=t4;
//printf("%d \n",t4);

/////////////////////////////////

stat("e.txt", &attrib2);     // get the attributes of afile.txt
clock1 =gmtime(&(attrib2.st_mtime));
t5=clock1->tm_hour*3600+clock1->tm_min*60+clock1->tm_sec;
t[4]=t5;
//printf("%d \n",t5);




FILE * filp;
    int count = 1;
    char c;
    filp = fopen(FILE_READ1, "r");
    if(filp == NULL)
        printf("file not found\n");
    while((c = fgetc(filp)) != EOF) {
        if(c == ' ')
            count++;
    }
    w1=count-1;
    w[0]=w1;

count =1;
FILE * filp1;
    filp1 = fopen(FILE_READ2, "r");
    if(filp1 == NULL)
        printf("file not found\n");
    while((c = fgetc(filp1)) != EOF) {
        if(c == ' ')
            count++;
    }
    w2=count-1;
    w[1]=w2;

count =1;
FILE * filp2;
    filp2 = fopen(FILE_READ3, "r");
    if(filp2 == NULL)
        printf("file not found\n");
    while((c = fgetc(filp2)) != EOF) {
        if(c == ' ')
            count++;
    }
    w3=count-1;
    w[2]=w3;
    
count =1;
FILE * filp3;
    filp3 = fopen(FILE_READ4, "r");
    if(filp3 == NULL)
        printf("file not found\n");
    while((c = fgetc(filp3)) != EOF) {
        if(c == ' ')
            count++;
    }
    w4=count-1;
    w[3]=w4;

count =1;
FILE * filp4;
    filp4 = fopen(FILE_READ5, "r");
    if(filp4 == NULL)
        printf("file not found\n");
    while((c = fgetc(filp4)) != EOF) {
        if(c == ' ')
            count++;
    }
    w5=count-1;
    w[4]=w5;
	

int mat[5][6];

for(i=0;i<5;i++)
	{
	mat[i][0]=i+1;	
	}


//arrival time	
for(i=0;i<5;i++)
	{
	mat[i][1]=t[i]; //arrvial time
	a[i]=t[i];
	mat[i][2]=w[i]; //burst time
	//printf("%d == \n",a[i]);
	}
//printf("!");
//printf("@@@@");
k=min(a,5);
for(i=0;i<5;i++)
{
	if(k==mat[i][1])
		kk=i;
}
//printf("%d   ** ",w[kk]);
int z=0;
mat[kk][3]=w[kk];	//ct
mat[kk][4]=mat[kk][3]-t[kk]; //tat
mat[kk][5]=mat[kk][4]-w[kk]; //wt
b[kk]=1;

for(i=0;i<5;i++)
	printf("%d ",mat[0][i]);

while(s<5)
{
	//printf(" a* %d \n",b[0]);
	n=0;z=0;
	for(i=0;i<5;i++)
	{
		if(b[i]!=1 && mat[i][1]<mat[kk][3])
		{
			z=1;
			a[n]=mat[i][1];
			n++;
			//printf("%d !!! ",a[n-1]);
		}
		
	}
	//printf("%d ** ",n);
	if(s<5 && z==1)
	{
	kk1=kk;
	k=min(a,n);
	for(i=0;i<5;i++)
	{
		if(k==mat[i][1])
			{
			kk=i;
			//printf("kk= %d \n",kk);
			break;
			}
	}
	//printf("%d @@@ ",k);
	mat[kk][3]=w[kk]+mat[kk1][3];	//ct
	mat[kk][4]=mat[kk][3]-t[kk]; //tat
	mat[kk][5]=mat[kk][4]-w[kk]; //wt
	b[kk]=1;
	}
	//for(i=0;i<5;i++)
		//printf(" %d ///// ",b[i]);
	//printf("\n");
	s=b[0]+b[1]+b[2]+b[3]+b[4];
}

/*
//completion time
mat[0][3]=w1;
mat[1][3]=w2+mat[0][3];
mat[2][3]=w3+mat[1][3];
mat[3][3]=w4+mat[2][3];
mat[4][3]=w5+mat[3][3];

//turn around time
mat[0][4]=mat[0][3]-t1;
mat[1][4]=mat[1][3]-t2;
mat[2][4]=mat[2][3]-t3;
mat[3][4]=mat[3][3]-t4;
mat[4][4]=mat[4][3]-t5;

//waiting time
mat[0][5]=mat[0][4]-w1;
mat[1][5]=mat[1][4]-w2;
mat[2][5]=mat[2][4]-w3;
mat[3][5]=mat[3][4]-w4;
mat[4][5]=mat[4][4]-w5;
*/

for(i=0;i<5;i++)
	{for(j=0;j<6;j++)
		printf("%8d",mat[i][j]);
	printf("\n");
	}



}
