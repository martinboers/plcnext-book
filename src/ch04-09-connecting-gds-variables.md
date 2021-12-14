## Connecting GDS Variables

Consider the following question:

You have an ACF component that needs to know the current average CPU load of the device it's running on. The component starts a worker thread that executes a method periodically. How can that method read the average CPU load of the device?

Using what you've learned so far in this chapter, you might consider two possible solutions:

1. Use the `GetItem` method on the [Device Status RSC service][device-status] to read the CPU load of the device, using the `Status.Cpu.0.Load.Percent` item specifier.

1. Use the `ReadSingle` method on the [Data Access RSC service][data-access] to read the CPU load of the device from the GDS port variable named `Arp.Plc.Eclr/DEVICE_STATE.CPU_LOAD_ALL_CORES`.

Those are both perfectly acceptable solutions, but in this case there is a third, simpler solution.

The GDS component in the PLCnext Runtime provides the facility to "connect" any GDS OUT ports to any GDS IN port(s) of compatible type, without any code. Once these ports connections are configured, the PLCnext runtime will automatically transfer data from each IN port to each connected OUT port.

The steps to do this are:

- Starting with the example in the previous section, add a worker thread that periodically executes a method that prints the value of `MyGdsVariable` to the `Output.log` file.

- In the project `src` directory, create a file named `MyGdsProject.gds.config`, containing the following:

  ```xml
  <?xml version="1.0" encoding="utf-8"?>
  <GdsConfigurationDocument xmlns:xsd="http://www.w3.org/2001/XMLSchema" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" schemaVersion="1.0" xmlns="http://www.phoenixcontact.com/schema/gdsconfig">
    <ComponentTaskRelations />
    <Connectors>
      <Connector startPort="Arp.Plc.Eclr/DEVICE_STATE.CPU_LOAD_ALL_CORES" endPort="MyComponent1/MyGdsVariable" />
    </Connectors>
  </GdsConfigurationDocument>
  ```

  This configuration file will create a GDS port connector that will automatically transfer data between the `startPort` and the `endPort`. In this case the `endPort` is the GDS port on your component instance.

- Build and deploy your project in the usual way.

- Copy the GDS configuration file from the host to the target:

  ```text
  $ scp src/MyGDSProject.acf.config admin@192.168.1.10:~/projects/Default/Plc/Gds
  ```

  The PLCnext runtime will automatically load all files in this destination directory that match the pattern `*.gds.config` (this is specified in the file `/etc/plcnext/device/Plc/Gds/Gds.settings`).

- Restart the PLCnext runtime.

  You should now see the value of the CPU load appearing in the `Output.log` file.

A benefit of this file-based configuration technique is that the `.gds.config` file can include I/O ports - that is, GDS port variables that are used to exchange data with inputs and outputs on physical I/O modules. The Data Access RSC service, on the other hand, cannot exchange data directly with I/O port variables.

One disadvantage of this technique is that the names of all the GDS ports must be known at design-time, since variable names must appear in a `.gds.config` file. When using the Data Access RSC service, on the other hand, the name of each GDS port is passed as a String variable, and so can be specified at run-time.

[device-status]: https://www.plcnext.help/te/Service_Components/Remote_Service_Calls_RSC/RSC_device_interface_services.htm
[data-access]: https://www.plcnext.help/te/Service_Components/Remote_Service_Calls_RSC/RSC_GDS_services.htm
