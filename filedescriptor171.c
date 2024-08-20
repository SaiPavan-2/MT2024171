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
