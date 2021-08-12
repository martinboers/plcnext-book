## Hello Again, World!

Once you have an SDK installed on your host machine, your PLCnext Control device can greet the world in C++ or Rust.

### C++

On the host machine, create a file called `main.cpp` with the following contents:

```cpp
#include <iostream>

int main() {
    std::cout << "Hello World!" << std::endl;
    return 0;
}
```

When [cross-compiling][cross-compile] open-source C/C++ code using the [GNU Build System][gnu-build], it is typical - and often necessary - to define an environment variable called `SDKROOT`. This variable contains the path where header files, shared libraries, build tools etc. for the target platform can be found. Defining this variable is not necessary for this simple example, but let's do it anyway. In this case, we define `SDKROOT` as the directory in the SDK that contains the `sysroot` directory. For example:

```text
$ export SDKROOT=/opt/pxc/sdk/AXCF2152/2021.6
```

The PLCnext SDK includes a bash script that sets up the build environment, so that standard build commands will result in binaries for the target platform. Execute this bash script using the `source` command:

```text
$ source ${SDKROOT}/environment-setup*
```

Now we can compile and link the program using the g++ compiler that comes with the PLCnext SDK:

```text
$ $CXX main.cpp -O -o say_hello  # Build with optimisations (-O) to avoid a warning.
```

Check that the resulting executable has been built for the correct platform:

```text
$ file say_hello
say_hello: ELF 32-bit LSB pie executable, ARM, EABI5 version 1 (SYSV), dynamically linked, interpreter /lib/ld-linux-armhf.so.3, BuildID[sha1]=b4a827997b3375494f750fa890c8796ff293d463, for GNU/Linux 3.2.0, with debug_info, not stripped
```

Copy the executable to the PLCnext Control device:

```text
$ scp say_hello admin@192.168.1.10:~
```

Run the program on the PLCnext Control device:

```text
$ ssh admin@192.168.1.10
# ./say_hello
Hello World!
```

Congratulations! You have just run your first C++ program for a PLCnext Control device.

### Rust

The build process for a simple Rust program targeting a PLCnext Control device is described in the [first step of the rust-sample-runtime tutorial in Github][rust-start].

### Building on target

The software development process for PLCnext Control devices - cross-compiling on a host, then deploying to a target - will be familiar to those with experience in embedded systems software development, but other programmers often wonder why they cannot build their PLCnext Control applications directly on the target device. The reason is that the resources required to run development and build tools are often orders of magnitude greater than those required to run the final application, and the types of applications for which PLCnext Control is designed cannot justify the cost of these additional resources (e.g. memory and CPU power). For this reason, PLCnext Control should be considered more like an embedded device rather than a full-featured computer.

### Accessing PLC I/O

After writing their first program, one of the first questions most PLCnext Control programmers ask is: How can an application read and write inputs and outputs from/to the I/O modules attached to the PLC?

Before you learn how to do this, you must learn about the *PLCnext runtime*. But first, you should know about some basic features of the operating system that runs on every PLCnext Control device.

[cross-compile]: https://www.gnu.org/software/automake/manual/html_node/Cross_002dCompilation.html
[gnu-build]: https://www.gnu.org/software/automake/manual/html_node/GNU-Build-System.html
[rust-start]: https://github.com/PLCnext/rust-sample-runtime/blob/master/getting-started/Part-01/README.md