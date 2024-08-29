/**
Name:q27.c
Author:Pavan
Description:Program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execle
d. execv
e. execvp
Date:29th August 2024
**/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        execl("/bin/ls", "ls", "-Rl", NULL);
        perror("execl failed");
        exit(EXIT_FAILURE);
    }
    wait(NULL);
    pid = fork();
    if (pid == 0) {
        execlp("ls", "ls", "-Rl", NULL);
        perror("execlp failed");
        exit(EXIT_FAILURE);
    }
    wait(NULL);
    pid = fork();
    if (pid == 0) {
        char *env[] = { NULL };
        execle("/bin/ls", "ls", "-Rl", NULL, env);
        perror("execle failed");
        exit(EXIT_FAILURE);
    }
    wait(NULL);
    pid = fork();
    if (pid == 0) {
        char *args[] = { "ls", "-Rl", NULL };
        execv("/bin/ls", args);
        perror("execv failed");
        exit(EXIT_FAILURE);
    }
    wait(NULL);
    pid = fork();
    if (pid == 0) {
        char *args[] = { "ls", "-Rl", NULL };
        execvp("ls", args);
        perror("execvp failed");
        exit(EXIT_FAILURE);
    }
    wait(NULL);

    return 0;
}
/**Output:
.:
total 632
-rwxrwxr-x 1 pavan pavan 16264 Aug 27 04:56 10_171
-rw-rw-r-- 1 pavan pavan  1099 Aug 27 05:04 10_171.c
-rwxrwxr-x 1 pavan pavan 16088 Aug 20 19:40 4a_171
-rw-rw-r-- 1 pavan pavan   254 Aug 20 19:40 4a_171.c
-rw-rw-r-- 1 pavan pavan     1 Aug 20 19:46 4b_171.c
-rwxrwxr-x 1 pavan pavan 16168 Aug 22 06:14 5_171
-rw-rw-r-- 1 pavan pavan   609 Aug 22 06:14 5_171.c
-rwxrwxr-x 1 pavan pavan 16096 Aug 22 07:34 6_171
-rw-rw-r-- 1 pavan pavan   353 Aug 22 07:34 6_171.c
-rwxrwxr-x 1 pavan pavan 16176 Aug 22 18:27 9_171
-rw-rw-r-- 1 pavan pavan  1031 Aug 22 18:28 9_171.c
-rwxrwxr-x 1 pavan pavan 15968 Aug 29 06:17 example
-rw-rw-r-- 1 pavan pavan   199 Aug 29 06:17 example.c
prw-rw-r-- 1 pavan pavan     0 Aug 20 16:22 fifo171
-rw-rw-r-- 1 pavan pavan   161 Aug 20 16:32 fifo171.c
-rw-r--r-- 1 pavan pavan    13 Aug 22 06:28 file171_1.txt
-rw-r--r-- 1 pavan pavan    13 Aug 22 06:28 file171_2.txt
-rw-r--r-- 1 pavan pavan    13 Aug 22 06:28 file171_3.txt
-rw-r--r-- 1 pavan pavan    13 Aug 22 06:28 file171_4.txt
-rw-r--r-- 1 pavan pavan    13 Aug 22 06:28 file171_5.txt
-rw-rw-r-- 3 pavan pavan    59 Aug 29 05:35 file1.txt
-rwxrwxr-x 1 pavan pavan 16104 Aug 20 16:56 filedescriptor
-rwxrwxr-x 1 pavan pavan 16104 Aug 20 16:57 filedescriptor171
-rw-rw-r-- 1 pavan pavan   329 Aug 20 16:56 filedescriptor171.c
-rw-rw-r-- 1 pavan pavan     0 Aug 20 16:57 filedescriptormt171.txt
-rw-rw-r-- 2 pavan pavan    13 Aug 20 15:58 file.txt
-rw-rw-r-- 3 pavan pavan    59 Aug 29 05:35 hard1
-rwxrwxr-x 1 pavan pavan 16008 Aug 20 16:17 hard171
-rw-rw-r-- 1 pavan pavan   139 Aug 20 16:17 hard171.c
-rw-rw-r-- 2 pavan pavan    13 Aug 20 15:58 hard2
-rw-rw-r-- 3 pavan pavan    59 Aug 29 05:35 hardm171
-rwxrwxr-x 1 pavan pavan 15784 Aug 20 16:39 infinite171
-rw-rw-r-- 1 pavan pavan    55 Aug 20 16:36 infinite171.c
-rwxrwxr-x 1 pavan pavan 16504 Aug 27 05:14 q11
-rw-rw-r-- 1 pavan pavan  2349 Aug 27 05:17 q11.c
-rwxrwxr-x 1 pavan pavan 16248 Aug 27 05:30 q12
-rw-rw-r-- 1 pavan pavan  1421 Aug 27 05:31 q12.c
-rwxrwxr-x 1 pavan pavan 16264 Aug 27 05:38 q13
-rw-rw-r-- 1 pavan pavan  1001 Aug 27 05:38 q13.c
-rwxrwxr-x 1 pavan pavan 16280 Aug 27 05:54 q14
-rw-rw-r-- 1 pavan pavan  1150 Aug 27 05:55 q14.c
-rwxrwxr-x 1 pavan pavan 16032 Aug 27 05:57 q15
-rw-rw-r-- 1 pavan pavan  3513 Aug 27 05:58 q15.c
-rwxrwxr-x 1 pavan pavan 16568 Aug 27 06:17 q16
-rw-rw-r-- 1 pavan pavan  2268 Aug 27 06:17 q16.c
-rw------- 1 pavan pavan     1 Aug 27 06:39 q16.c.save
-rwxrwxr-x 1 pavan pavan 16416 Aug 27 06:26 q17
-rw-rw-r-- 1 pavan pavan  1924 Aug 27 06:26 q17.c
-rw------- 1 pavan pavan  2111 Aug 27 06:39 q17.c.save
-rwxrwxr-x 1 pavan pavan 16032 Aug 29 05:18 q19
-rw-rw-r-- 1 pavan pavan   505 Aug 29 05:20 q19.c
-rwxrwxr-x 1 pavan pavan 16096 Aug 29 05:25 q20
-rw-rw-r-- 1 pavan pavan   620 Aug 29 05:26 q20.c
-rwxrwxr-x 1 pavan pavan 16128 Aug 27 06:30 q21
-rw-rw-r-- 1 pavan pavan   508 Aug 27 06:30 q21.c
-rwxrwxr-x 1 pavan pavan 16208 Aug 29 05:35 q22
-rw-rw-r-- 1 pavan pavan   745 Aug 29 05:35 q22.c
-rwxrwxr-x 1 pavan pavan 16168 Aug 27 06:36 q23
-rw-rw-r-- 1 pavan pavan   919 Aug 27 06:37 q23.c
-rwxrwxr-x 1 pavan pavan 16168 Aug 29 05:41 q24
-rw-rw-r-- 1 pavan pavan   727 Aug 29 05:44 q24.c
-rwxrwxr-x 1 pavan pavan 16264 Aug 29 06:04 q25
-rw-rw-r-- 1 pavan pavan  3043 Aug 29 06:09 q25.c
-rwxrwxr-x 1 pavan pavan 16264 Aug 29 06:19 q26
-rw-rw-r-- 1 pavan pavan  1050 Aug 29 06:20 q26.c
-rwxrwxr-x 1 pavan pavan 16344 Aug 29 06:27 q27
-rw-rw-r-- 1 pavan pavan  1066 Aug 29 06:27 q27.c
-rwxrwxr-x 1 pavan pavan 16184 Aug 22 08:56 q8_171
-rw-rw-r-- 1 pavan pavan   229 Aug 22 08:56 q8_171.c
-rwxrwxr-x 1 pavan pavan 16008 Aug 20 16:09 soft
lrwxrwxrwx 1 pavan pavan     8 Aug 20 16:02 soft1 -> file.txt
lrwxrwxrwx 1 pavan pavan     8 Aug 20 16:09 soft171 -> file.txt
-rw-rw-r-- 1 pavan pavan   133 Aug 20 16:09 soft.c
-rw-rw-r-- 1 pavan pavan   342 Aug 27 06:17 text.txt
-rw-rw-r-- 1 pavan pavan     4 Aug 27 06:27 ticket.dat
.:
total 632
-rwxrwxr-x 1 pavan pavan 16264 Aug 27 04:56 10_171
-rw-rw-r-- 1 pavan pavan  1099 Aug 27 05:04 10_171.c
-rwxrwxr-x 1 pavan pavan 16088 Aug 20 19:40 4a_171
-rw-rw-r-- 1 pavan pavan   254 Aug 20 19:40 4a_171.c
-rw-rw-r-- 1 pavan pavan     1 Aug 20 19:46 4b_171.c
-rwxrwxr-x 1 pavan pavan 16168 Aug 22 06:14 5_171
-rw-rw-r-- 1 pavan pavan   609 Aug 22 06:14 5_171.c
-rwxrwxr-x 1 pavan pavan 16096 Aug 22 07:34 6_171
-rw-rw-r-- 1 pavan pavan   353 Aug 22 07:34 6_171.c
-rwxrwxr-x 1 pavan pavan 16176 Aug 22 18:27 9_171
-rw-rw-r-- 1 pavan pavan  1031 Aug 22 18:28 9_171.c
-rwxrwxr-x 1 pavan pavan 15968 Aug 29 06:17 example
-rw-rw-r-- 1 pavan pavan   199 Aug 29 06:17 example.c
prw-rw-r-- 1 pavan pavan     0 Aug 20 16:22 fifo171
-rw-rw-r-- 1 pavan pavan   161 Aug 20 16:32 fifo171.c
-rw-r--r-- 1 pavan pavan    13 Aug 22 06:28 file171_1.txt
-rw-r--r-- 1 pavan pavan    13 Aug 22 06:28 file171_2.txt
-rw-r--r-- 1 pavan pavan    13 Aug 22 06:28 file171_3.txt
-rw-r--r-- 1 pavan pavan    13 Aug 22 06:28 file171_4.txt
-rw-r--r-- 1 pavan pavan    13 Aug 22 06:28 file171_5.txt
-rw-rw-r-- 3 pavan pavan    59 Aug 29 05:35 file1.txt
-rwxrwxr-x 1 pavan pavan 16104 Aug 20 16:56 filedescriptor
-rwxrwxr-x 1 pavan pavan 16104 Aug 20 16:57 filedescriptor171
-rw-rw-r-- 1 pavan pavan   329 Aug 20 16:56 filedescriptor171.c
-rw-rw-r-- 1 pavan pavan     0 Aug 20 16:57 filedescriptormt171.txt
-rw-rw-r-- 2 pavan pavan    13 Aug 20 15:58 file.txt
-rw-rw-r-- 3 pavan pavan    59 Aug 29 05:35 hard1
-rwxrwxr-x 1 pavan pavan 16008 Aug 20 16:17 hard171
-rw-rw-r-- 1 pavan pavan   139 Aug 20 16:17 hard171.c
-rw-rw-r-- 2 pavan pavan    13 Aug 20 15:58 hard2
-rw-rw-r-- 3 pavan pavan    59 Aug 29 05:35 hardm171
-rwxrwxr-x 1 pavan pavan 15784 Aug 20 16:39 infinite171
-rw-rw-r-- 1 pavan pavan    55 Aug 20 16:36 infinite171.c
-rwxrwxr-x 1 pavan pavan 16504 Aug 27 05:14 q11
-rw-rw-r-- 1 pavan pavan  2349 Aug 27 05:17 q11.c
-rwxrwxr-x 1 pavan pavan 16248 Aug 27 05:30 q12
-rw-rw-r-- 1 pavan pavan  1421 Aug 27 05:31 q12.c
-rwxrwxr-x 1 pavan pavan 16264 Aug 27 05:38 q13
-rw-rw-r-- 1 pavan pavan  1001 Aug 27 05:38 q13.c
-rwxrwxr-x 1 pavan pavan 16280 Aug 27 05:54 q14
-rw-rw-r-- 1 pavan pavan  1150 Aug 27 05:55 q14.c
-rwxrwxr-x 1 pavan pavan 16032 Aug 27 05:57 q15
-rw-rw-r-- 1 pavan pavan  3513 Aug 27 05:58 q15.c
-rwxrwxr-x 1 pavan pavan 16568 Aug 27 06:17 q16
-rw-rw-r-- 1 pavan pavan  2268 Aug 27 06:17 q16.c
-rw------- 1 pavan pavan     1 Aug 27 06:39 q16.c.save
-rwxrwxr-x 1 pavan pavan 16416 Aug 27 06:26 q17
-rw-rw-r-- 1 pavan pavan  1924 Aug 27 06:26 q17.c
-rw------- 1 pavan pavan  2111 Aug 27 06:39 q17.c.save
-rwxrwxr-x 1 pavan pavan 16032 Aug 29 05:18 q19
-rw-rw-r-- 1 pavan pavan   505 Aug 29 05:20 q19.c
-rwxrwxr-x 1 pavan pavan 16096 Aug 29 05:25 q20
-rw-rw-r-- 1 pavan pavan   620 Aug 29 05:26 q20.c
-rwxrwxr-x 1 pavan pavan 16128 Aug 27 06:30 q21
-rw-rw-r-- 1 pavan pavan   508 Aug 27 06:30 q21.c
-rwxrwxr-x 1 pavan pavan 16208 Aug 29 05:35 q22
-rw-rw-r-- 1 pavan pavan   745 Aug 29 05:35 q22.c
-rwxrwxr-x 1 pavan pavan 16168 Aug 27 06:36 q23
-rw-rw-r-- 1 pavan pavan   919 Aug 27 06:37 q23.c
-rwxrwxr-x 1 pavan pavan 16168 Aug 29 05:41 q24
-rw-rw-r-- 1 pavan pavan   727 Aug 29 05:44 q24.c
-rwxrwxr-x 1 pavan pavan 16264 Aug 29 06:04 q25
-rw-rw-r-- 1 pavan pavan  3043 Aug 29 06:09 q25.c
-rwxrwxr-x 1 pavan pavan 16264 Aug 29 06:19 q26
-rw-rw-r-- 1 pavan pavan  1050 Aug 29 06:20 q26.c
-rwxrwxr-x 1 pavan pavan 16344 Aug 29 06:27 q27
-rw-rw-r-- 1 pavan pavan  1066 Aug 29 06:27 q27.c
-rwxrwxr-x 1 pavan pavan 16184 Aug 22 08:56 q8_171
-rw-rw-r-- 1 pavan pavan   229 Aug 22 08:56 q8_171.c
-rwxrwxr-x 1 pavan pavan 16008 Aug 20 16:09 soft
lrwxrwxrwx 1 pavan pavan     8 Aug 20 16:02 soft1 -> file.txt
lrwxrwxrwx 1 pavan pavan     8 Aug 20 16:09 soft171 -> file.txt
-rw-rw-r-- 1 pavan pavan   133 Aug 20 16:09 soft.c
-rw-rw-r-- 1 pavan pavan   342 Aug 27 06:17 text.txt
-rw-rw-r-- 1 pavan pavan     4 Aug 27 06:27 ticket.dat
.:
total 632
-rwxrwxr-x 1 pavan pavan 16264 Aug 27 04:56 10_171
-rw-rw-r-- 1 pavan pavan  1099 Aug 27 05:04 10_171.c
-rwxrwxr-x 1 pavan pavan 16088 Aug 20 19:40 4a_171
-rw-rw-r-- 1 pavan pavan   254 Aug 20 19:40 4a_171.c
-rw-rw-r-- 1 pavan pavan     1 Aug 20 19:46 4b_171.c
-rwxrwxr-x 1 pavan pavan 16168 Aug 22 06:14 5_171
-rw-rw-r-- 1 pavan pavan   609 Aug 22 06:14 5_171.c
-rwxrwxr-x 1 pavan pavan 16096 Aug 22 07:34 6_171
-rw-rw-r-- 1 pavan pavan   353 Aug 22 07:34 6_171.c
-rwxrwxr-x 1 pavan pavan 16176 Aug 22 18:27 9_171
-rw-rw-r-- 1 pavan pavan  1031 Aug 22 18:28 9_171.c
-rwxrwxr-x 1 pavan pavan 15968 Aug 29 06:17 example
-rw-rw-r-- 1 pavan pavan   199 Aug 29 06:17 example.c
prw-rw-r-- 1 pavan pavan     0 Aug 20 16:22 fifo171
-rw-rw-r-- 1 pavan pavan   161 Aug 20 16:32 fifo171.c
-rw-rw-r-- 2 pavan pavan    13 Aug 20 15:58 file.txt
-rw-rw-r-- 3 pavan pavan    59 Aug 29 05:35 file1.txt
-rw-r--r-- 1 pavan pavan    13 Aug 22 06:28 file171_1.txt
-rw-r--r-- 1 pavan pavan    13 Aug 22 06:28 file171_2.txt
-rw-r--r-- 1 pavan pavan    13 Aug 22 06:28 file171_3.txt
-rw-r--r-- 1 pavan pavan    13 Aug 22 06:28 file171_4.txt
-rw-r--r-- 1 pavan pavan    13 Aug 22 06:28 file171_5.txt
-rwxrwxr-x 1 pavan pavan 16104 Aug 20 16:56 filedescriptor
-rwxrwxr-x 1 pavan pavan 16104 Aug 20 16:57 filedescriptor171
-rw-rw-r-- 1 pavan pavan   329 Aug 20 16:56 filedescriptor171.c
-rw-rw-r-- 1 pavan pavan     0 Aug 20 16:57 filedescriptormt171.txt
-rw-rw-r-- 3 pavan pavan    59 Aug 29 05:35 hard1
-rwxrwxr-x 1 pavan pavan 16008 Aug 20 16:17 hard171
-rw-rw-r-- 1 pavan pavan   139 Aug 20 16:17 hard171.c
-rw-rw-r-- 2 pavan pavan    13 Aug 20 15:58 hard2
-rw-rw-r-- 3 pavan pavan    59 Aug 29 05:35 hardm171
-rwxrwxr-x 1 pavan pavan 15784 Aug 20 16:39 infinite171
-rw-rw-r-- 1 pavan pavan    55 Aug 20 16:36 infinite171.c
-rwxrwxr-x 1 pavan pavan 16504 Aug 27 05:14 q11
-rw-rw-r-- 1 pavan pavan  2349 Aug 27 05:17 q11.c
-rwxrwxr-x 1 pavan pavan 16248 Aug 27 05:30 q12
-rw-rw-r-- 1 pavan pavan  1421 Aug 27 05:31 q12.c
-rwxrwxr-x 1 pavan pavan 16264 Aug 27 05:38 q13
-rw-rw-r-- 1 pavan pavan  1001 Aug 27 05:38 q13.c
-rwxrwxr-x 1 pavan pavan 16280 Aug 27 05:54 q14
-rw-rw-r-- 1 pavan pavan  1150 Aug 27 05:55 q14.c
-rwxrwxr-x 1 pavan pavan 16032 Aug 27 05:57 q15
-rw-rw-r-- 1 pavan pavan  3513 Aug 27 05:58 q15.c
-rwxrwxr-x 1 pavan pavan 16568 Aug 27 06:17 q16
-rw-rw-r-- 1 pavan pavan  2268 Aug 27 06:17 q16.c
-rw------- 1 pavan pavan     1 Aug 27 06:39 q16.c.save
-rwxrwxr-x 1 pavan pavan 16416 Aug 27 06:26 q17
-rw-rw-r-- 1 pavan pavan  1924 Aug 27 06:26 q17.c
-rw------- 1 pavan pavan  2111 Aug 27 06:39 q17.c.save
-rwxrwxr-x 1 pavan pavan 16032 Aug 29 05:18 q19
-rw-rw-r-- 1 pavan pavan   505 Aug 29 05:20 q19.c
-rwxrwxr-x 1 pavan pavan 16096 Aug 29 05:25 q20
-rw-rw-r-- 1 pavan pavan   620 Aug 29 05:26 q20.c
-rwxrwxr-x 1 pavan pavan 16128 Aug 27 06:30 q21
-rw-rw-r-- 1 pavan pavan   508 Aug 27 06:30 q21.c
-rwxrwxr-x 1 pavan pavan 16208 Aug 29 05:35 q22
-rw-rw-r-- 1 pavan pavan   745 Aug 29 05:35 q22.c
-rwxrwxr-x 1 pavan pavan 16168 Aug 27 06:36 q23
-rw-rw-r-- 1 pavan pavan   919 Aug 27 06:37 q23.c
-rwxrwxr-x 1 pavan pavan 16168 Aug 29 05:41 q24
-rw-rw-r-- 1 pavan pavan   727 Aug 29 05:44 q24.c
-rwxrwxr-x 1 pavan pavan 16264 Aug 29 06:04 q25
-rw-rw-r-- 1 pavan pavan  3043 Aug 29 06:09 q25.c
-rwxrwxr-x 1 pavan pavan 16264 Aug 29 06:19 q26
-rw-rw-r-- 1 pavan pavan  1050 Aug 29 06:20 q26.c
-rwxrwxr-x 1 pavan pavan 16344 Aug 29 06:27 q27
-rw-rw-r-- 1 pavan pavan  1066 Aug 29 06:27 q27.c
-rwxrwxr-x 1 pavan pavan 16184 Aug 22 08:56 q8_171
-rw-rw-r-- 1 pavan pavan   229 Aug 22 08:56 q8_171.c
-rwxrwxr-x 1 pavan pavan 16008 Aug 20 16:09 soft
-rw-rw-r-- 1 pavan pavan   133 Aug 20 16:09 soft.c
lrwxrwxrwx 1 pavan pavan     8 Aug 20 16:02 soft1 -> file.txt
lrwxrwxrwx 1 pavan pavan     8 Aug 20 16:09 soft171 -> file.txt
-rw-rw-r-- 1 pavan pavan   342 Aug 27 06:17 text.txt
-rw-rw-r-- 1 pavan pavan     4 Aug 27 06:27 ticket.dat
.:
total 632
-rwxrwxr-x 1 pavan pavan 16264 Aug 27 04:56 10_171
-rw-rw-r-- 1 pavan pavan  1099 Aug 27 05:04 10_171.c
-rwxrwxr-x 1 pavan pavan 16088 Aug 20 19:40 4a_171
-rw-rw-r-- 1 pavan pavan   254 Aug 20 19:40 4a_171.c
-rw-rw-r-- 1 pavan pavan     1 Aug 20 19:46 4b_171.c
-rwxrwxr-x 1 pavan pavan 16168 Aug 22 06:14 5_171
-rw-rw-r-- 1 pavan pavan   609 Aug 22 06:14 5_171.c
-rwxrwxr-x 1 pavan pavan 16096 Aug 22 07:34 6_171
-rw-rw-r-- 1 pavan pavan   353 Aug 22 07:34 6_171.c
-rwxrwxr-x 1 pavan pavan 16176 Aug 22 18:27 9_171
-rw-rw-r-- 1 pavan pavan  1031 Aug 22 18:28 9_171.c
-rwxrwxr-x 1 pavan pavan 15968 Aug 29 06:17 example
-rw-rw-r-- 1 pavan pavan   199 Aug 29 06:17 example.c
prw-rw-r-- 1 pavan pavan     0 Aug 20 16:22 fifo171
-rw-rw-r-- 1 pavan pavan   161 Aug 20 16:32 fifo171.c
-rw-r--r-- 1 pavan pavan    13 Aug 22 06:28 file171_1.txt
-rw-r--r-- 1 pavan pavan    13 Aug 22 06:28 file171_2.txt
-rw-r--r-- 1 pavan pavan    13 Aug 22 06:28 file171_3.txt
-rw-r--r-- 1 pavan pavan    13 Aug 22 06:28 file171_4.txt
-rw-r--r-- 1 pavan pavan    13 Aug 22 06:28 file171_5.txt
-rw-rw-r-- 3 pavan pavan    59 Aug 29 05:35 file1.txt
-rwxrwxr-x 1 pavan pavan 16104 Aug 20 16:56 filedescriptor
-rwxrwxr-x 1 pavan pavan 16104 Aug 20 16:57 filedescriptor171
-rw-rw-r-- 1 pavan pavan   329 Aug 20 16:56 filedescriptor171.c
-rw-rw-r-- 1 pavan pavan     0 Aug 20 16:57 filedescriptormt171.txt
-rw-rw-r-- 2 pavan pavan    13 Aug 20 15:58 file.txt
-rw-rw-r-- 3 pavan pavan    59 Aug 29 05:35 hard1
-rwxrwxr-x 1 pavan pavan 16008 Aug 20 16:17 hard171
-rw-rw-r-- 1 pavan pavan   139 Aug 20 16:17 hard171.c
-rw-rw-r-- 2 pavan pavan    13 Aug 20 15:58 hard2
-rw-rw-r-- 3 pavan pavan    59 Aug 29 05:35 hardm171
-rwxrwxr-x 1 pavan pavan 15784 Aug 20 16:39 infinite171
-rw-rw-r-- 1 pavan pavan    55 Aug 20 16:36 infinite171.c
-rwxrwxr-x 1 pavan pavan 16504 Aug 27 05:14 q11
-rw-rw-r-- 1 pavan pavan  2349 Aug 27 05:17 q11.c
-rwxrwxr-x 1 pavan pavan 16248 Aug 27 05:30 q12
-rw-rw-r-- 1 pavan pavan  1421 Aug 27 05:31 q12.c
-rwxrwxr-x 1 pavan pavan 16264 Aug 27 05:38 q13
-rw-rw-r-- 1 pavan pavan  1001 Aug 27 05:38 q13.c
-rwxrwxr-x 1 pavan pavan 16280 Aug 27 05:54 q14
-rw-rw-r-- 1 pavan pavan  1150 Aug 27 05:55 q14.c
-rwxrwxr-x 1 pavan pavan 16032 Aug 27 05:57 q15
-rw-rw-r-- 1 pavan pavan  3513 Aug 27 05:58 q15.c
-rwxrwxr-x 1 pavan pavan 16568 Aug 27 06:17 q16
-rw-rw-r-- 1 pavan pavan  2268 Aug 27 06:17 q16.c
-rw------- 1 pavan pavan     1 Aug 27 06:39 q16.c.save
-rwxrwxr-x 1 pavan pavan 16416 Aug 27 06:26 q17
-rw-rw-r-- 1 pavan pavan  1924 Aug 27 06:26 q17.c
-rw------- 1 pavan pavan  2111 Aug 27 06:39 q17.c.save
-rwxrwxr-x 1 pavan pavan 16032 Aug 29 05:18 q19
-rw-rw-r-- 1 pavan pavan   505 Aug 29 05:20 q19.c
-rwxrwxr-x 1 pavan pavan 16096 Aug 29 05:25 q20
-rw-rw-r-- 1 pavan pavan   620 Aug 29 05:26 q20.c
-rwxrwxr-x 1 pavan pavan 16128 Aug 27 06:30 q21
-rw-rw-r-- 1 pavan pavan   508 Aug 27 06:30 q21.c
-rwxrwxr-x 1 pavan pavan 16208 Aug 29 05:35 q22
-rw-rw-r-- 1 pavan pavan   745 Aug 29 05:35 q22.c
-rwxrwxr-x 1 pavan pavan 16168 Aug 27 06:36 q23
-rw-rw-r-- 1 pavan pavan   919 Aug 27 06:37 q23.c
-rwxrwxr-x 1 pavan pavan 16168 Aug 29 05:41 q24
-rw-rw-r-- 1 pavan pavan   727 Aug 29 05:44 q24.c
-rwxrwxr-x 1 pavan pavan 16264 Aug 29 06:04 q25
-rw-rw-r-- 1 pavan pavan  3043 Aug 29 06:09 q25.c
-rwxrwxr-x 1 pavan pavan 16264 Aug 29 06:19 q26
-rw-rw-r-- 1 pavan pavan  1050 Aug 29 06:20 q26.c
-rwxrwxr-x 1 pavan pavan 16344 Aug 29 06:27 q27
-rw-rw-r-- 1 pavan pavan  1066 Aug 29 06:27 q27.c
-rwxrwxr-x 1 pavan pavan 16184 Aug 22 08:56 q8_171
-rw-rw-r-- 1 pavan pavan   229 Aug 22 08:56 q8_171.c
-rwxrwxr-x 1 pavan pavan 16008 Aug 20 16:09 soft
lrwxrwxrwx 1 pavan pavan     8 Aug 20 16:02 soft1 -> file.txt
lrwxrwxrwx 1 pavan pavan     8 Aug 20 16:09 soft171 -> file.txt
-rw-rw-r-- 1 pavan pavan   133 Aug 20 16:09 soft.c
-rw-rw-r-- 1 pavan pavan   342 Aug 27 06:17 text.txt
-rw-rw-r-- 1 pavan pavan     4 Aug 27 06:27 ticket.dat
.:
total 632
-rwxrwxr-x 1 pavan pavan 16264 Aug 27 04:56 10_171
-rw-rw-r-- 1 pavan pavan  1099 Aug 27 05:04 10_171.c
-rwxrwxr-x 1 pavan pavan 16088 Aug 20 19:40 4a_171
-rw-rw-r-- 1 pavan pavan   254 Aug 20 19:40 4a_171.c
-rw-rw-r-- 1 pavan pavan     1 Aug 20 19:46 4b_171.c
-rwxrwxr-x 1 pavan pavan 16168 Aug 22 06:14 5_171
-rw-rw-r-- 1 pavan pavan   609 Aug 22 06:14 5_171.c
-rwxrwxr-x 1 pavan pavan 16096 Aug 22 07:34 6_171
-rw-rw-r-- 1 pavan pavan   353 Aug 22 07:34 6_171.c
-rwxrwxr-x 1 pavan pavan 16176 Aug 22 18:27 9_171
-rw-rw-r-- 1 pavan pavan  1031 Aug 22 18:28 9_171.c
-rwxrwxr-x 1 pavan pavan 15968 Aug 29 06:17 example
-rw-rw-r-- 1 pavan pavan   199 Aug 29 06:17 example.c
prw-rw-r-- 1 pavan pavan     0 Aug 20 16:22 fifo171
-rw-rw-r-- 1 pavan pavan   161 Aug 20 16:32 fifo171.c
-rw-r--r-- 1 pavan pavan    13 Aug 22 06:28 file171_1.txt
-rw-r--r-- 1 pavan pavan    13 Aug 22 06:28 file171_2.txt
-rw-r--r-- 1 pavan pavan    13 Aug 22 06:28 file171_3.txt
-rw-r--r-- 1 pavan pavan    13 Aug 22 06:28 file171_4.txt
-rw-r--r-- 1 pavan pavan    13 Aug 22 06:28 file171_5.txt
-rw-rw-r-- 3 pavan pavan    59 Aug 29 05:35 file1.txt
-rwxrwxr-x 1 pavan pavan 16104 Aug 20 16:56 filedescriptor
-rwxrwxr-x 1 pavan pavan 16104 Aug 20 16:57 filedescriptor171
-rw-rw-r-- 1 pavan pavan   329 Aug 20 16:56 filedescriptor171.c
-rw-rw-r-- 1 pavan pavan     0 Aug 20 16:57 filedescriptormt171.txt
-rw-rw-r-- 2 pavan pavan    13 Aug 20 15:58 file.txt
-rw-rw-r-- 3 pavan pavan    59 Aug 29 05:35 hard1
-rwxrwxr-x 1 pavan pavan 16008 Aug 20 16:17 hard171
-rw-rw-r-- 1 pavan pavan   139 Aug 20 16:17 hard171.c
-rw-rw-r-- 2 pavan pavan    13 Aug 20 15:58 hard2
-rw-rw-r-- 3 pavan pavan    59 Aug 29 05:35 hardm171
-rwxrwxr-x 1 pavan pavan 15784 Aug 20 16:39 infinite171
-rw-rw-r-- 1 pavan pavan    55 Aug 20 16:36 infinite171.c
-rwxrwxr-x 1 pavan pavan 16504 Aug 27 05:14 q11
-rw-rw-r-- 1 pavan pavan  2349 Aug 27 05:17 q11.c
-rwxrwxr-x 1 pavan pavan 16248 Aug 27 05:30 q12
-rw-rw-r-- 1 pavan pavan  1421 Aug 27 05:31 q12.c
-rwxrwxr-x 1 pavan pavan 16264 Aug 27 05:38 q13
-rw-rw-r-- 1 pavan pavan  1001 Aug 27 05:38 q13.c
-rwxrwxr-x 1 pavan pavan 16280 Aug 27 05:54 q14
-rw-rw-r-- 1 pavan pavan  1150 Aug 27 05:55 q14.c
-rwxrwxr-x 1 pavan pavan 16032 Aug 27 05:57 q15
-rw-rw-r-- 1 pavan pavan  3513 Aug 27 05:58 q15.c
-rwxrwxr-x 1 pavan pavan 16568 Aug 27 06:17 q16
-rw-rw-r-- 1 pavan pavan  2268 Aug 27 06:17 q16.c
-rw------- 1 pavan pavan     1 Aug 27 06:39 q16.c.save
-rwxrwxr-x 1 pavan pavan 16416 Aug 27 06:26 q17
-rw-rw-r-- 1 pavan pavan  1924 Aug 27 06:26 q17.c
-rw------- 1 pavan pavan  2111 Aug 27 06:39 q17.c.save
-rwxrwxr-x 1 pavan pavan 16032 Aug 29 05:18 q19
-rw-rw-r-- 1 pavan pavan   505 Aug 29 05:20 q19.c
-rwxrwxr-x 1 pavan pavan 16096 Aug 29 05:25 q20
-rw-rw-r-- 1 pavan pavan   620 Aug 29 05:26 q20.c
-rwxrwxr-x 1 pavan pavan 16128 Aug 27 06:30 q21
-rw-rw-r-- 1 pavan pavan   508 Aug 27 06:30 q21.c
-rwxrwxr-x 1 pavan pavan 16208 Aug 29 05:35 q22
-rw-rw-r-- 1 pavan pavan   745 Aug 29 05:35 q22.c
-rwxrwxr-x 1 pavan pavan 16168 Aug 27 06:36 q23
-rw-rw-r-- 1 pavan pavan   919 Aug 27 06:37 q23.c
-rwxrwxr-x 1 pavan pavan 16168 Aug 29 05:41 q24
-rw-rw-r-- 1 pavan pavan   727 Aug 29 05:44 q24.c
-rwxrwxr-x 1 pavan pavan 16264 Aug 29 06:04 q25
-rw-rw-r-- 1 pavan pavan  3043 Aug 29 06:09 q25.c
-rwxrwxr-x 1 pavan pavan 16264 Aug 29 06:19 q26
-rw-rw-r-- 1 pavan pavan  1050 Aug 29 06:20 q26.c
-rwxrwxr-x 1 pavan pavan 16344 Aug 29 06:27 q27
-rw-rw-r-- 1 pavan pavan  1066 Aug 29 06:27 q27.c
-rwxrwxr-x 1 pavan pavan 16184 Aug 22 08:56 q8_171
-rw-rw-r-- 1 pavan pavan   229 Aug 22 08:56 q8_171.c
-rwxrwxr-x 1 pavan pavan 16008 Aug 20 16:09 soft
lrwxrwxrwx 1 pavan pavan     8 Aug 20 16:02 soft1 -> file.txt
lrwxrwxrwx 1 pavan pavan     8 Aug 20 16:09 soft171 -> file.txt
-rw-rw-r-- 1 pavan pavan   133 Aug 20 16:09 soft.c
-rw-rw-r-- 1 pavan pavan   342 Aug 27 06:17 text.txt
-rw-rw-r-- 1 pavan pavan     4 Aug 27 06:27 ticket.dat
**/
