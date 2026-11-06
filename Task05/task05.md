# TASK 05 – SYSTEM CALLS

## 1. Introduction

A system call is a method through which a user program requests a service from the operating system kernel.

## 2. Types of System Calls

- **Process Control:** Creates and terminates processes.
- **File Management:** Creates, reads, writes and deletes files.
- **Device Management:** Controls input and output devices.
- **Information Maintenance:** Gets system information.
- **Communication:** Allows processes to exchange data.
- **Protection:** Controls access to system resources.

## 3. Working of the read() System Call

1. A user program requests data using `read()`.
2. The system call transfers control to the kernel.
3. The CPU switches from user mode to kernel mode.
4. The kernel checks the file descriptor and memory address.
5. The kernel performs the requested read operation.
6. The result is returned to the user program.
7. The CPU switches back to user mode.

## 4. Parameter Passing

System call parameters can be passed using:
- CPU registers.
- A memory block containing parameters.
- The program stack.

## 5. Practical Implementation Using strace

A C program named `test.c` was created using the `write()` system call.

The program displays the message "Hello Hospital" on the terminal.

**Program output:**

```text
Hello Hospital
```

**Important strace output:**

```text
write(1, "Hello Hospital\n", 15) = 15
exit_group(0)
```

### Explanation

- `write()` sends data to standard output.
- `1` represents standard output.
- `15` represents the number of bytes written.
- `exit_group(0)` indicates successful program termination.

## 6. Alternative Approach

Instead of directly using system calls such as `read()` and `write()`, a C program can use library functions such as `fread()` and `fwrite()`.

These library functions support buffering and can reduce the number of system calls.

## 7. Conclusion

System calls provide an interface between user programs and the operating system kernel. They allow programs to access files, devices, processes and other system resources safely and efficiently. The `strace` experiment demonstrated how a program uses system calls during execution.
