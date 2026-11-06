# TASK 08 – CPU STATES AND PROTECTION

## 1. Introduction
An operating system uses different CPU modes to protect the system and control access to hardware resources.

## 2. User Mode and Kernel Mode

- **User Mode:** Applications run with limited permissions. They cannot directly access protected hardware or kernel memory.
- **Kernel Mode:** The operating system kernel runs with full privileges and can access hardware and protected memory.

## 3. Privileged Instructions

Privileged instructions are commands that can only be executed in kernel mode.

Examples:
- Disabling or enabling interrupts.
- Changing memory-management settings.
- Controlling hardware devices.

If a user program tries to execute a privileged instruction, the CPU generates a protection exception.

## 4. Interrupts and Traps

- **Interrupt:** A signal that makes the CPU respond to an event, such as a keyboard input or timer.
- **Trap:** A synchronous event caused by the currently executing program, such as a system call or an exception.

Both can transfer control to the operating system.

## 5. Timer Interrupts

A timer interrupt occurs at regular intervals. It allows the operating system to regain CPU control and schedule another process.

Without timer interrupts, a process could occupy the CPU for too long and affect other processes.

## 6. Memory Protection

Memory protection prevents one process from accessing another process's memory without permission.

It provides:
- Process isolation.
- Protection of operating system memory.
- Prevention of unauthorized memory access.
- Improved system stability and security.

## 7. Polling vs Interrupts

| Polling | Interrupts |
|---|---|
| CPU repeatedly checks device status. | Device notifies CPU when attention is needed. |
| Can waste CPU time. | Uses CPU time when an event occurs. |
| Simple to implement. | Requires interrupt handling. |
| Useful for frequent or predictable checks. | Useful for irregular events. |

## 8. Effect of Disabling Interrupts

If interrupts are disabled for a long time:
- The CPU may not respond promptly to important events.
- Other processes may experience delays.
- System responsiveness can decrease.
- Real-time deadlines may be missed.

Therefore, interrupts should only be disabled for short and controlled periods.

## 9. Conclusion

CPU modes and memory protection help maintain operating system security and stability. Interrupts and traps allow the operating system to respond to events and manage processes efficiently. Timer interrupts support CPU scheduling, while memory protection prevents unauthorized access between processes.
