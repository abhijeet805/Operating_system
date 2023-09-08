#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <libgen.h>
#include <stdlib.h>
#include <string.h>


int main()
{
   DIR *dr;
   struct dirent *en;
   int cnt=0;
   int ch;
   printf("Enter command:");
   scanf("%d",&ch);
   
   dr=opendir("Abhi");
   
   if(dr==NULL)
     printf("Dirrectory not found");
   
   if(dr)
   {  
   switch(ch)
   {
    case 1:
   
     while((en=readdir(dr)) !=NULL)
      {  
       printf("%s\n",en->d_name);
       
      }
      break;
    case 2:
       
       while((en=readdir(dr)) !=NULL)
      {  
         cnt++;
      }
      printf("Number of entries=%d",cnt-2);
     case 3:
     
     printf("Files \t inode number\n");
     while((en=readdir(dr)) !=NULL)
      {   
       printf("%li\n",(*en).d_ino);
      }
   }
   
   }
   closedir(dr);
}
