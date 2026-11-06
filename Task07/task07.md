# TASK 07 – PROCESS CONTROL SYSTEM CALLS

## 1. Introduction
Process control system calls help the operating system create, execute, manage and terminate processes.

## 2. Important Process Control System Calls

- **fork():** Creates a new child process.
- **exec():** Replaces the current process with a new program.
- **wait():** Makes the parent process wait for the child process to finish.
- **exit():** Terminates a process and returns an exit status.

## 3. Working of fork() and exec()

1. The parent process calls `fork()`.
2. A child process is created.
3. The child process executes a new program using `execlp()`.
4. The `expr` command calculates 6 × 7.
5. The parent waits using `waitpid()`.
6. The child process terminates and returns its exit status.

## 4. Practical Implementation

A C program named `process.c` was created using `fork()`, `execlp()` and `waitpid()`.

**Program output:**

```text
42
Child 1 exited with status 0
Child 2 exited with status 3
```

**Explanation:**
- 42 is the result of 6 × 7.
- Child 1 exits successfully with status 0.
- Child 2 exits with status 3.

## 5. Zombie and Orphan Processes

- **Zombie process:** A child process that has finished execution but whose parent has not yet collected its exit status.
- **Orphan process:** A child process whose parent terminates before it.

Using `wait()` or `waitpid()` helps the parent collect the child's exit status and prevents an unreaped child from remaining a zombie.

## 6. strace Evidence

The program was executed using `strace -f` to observe process-related system calls.

Important system calls observed:

- `clone()` – Linux uses this system call internally to create the child process for `fork()`.
- `execve()` – Executes the `expr` program.
- `wait4()` – Waits for the child process.
- `exit_group()` – Terminates a process.

The output confirmed that the child processes were created, executed and terminated successfully.

## 7. Output Buffering

When output is redirected to a file, standard output may be fully buffered. If a program calls `fork()` before flushing its output buffer, the buffer is copied to the child process.

Using `fflush(stdout)` before `fork()` prevents previously buffered output from being printed more than once.

## 8. Alternative Approach

`posix_spawn()` can be used as an alternative to the combination of `fork()` and `exec()`. It creates a new process and executes a program with a simpler interface.

Threads are another alternative when tasks need to share the same process memory, but they do not provide the same process isolation.

## 9. Conclusion

Process control system calls are important for managing multiple processes in an operating system. The practical experiment demonstrated process creation using `fork()`, program execution using `exec()`, synchronization using `waitpid()` and process termination using `exit()`. The `strace` output helped verify these operations.
