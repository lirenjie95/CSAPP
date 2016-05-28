#include "csapp.h"
#define N 2
int main()
{
	int status, i;
	pid_t pid;
	char buf[MAXLINE]
	/* Parent creates N children */
	for (i = 0; i < N; i++) {
		pid = Fork();
		if (pid == 0) /* child */
		/* child attempts to modify first byte of main */
			*(char *)main = 1;
	}
	/* Parent reaps N children in no particular order */
	while ((pid = waitpid(-1, &status, 0)) > 0) {
		if (WIFEXITED(status))
			printf("child %d terminated normally with exit status=%d\n",
			pid, WEXITSTATUS(status));
		else if (WIFSIGNALED(status)) {
			sprintf(buf, "child %d terminated by signal %d",
				pid, WTERMSIG(status));
			psignal(WTERMSIG(status), buf);
		}
	}
	/* The only normal termination is if there are no more children */
	if (errno != ECHILD)
		unix_error("waitpid error");
	exit(0);
}