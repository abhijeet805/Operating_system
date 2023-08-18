#include<stdio.h>
void main()
{
  int i,j,temp,btemp,at[6],bt[6],wt[6],tt[6],sum=0,proc[6],num;
  float avrg,avg;
  printf("Enter the Number of processor=");
  scanf("%d",&num);
  for(i=0;i<num;i++)
  {
    printf("Enter the process Number");
    scanf("%d",&proc[i]);
    printf("Enter the process Arrival time=");
    scanf("%d",&at[i]);
    printf("Enter the process Brust Time=");
    scanf("%d",&bt[i]);
  }
  for(i=0;i<num;i++)
  {
    for(j=i+1;j<num;j++)
    {
      if(at[i]>at[j])
      {
      temp=at[i];
      at[i]=at[j];
      at[j]=temp;
      btemp=bt[i];
      bt[i]=bt[j];
      bt[j]=bt[temp];
      temp=proc[i];
      proc[i]=proc[j];
      proc[j]=temp;
      }
    }
  }
 printf("\nAfter sorting on Arrival time");
 printf("\nProcess\tArrivatl Time \tBrust time");
 for(i=0;i<num;i++)
 {
  printf("\nP%d\t",proc[i]);
  printf("%d\t",at[i]);
  printf("%d\t",bt[i]);
 }
   wt[0]=0;
   for(i=0;i<num;i++)
   {
    wt[i+1]=wt[i]+bt[i];
    sum+=(wt[i]-at[i]);
   }
  wt[num]=wt[num-1]+bt[num-1];
  printf("\nThe waiting time is \t%d",sum);
  avrg=(float)sum/(float)num;
  printf("\nThe Average waiting time is \t%f",avrg);
  sum=0;
  for(i=0;i<num;i++)
  {
    tt[i]=wt[i+1]-at[i];
    sum+=tt[i];
  }
  printf("\nthe sum of turnaround time is \t%d",sum);
  avg=(float)sum/(float)num;
  printf("\nthe average Turnaround time is \t%f",avg);
  printf("\nGantt chart");
  printf("\n-------------------------------------------------------------------------\n");
  for(i=0;i<num;i++)
  {
    printf("|p%d\t",proc[i]);
  } 
  printf("\n-------------------------------------------------------------------------\n");
  for(i=0;i<=num;i++)
  {
    printf("%d\t",wt[i]);
  }
}








