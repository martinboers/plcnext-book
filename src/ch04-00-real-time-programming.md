# Real Time Programming

Define real-time.
(this is familiar to PLC programmers)

For many components - including many components of the PLCnext runtime - real-time performance is not necessary.

Linux kernel includes PREEMPT-RT patch, so it is possible to create real-time threads. However, this requires deep experience of C++ and OS thread handling.

The PLCnext runtime makes it simple to write C++ programs that run in real time.

- Execution and synchronisation manager.
- The ESM borrows some terminology from the IEC 61131 standard - "Tasks" (the things that execute in real time), and "programs" (code that is executed whenever a task is run). Link to overview of ESM in info center, including task and program scheduling.

The ESM is configured using an esm.config file:

- Example.
- Task definition
- Program instances assigned to tasks.

In this chapter, you will create a real-time C++ program and run it on the target.
