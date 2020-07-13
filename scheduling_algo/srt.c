#include <stdio.h>

int main()
{
    //printf("Hello World");
   
    int a[6],at[6],AT[6],b[6],bt[6],BT[6],ct[6],tat[6],wt[6];
    int i,j,min,imin;
    for(i=0;i<6;i++)
        {
        //printf("enter the arrival time %d  \n",i);
        //scanf("%d",&AT[i]);
        AT[i]=i;
        BT[0]=8;
        BT[1]=4;
        BT[2]=2;
        BT[3]=1;
        BT[4]=3;
        BT[5]=2;
        //printf("enter the burst time %d \n",i);
        //scanf("%d",&BT[i]);
        at[i]=AT[i];
        bt[i]=BT[i];
        }
       
    int time=0;
    //bt[0]--;
    while(1)
    {
        for(i=0;i<6;i++)
        {
            if(at[i]<=time+at[0])
            {
                a[i]=1;
            }
        }
        //printf("\n");
        min=1000;
        imin=1000;
        for(i=0;i<6;i++)
        {
            if(a[i]==1)
            {
                if(min>bt[i] && bt[i]>0)
                    {
                        min=bt[i];
                        imin=i;
                    }    
            }
        }
        if(min!=1000)
            bt[imin]--;
        else break;    
         //printf("min--= %d imin= %d t=%d \n",bt[imin],imin,time);
        for(i=0;i<6;i++)
            {
                if(b[i]!=1)
                    if(bt[i]==0)
                    {
                        b[i]=1;
                        ct[i]=time+1;
                    }
       
            }
        time++;
        //ct[0]++;
        if(b[0]+b[1]+b[2]+b[3]+b[4]+b[5]==5)
            break;
    }
   
    for(i=0;i<6;i++)
        {
        tat[i]=ct[i]-AT[i];    
        wt[i]=tat[i]-BT[i];    
        }
    printf("  AT   BT   CT   TAT   WT\n");
    for(i=0;i<6;i++)
        printf("%4d %4d %4d %4d %4d\n",AT[i],BT[i],ct[i],tat[i],wt[i]);
   
    return 1;
}
