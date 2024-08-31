/**
Name:1b.c
Author:Pavan
Description:Creating hardlink.
Date:20th August 2024"
**/


#include <stdio.h>
#include <unistd.h>
int main(){
if(link("text.txt","hardmt_171")==-1){
perror("link not created");
return 1;}
printf("Hard link created successfully");
return 0;}
/**
Output:
Hard link created successfully
**/


