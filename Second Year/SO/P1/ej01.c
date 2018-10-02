#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {

  key_t key;
  int status;

    if (! fork()){
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
      pid_t pid = wait(&status);
      printf("Child process with PID = %d finished with status: %d\n", pid, WEXITSTATUS(status));
    }


  return 0;
}
