#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int x;
    int rc;
    (void) (x = 100);
    (void) (rc = fork());

    if (rc < 0) {
        (void) fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (rc == 0) {
        x = 200; // Values differ from parent to child.
        (void) printf("Child: (PID:%d)\n", (int) getpid());
        (void) printf("%d\n", x);
    } else {
        x = 300;
        (void) printf("Parent of %d : (PID:%d)\n", rc, (int) getpid());
        (void) printf("%d\n", x);
    }
    return 0;
}
