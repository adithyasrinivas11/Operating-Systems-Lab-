#include <stdio.h>

struct queue
{
    int a[100];
    int r,f;
}q;

void enq(int n)
{
   
    if(q.r==-1)
        {
        q.r=q.f=0;
        q.a[q.r]=n;
        }
    else
    {
        q.r++;
        q.a[q.r]=n;
    }

   
}

int deq()
{
    int x=-1;
    if(q.f<=q.r)
        {
        x= q.a[q.f];
        q.f++;
        }
   if(q.f>q.r)
        q.f=q.r=-1;
   
   return x;
}

print()
{
    int i;
    printf("printing::     ");
    for(i=q.f;i<=q.r;i++)
        printf(" %d",q.a[i]);
   
    printf("\n");
}
int main()
{
    q.r=q.f=-1;
    int a[6],at[6],AT[6],b[6],bt[6],BT[6],ct[6],tat[6],wt[6];
    int i,j,min,imin,s=0;
    for(i=0;i<6;i++)
        {
        printf("enter the arrival time %d  \n",i);
        //scanf("%d",&AT[i]);
        AT[i]=i;
        BT[0]=4;
        BT[1]=5;
        BT[2]=2;
        BT[3]=1;
        BT[4]=6;
        BT[5]=3;
        printf("enter the burst time %d \n",i);
        //scanf("%d",&BT[i]);
        at[i]=AT[i];
        bt[i]=BT[i];
        }
    
    int x;  
    int time=0;
    int tq=2;
    for(i=0;i<6;i++)
        {
            if(at[i]<=time+at[0])
            {
                if(a[i]!=1)
                {    
                		a[i]=1;
                		enq(i);
                }
            }
        }
   
    while(1) 
    {
        for(i=0;i<6;i++)
        {
            x=deq();
            if(x!=-1)
            {
           
                if(bt[x]>=tq)
                {  
		           bt[x]-=tq;
		           time+=tq;
                   
		          for(i=0;i<6;i++)
		          {
		              if(at[i]<=time+at[0])
		              {
		                  if(a[i]!=1)
		                  {    
		                  	a[i]=1;
		                  	enq(i);
		                      	//printf("! %d $  %d \n",a[i],i);
		                      	
		                  }
		              }
		          }
               
                
                
                if(bt[x]==0)
                    {
                        ct[x]=time;
                    }
                else
                    {
                    enq(x); 
                    //print();
		        //printf("\n");
                    }
                       
                }
                else
                {
                    time+=bt[x];
                    bt[x]=0;
                    ct[x]=time;
                }
            }
            else
                {
                time+=2;
                break;
                }
        }
        //printf("@@@   %d ",time);
        
        if(bt[0]+bt[1]+bt[2]+bt[3]+bt[4]+bt[5]==0)
        	break;
        //time++;
    }    
   
     for(i=0;i<6;i++)
        {
        tat[i]=ct[i]-AT[i];    
        wt[i]=tat[i]-BT[i];    
        }
    printf("\n   AT    BT    CT    TAT    WT\n");
    for(i=0;i<6;i++)
        printf("%5d %5d %5d %5d %5d\n",AT[i],BT[i],ct[i],tat[i],wt[i]);
   
    return 0;
}
