# TASK 10 – MEASUREMENT AND COMPARISON

## 1. Introduction
Operating system performance can be evaluated by measuring execution time, system calls, CPU usage and resource utilization.

## 2. Measuring System Calls

The `strace -c` command can measure the number of system calls made by a program.

For the file-copying program from Task06, different buffer sizes were tested.

| Buffer Size | Read Calls | Write Calls |
|---|---:|---:|
| 1 byte | 10002 | 10001 |
| 512 bytes | 22 | 21 |
| 4096 bytes | 5 | 4 |

**Observation:** Smaller buffer sizes require more system calls. Larger buffer sizes reduce system call overhead.

## 3. Measuring Execution Time

The `time` command measures how long a program takes to execute.

Example:

```bash
time ./copy_file input.txt output.txt 4096
```

It reports:
- Real time: Total elapsed time.
- User time: Time spent executing user-level code.
- System time: Time spent executing kernel-level operations.

## 4. Processes vs Threads

| Processes | Threads |
|---|---|
| Have separate memory spaces. | Share the same process memory. |
| Creation usually has more overhead. | Creation usually has less overhead. |
| Provide better isolation. | Communication is easier through shared memory. |
| Context switching can be more expensive. | Context switching can be less expensive. |

## 5. Alternative Approach

Threads can be used instead of creating many separate processes when tasks need to share data.

However, threads require synchronization to avoid data races. Processes provide stronger isolation, which can be useful for critical hospital applications.

## 6. Conclusion

Performance measurement helps compare operating system operations. The Task06 experiment showed that increasing the buffer size reduces the number of read and write system calls. Processes provide isolation, while threads can reduce overhead when tasks share resources.
