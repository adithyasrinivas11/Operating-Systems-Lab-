//#include<iostream>
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
//process p[10];
int n,i,j;

int t1,t2,t3,t4,t5;
int w1,w2,w3,w4,w5;

struct tm* clock1,clock2;               // create a time structure

struct stat attrib1,attrib2;         // create a file attribute structure

stat("a.txt", &attrib1);     // get the attributes of afile.txt

clock1 = gmtime(&(attrib1.st_mtime));
t1=clock1->tm_hour*3600+clock1->tm_min*60+clock1->tm_sec;
//printf("%d \n",t1);
/////////////////////////////////

stat("b.txt", &attrib2);     // get the attributes of afile.txt
clock1 =gmtime(&(attrib2.st_mtime));
t2=clock1->tm_hour*3600+clock1->tm_min*60+clock1->tm_sec;
//printf("%d \n",t2);

/////////////////////////////////

stat("c.txt", &attrib2);     // get the attributes of afile.txt
clock1 =gmtime(&(attrib2.st_mtime));
t3=clock1->tm_hour*3600+clock1->tm_min*60+clock1->tm_sec;
//printf("%d \n",t3);

/////////////////////////////////

stat("d.txt", &attrib2);     // get the attributes of afile.txt
clock1 =gmtime(&(attrib2.st_mtime));
t4=clock1->tm_hour*3600+clock1->tm_min*60+clock1->tm_sec;
//printf("%d \n",t4);

/////////////////////////////////

stat("e.txt", &attrib2);     // get the attributes of afile.txt
clock1 =gmtime(&(attrib2.st_mtime));
t5=clock1->tm_hour*3600+clock1->tm_min*60+clock1->tm_sec;
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

int mat[5][6];

for(i=0;i<5;i++)
	{mat[i][0]=i+1;
	
	}


//arrival time	
mat[0][1]=t1;
mat[1][1]=t2;
mat[2][1]=t3;
mat[3][1]=t4;
mat[4][1]=t5;


//burst time
mat[0][2]=w1;
mat[1][2]=w2;
mat[2][2]=w3;
mat[3][2]=w4;
mat[4][2]=w5;


int temp1,temp2,temp3;
for(i=0;i<5;i++)
	for(j=0;j<4;j++)
	{
	if(mat[j][1]>mat[j+1][1])
		{
		temp1=mat[j][1];
		mat[j][1]=mat[j+1][1];
		mat[j+1][1]=temp1;
		
		temp2=mat[j][0];
		mat[j][0]=mat[j+1][0];
		mat[j+1][0]=temp2;
					
		temp3=mat[j][2];
		mat[j][2]=mat[j+1][2];
		mat[j+1][2]=temp3;
		}
	}

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


for(i=0;i<5;i++)
	{for(j=0;j<6;j++)
		printf("%8d",mat[i][j]);
	printf("\n");
	}
	


}
