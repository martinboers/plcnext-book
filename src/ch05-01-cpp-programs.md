## C++ Programs

PLCnext runtime programs created in C++ must inherit from `ProgramBase`.

Program instances are created using a special type of PLCnext component. While standard ACF components are only required to inherit from `ComponentBase`, components that can create program instances must also inherit from `ProgramComponentBase`. The corresponding library singleton must also inherit from `ProgramLibraryBase`. When the PLCnext runtime starts, this library is loaded not by the ACF, but instead is loaded by the [*Program Library Manager*][plm] (PLM). The PLM creates non-real-time component instances in a similar way to the ACF, but it also has the ability to create instances of real-time programs.

A high-level comparison of the ACF and the PLM is given in the [PLCnext Technology Info Center][comparison].

Like in the previous chapter, we can use the PLCnext CLI to generate a project template containing a C++ program:

- Create a new project on the host system:

  $ plcncli new project --name MyProject --namespace MyNamespace --component MyComponent --program MyProgram --verbose

  In this case we are using the PLCnext CLI template called `project`, whereas in the previous chapter we used the template called `acfproject`. You can also see that there is now a program name specified in the command along with the component name.

- Set the build target for the project:

  $ cd MyProject
  $ plcncli set target --add --name AXCF2152 --version 2021.9

- Edit the source code using your favourite editor.

  You can see that the PLCnext CLI has created the following source and configuration files in the `MyProject` directory:

    ```text
    ├── CMakeLists.txt
    ├── external
    │   └── ADD_DEPENDENT_LIBRARIES_HERE.txt
    ├── plcnext.proj
    └── src
        ├── MyComponent.cpp
        ├── MyComponent.hpp
        ├── MyProgram.cpp
        ├── MyProgram.hpp
    ```

  This project now includes both component and program source files, and does not include a `.acf.config` file.

- Look at the `MyComponent.cpp` and `MyComponent.cpp` files.

  These files implement a *program component*, which looks quite similar to the ACF component you saw in the previous chapter. You can do almost everything in a program component that you can do in an ACF component, including declaring GDS port variables on the component.

- Look at the `MyProgram.hpp` file.

  You can see from the comments that it is possible to declare GDS port variables on a program. This means that program instances can have GDS ports, and those ports can be connected to GDS ports on other components and programs. Just like in the previous chapter, these GDS connections are specified in a `.gds.config` file.

- Look at the `MyProgram.cpp` file.

  The `Execute` method you see here will be called by a real-time task. That real-time task will be scheduled to run on one of the Execution and Synchronisation Manager (ESM) instances created by the PLCnext runtime. Every time the real-time task runs, the Execute method on all program instances in that real-time task will be executed in the order that those program instances appear in the task. If the task is a *cyclic* task, then the Execute method will be called at the period of the cyclic task.

You can now go ahead and fill the Execute method with your real-time-dependent code.

[plm]: https://www.plcnext.help/te/Programming/Cpp/Cpp_program_structure/PLM_Program_Library_Manager.htm
[comparison]: https://www.plcnext.help/te/PLCnext_Runtime/Managing_of_components.htm
