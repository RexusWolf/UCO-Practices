## Function prototypes

* pid_t fork(void);
* pid_t getpid(void);
* key_t ftok(const char *pathname, int * proj_id);
* int shmget(key_t key, size_t size, int shmflg);
* void *shmat(int shmid, const void *shmaddr, int shmflg);
* int shmdt(const void *shmaddr);
* int shmctl(int shmid, int cmd, struct shmid_ds *buf);
* pid_t wait(int *status);
* pid_t waitpid(pid_t pid, int *status, int options);
* unsigned int sleep(unsigned int seconds);
