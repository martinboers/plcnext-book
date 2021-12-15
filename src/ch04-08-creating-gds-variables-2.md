## Creating GDS variables - Part 2

Now that we have seen how the PLCnext CLI can help us, let's use it to create a project containing an ACF component that creates some GDS variables.

- Create a new project on the host system:

  $ plcncli new acfproject --name MyGdsProject --namespace MyNamespace --component MyComponent --verbose

- Set the build target for the project:

  $ cd MyGdsProject
  $ plcncli set target --add --name AXCF2152 --version 2021.9

  If the target is ambiguous or cannot be found, you can use the following command to see the list of installed targets that the PLCnext CLI knows about:

  $ plcncli get targets

- Edit the source code using your favourite editor. In this case we will use [Visual Studio Code][vs-code]:

  $ code .

  You can see that the PLCnext CLI has created the following source and configuration files in the `MyGdsProject` directory:

    ```text
    ├── CMakeLists.txt
    ├── external
    │   └── ADD_DEPENDENT_LIBRARIES_HERE.txt
    ├── How_to_deploy.txt
    ├── plcnext.proj
    └── src
        ├── MyComponent.cpp
        ├── MyComponent.hpp
        └── MyGdsProjectLibrary.acf.config
    ```

- Add a GDS variable to the section indicated in the component `.hpp` file:

  ```cpp
  //#port
  Arp::uint8 MyGdsVariable;
  ```

  GDS variables are also referred to as "ports". The [PLCnext Info Center][info-center] provides detailed information on GDS port definitions in C++ code, including the attributes that can be applied to GDS ports defined in this way.

- Change the `.acf.config` file if necessary, e.g. the path to the shared object library file.

- Save the edited file(s)

- On the command-line, use the PLCnext CLI to generate the intermediate files for the project:

  $ plcncli generate code --verbose

  You can see that the PLCnext CLI has now created a lot of files in the `MyGdsProject` directory, including the following:

    ```text
    ├── intermediate
    │   └── code
    │       ├── MyComponent.meta.cpp
    │       ├── MyGdsProjectLibrary.cpp
    │       ├── MyGdsProjectLibrary.hpp
    │       └── MyGdsProjectLibrary.meta.cpp
    ```

  These C++ source files contain additional code required for the PLCnext runtime to create instances of the C++ component and its GDS port(s).

- Build the project:

  $ plcncli build --verbose

  This command uses CMake to build the project for all the specified targets.

- Deploy the shared object library and the `.acf.config` file to the PLC as you've done [previously][simple-component].

- Restart the PLCnext Runtime.

Your ACF component instance now includes a GDS port in the Global Data Space that can be accessed by other components using the Data Access RSC service.

[vs-code]: https://code.visualstudio.com/
[info-center]: https://www.plcnext.help/te/Programming/Cpp/Cpp_program_structure/IComponent_and_IProgram.htm
[simple-component]: ch04-01-simple-component.md
