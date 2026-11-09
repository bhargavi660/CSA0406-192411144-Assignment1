# TASK 09 – MEMORY HIERARCHY AND I/O

## 1. Introduction
Memory hierarchy organizes computer storage based on speed, capacity and cost. The operating system manages memory and I/O devices to provide efficient performance.

## 2. Memory Hierarchy

| Memory Type | Approximate Access Time | Capacity |
|---|---|---|
| Registers | Less than 1 ns | Very small |
| Cache | 1–10 ns | KB to MB |
| RAM | 50–100 ns | GB |
| SSD | 50–200 microseconds | GB to TB |
| HDD | 5–15 milliseconds | TB |
| Network Storage | Depends on network | GB to PB |

These are approximate values and vary with hardware.

## 3. Data Placement

- Frequently used data is stored in cache for faster access.
- Currently running programs and active data are stored in RAM.
- Large files and long-term data are stored on SSDs or HDDs.
- Hospital patient records can be stored on secure network or cloud storage.

## 4. I/O Techniques

**Programmed I/O:** The CPU repeatedly checks the device and transfers data.

**Interrupt-driven I/O:** The device sends an interrupt when it needs attention or completes an operation.

**Direct Memory Access (DMA):** A DMA controller transfers data directly between a device and main memory with limited CPU involvement.

## 5. DMA in MRI Systems

MRI systems generate large amounts of image data. DMA can transfer this data from the imaging device to RAM efficiently.

Benefits:
- Reduces CPU workload.
- Supports faster data transfer.
- Allows the CPU to perform other tasks.
- Improves overall system efficiency.

## 6. Alternative: Interrupt per Word vs DMA

Consider transferring a 500 MB MRI data file.

- **Interrupt per word:** The CPU receives frequent interrupts and handles each small data transfer. This creates high CPU overhead.
- **DMA:** A DMA controller transfers a large block of data directly into memory. The CPU is mainly involved in setting up and completing the transfer.

DMA is generally more efficient for large data transfers because it reduces CPU involvement and interrupt overhead.

## 7. Conclusion

Memory hierarchy improves system performance by placing data in suitable storage levels. Programmed I/O, interrupt-driven I/O and DMA provide different methods of data transfer. DMA is especially useful for large data transfers in hospital systems, such as MRI imaging.
