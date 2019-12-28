## Worker Threads

There are no component methods that are called cyclically - only ones that are called on startup, shutdown and on certain (usually rare) events.

The TCP Server example registered a callback, but sometime you want something to be executed "continuously", for example on a fixed period - like reading and writing the GDS variables in the previous example.

WORKER THREADS.

Link to examples.

- THESE THREADS ARE NOT DESIGNED TO BE USED FOR "REAL TIME" PROCESSING, and are not to be confused with the Cyclic Tasks in a PLC. We will get to those later. These worker threads are not deterministic, and the cycle time cannot be guaranteed with any accuracy. But that is fine for many applications.
