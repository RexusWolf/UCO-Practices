/*------------------------------------------------------------------------------
Exercise_1.c
In this file, a parent process creates 3 different child processes that print
their own process id (PID). Then the parent process wait until the children end
and print the PID of the process that has finished and its status.
------------------------------------------------------------------------------*/

//key_t
#include <sys/types.h>
//fork() and getpid()
#include <unistd.h>
//exit()
#include <stdlib.h>
//wait()
#include <wait.h>
//printf()
#include <stdio.h>

int main(int argc, char const *argv[]) {


  int status;
    /*
    On success, the PID of the child process is returned in the parent,
    and 0 is returned in the child. On failure, -1 is returned in the parent,
    no child process is created, and errno is set appropriatel
    */
    if (! fork()){ // It's like if (fork() == 0)
      printf("First Child PID = %d\n", getpid() );
      exit(0);
    }

    if (! fork()){
      printf("Second Child PID = %d\n", getpid() );
      exit(0);
    }

    if (! fork()){
      printf("Third Child PID = %d\n", getpid() );
      exit(0);
    }

    for (int i=0; i<3; i++) {
      pid_t pid = wait(&status); // Waits for the process to change its status.
      printf("Child process with PID = %d finished with status: %d\n", pid, WEXITSTATUS(status));
    }


  return 0;
}
