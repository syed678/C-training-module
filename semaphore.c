#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t mutex;
int x=2;
void* thread(void* arg) { //function which act like thread
   sem_wait(&mutex); //wait state ,lock for other if executing thread
   printf("\nEntered into the Critical Section..\n");
   sleep(3); //critical section
   x += 2;
   printf("x = %d\n",x);
   printf("\nCompleted...\n"); //comming out from Critical section
   
  sem_post(&mutex);//  after completetion of current thread ,next thread will execute
}
main() {
   printf("x = %d\n",x);
   sem_init(&mutex, 0, 1);
   pthread_t th1,th2;
   pthread_create(&th1,NULL,thread,NULL);
   sleep(2);
   pthread_create(&th2,NULL,thread,NULL);
   //Join threads with the main thread
   pthread_join(th1,NULL);
   pthread_join(th2,NULL);
   sem_destroy(&mutex);
}
