## Creating GDS variables - Part 1

The previous example read and wrote values from and to existing GDS variables.

The GDS provides a simple way to exchange data between otherwise isolated PLCnext runtime components.

(link to the GDS in the info centre)

It is possible for your own component instance to register fields in the Global Data Space. These fields can then be accessed as GDS variables from other PLCnext runtime components using the Data Access RSC service, in a similar way to how we accessed GDS variables in the previous example.

GDS variables can also:

- be included in the OPC UA server address space
- have their value persisted (or "retained") across restarts of the PLCnext runtime.
- have their value logged to the Proficloud TSD service.
- be used on the web-based eHMI (more on that later)
- be connected to GDS variables on physical I/O modules
- etc.

In order for a component to register GDS variables, the component must inherit from MetaComponentBase, rather than from ComponentBase. The library must inherit from MetaLibraryBase.

Rather than making these changes to the source code manually, we will make use of the tool you used to install the SDK - `plcncli`.
