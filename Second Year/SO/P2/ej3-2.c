/*
Francisco Javier Molina Prieto
P2 Ejercicio 3.
*/

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>

#define TAMBUFFER 10
#define P 10
#define C 10
#define NPROD 100

int buffer[TAMBUFFER], producer_addition = 0, consumer_addition = 0;
sem_t mutex, full, empty,global;
int consumer_id = 0;
int producer_id = 0;

void * Producer();
void * Consumer();
int ConsumerDistribution(int thread_id);


int main(int argc, char const *argv[]) {

  extern sem_t mutex, full, empty, global;
  srand(time(NULL));

  if((sem_init(&mutex, 0, 1)) == -1) perror("Error: Couldn't initialize mutex.");
  if((sem_init(&full, 0, 0)) == -1) perror("Error: Couldn't initialize full.");
  if((sem_init(&empty, 0, TAMBUFFER)) == -1) perror("Error: Couldn't initialize empty.");
  if((sem_init(&global, 0, 1)) == -1) perror("Error: Couldn't initialize global.");

  pthread_t consumer[C];
  pthread_t producer[P];
  int thread_status;

  int *return_value = 0;

  int consumer_id[C];
  for(int i = 0; i < C; i++){
    consumer_id[i] =  i;
    if((thread_status = pthread_create(&consumer[i], NULL, Consumer, (void *) &consumer_id[i]))) {
      fprintf(stderr, "Failed to create consumer thread.\n");
      exit(thread_status);
    }
  }

  int producer_id[P];
  for(int i = 0; i < P; i++){
    producer_id[i] =  i;
    if((thread_status = pthread_create(&producer[i], NULL, Producer, NULL))) {
      fprintf(stderr, "Failed to create producer thread.\n");
      exit(thread_status);
    }
  }

  for(int i = 0; i < P; i++){
    if(pthread_join(producer[i], (void *) &return_value)) fprintf(stderr, "Error in producer pthread_join\n");
      printf("Producer addition has been: %d\n", *return_value);
  }

  for(int i = 0; i < P; i++){
  if(pthread_join(consumer[i], (void *) &return_value)) fprintf(stderr, "Error in consumer pthread_join\n");
      printf("Consumer %d addition has been: %d\n",i, *return_value);
  }

  printf("Total producers addition = %d\n", producer_addition);
  printf("Total consumers addition = %d\n", consumer_addition);

  return 0;
}

// Proceso o hilo productor.
void * Producer(){
  extern sem_t mutex, full, empty;
  extern int buffer[TAMBUFFER], producer_addition, producer_id;
  int number;
  int *to_return;

  // Nuestro hilo productor producirá PPP productos (no todos acabarán en el hilo).
    for(int i = 0; i< NPROD; i++){
      number = ((rand() % 1000) +1);
      sem_wait(&empty);
      sem_wait(&mutex);
      producer_id++;
      buffer[producer_id % TAMBUFFER] = number;
      producer_addition += number;
      sem_post(&mutex);
      sem_post(&full);
    }
    to_return = malloc(sizeof(int));
    *to_return = producer_addition;
    pthread_exit((void *)to_return);
  }

// Proceso o hilo consumidor.
void * Consumer(void * arg){
  extern sem_t mutex, full, empty;
  extern int buffer[TAMBUFFER], consumer_addition, consumer_id;
  int *to_return;


  for(int i = 0; i < NPROD; i++){
    sem_wait(&full);
    sem_wait(&mutex);
    consumer_id++;
    consumer_addition += buffer[consumer_id % TAMBUFFER];
    buffer[consumer_id % TAMBUFFER] = 0;
    sem_post(&mutex);
    sem_post(&empty);
  }

  to_return = malloc(sizeof(int));
  *to_return = consumer_addition;
  pthread_exit((void *)to_return);
}
