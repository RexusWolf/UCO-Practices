## Function prototypes

* pid_t fork(void);
  * Creates a process that's a copy of the calling process.
  * System returns Child PID if the calling process is the father.
  * System return 0 if the calling process is the child.
* pid_t getpid(void);
  * Returns the Process ID (PID) of the calling process.
* key_t ftok(const char **pathname*, int *id*);
  * Returns a key based on path and id.
  * Used for sharing memory.
* int shmget(key_t key, size_t size, int shmflg);
  * Similar to *malloc()*.
  * Reserves the shared memory and assigns it to the key.
  * For the third argument we'll use *IPC_CREAT | 0777*
* void ***shmat**(int shmid, const void ***shmaddr**, int shmflg);
  * Assigns a pointer to the shared memory with the given id.
  * For the second argument, we'll use *NULL*.
  * For the third argument, we'll use *0*.
* int shmdt(const void **shmaddr*);
  * Frees the shared memory that the pointer points.
* int shmctl(int shmid, int cmd, struct shmid_ds **buf*);
  * Indicates the system to delete the shared memory.
  * For the second argument we'll use *IPC_RMID*.
  * The third argument is a buffer located in <sys/shm.h>.
* pid_t wait(int **status*);
  * Wait for process to change state.
* pid_t waitpid(pid_t pid, int **status*, int options);
  * Wait for process to change state.
* unsigned int sleep(unsigned int seconds);
  * Waits for the given time (in seconds).
