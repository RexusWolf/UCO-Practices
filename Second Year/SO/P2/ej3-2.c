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
#define P 10
#define C 10
#define PPP 50

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

  pthread_t consumer[C];
  pthread_t producer[P];
  int thread_status;

  int *consumer_return = 0;
  int *producer_return = 0;

  for(int i = 0; i < C; i++){
    consumer_id[i] =  i;
    if((thread_status = pthread_create(&consumer[i], NULL, Consumer, (void *) &consumer_id[i]))) {
      fprintf(stderr, "Failed to create consumer thread.\n");
      exit(thread_status);
    }
  }
  for(int i = 0; i < P; i++){
    producer_id[i] =  i;
    if((thread_status = pthread_create(&producer[i], NULL, Producer, (void *) &producer_id[i]))) {
      fprintf(stderr, "Failed to create producer thread.\n");
      exit(thread_status);
    }
  }

  for(int i = 0; i < P; i++){
    if(pthread_join(producer[i], (void *) &producer_return)) fprintf(stderr, "Error in producer pthread_join\n");
    if(*producer_return == producer_addition){
      printf("Producer addition has been: %d\n", *producer_return);
    }
  }

  for(int i = 0; i < P; i++){
  if(pthread_join(consumer[i], (void *) &consumer_return)) fprintf(stderr, "Error in consumer pthread_join\n");
    if(*consumer_return == consumer_addition){
      printf("Consumer addition has been: %d\n", *consumer_return);
    }
  }

  printf("Total producers addition = %d\n", producer_addition);
  printf("Totall consumers addition = %d\n", consumer_addition);

  return 0;
}

// Proceso o hilo productor.
void * Producer(){
  extern sem_t mutex, full, empty;
  extern int buffer[TAMBUFFER], producer_addition, producer_id;
  int number;
  int *to_return, *thread_id = (int *) arg;

  printf("Productor %d\n", *thread_id);
    for(int i = 0; i< PPP; i++){
      number = ((rand() % 100) +1);
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
void * Consumer(){
  extern sem_t mutex, full, empty;
  extern int buffer[TAMBUFFER], consumer_addition, consumer_id;
  int *to_return, *thread_id = (int *) arg;

	printf("Consumidor %d\n", *thread_id);
  for(int i = 0; i < ConsumeProduct(*thread_id); i++){
    sem_wait(&full);
    sem_wait(&mutex);
    consumer_id++;
    consumer_addition += buffer[consumer_id % TAMBUFFER];
    //Sets to 0 for easier debugging (if necessary)
    buffer[consumer_id % TAMBUFFER] = 0;
    sem_post(&mutex);
    sem_post(&empty);
  }
  to_return = malloc(sizeof(int));
  *to_return = consumer_addition;
  pthread_exit((void *)to_return);
}

int ConsumeProduct(int thread_id) {
	int products_per_consumer;
	products_per_consumer = PPP * P / C
	if(thread_id == (C - 1) return;
}
