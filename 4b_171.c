/**
Name:4b_171.c
Author:Pavan
Description:program to open an existing file with read write mode(O_EXCL flag)
Date:29th August 2024
**/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char *filename = "abcd.txt";
    int fd;

    fd = open(filename, O_RDWR);
    if (fd == -1) {
        perror("Error opening file with O_RDWR");
        exit(EXIT_FAILURE);
    }
    printf("File opened with O_RDWR successfully.\n");

    int fd_excl;
    fd_excl = open(filename, O_RDWR | O_EXCL);
    if (fd_excl == -1) {
        perror("Error opening file with O_RDWR | O_EXCL");
    } else {
        printf("File opened with O_RDWR | O_EXCL successfully.\n");
        close(fd_excl);
    }

    close(fd);
    return 0;
}
/**
Output:
File opened with O_RDWR successfully.
File opened with O_RDWR | O_EXCL successfully.
**/
