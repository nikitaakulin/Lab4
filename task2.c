#include <stdio.h>
#include <unistd.h>


int main(int argc, char **argv) 
{
    for (int i = 0; i < 10; i++) 
	{
	    //create 10 child processes
		pid_t child_pid = fork();
		if (child_pid == 0) 
		{
			sleep(5);
			//we havent send  SIGCHLD, so it remains in PID
			return 0;
		}
		printf("PID = %d\n", child_pid);
	}
	execl("/bin/ps", "ps", "-a", NULL);
}
