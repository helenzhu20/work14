#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>

static void sighandler(int sig) {
    if (sig == SIGINT) {
   	 int file = open("exit_info", O_WRONLY | O_APPEND | O_CREAT, 0644);
   	 char *exit_message = "Program exited due to SIGINT\n";
   	 write(file, exit_message, strlen(exit_message));
   	 exit(0);
    }
    if (sig == SIGUSR1) {
   	 printf("parent pid: %d\n", getppid());
    }
}

int main() {
    signal(SIGINT, sighandler);
    signal(SIGUSR1, sighandler);
    while(1) {
   	 printf("pid: %d\n", getpid());
   	 sleep(1);
    }
}
