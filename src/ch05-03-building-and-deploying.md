## Building and Deploying a Real-time C++ Application

Real-time C++ applications can be built using the PLCnext CLI, in a similar way to the ACF applications in the previous chapter:

- On the command-line, use the PLCnext CLI to generate the intermediate files for the project:

  ```text
  $ plcncli generate code --verbose
  ```

- Generate the configuration files for the project:

  ```text
  $ plcncli generate config --verbose
  ```

  This step - which is not required for ACF projects - creates configuration files that are used by the Program Library Manager.

- Build the project:

  ```text
  $ plcncli build --verbose
  ```

  This command uses CMake to build the project for all the specified targets.

### Deploying

It is possible to deploy a real-time C++ project by copying binary and configuration files to specific directories on the target, in a similar way to the ACF projects in the previous chapter. This procedure, which is more complicated than for ACF projects, is described in the Github repository [*PLM/ESM/GDS Configuration without PLCnext Engineer*][file-deploy].

There is a simpler way to generate the required configuration files and deploy them to the target, and that uses PLCnext Engineer software running on a Windows machine. To use your C++ project in PLCnext Engineer, it must be packaged as a PLCnext Engineer library. This can be done using the following PLCnext CLI command:

  ```text
  $ plcncli deploy --verbose
  ```

This will create a file with the extension `.pcwlx`, which is a PLCnext Engineer library file.

When this library is added to a PLCnext Engineer project, then the configuration of tasks, program instances and GDS port connections can all be done graphically in PLCnext Engineer. The complete project can also be deployed to the target from PLCnext Engineer. This process is described in a [tutorial video][eng-deploy] from Phoenix Contact.

If your project does not preclude the use of PLCnext Engineer, then this is the easiest way to configure and deploy a real-time C++ application to a PLCnext Control device.

[file-deploy]: https://github.com/PLCnext/CppExamples/tree/master/Examples/NoEngineer
[eng-deploy]: https://youtu.be/IUGSZzuzm-c?t=173
