#include <stdio.h>
#include <unistd.h>
int main(){
if(link("file1.txt","hardm171")==-1){
perror("link not created");
return 1;}
return 0;}
