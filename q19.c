#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

uint64_t get_tsc() {
    uint32_t low, high;
    asm volatile ("rdtsc" : "=a" (low), "=d" (high));
    return ((uint64_t)high << 32) | low;
}

int main() {
    uint64_t start_time, end_time;
    
    start_time = get_tsc();
    getpid();
    end_time = get_tsc();
    
    printf("Time taken to execute getpid(): %lu clock cycles\n", end_time - start_time);
    
    return 0;
}
/**Output:
Time taken to execute getpid(): 12925 clock cycles
**/
