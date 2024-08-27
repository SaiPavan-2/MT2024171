#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
void write_lock(int fd) {
    struct flock lock;
    lock.l_type = F_WRLCK; 
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; 

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Failed to acquire write lock");
        exit(EXIT_FAILURE);
    }
    printf("Write lock acquired.\n");
}
void write_unlock(int fd) {
    struct flock lock;
    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; 

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Failed to release write lock");
        exit(EXIT_FAILURE);
    }
    printf("Write lock released.\n");
}
void read_lock(int fd) {
    struct flock lock;
    lock.l_type = F_RDLCK; 
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; 

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Failed to acquire read lock");
        exit(EXIT_FAILURE);
    }
    printf("Read lock acquired.\n");
}
void read_unlock(int fd) {
    struct flock lock;
    lock.l_type = F_UNLCK; 
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; 

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Failed to release read lock");
        exit(EXIT_FAILURE);
    }
    printf("Read lock released.\n");
}

int main() {
    int fd = open("text.txt", O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    write_lock(fd);
    const char *text = "Writing some data to the file.\n";
    if (write(fd, text, strlen(text)) == -1) {
        perror("Failed to write to file");
        exit(EXIT_FAILURE);
    }
    write_unlock(fd);
    read_lock(fd);
    char buffer[100];
    lseek(fd, 0, SEEK_SET); 
    if (read(fd, buffer, sizeof(buffer)) == -1) {
        perror("Failed to read from file");
        exit(EXIT_FAILURE);
    }
    printf("Data read from file: %s\n", buffer);
    read_unlock(fd);

    close(fd);
    return 0;
}
/** Output:
Write lock acquired.
Write lock released.
Read lock acquired.
Data read from file: Writing some data to the file.
295508426487569681952955084264875696819529550842648756968195295508426
Read lock released.
**/
