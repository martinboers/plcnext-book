## IEC 61131-3 Programs

Real-time programs can be written in the four languages defined by the IEC standard - Ladder (LD), Function Block Diagram (FBD), Structured Text (ST) and Sequential Function Chart (SFC). Programs written in these languages run on the [Embedded Common Language Runtime][eclr-info] (ECLR).

### ECLR

As the name suggests, the Embedded Common Language Runtime is based on [Microsoft's Common Language Runtime][clr-info] (CLR), which is required to run C# and other .NET programs on Windows platforms. Unlike the CLR, the ECLR is specifically designed to run real-time, deterministic programs on embedded devices. The ECLR contains a sub-set of CLR libraries, along with specialised libraries added by Phoenix Contact.

### PLCnext Engineer

(outside the scope of this book)

Includes the following features:
- Write programs in IEC 61131 languages and C#, which run on the ECLR
- Integrates with Matlab Simulink
- Import C++ programs
- Tabular configuration of I/O
- Tabular configuration of ESM Tasks and program instances, using both IEC and C++ programs
- Tabular configuration of GDS variable connections.
- Automatically generates the following configuration files: .tic, gds.config, esm.config and plm.config.
- Debugging features including GDS variable "Watch" window, Force variables, notification viewer.

[eclr-info]: https://www.plcnext.help/te/Programming/Csharp/eCLR_Programming_System.htm

[clr-info]: https://docs.microsoft.com/en-us/dotnet/standard/clr
