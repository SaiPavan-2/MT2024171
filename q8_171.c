/**
Name:q8_171.c
Author:Pavan
DescriptionL:Program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date:22nd August 2024
**/
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
/**
Output:
Writing some data to the file.
2955084264875696819529550842648756968195295508426487569681952955084264875696819529550842648756968195295508426487569681952955084264875696819529550842648
756968195295508426487569681952Added with dup
**/
