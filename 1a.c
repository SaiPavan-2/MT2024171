/**
Name:1a.c
Author:Pavan
Description:To create soft link
Date:20th August 2024
**/
#include <stdio.h>
#include <unistd.h>
int main(){
if(symlink("abcd.txt","soft_171")==-1){
perror("symlink1");
return 1;}
printf("Soft link created successfully");
return 0;
}
/**
Output:
Soft link created successfully
**/
