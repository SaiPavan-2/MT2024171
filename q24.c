#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        printf("Child process (PID: %d) is running...\n", getpid());
        sleep(10);
        printf("Child process (PID: %d) is still running after parent exit...\n", getpid());
    } else {
        printf("Parent process (PID: %d) is exiting...\n", getpid());
        exit(EXIT_SUCCESS);
    }

    return 0;
}
/**Output:
Parent process (PID: 4754) is exiting...
Child process (PID: 4755) is running...
Child process (PID: 4755) is still running after parent exit...
**/
