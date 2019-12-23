## Hello, World!

OK, enough of software written by other people. You're a programmer. So let's start programming!

### Your First Program

Every PLCnext Control comes with Python already installed.

```text
# python3
Python 3.7.2 (default, Nov 12 2019, 23:37:48)
[GCC 8.3.0] on linux
Type "help", "copyright", "credits" or "license" for more information.
```

Here, you can see the version of Python that is installed on the PLC. The Python command prompt `>>>` is now waiting for further input. Enter the following command:

```text
>>> print ("Hello, World!")
Hello, World!
```

Press Ctrl-D to exit from the Python interpreter and return to the PLC command prompt.

Close the shell session on the PLC:

```text
# exit
```

You have just written your first PLCnext Control program!

### Your Second Program

You probably don't want to be limited to Python when building applications for a PLCnext Control. Python scripts are quick and easy to run on a PLCnext Control because the firmware includes a Python interpreter. Other interpreted languages (like Javascript) need their own interpreter. Similarly, Java bytecode and .NET CLI code need their own runtimes. It is beyond the scope of this book to describe how to program a PLCnext Control device in every language. However, there is a diversity of skills and interests among members of the PLCnext Community, and there are excellent contributions from community members on the use of various programming languages and frameworks. Here are a few examples:

(TODO: Fill in)

* C#
* Node.js, including Node-red.
* Python
* Java (also information on Java programming in the Info Center)

Native applications can also be built for a PLCnext Control using C/C++ or Rust, for example, with the help of the appropriate Software Development Kit (SDK). Next, we will see how to install the SDK for a PLCnext Control on your host machine, and then write "Hello, World!" programs for a PLCnext Control in C/C++ and Rust.
