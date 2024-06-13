# round-robin-scheduler
The Round Robin scheduling algorithm is a widely used process scheduling algorithm in operating systems. It is one of the CPU scheduling algorithms in which every process gets a fixed amount of time quantum to execute the process.

In this algorithm, every process gets executed cyclically. This means that processes that have their burst time remaining after the expiration of the time quantum are sent back to the ready state and wait for their next turn to complete the execution until it terminates. This processing is done in FIFO order which suggests that processes are executed on a first-come, first-serve basis. It is the oldest scheduling algorithm, which is mainly used for multitasking.

The objective is to implement the Round Robin scheduling algorithm in the operating system. The goal is to ensure that each process gets a fair share of the CPU time, and no process is allowed to monopolize the CPU for an extended period.

# implementation

To implement the Round Robin scheduling algorithm in an operating system:

1. Initialize the scheduling queue and data structures to represent processes.
2. Set the time quantum (e.g., 10 milliseconds).

3. While there are processes in the queue:
   a. Dequeue the next process from the front of the scheduling queue.
   b. Execute the process for a time slice (time quantum) or until it voluntarily yields or completes.

   c. Update process information:
      - If the process has completed:
        - Record its turnaround time (current_time - arrival_time).
      - If the process still has remaining burst time:
        - Enqueue the process back to the end of the scheduling queue.

4. Calculate and report performance metrics:
   - Average turnaround time.
   - Average waiting time (turnaround time - burst time).
   - Any other relevant statistics.


