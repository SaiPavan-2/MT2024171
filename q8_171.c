#include <stdio.h>
int main(){
 FILE *fd=fopen("text.txt","r");

if(fd==NULL){
printf("Error:Could not open file\n");
return 1;
}

char data[256];
while(fgets(data,sizeof(data),fd)){
printf("%s",data);
}

fclose(fd);
return 0;
}
