/**
Name:fifo171.c
Author:Pavan
Description:To create FIFO file type
Date:20th august 2024**/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(){
if(mknod("fifo_171",S_IFIFO | 7777,0)==-1){
perror("mknod");
return 1;
}
printf("created");
return 0;
}
/**
Output:created
**/

