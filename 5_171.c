/**
Name:5_171.c
Author:Pavan
Description:Program to create five new files with infinite loop
Date:22nd August 2024
**/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fds[5];
    char *file_names[5] = {"file171_1.txt", "file171_2.txt", "file171_3.txt", "file171_4.txt", "file171_5.txt"};

    while (1) {
        for (int i = 0; i < 5; i++) {
            fds[i] = open(file_names[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fds[i] == -1) {
                perror("Error opening file");
                exit(EXIT_FAILURE);
            }
            write(fds[i], "Power Pavan\n", 13);
	printf("Written into file %d\n",i+1);
            close(fds[i]);
        }

        sleep(1);
    }

    return 0;
}
/**
Output:
Written into file 1
Written into file 2
Written into file 3
Written into file 4
Written into file 5
Written into file 1
Written into file 2
Written into file 3
Written into file 4
Written into file 5
Written into file 1
Written into file 2
Written into file 3
Written into file 4
Written into file 5
Written into file 1
Written into file 2
Written into file 3
Written into file 4
Written into file 5
Written into file 1
Written into file 2
Written into file 3
Written into file 4
Written into file 5
Written into file 1
Written into file 2
Written into file 3
Written into file 4
Written into file 5
Written into file 1
Written into file 2
Written into file 3
Written into file 4
Written into file 5
Written into file 1
Written into file 2
Written into file 3
Written into file 4
Written into file 5
Written into file 1
Written into file 2
Written into file 3
Written into file 4
Written into file 5
Written into file 1
Written into file 2
Written into file 3
Written into file 4
Written into file 5
Written into file 1
Written into file 2
Written into file 3
Written into file 4
Written into file 5
Written into file 1
Written into file 2
Written into file 3
Written into file 4
Written into file 5

**/

