#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Give the correct no of arguments");
        return 1;
    }

    int fd = open(argv[1], O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    char data1[] = "7569681952";
    char data2[] = "9550842648";
   off_t offset2= lseek(fd,0,SEEK_END);
   if(offset2==-1){
       perror("Error");
       close(fd);
       return 1;}

    if (write(fd, data1, strlen(data1)) != strlen(data1)) {
        perror("Error writing data1");
        close(fd);
        return 1;
    }
    off_t offset1 = lseek(fd,10,SEEK_CUR);
    if (offset1 == -1) {
        perror("Error");
        close(fd);
        return 1;
    }
    printf("lseek moved the file pointer to: %ld\n", offset1);
    if (write(fd, data2, strlen(data2)) != strlen(data2)) {
        perror("Error writing data2");
        close(fd);
        return 1;
    }
    close(fd);
    return 0;
}
