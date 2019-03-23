#define _XOPEN_SOURCE 700 // required for barriers to work
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	printf("\nParent Process\n");
int c1_process=fork();
 wait(NULL);
if (c1_process==0)
{
sleep(1);
printf("Child process\n");
}
if (c1_process!=0)
printf("Parent process complete\n");

return 0;
}
