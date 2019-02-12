## Function prototypes

### Threads

* int pthread_create(pthread_t * thread, pthread_attr_t *attr, void * (*start_routine) (void *), void *arg)
  * Creates a thread.
  * If the second argument is NULL, the library assigns default attributes to the thread.
  * Third argument is the function that the thread will execute.
  * Fourth argument is a parameter to this function.
  * Function returns a (**void***) pointer. Argument is casted to (**void***).
* int pthread_join(pthread_t th, void **thread_return)
  * Suspends the calling thread and waits for the *th* thread to end.
  * Second argument is a pointer to pointer that points to the result returned by the thread.
* void pthread_exit (void *retval)
  * retval is a generic pointer to the returned argument of the thread that's going to be collected in pthread_join.
* pthread_t pthread_self(void)
  * This function returns its id to the calling thread.

### Mutex

* int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr)
  * Initialize a mutex.
  * Second argument is the type of mutex that will be created.
* int pthread_mutex_lock(pthread_mutex_t *mutex)
  * Locks the mutex given to enter a critic section of the code.
* int pthread_mutex_unlock (pthread_mutex_t *mutex)
  * Unlocks the mutex given.
* int pthread_mutex_destroy(pthread_mutex_t *mutex)
  * Destroys the mutex.

### Semaphores

* int sem_init(sem_t *sem, int pshared, int value);
  * Initialize a semaphore.
  * Second arguments indicates if the semaphore can be used by threads of the initializer process (0) or not (!0).
  * Initial value assigned to the semaphore (1).
* int sem_wait(sem_t *sem);
  * Locks the semaphore given to enter a critic section of the code.
  * Value of the semaphore is decremented. If the new value is negative, the calling process is blocked.
* int sem_trywait(sem_t *sem);
  * Same function as sem_wait but doesn't blocks the process if the new value is negative.
* int sem_post(sem_t *sem);
  * Unlocks the semaphore, incrementing its value.
* int sem_getvalue(sem_t *sem, int *sval);
  * Returns the value of the semaphore given.
* int sem_destroy(sem_t *sem);
  * Destroys the semaphore given.
