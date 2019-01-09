/*
Francisco Javier Molina Prieto
P2 Ejercicio 3.
*/

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>

#define TAMBUFFER 20
#define NPROD 100

//Buffer where producer sets data and consumer reads and extract data
int buffer[TAMBUFFER];
//Variables where addition of consumer and producer are stored
int producer_addition = 0, consumer_addition = 0;
//Binary semaphore for mutual exclusion between consumer and producer
sem_t mutex;
//General semaphore that counts number of ocupied spaces in buffer
sem_t full;
//General semaphore that counts number of free spaces in buffer
sem_t empty;

//Function headers
void * Producer();
void * Consumer();

int main(int argc, char const *argv[]) {

  //Global variables
  extern sem_t mutex, full, empty;
  srand(time(NULL));

  //Initialisation of semaphores
  if((sem_init(&mutex, 0, 1)) == -1) perror("Error: Couldn't initialize mutex.");
  if((sem_init(&full, 0, 0)) == -1) perror("Error: Couldn't initialize full.");;
  if((sem_init(&empty, 0, TAMBUFFER)) == -1) perror("Error: Couldn't initialize empty.");;

  //Threads variables
  pthread_t consumer;
  pthread_t producer;
  int thread_status;

  //Local additions (checks global producer and consumer additions)
  int *consumer_return = 0;
  int *producer_return = 0;

  //Creates consumer
  if((thread_status = pthread_create(&consumer, NULL, Consumer, NULL))) {
    fprintf(stderr, "Failed to create consumer thread.\n");
    exit(thread_status);
  }

  //Creates producer
  if((thread_status = pthread_create(&producer, NULL, Producer, NULL))) {
    fprintf(stderr, "Failed to create producer thread.\n");
    exit(thread_status);
  }

  //Waits producer
  if(pthread_join(producer, (void *) &producer_return)) fprintf(stderr, "Error in producer pthread_join\n");
  if(*producer_return == producer_addition){
    printf("Producer addition has been: %d\n", *producer_return);

  }

  //Waits consumer
  if(pthread_join(consumer, (void *) &consumer_return)) fprintf(stderr, "Error in consumer pthread_join\n");
  if(*consumer_return == consumer_addition){
    printf("Consumer addition has been: %d\n", *consumer_return);
  }

  return 0;
}

// Hilo productor.
void * Producer(){

    extern sem_t mutex, full, empty;
    extern int buffer[TAMBUFFER], producer_addition;
    int number; // Random number.
    int *to_return;

    for(int i = 0; i<NPROD; i++){
      number = ((rand() % 1000) +1);
      sem_wait(&empty); // Decrements empty semaphore.
      sem_wait(&mutex); // Decrements binary semaphore and enters Crit Section.
      buffer[i % TAMBUFFER] = number;
      producer_addition += buffer[i % TAMBUFFER];
      sem_post(&mutex); // Increrments binary semaphore and exits Crit Section.
      sem_post(&full);  // Increrments full semaphore.
    }
    to_return = malloc(sizeof(int)); // Reserves memory for return pointer.
    *to_return = producer_addition;  // Assigns total addition to r_pointer.
    pthread_exit((void *)to_return); // Exits  thread and returns value.

  }

// Proceso o hilo consumidor.
void * Consumer(){
  extern sem_t mutex, full, empty;
  extern int buffer[TAMBUFFER], consumer_addition;
  int *to_return;

  for(int i = 0; i < NPROD; i++){
    sem_wait(&full);  // Decrements full semaphore.
    sem_wait(&mutex); // Decrements binary semaphore and enters Crit Section.
    consumer_addition += buffer[i % TAMBUFFER];
    buffer[i % TAMBUFFER] = 0;
    sem_post(&mutex); // Increrments binary semaphore and exits Crit Section.
    sem_post(&empty); // Increrments empty semaphore.
  }
  to_return = malloc(sizeof(int)); // Reserves memory for return pointer.
  *to_return = consumer_addition;  // Assigns total addition to r_pointer.
  pthread_exit((void *)to_return); // Exits  thread and returns value.
}
