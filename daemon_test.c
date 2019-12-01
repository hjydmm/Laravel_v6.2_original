#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int  mydaemon()
{
    pid_t pid, sid;
    int ret;

    pid = fork();

    if(pid > 0) {
        return 0;
    }

    setsid();

    ret = chdir("/home/hejunyang/");
    if(ret == -1) {
        perror("chdir error");
	exit(1);
    }

    umask(0022);

    close(STDIN_FILENO);
    open("/dev/null", O_RDWR);
    dup2(0, STDOUT_FILENO);
    dup2(0, STDERR_FILENO);
}

int main(void)
{
    mydaemon();

    while(1) {
    
    }

    return 0;
}
