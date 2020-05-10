## Hello, World!

Let's write our first PLCnext Control program!

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

You probably don't want to be limited to Python when building applications for a PLCnext Control. Python scripts are quick and easy to run on a PLCnext Control because the firmware includes a Python interpreter. Other interpreted languages (like Javascript) need their own interpreter. Similarly, Java bytecode and .NET CLI code need their own runtimes. It is beyond the scope of this book to describe how to program a PLCnext Control device in every language. Appendix A includes a list of resources that demonstrate how to use PLCnext Control devices with a number of popular programming languages and frameworks, including contributions from members of the PLCnext Community.

Native applications can be built for a PLCnext Control device using C/C++ or Rust, for example, with the help of the appropriate Software Development Kit (SDK). Next, we will see how to install the SDK for a PLCnext Control device on your host machine, and then write "Hello, World!" programs for that controller in C/C++ and Rust.
