#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
  int pid=fork();
  if(pid>0)
  {
    printf("Parent process started:");
    printf("\nParent Process ID=%d",getpid());
    printf("\nNow creating child process");
    printf("\nParent completed");
  }
  else if(pid==0)
  {
     printf("\nchild Process ID=%d",getpid());
     sleep(5);
     printf("\nchild orphan process");
  }
}

