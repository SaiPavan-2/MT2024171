/**
Name:filedescriptor171.c
Author:Pavan
DEscription:Program to create a file and print the file descriptor value
Date:20th August 2024
**/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(){
const char *filepath="filedescriptormt171.txt";
mode_t file_mode=0664;
int fd=creat(filepath,file_mode);
if(fd==-1){
perror("creat failed");
return 1;
}
printf("File descriptor is :%d\n",fd);
if(close(fd)==-1){
perror("close failed");
return 1;
}
return 0;
}
/**
Output:File descriptor is :3
**/
