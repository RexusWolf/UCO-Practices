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

//Buffer where producer sets data and consumer reads and extract data
int buffer[TAMBUFFER];
//Variables where addition of consumers and producers are stored
int consumer_addition = 0;
int producer_addition = 0;
//Indices for producers and consumers. In this second part, the iterator can not be
//used as index anymore because it is not common for all producers/consumers threads
int consumer_id = 0;
int producer_id = 0;
//Binary semaphore for mutual exclusion between consumer and producer
sem_t mutex;
//General semaphore that counts number of ocupied spaces in buffer
sem_t full;
//General semaphore that counts number of empty spaces in buffer
sem_t empty;

//Function headers
void * Consumer();
void * Producer();

int main(int argc, char const *argv[]) {
  //Global variables
  extern sem_t mutex, full, empty, global;
  srand(time(NULL));

  //Initialisation of semaphores
  if((sem_init(&mutex, 0, 1)) == -1) perror("Error: Couldn't initialize mutex.");
  if((sem_init(&full, 0, 0)) == -1) perror("Error: Couldn't initialize full.");
  if((sem_init(&empty, 0, TAMBUFFER)) == -1) perror("Error: Couldn't initialize empty.");

  //Threads variables
  pthread_t consumer[C];
  pthread_t producer[P];
  int thread_status;

  int *return_value = 0;

  //Create producers
  for(int i = 0; i < P; i++){
    if((thread_status = pthread_create(&producer[i], NULL, Producer, NULL))) {
      fprintf(stderr, "Failed to create producer thread.\n");
      exit(thread_status);
    }
  }
  //Create consumers
  for(int i = 0; i < C; i++){
    if((thread_status = pthread_create(&consumer[i], NULL, Consumer, NULL))) {
      fprintf(stderr, "Failed to create consumer thread.\n");
      exit(thread_status);
    }
  }
  //Wait producers
  for(int i = 0; i < P; i++){
    if(pthread_join(producer[i], (void *) &return_value)) fprintf(stderr, "Error in producer pthread_join\n");
      printf("Producer addition has been: %d\n", *return_value);
  }
  //Wait consumers
  for(int i = 0; i < C; i++){
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
  // Necesitaremos un iterador global para productores (producer_id).
  extern int buffer[TAMBUFFER], producer_addition, producer_id;
  int number;
  int *to_return;

  // Nuestro hilo productor producirá NPROD productos (no todos acabarán en el hilo).
    for(int i = 0; i< NPROD; i++){
      number = ((rand() % 1000) +1);
      sem_wait(&empty);
      sem_wait(&mutex);
      producer_id++; // Aumentamos el iterador.
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
  // Necesitaremos un iterador global para consumidores (consumer_id).
  extern int buffer[TAMBUFFER], consumer_addition, consumer_id;
  int *to_return;

  for(int i = 0; i < NPROD; i++){
    sem_wait(&full);
    sem_wait(&mutex);
    consumer_id++; // Aumentamos el iterador.
    consumer_addition += buffer[consumer_id % TAMBUFFER];
    buffer[consumer_id % TAMBUFFER] = 0;
    sem_post(&mutex);
    sem_post(&empty);
  }

  to_return = malloc(sizeof(int));
  *to_return = consumer_addition;
  pthread_exit((void *)to_return);
}
