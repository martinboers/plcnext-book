## Hello Again, World!

Once you have an SDK installed on your host machine, your PLC can greet the world in C++ or Rust.

### C++

(include links to Github)

### Rust

(include links to Github)

### Building on target

The software development process for PLCnext Control - cross-compiling on a host, then deploying to a target - will be familiar to those with experience in embedded systems software development, but other programmers often wonder why they cannot build their PLCnext Control applications directly on the target device. The reason is that the resources required to run development and build tools are often orders of magnitude greater than those required to run the final application, and the types of applications for which PLCnext Control is designed cannot justify the cost of these additional resources (e.g. memory and CPU power). For this reason, PLCnext Control should be considered more like an embedded device than a full-featured computer.

### Accessing PLC I/O

One of the first questions most PLCnext Control programmers ask is: How can a program read and write inputs and outputs from/to the I/O modules attached to the PLC?

Before you learn how to do this, you must learn about the *PLCnext runtime*.
