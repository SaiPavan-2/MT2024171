/**
Name:6_171.c
Author:Pavan
Description:Program to take input from STDIN and display on STDOUT
Date:22nd August 2024
**/
#include <unistd.h>
#include <stdlib.h>

int main() {
    char input[1024];
    ssize_t bytes_read;

    while ((bytes_read = read(STDIN_FILENO, input, sizeof(input))) > 0) {
        write(STDOUT_FILENO, input, bytes_read);
    }

    if (bytes_read == -1) {
        write(STDERR_FILENO, "Error\n",6);
        exit(EXIT_FAILURE);
    }

    return 0;
}
/**
Output:
Hello Pavan
Hello Pavan
**/
