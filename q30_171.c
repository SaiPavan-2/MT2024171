#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include<string.h>
#define SCRIPT_NAME "script.sh"
#define LOG_FILE "daemon.txt"

void log_message(const char *message) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file != NULL) {
        fprintf(log_file, "%s\n", message);
        fclose(log_file);
    }
}

void start_daemon() {
    pid_t first_fork = fork();

    if (first_fork < 0) {
        log_message("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (first_fork > 0) {
        exit(EXIT_SUCCESS);
    }

    if (setsid() < 0) {
        log_message("Setsid failed");
        exit(EXIT_FAILURE);
    }

    pid_t second_fork = fork();

    if (second_fork < 0) {
        log_message("Second fork failed");
        exit(EXIT_FAILURE);
    }

    if (second_fork > 0) {
        exit(EXIT_SUCCESS);
    }

    umask(0);

    if (chdir("/") < 0) {
        log_message("Chdir failed");
        exit(EXIT_FAILURE);
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    log_message("Daemon started");
}

int main() {
    int target_hour = 15;
    int target_minute = 30;

    start_daemon();

    while (1) {
        time_t current_time;
        struct tm *time_info;

        time(&current_time);
        time_info = localtime(&current_time);

        if (time_info->tm_hour == target_hour && time_info->tm_min == target_minute) {
            const char *script_path = getenv("SCRIPT_PATH");
            if (script_path == NULL) {
                char cwd[1024];
                if (getcwd(cwd, sizeof(cwd)) != NULL) {
                    snprintf(cwd + strlen(cwd), sizeof(cwd) - strlen(cwd), "/%s", SCRIPT_NAME);
                    script_path = cwd;
                } else {
                    log_message("getcwd() error");
                    continue;
                }
            }

            char command[1024];
            snprintf(command, sizeof(command), "%s", script_path);

            int result = system(command);
            if (result == -1) {
                log_message("Error executing script");
            } else {
                log_message("Script executed successfully");
            }

            sleep(60);
        }

        sleep(30);
    }

    return 0;
}
/**Output:
**/
