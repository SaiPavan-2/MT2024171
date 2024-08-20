#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(){
if(mknod("fifo_171",S_IFIFO | 7777,0)==-1){
perror("mknod");
return 1;
}
return 0;
}
