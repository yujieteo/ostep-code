#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int rc;
    int w;
    (void) (rc = fork());

    if (rc < 0) {
        (void) fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (rc == 0) {
        (void) printf("Child: (PID : %d)\n", (int) getpid());
        (void) printf("Hello.\n");
    } else {
        int status;
        // Used waitpid instead of wait.
        (void) (w = waitpid(-1, &status, 0));
        (void) printf("Parent of %d : (PID : %d)\n", rc, (int) getpid());
        (void) printf("Value of waitpid: %d\n", w);
        (void) printf("Goodbye.\n");
    }
    return 0;
}
