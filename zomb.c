#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main ()
{
  pid_t child_pid;

  child_pid = fork ();
  if (child_pid > 0) { // parent process
   // wait(NULL);   // It is necessary to use wait()
    sleep (15);
  }
  else {
    exit (0);
  }
  return 0;
}