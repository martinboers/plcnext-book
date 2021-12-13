## Creating GDS variables - Part 1

You have seen how the Global Data Space (GDS) provides a simple way to exchange data between otherwise isolated PLCnext runtime components.

It is possible for your own component instance to create variables in the GDS. These variables can then be accessed by other PLCnext runtime components using (for example) the Data Access RSC service, as discussed the previous section.

GDS variables can also:

- be included in the OPC UA server address space,
- have their value persisted (or "retained") across restarts of the PLCnext runtime,
- have their value logged to a Proficloud Time Series Data (TSD) service,
- be accessed through a REST API,
- be used on web-based HMI pages,
- be used to exchange data with physical I/O modules.

In order for a component to create its own variables in the GDS, the component must inherit from `MetaComponentBase`, rather than from `ComponentBase`. The library class must also inherit from `MetaLibraryBase`. Additional code must also be added to the library and the component class, e.g. the `RegisterComponentPorts` method must be implemented in the component.

Rather than making these changes to the source code manually, we will make use of the tool you probably used to install the SDK - the PLCnext Command Line Interface, or `plcncli`.
