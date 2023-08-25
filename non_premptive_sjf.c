#include<stdio.h>

void main()
{
  int i,j,n,at[6],bt[6],wt[6],tt[6],proc[6],temp,btemp,sum=0;
  float avg,avrg;
  printf("\nEnter no of procesor=");
  scanf("%d",&n);
  
  for(i=0;i<n;i++)
  {
    printf("\nEnter nber of processor");
    scanf("%d",&proc[i]);
    printf("\nEnter A.T");
    scanf("%d",&at[i]);
    printf("\nEnter B.T");
    scanf("%d",&bt[i]);
  }
  
  for(i=0;i<n;i++)
  {
    if(at[i]==0)
    {
      temp=at[i];
      at[i]=at[j];
      at[j]=temp;
      
      btemp=bt[i];
      bt[i]=bt[j];
      bt[j]=btemp;
    
      temp=proc[i];
      proc[i]=proc[j];
      proc[j]=temp;
    }
  }
  
  for(i=1;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
      if(bt[i]>bt[j])
       {
      temp=at[i];
      at[i]=at[j];
      at[j]=temp;
      
      btemp=bt[i];
      bt[i]=bt[j];
      bt[j]=btemp;
    
      temp=proc[i];
      proc[i]=proc[j];
      proc[j]=temp;
       }
    }
  }
 
   for(i=1;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
      if(bt[i]==bt[j])
       {
       if(at[i]>at[j])
       {
       temp=at[i];
       at[i]=at[j];
       at[j]=temp;
      
       btemp=bt[i];
       bt[i]=bt[j];
       bt[j]=btemp;
    
       temp=proc[i];
       proc[i]=proc[j];
       proc[j]=temp;
       }
      }
    }
  }
  
 printf("\nAfter sorting on Arrival time");
 printf("\nProcess\tArrivatl Time \tBrust time");
 for(i=0;i<n;i++)
 {
  printf("\nP%d\t",proc[i]);
  printf("%d\t",at[i]);
  printf("%d\t",bt[i]);
 }

 wt[0]=0;
   for(i=0;i<n;i++)
   {
    wt[i+1]=wt[i]+bt[i];
    sum+=(wt[i]-at[i]);
   }
  wt[n]=wt[n-1]+bt[n-1];
  printf("\nThe waiting time is \t%d",sum);
  avrg=(float)sum/(float)n;
  printf("\nThe Average waiting time is \t%f",avrg);
  sum=0;
  for(i=0;i<n;i++)
  {
    tt[i]=wt[i+1]-at[i];
    sum+=tt[i];
  }
  printf("\nthe sum of turnaround time is \t%d",sum);
  avg=(float)sum/(float)n;
  printf("\nthe average Turnaround time is \t%f",avg);
  printf("\nGantt chart");
  printf("\n-------------------------------------------------------------------------\n");
  for(i=0;i<n;i++)
  {
    printf("|p%d\t",proc[i]);
  } 
  printf("\n-------------------------------------------------------------------------\n");
  for(i=0;i<=n;i++)
  {
    printf("%d\t",wt[i]);
  } 
  
}
