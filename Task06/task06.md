# Task 06 – Evaluate the Cost of System Calls

## 1. Introduction

A system call allows a user program to request a service from the operating system kernel. System calls take more time than normal function calls because they require switching from user mode to kernel mode.

The cost of system calls depends on the number of calls, data size, buffer size and system performance.

## 2. System Call Cost vs Normal Function Call

| Normal Function Call | System Call |
|---|---|
| Executes within the user program | Requests a service from the kernel |
| No mode switching | Requires user-to-kernel mode switching |
| Generally faster | Generally slower |
| Does not require kernel validation | Kernel validates the request and parameters |

## 3. Effect of Buffer Size

Buffering improves file-copy performance by reducing the number of system calls.

- Small buffer: More `read()` and `write()` calls, increasing overhead.
- Medium buffer: Fewer system calls and better performance.
- Large buffer: Further reduces calls, but uses more memory.

For example, copying a 10,000-byte file:

| Buffer Size | Expected Read Calls |
|---:|---:|
| 1 byte | 10,001 |
| 512 bytes | 21 |
| 4096 bytes | 4 |

The exact number of calls can depend on how the program handles the end of the file and partial reads.

## 4. C Program Using read() and write()

The following program copies a file using the `read()` and `write()` system calls. The buffer size is supplied as a command-line argument.

```c
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
```

## 5. Execution and Testing

Compile the program in Linux:

```bash
gcc copy_file.c -o copy_file
```

Create a sample input file:

```bash
printf 'Operating System System Call Testing\n' > input.txt
```

Run the program with different buffer sizes:

```bash
./copy_file input.txt output1.txt 1
./copy_file input.txt output512.txt 512
./copy_file input.txt output4096.txt 4096
```

Check the copied files:

```bash
cmp input.txt output1.txt
cmp input.txt output512.txt
cmp input.txt output4096.txt
```

If the files match, `cmp` produces no output.

## 6. Measuring System Calls

Use `strace` to count system calls:

```bash
strace -c ./copy_file input.txt output.txt 512
```

Repeat the command with buffer sizes 1 and 4096.

Use the `time` command to measure execution time:

```bash
time ./copy_file input.txt output.txt 4096
```

Record the actual results for each buffer size.

## 7. Alternative Approach – Memory Mapping (mmap)

Another method of file copying is memory mapping using `mmap()`.

- It maps file contents into the process's virtual memory.
- The program can access file data through memory addresses.
- It can reduce explicit `read()` and `write()` calls.
- It may be useful for suitable large-file workloads.
- It requires careful memory management and does not guarantee better performance in every situation.

## 8. Complexity Analysis

For a file of size N bytes and a buffer of size B bytes:

- Number of read operations is approximately O(N/B).
- Number of write operations is approximately O(N/B).
- Total copying work is O(N).
- Extra buffer memory is O(B).

A larger buffer reduces the number of system calls, while requiring more memory.

## 9. Conclusion

System calls have overhead because they involve switching between user mode and kernel mode. Using a suitable buffer size reduces the number of system calls and improves file-copy efficiency. The best buffer size should be selected based on actual measurements of execution time and system-call counts.

## 10. Evidence to Attach

1. Screenshot of the C program.
2. Screenshot showing successful compilation and execution.
3. Screenshot of `strace -c` results for buffer sizes 1, 512 and 4096.
4. Screenshot of execution-time measurements.
5. Comparison table containing the actual results.
