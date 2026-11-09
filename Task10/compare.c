#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

#define N 1000

void *thread_function(void *arg)
{
    return NULL;
}

int main()
{
    int i;
    pthread_t threads[N];
    pid_t pid;

    printf("Creating 1000 processes...\n");

    for (i = 0; i < N; i++)
    {
        pid = fork();

        if (pid == 0)
            exit(0);

        if (pid < 0)
        {
            perror("fork failed");
            break;
        }

        waitpid(pid, NULL, 0);
    }

    printf("Process creation test completed.\n");

    printf("Creating 1000 threads...\n");

    for (i = 0; i < N; i++)
    {
        if (pthread_create(&threads[i], NULL, thread_function, NULL) != 0)
        {
            perror("pthread_create failed");
            break;
        }
    }

    for (int j = 0; j < i; j++)
        pthread_join(threads[j], NULL);

    printf("Thread creation test completed.\n");

    return 0;
}
