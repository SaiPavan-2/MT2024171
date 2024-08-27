#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

void file_type(const struct stat *file) {
    if (S_ISREG(file->st_mode)) {
        printf("Regular file\n");
    } else if (S_ISDIR(file->st_mode)) {
        printf("Directory\n");
    } else if (S_ISCHR(file->st_mode)) {
        printf("Character device\n");
    } else if (S_ISBLK(file->st_mode)) {
        printf("Block device\n");
    } else if (S_ISFIFO(file->st_mode)) {
        printf("FIFO (named pipe)\n");
    } else if (S_ISLNK(file->st_mode)) {
        printf("Symbolic link\n");
    } else if (S_ISSOCK(file->st_mode)) {
        printf("Socket\n");
    } else {
        printf("Unknown file type\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *filePath = argv[1];
    struct stat file;

    if (stat(filePath, &file) < 0) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    printf("File: %s\n", filePath);
    printf("File type: ");
    file_type(&file);

    return 0;
}
/** Output:
File: text.txt
File type: Regular file
**/
