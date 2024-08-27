#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/time.h>

int main() {
    struct timeval tl;
    fd_set readfds;
    tl.tv_sec = 10;
    tl.tv_usec = 0;
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);
    int retval = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &tl);

    if (retval == -1) {
        perror("select"); 
        exit(EXIT_FAILURE);
    } else if (retval) {
        printf("Data is available within 10 seconds.\n");
        char buffer[100];
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            printf("Input received: %s\n", buffer);
        }
    } else {
        printf("No data within 10 seconds. Timeout occurred.\n");
    }

    return 0;
}
/** Output:
pavan@pavan-HP-Pavilion-Laptop-14-dv0xxx:~/.ssh/MT2024171$ ./q13
No data within 10 seconds. Timeout occurred.
pavan@pavan-HP-Pavilion-Laptop-14-dv0xxx:~/.ssh/MT2024171$ ./q13
pavan
Data is available within 10 seconds.
Input received: pavan 
**/
