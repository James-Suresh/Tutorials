#define _XOPEN_SOURCE 700 // required for barriers to work
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/wait.h>

int moving_sum[5];

struct numinfo{
int number;
int index;
}

void* factorial(void *arg){
  printf("hi\n" );
}
int main()
{
pthread_t t1,t2,t3,t4,t5;



printf("Enter the first number\n");

getchar();
  struct args numinfo *n = (struct numinfo *)malloc(sizeof(struct numinfo));
  n->number= getchar()- '0';
  n->index=1;
pthread_create(&t1, NULL, &factorial, (void *)n);
//pthread_join(t1, NULL);

printf("Enter the second number\n");
moving_sum[1]= getchar()- '0';
getchar();
printf("Enter the third number\n");
moving_sum[2]= getchar()- '0';
getchar();
printf("Enter the fourth number\n");
moving_sum[3] = getchar()- '0';
getchar();
printf("Enter the fifth number\n");
moving_sum[4]= getchar()- '0';
getchar();
}
