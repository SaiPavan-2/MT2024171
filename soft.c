#include <stdio.h>
#include <unistd.h>
int main(){
if(symlink("file.txt","soft171")==-1){
perror("symlink1");
return 1;}
return 0;
}
