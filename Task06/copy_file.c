#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s source destination buffer_size\n", argv[0]);
        return 1;
    }

    int buffer_size = atoi(argv[3]);

    if (buffer_size <= 0)
    {
        printf("Invalid buffer size\n");
        return 1;
    }

    int source = open(argv[1], O_RDONLY);
    if (source < 0)
    {
        perror("Source file error");
        return 1;
    }

    int destination = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (destination < 0)
    {
        perror("Destination file error");
        close(source);
        return 1;
    }

    char *buffer = malloc(buffer_size);
    if (buffer == NULL)
    {
        perror("Memory allocation error");
        close(source);
        close(destination);
        return 1;
    }

    ssize_t bytes_read;

    while ((bytes_read = read(source, buffer, buffer_size)) > 0)
    {
        ssize_t total_written = 0;

        while (total_written < bytes_read)
        {
            ssize_t bytes_written = write(
                destination,
                buffer + total_written,
                bytes_read - total_written
            );

            if (bytes_written <= 0)
            {
                perror("Write error");
                free(buffer);
                close(source);
                close(destination);
                return 1;
            }

            total_written += bytes_written;
        }
    }

    if (bytes_read < 0)
        perror("Read error");
    else
        printf("File copied successfully using buffer size %d\n", buffer_size);

    free(buffer);
    close(source);
    close(destination);

    return bytes_read < 0 ? 1 : 0;
}
