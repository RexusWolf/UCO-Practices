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

int buffer[TAMBUFFER], producer_addition = 0, consumer_addition = 0;
sem_t mutex, full, empty;

void * Producer();
void * Consumer();

int consumer_addition;
int producer_addition;

int main(int argc, char const *argv[]) {

  extern sem_t mutex, full, empty;
  srand(time(NULL));
  
  if((sem_init(&mutex, 0, 1)) == -1) perror("Error: Couldn't initialize mutex.");
  if((sem_init(&full, 0, 0)) == -1) perror("Error: Couldn't initialize full.");;
  if((sem_init(&empty, 0, TAMBUFFER)) == -1) perror("Error: Couldn't initialize empty.");;

  pthread_t consumer;
  pthread_t producer;
  int thread_status;

  int *consumer_return = 0;
  int *producer_return = 0;


  if((thread_status = pthread_create(&consumer, NULL, Consumer, NULL))) {
    fprintf(stderr, "Failed to create consumer thread.\n");
    exit(thread_status);
  }
  if((thread_status = pthread_create(&producer, NULL, Producer, NULL))) {
    fprintf(stderr, "Failed to create producer thread.\n");
    exit(thread_status);
  }

  if(pthread_join(producer, (void *) &producer_return)) fprintf(stderr, "Error in producer pthread_join\n");
  if(*producer_return == producer_addition){
    printf("Producer addition has been: %d\n", *producer_return);

  }
  if(pthread_join(consumer, (void *) &consumer_return)) fprintf(stderr, "Error in consumer pthread_join\n");
  if(*consumer_return == consumer_addition){
    printf("Consumer addition has been: %d\n", *consumer_return);
  }

  return 0;
}

// Proceso o hilo productor.
void * Producer(){
  extern sem_t mutex, full, empty;
  extern int buffer[TAMBUFFER], producer_addition;
  int number;
  int *to_return;

    for(int i = 0; i<50; i++){
      number = ((rand() % 100) +1);
      sem_wait(&empty);
      sem_wait(&mutex);
      buffer[i % TAMBUFFER] = number;
      producer_addition += buffer[i % TAMBUFFER];
      sem_post(&mutex);
      sem_post(&full);
    }
    to_return = malloc(sizeof(int));
    *to_return = producer_addition;
    pthread_exit((void *)to_return);
  }

// Proceso o hilo consumidor.
void * Consumer(){
  extern sem_t mutex, full, empty;
  extern int buffer[TAMBUFFER], consumer_addition;
  int *to_return;

  for(int i = 0; i < 50; i++){
    sem_wait(&full);
    sem_wait(&mutex);
    consumer_addition += buffer[i % TAMBUFFER];
    buffer[i % TAMBUFFER] = 0;
    sem_post(&mutex);
    sem_post(&empty);
  }
  to_return = malloc(sizeof(int));
  *to_return = consumer_addition;
  pthread_exit((void *)to_return);
}
