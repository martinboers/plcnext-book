## C++ Programs

PLCnext programs created in C++ must inherit from ProgramBase.

Program instances are created using a special type of PLCnext component. This component must inherit ProgramComponentBase, and the corresponding library singleton must inherit ProgramLibraryBase. When the PLCnext runtime starts, this library is loaded not by the ACF, but by the *Program Library Manager* (PLM). The PLM creates non-real-time component instances in a similar way to the ACF, but it also has the ability to create instances of real-time programs.

A high-level comparison of the ACF and the PLM is given in the [PLCnext Technology Info Center][comparison].

We can again use plcncli to help us with this project.

- Generate a project.

### Program Component features

- familiar from ACF components.


### Program features

- Program Execute method. That's it! This is called every time the real-time Task executes.
- Can define GDS ports - e.g. for connecting to I/O.
- MUST NOT do anything that blocks the Execute method - including GDS calls, file access, database access, tcp socket comms, etc.
- Any non-real-time work can be done in the Component (each Program has a pointer to a component). Don't hold references to Program instances in the Component - while components live for the lifetime of the PLCnext runtime, Program instances are more ethereal.

### Building 


### Deploying 


### Configuring

- plm.config instead of acf.config file, since the component must be loaded by the PLM rather than the ACF.
- esm.config file.

### Running

[comparison]: https://www.plcnext.help/te/PLCnext_Runtime/Managing_of_components.htm
