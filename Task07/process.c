#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0)
    {
        execlp("expr", "expr", "6", "*", "7", (char *)NULL);
        perror("execlp failed");
        exit(1);
    }
    else if (pid > 0)
    {
        waitpid(pid, &status, 0);

        if (WIFEXITED(status))
            printf("Child 1 exited with status %d\n", WEXITSTATUS(status));
    }

    pid = fork();

    if (pid == 0)
    {
        exit(3);
    }
    else if (pid > 0)
    {
        waitpid(pid, &status, 0);

        if (WIFEXITED(status))
            printf("Child 2 exited with status %d\n", WEXITSTATUS(status));
    }

    return 0;
}
