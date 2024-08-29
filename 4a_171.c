/**
Name:4a_171.c
Author:pavan
Description:Program to open an existing file with read write mode
Date:20 August 2024**/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
int main(){
const char *file_p="filedescriptormt171.txt";
int fd=open(file_p,0666);
if(fd==-1){
perror("open");
return 1;
}
printf("File opened%d\n",fd);
close(fd);
return 0;
}
/**
Output:File opened3
**/
