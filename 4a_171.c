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
printf("File opened\n",fd);
close(fd);
return 0;
}
