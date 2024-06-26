## PLCnext CLI

You [previously][sdk-install] used the PLCnext CLI to install the SDK that you have been using to build your C++ projects for the target. However, the PLCnext CLI does more than just manage SDKs.

You can read more about the features of the PLCnext CLI in the [PLCnext Info Center][info-center]. These features include:

### Code Generation

PLCnext CLI can automatically generate code in a number of scenarios.

#### Initial project setup

The PLCnext CLI can generate customised C++ source and configuration files for different types of projects, based on code templates in the `Templates` directory (in the plcncli installation directory). This is useful when starting a new C++ project that targets a PLCnext Control device.

The templates that are installed with the PLCnext CLI are also available [in Github][cli-templates].

It is possible to create your own code templates that can be used with the PLCnext CLI. At the moment the required structure of PLCnext CLI templates [is not documented][cli-issue], but this is planned for the future.

#### Add components and programs to a project

There are PLCnext CLI commands for adding C++ components and programs to an existing project. These commands are useful when your C++ project requires more than the single C++ component and/or program that are created by the PLCnext CLI in a new C++ project.

#### Generate 'intermediate' code

Intermediate code includes "boilerplate" C++ code that is required for a PLCnext runtime project, but which can be generated automatically e.g by parsing the C++ components and programs in that project. Intermediate files include:

- The [Library singleton][library] that is required in a PLCnext runtime library.
- Code required to create GDS variables for your C++ component and/or program in the Global Data Space.

> You should not edit any of the intermediate files that are auto-generated by the PLCnext CLI. These files are regenerated whenever the `plcncli generate` command is executed, and at that point any manual changes to those files will be lost.

### Managing build target(s)

Each C++ project generated by the PLCnext CLI includes a list of build targets for that project. This list can be managed using `plcncli` commands.

### Building the project

The PLCnext CLI can build a C++ project for the selected target(s) with one command - `plcncli build`.

The next section will use the PLCnext CLI to create and build a C++ project containing one ACF component.

[sdk-install]: ch01-04-installing-a-software-development-kit.md
[info-center]: https://plcnext.help/te/Programming/PLCnext_toolchain/Installing_PLCnext_toolchain.htm
[cli-templates]: https://github.com/PLCnext/PLCnext_CLI_Templates
[cli-issue]: https://github.com/PLCnext/PLCnext_CLI_Templates/issues/1
[library]: ch04-02-library-singleton.md
