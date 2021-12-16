# Configuring I/O

Now that you know more about the PLCnext runtime and how to write C++ applications for PLCnext Control devices, we can return to the question that was asked at the end of Chapter 1: *How can an application read and write inputs and outputs from/to the I/O modules attached to the PLCnext Control device?*

The simplest way to do this is as follows:

- Using PLCnext Engineer software, create a new project for your target device and configure the I/O modules that are connected to the controller via Axioline, Interbus and/or Profinet. Send the PLCnext Engineer project to the PLC.

- In PLCnext Engineer, take note of the names of the GDS ports that are automatically created for the channels on each I/O module.

- In a `.gds.config` file, connect the GDS ports from the I/O modules to corresponding GDS ports on your ACF component(s) and/or real-time program(s).

In this way, C++ components and programs can easily exchange data with field devices via the I/O modules attached to the PLCnext Control device.

## IoConf

If your application precludes the use of PLCnext Engineer for some reason, then it is possible to generate the same I/O configuration files that PLCnext Engineer creates using a .NET class library called IoConf. The use of this tool is demonstrated in a [tutorial on Github][ioconf].

## Axioline Master service

Another I/O configuration option is given in the [Bus Conductor example][bus-conductor] on Github. This solution is suitable when the precise I/O configuration is not known at design-time, or if the configuration must be changed dynamically at run-time.

[ioconf]: https://github.com/PLCnext/IOconf_Examples
[bus-conductor]: https://github.com/PLCnext/BusConductor
