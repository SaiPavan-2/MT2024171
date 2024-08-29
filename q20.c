#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

int main() {
    pid_t pid = getpid();
    
    int current_priority = getpriority(PRIO_PROCESS, pid);
    printf("Current priority of the process (PID: %d): %d\n", pid, current_priority);

    int change = 1;
    int new_priority = nice(change);
    
    current_priority = getpriority(PRIO_PROCESS, pid);
    printf("New priority of the process (PID: %d): %d\n", pid, current_priority);

    return 0;
}
/**
Output:
Current priority of the process (PID: 4436): 0
New priority of the process (PID: 4436): 1
**/
