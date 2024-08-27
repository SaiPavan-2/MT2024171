#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define TICKET_FILE "ticket.dat"

struct ticket_data {
    int ticket_number;
};

void initialize(int fd) {
    struct ticket_data data;
    data.ticket_number = 1; 
    
    if (write(fd, &data, sizeof(data)) != sizeof(data)) {
        perror("Failed to write");
        close(fd);
        exit(EXIT_FAILURE);
    }
    printf("Initial ticket number set to %d.\n", data.ticket_number);
}

void increment(int fd) {
    struct ticket_data data;
    struct flock lock;
    
    lock.l_type = F_WRLCK;  
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = sizeof(data);

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Failed to acquire write lock");
        close(fd);
        exit(EXIT_FAILURE);
    }
    
    if (read(fd, &data, sizeof(data)) != sizeof(data)) {
        perror("Failed to read ticket number");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Current ticket number: %d\n", data.ticket_number);
    data.ticket_number++;
    
    lseek(fd, 0, SEEK_SET); 

    if (write(fd, &data, sizeof(data)) != sizeof(data)) {
        perror("Failed to write new ticket number");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("New ticket number: %d\n", data.ticket_number);

    lock.l_type = F_UNLCK;  
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Failed to release write lock");
        close(fd);
        exit(EXIT_FAILURE);
    }
}

int main() {
    int fd = open(TICKET_FILE, O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    struct ticket_data data;
    if (read(fd, &data, sizeof(data)) != sizeof(data)) {
        lseek(fd, 0, SEEK_SET); 
        initialize(fd);
    }
    lseek(fd, 0, SEEK_SET);
    increment(fd);

    close(fd);
    return 0;
}
/** Output:
**/
