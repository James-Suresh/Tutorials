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
};
void *factorial(void *n){
  printf("hi%d\n",((struct numinfo*)n)->number );
pthread_exit(NULL);
}

int main()
{
pthread_t t1,t2,t3,t4,t5;
int in;


printf("Enter the first number\n");


struct  numinfo *n = (struct numinfo *)malloc(sizeof(struct numinfo));
scanf("%d", &n->number);
n->index=1;
pthread_create(&t1, NULL, factorial, (void *)n);
pthread_join(t1, NULL);


printf("Enter the second number\n");
scanf("%d", &n->number);
n->index=1;
pthread_create(&t2, NULL, factorial, (void *)n);
pthread_join(t2, NULL);



printf("Enter the third number\n");
scanf("%d", &n->number);
n->index=1;
pthread_create(&t3, NULL, factorial, (void *)n);
pthread_join(t3, NULL);

printf("Enter the fourth number\n");
scanf("%d", &n->number);
n->index=1;
pthread_create(&t4, NULL, factorial, (void *)n);
pthread_join(t4, NULL);

printf("Enter the fifth number\n");
scanf("%d", &n->number);
n->index=1;
pthread_create(&t5, NULL, factorial, (void *)n);
pthread_join(t5, NULL);
}
