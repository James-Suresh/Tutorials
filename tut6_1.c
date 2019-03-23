#define _XOPEN_SOURCE 700 // required for barriers to work
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

int main(void)
{

FILE *fp;
 fp = fopen("Child.txt", "w+");
 fputs("Child 1\n", fp);
 fclose(fp);

 FILE *fp2;

fp2 = fopen("Child2.txt", "w+");
fputs("Child 2\n", fp2);
fclose(fp2);

int c1_process  = fork();
if (c1_process==0)
{
  sleep(1);
  FILE *fp;
  char buffer[255];
   fp = fopen("Child.txt", "r");
   fgets(buffer, 255, (FILE*)fp);
   printf("\n%s\n", buffer);
   fclose(fp);

}

int c2_process;

if(c1_process!=0)
{
c2_process = fork();
}


if (c2_process==0)
{
  sleep(1);
  FILE *fp2;
  char buffer[255];
   fp2 = fopen("Child2.txt", "r");
   fgets(buffer, 255, (FILE*)fp2);
   printf("%s\n", buffer);
   fclose(fp2);
}

return 0;
}
