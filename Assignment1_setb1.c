#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>


void bubblesort(int a1[30],int n)
{
     int i,j,temp;
     for(int i=0;i<n;i++)
     {
        for(j=0;j<n-1;j++)
        {
           if(a1[j]>a1[j+1])
           {
              int t=a1[j];
              a1[j]=a1[j+1];
              a1[j+1]=t;
           }
        }
     }
}

void insertionsort(int a[30],int n)
{
   int pass,i,num; 
   for(pass=1;pass<n;pass++)
  {
      num=a[pass];
      for(i=pass-1;i>=0 && num<a[i];i--)
      {
         a[i+1]=a[i];
      }
      a[i+1]=num;
  }
  
}

void sort()
{
    int a[30],a1[30],n,i,status;
    printf("\nEnter the number of values in array");
    scanf("%d",&n);
    printf("\nEnter the array Element");
    for(i=0;i<n;i++)
       scanf("%d",&a[i]);
    
    printf("\nEnter the array Element");
    for(i=0;i<n;i++)
       scanf("%d",&a1[i]);
       
     int pid=fork();
     if(pid==0)
     {
         sleep(5);
         printf("\nChild process\n");
         printf("Child process id=%d\n",getpid());
         insertionsort(a,n);
         printf("Element sorted using insertion sort\n");
         for(i=0;i<n;i++)
           printf("%d\t",a[i]);
           
           printf("\b");
           printf("\nParent process id=%d\n",getpid());
         
     }
    
    else
    {
       printf("\nparent process\n");
       printf("\nParent process id=%d\n",getpid());
       bubblesort(a1,n); 
       
        printf("Element sorted using bubble sort\n");
         for(i=0;i<n;i++)
           printf("%d\t",a1[i]);
           
              
    }
}

void main()
{
  sort();
  
}
