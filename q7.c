/**
Name:q7.c
Author:Pavan
Description:Program to copy file1 into file2
Date:29th August 2024
**/
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void copy_file(const char *source_path, const char *dest_path) {
    FILE *source_file = fopen(source_path, "rb");
    if (source_file == NULL) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    FILE *dest_file = fopen(dest_path, "wb");
    if (dest_file == NULL) {
        perror("Error opening destination file");
        fclose(source_file);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, source_file)) > 0) {
        if (fwrite(buffer, 1, bytes_read, dest_file) != bytes_read) {
            perror("Error writing to destination file");
            fclose(source_file);
            fclose(dest_file);
            exit(EXIT_FAILURE);
        }
    }

    if (ferror(source_file)) {
        perror("Error reading from source file");
    }

    fclose(source_file);
    fclose(dest_file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *source_file = argv[1];
    const char *destination_file = argv[2];

    copy_file(source_file, destination_file);

    printf("File copied successfully from %s to %s\n", source_file, destination_file);

    return 0;
}
/**Output:
File copied successfully from text.txt to abcd.txt
**/
