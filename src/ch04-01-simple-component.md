## Simple Extension Component

The simplest PLCnext component is a C++ class that inherits [`Arp::System::Acf::ComponentBase`][component-base-doc].

The C++ source files (`.hpp` and `.cpp`) for a simple component, called `MyComponent`, can be downloaded here:

[MyComponent.hpp][component-hpp]
[MyComponent.cpp][component-cpp]

At this point `MyComponent` is a valid PLCnext Runtime component, but it contains no functionality - this will be added later.

### Library Singleton

Named component instances are created by the PLCnext runtime from a singleton that inherits [`Arp::System::Acf::LibraryBase`][library-base-doc].

The C++ source files (`.hpp` and `.cpp`) for a singleton - called `MyLibrary` - that creates named instances of `MyComponent` can be downloaded here:

[MyLibrary.hpp][library-hpp]
[MyLibrary.cpp][library-cpp]

Note that both `MyComponent` and `MyLibrary` are defined in a namespace called `MyNamespace`.

### Building the Library

You can build a shared object library containing both these classes (`MyComponent` and `MyLibrary`) using the SDK that you installed earlier.

The following procedure uses the build tools `CMake` and `Ninja`, so make sure these are also installed on the host machine.

Build the library as follows:

* On your host machine, create a project directory. Under this directory, create two sub-directories called `src` and `tools`.

* Copy the four source files to the `src` directory.

* In the project root directory, create a CMakeLists.txt file containing the following text:

```cmake
{{#include samples/ch04-01-simple-component/MyProject/CMakeLists.txt}}
```

* In the project `tools` directory, create a file named `build.sh` containing the following bash commands:

```bash
{{#include samples/ch04-01-simple-component/MyProject/tools/build.sh}}
```

  Obviously these bash commands will not work on a Windows operating system. Windows users may consider installing [Windows Subsystem for Linux][wsl].

* From the project root directory, execute the build script.

  You will need to customise the following command with the strings that apply to your SDK installation and target.

   ```text
   $ tools/build.sh -t "/opt/pxc/sdk/AXCF2152/2020.0" -a "2020.0 LTS (20.0.0.24752)" -n "AXCF2152"
   Version:20.0.0.24752
   CMAKE Configure
      :
   [0/1] Install the project...
   -- Install configuration: "Release"
   -- Installing: /home/tcs-user/MyProject/tools/../deploy/AXCF2152_20.0.0.24752/Release/lib/libMyProject.so
   ```

You can see that a shared object library, `libMyProject.so`, has been created. This contains the component called `MyNamespace::MyComponent` and the singleton called `MyNamespace::MyLibrary`.

* On the PLC, create a project directory e.g. `/opt/plcnext/projects/MyProject`, and a `lib` subdirectory.

* Copy the shared object library from the host to the target:

   ```text
   $ scp deploy/AXCF2152_20.0.0.24752/Release/lib/libMyProject.so admin@192.168.1.10:~/projects/MyProject/lib
   ```

### Instantiating the Component

Now that the shared object library containing the extension component is on the target, the PLCnext runtime must be instructed to create an instance of `MyComponent`.

* On the host, in the project root directory, create a file named `MyProject.acf.config`, containing the following text:

```xml
{{#include samples/ch04-01-simple-component/MyProject/MyProject.acf.config}}
```

* Copy this ACF configuration file from the host to the target:

   ```text
   $ scp MyProject.acf.config admin@192.168.1.10:~/projects/Default
   ```

   The PLCnext runtime will automatically load this configuration file, since the `Default.acf.config` file in the same directory includes all files that match the  pattern `*.acf.config`. The ACF configuration file for `MyProject` instructs the PLCnext runtime to:

  * Create a new child process called `MyProcess`.
  * Load the shared object library and name it `MyProject`. This name can be considered an alias, or shorthand reference, to the shared object library. This name does not have any relationship to the name of the class in the shared object library that inherited `LibraryBase`.
  * Create an instance of `MyNamespace::MyComponent`, called `MyComponentInstance`, from the library it named `MyProject`.

* Restart the PLCnext runtime:

   ```text
   # /etc/init.d/plcnext start && tail -f -n 0 /opt/plcnext/logs/Output.log
   (result)
   ```

Among the messages that appear in the Output.log file, you should see the following:

```text
LOADED LIBRARY
LOADED COMPONENT
```

Your first PLCnext runtime extension component instance is now running!

[component-base-doc]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1System_1_1Acf_1_1ComponentBase.html
[component-hpp]: samples/ch04-01-simple-component/MyProject/src/MyComponent.hpp
[component-cpp]: samples/ch04-01-simple-component/MyProject/src/MyComponent.cpp
[library-base-doc]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1System_1_1Acf_1_1LibraryBase.html
[library-hpp]: samples/ch04-01-simple-component/MyProject/src/MyLibrary.hpp
[library-cpp]: samples/ch04-01-simple-component/MyProject/src/MyLibrary.cpp
[wsl]: https://docs.microsoft.com/en-us/windows/wsl/
