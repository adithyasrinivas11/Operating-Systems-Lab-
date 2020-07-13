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

void main()
{
//process p[10];
int n=0,i,j,cc;
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

for(i=0;i<5;i++)
	{
	mat[i][1]=t[i]; //arrvial time
	a[i]=t[i];
	mat[i][2]=w[i]; //burst time
	}

int min;
min=a[0];
int m=0;
for(j=0;j<i;j++)
	{
	if(min>a[j])
	{
		min=a[j];
		m=j;
	}
	
	}
	
int r=0;
mat[m][3]=mat[m][2];
mat[m][4]=mat[m][3]-t[m];
mat[m][5]=mat[m][4]-w[m];	
b[m]=1;
n=m;
s=1;
while(1)
{
	r++;
	cc=0;
	for(i=0;i<5;i++)
	{
		if(b[i]!=1)
		{
			if(mat[i][2]<mat[n][4])
				{
				cc=1;
				break;
				}
			else 
				cc=0;	
		}
		
	}
	if(cc==1)
	{
		mat[i][3]=w[i]+mat[n][3];	//ct
		mat[i][4]=mat[i][3]-t[i]; //tat
		mat[i][5]=mat[i][4]-w[i]; //wt
		b[i]=1;
		n=m;
		m=i;
		
		if(r==4)
			break;
	}
	else if (cc==0)
	{	
		
		
		int ii;
		min=222222222;

		for(ii=0;ii<5;ii++)
		{
			if(b[ii]!=1)
			{
				if(min>mat[ii][1])
				{
					min=mat[ii][1];
					m=ii;
				}	
			}
		}
			
		
		mat[m][3]=mat[m][2]+mat[n][3];
		mat[m][4]=mat[m][3]-t[m];
		mat[m][5]=mat[m][4]-w[m];	
		b[m]=1;
		n=m;
		s=b[0]+b[1]+b[2]+b[3]+b[4];
		
		if(r==4)
			break;
	}
		
	
	
}

for(i=0;i<5;i++)
	{for(j=0;j<6;j++)
		printf("%7d",mat[i][j]);
	printf("\n");
	}

}
