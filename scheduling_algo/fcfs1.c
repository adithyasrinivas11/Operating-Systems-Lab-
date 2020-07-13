#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>

#define FILE_READ1 "a.txt"
#define FILE_READ2 "b.txt"
#define FILE_READ3 "c.txt"
#define FILE_READ4 "d.txt"
#define FILE_READ5 "e.txt"



void main()
{
int b[5],tat[5],wt[5];
int w[5],t[5],i,j;
int t1,t2,t3,t4,t5,w1,w2,w3,w4,w5;
int mat[5][6];

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


for(i=0;i<5;i++)
	{
	mat[i][0]=i+1;	
	b[i]=0;
	}
	
for(i=0;i<5;i++)
	{
	mat[i][1]=t[i]; //arrvial time
	mat[i][2]=w[i]; //burst time
	}

int temp1,temp2,temp3;
for(i=0;i<5;i++)
	for(j=0;j<4;j++)
	{
	if(mat[j][1]>mat[j+1][1])
		{
		
		temp2=mat[j][0];
		mat[j][0]=mat[j+1][0];
		mat[j+1][0]=temp2;
		
		temp1=mat[j][1];
		mat[j][1]=mat[j+1][1];
		mat[j+1][1]=temp1;
					
		temp3=mat[j][2];
		mat[j][2]=mat[j+1][2];
		mat[j+1][2]=temp3;
		}
	}

mat[0][3]=mat[0][1]+mat[0][2];//ct
mat[0][4]=mat[0][3]-mat[0][1];
mat[0][5]=mat[0][4]-mat[0][2];

for(i=1;i<5;i++)
{
	if(mat[i][1]<mat[i-1][3])
		{
		mat[i][3]=mat[i-1][3]+mat[i][2];
		mat[i][4]=mat[i][3]-mat[i][1];
		mat[i][5]=mat[i][4]-mat[i][2];
		}
		
	else 
		{
		mat[i][3]=mat[i][1]+mat[i][2];
		mat[i][4]=mat[i][3]-mat[i][1];
		mat[i][5]=mat[i][4]-mat[i][2];
		}	
}	

for(i=0;i<5;i++)
	{for(j=0;j<6;j++)
		printf("%7d",mat[i][j]);
	printf("\n");
	}
}
