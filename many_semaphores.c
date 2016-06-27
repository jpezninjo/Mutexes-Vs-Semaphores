/* File:     many_sephamores.c
 *
 * Purpose:  Lock and unlock semaphores many times, and report on elapsed time
 *
 * Compile:  gcc -g -Wall -o many_semaphores many_semaphores.c -lpthread
 * Run:      ./many_semaphores <thread_count> <n>
 *              n:  total number of times any semaphore is locked and unlocked
 *                  by each thread
 *
 * Input:    none
 * Output:   Total number of times any semaphore was locked and elapsed time for
 *           the threads
 *
 * Results:  Mutex results with 1 penguin nodes
 *                8.987060e-01s
 *                7.890031e-01s
 *                8.127439e-01s
 *           Semophores results with 1 penguin nodes
 *                1.439553e+01s
 *                1.432214e+01s
 *                1.424277e+01s
 *           Mutex results on lab computer
 *                8.656139e-01s
 *                8.284121e-01s
 *                9.090199e-01s
 *           Semaphores results on lab computer
 *                5.774460e+00s
 *                5.884847e+00s
 *                5.742924e+00s
 * Conclusion: If we compare the worse run times for
 *             all tests, we see that semaphores perform
 *             worse than mutexes in general. Also, semaphores perform 
 *             worse on server nodes than on local (lab) computers with 
 *             drastically longer run times.
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include "timer.h"

int thread_count;
int n;
int total = 0;
sem_t* semaphores;

void Usage(char prog_name[]);
void* Lock_and_unlock(void* rank);

int main(int argc, char* argv[]) {
   pthread_t* thread_handles;
   long thread;
   double start, finish;

   if (argc != 3) Usage(argv[0]);
   thread_count = strtol(argv[1], NULL, 10);
   n = strtol(argv[2], NULL, 10);

   thread_handles = malloc(thread_count*sizeof(pthread_t));
   semaphores = malloc(thread_count*sizeof(sem_t));
   for (thread = 0; thread < thread_count; thread++) {
      /* Initialize all semaphores to 0 -- i.e., locked */
      sem_init(&semaphores[thread], 0, 0);
   }

   GET_TIME(start);
   for (thread = 0; thread < thread_count; thread++)
      pthread_create(&thread_handles[thread], (pthread_attr_t*) NULL,
          Lock_and_unlock, (void*) thread);

   for (thread = 0; thread < thread_count; thread++)
      pthread_join(thread_handles[thread], NULL);

   GET_TIME(finish);

   for (thread = 0; thread < thread_count; thread++) {
      sem_destroy(&semaphores[thread]);
   }

   printf("Total number of times a semaphore was locked and unlocked: %d\n",
         total);
   printf("Elapsed time = %e seconds\n", finish-start);

   free(semaphores);
   free(thread_handles);
   return 0;
}  /* main */

/*---------------------------------------------------------------------
 * Function:   Usage
 * Purpose:    Print a message explaining how to start the program.
 *             Then quit.
 * In arg:     prog_name:  name of program from command line
 */
void Usage(char prog_name[]) {
   fprintf(stderr, "usage: %s <thread_count> <n>\n", prog_name);
   fprintf(stderr, "    n: total number of times all the semaphores are locked");
   fprintf(stderr, " and unlocked by each thread\n");
   exit(0);
}  /* Usage */


/*---------------------------------------------------------------------
 * Function:   Lock_and_unlock
 * Purpose:    Repeatedly lock and unlock individuals of the set of 
 *             semaphores to determine performance
 *             of semaphores
 * In arg:     rank:  thread rank
 * In globals: thread_count:  number of threads
 *             n:  number of times each thread should lock and unlock semaphore 
 *             semaphore:
 * In/out global:  total:  total number of times members of semophores is locked and unlocked.
 */
void* Lock_and_unlock(void* rank) {
   long my_rank = (long) rank;
   long dest = (my_rank + 1) % thread_count;
   int i;

   for (i = 0; i < n; i++) {
      sem_post(&semaphores[dest]);  /* "Unlock" the semaphore of dest */
      total++;
      sem_wait(&semaphores[my_rank]);  /* Wait for our semaphore to be unlocked */
   }

   return NULL;
}  /* Lock_and_unlock */