#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
int main(){
 struct stat filestatistics;
if(stat("text.txt",&filestatistics)<0){
perror("Error retrieving fileinfo");
return 1;
}
printf("Filename text.txt\n");
printf("Inode--%ld\n",filestatistics.st_ino);
printf("hardlinks%ld\n",filestatistics.st_nlink);
printf("uid-%d\n",filestatistics.st_uid);
printf("gid-%d\n",filestatistics.st_gid);
printf("size-%ld\n",filestatistics.st_size);
printf("block-size-%ld\n",filestatistics.st_blksize);
printf("No of blocks-%ld\n",filestatistics.st_blocks);
printf("Time of last access-%s\n",ctime(&filestatistics.st_atime));
printf("Last modification time-%s\n",ctime(&filestatistics.st_mtime));
printf("Time of last change-%s\n",ctime(&filestatistics.st_ctime));
return 0;
}
/**
Output--
Filename text.txt
Inode--934541
hardlinks1
uid-1000
gid-1000
size-51
block-size-4096
No of blocks-8
Time of last access-Thu Aug 22 08:50:17 2024

Last modification time-Thu Aug 22 08:42:07 2024

Time of last change-Thu Aug 22 08:42:07 2024
**/

