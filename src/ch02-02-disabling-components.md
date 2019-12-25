## Disabling Components

By default, the PLCnext runtime starts a large number of components, each implementing a different feature on the PLC. In some circumstances it may be desirable to disable some of these features - for example, you want to free the resources that unused components would otherwise consume.

In this section, you will learn how to disable specific features of the PLCnext runtime.

First, take a copy of the system file `Device.acf.settings`:

> The `/etc/plcnext/Device.acf.settings` file is installed as part of the firmware file system and should not be edited, for reasons given in the "Firmware" section of this book.

```text
# cp /etc/plcnext/Device.acf.settings /opt/plcnext/appshome/Custom.acf.settings
(result)
```

> The acronym *acf* is short for *Application Component Framework*, which is the framework used by all PLCnext components. You will learn more about this framework later, when you start writing your own PLCnext runtime components.

Next, edit the `Custom.acf.settings` file, using either the `nano` or `vi` (vim) editor on the PLC, as follows:

* Delete all the child elements under the `<AcfSettingsDocument>` element, *except* the `<EnvironmentVariables>` element.
* Delete all the `<EnvironmentVariables>` elements *except* those whose `name` ends with **_SUPPORT**.
* Delete any remaining `<EnvironmentVariables>` elements whose `value` is set by other environment variables.

The features controlled by the remaining environment variables are ones that you can disable, if required.

* Add an `overridden` attribute to each `<EnvironmentVariable>` element.

The resulting file should look like this:

```xml
<?xml version="1.0" encoding="UTF-8"?>
<AcfSettingsDocument
  xmlns="http://www.phoenixcontact.com/schema/acfsettings"
  xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
  xsi:schemaLocation="http://www.phoenixcontact.com/schema/acfsettings.xsd"
  schemaVersion="1.0" >

  <EnvironmentVariables>
    <EnvironmentVariable name="ARP_TSM_SUPPORT" value="false" overridden="true" />
    <EnvironmentVariable name="ARP_PROFINET_SUPPORT" value="true" overridden="true" />
    <EnvironmentVariable name="ARP_PROFICLOUD_SUPPORT" value="true" overridden="true" />
    <EnvironmentVariable name="ARP_ETHERNETIP_SUPPORT" value="true" overridden="true" />
    <EnvironmentVariable name="ARP_OPC_UA_SUPPORT" value="true" overridden="true" />
    <EnvironmentVariable name="ARP_EHMI_SUPPORT" value="true" overridden="true" />
    <EnvironmentVariable name="ARP_WBM_SUPPORT" value="true" overridden="true" />
    <EnvironmentVariable name="ARP_FWM_SUPPORT" value="true" overridden="true" />
    <EnvironmentVariable name="ARP_TRACECONTROLLER_SUPPORT" value="true" overridden="true" />
    <EnvironmentVariable name="ARP_DATALOGGER_SUPPORT" value="true" overridden="true" />
    <EnvironmentVariable name="ARP_APPMANAGER_SUPPORT" value="true" overridden="true" />
    <EnvironmentVariable name="ARP_RETAIN_SUPPORT" value="true" overridden="true" />
    <EnvironmentVariable name="ARP_ECLR_SUPPORT" value="true" overridden="true" />
    <EnvironmentVariable name="ARP_SYSTEM_WATCHDOG_SUPPORT" value="true" overridden="true" />
    <EnvironmentVariable name="ARP_NETLOAD_LIMITER_SUPPORT" value="false" overridden="true" />
  </EnvironmentVariables>

</AcfSettingsDocument>
```

* Set the `value` attributes to `"true"` or `"false"`, to control whether this feature will be supported by the PLCnext runtime.
* Set the `overridden` attribute to `"true"` or `"false"`, to ... WHAT ???

Save the file, and restart the PLCnext runtime:

```text
# /etc/init.d/plcnext restart
(result)
```

If you carefully examine the latest entries in the `Output.log` file, you will notice that there are no messages relating to the startup of components that were disabled in the `.acf.settings` file.

There are many components that cannot be disabled, and which do not have an entry in the `.acf.settings` file - you will still see entries for these components in the the `Output.log` file.

> ### Components Required by PLCnext Engineer
>
> By default, the PLC is configured to run a PLCnext Engineer project. If this default configuration is not changed, the following should not be disabled:
>
>* ARP_ECLR_SUPPORT
>* ARP_PROFINET_SUPPORT
>* ARP_ETHERNETIP_SUPPORT
>
>Later, you will learn how to disable support for PLCnext Engineer, which will then give you the option of disabling any or all of these three components.

### ACF Settings File Name(s)

The name of the custom settings file does not need to be `Custom.acf.settings`. The filename can be anything, as long as it ends in `.acf.settings`, and is located in the `/opt/plcnext/appshome` directory. You may have noticed that the custom settings file is included using this directive in the `/etc/plcnext/Device.acf.settings` file:

```xml
    <Include path="$ARP_HOME_DIR$/appshome/*.acf.settings" />
```

As you can see, this directive will include *all* files that match the pattern specified in the `path` attribute. If multiple files match this pattern, any conflicts in the file contents are resolved as follows:

(TODO: How are conflicts resolved?)

(TODO: APPENDIX - Cross reference all the "SUPPORT" env variables to components - are the components just not started, are they just configured differenty?)

### Components Included in each Support Category

You may be wondering what (for example) *Profinet Support* actually is, and how this relates to the ARP_PROFINET_SUPPORT environment variable.

Here is a list of the PLCnext components that are affected by each environment variable.

| Environment Variable        | Component(s) affected           | Description      |
|:----------------------------|:--------------------------------|:-----------------|
| ARP_TSM_SUPPORT             | ???                             | ???              |
| ARP_PROFINET_SUPPORT        | Arp.Io.FbIo.PnC<br/>Arp.Io.FbIo.PnD<br/>Arp.Io.PnS<br/>Arp.Io.PnC<br/>Arp.Io.PnC | Profinet Controller<br/>Profinet Device |
| ARP_PROFICLOUD_SUPPORT      | Arp.Services.ProfiCloud         | Publishes data to the Proficloud Time-Series Data (TSD) service |
| ARP_ETHERNETIP_SUPPORT      | Arp.Io.FbIo.EthernetIP<br/>Arp.Io.EthernetIP | Ethernet/IP device |
| ARP_OPC_UA_SUPPORT          | Arp.Services.OpcUAServer        | OPC UA Server |
| ARP_EHMI_SUPPORT            | Arp.Services.Ehmi               | Embedded Human-Machine Interface |
| ARP_WBM_SUPPORT             | Arp.Services.Wbm                | Web-based management |
| ARP_FWM_SUPPORT             | Arp.Services.Fwm                | Firmware manager (?) |
| ARP_TRACECONTROLLER_SUPPORT | Arp.Services.TraceController    |                  |
| ARP_DATALOGGER_SUPPORT      | Arp.Services.DataLogger         | Datalogger included with the PLCnext firmware |
| ARP_APPMANAGER_SUPPORT      | Arp.Services.AppManager         | Manages PLCnext Store app installation & removal |
| ARP_RETAIN_SUPPORT          | Arp.Plc.Retain                  | Manages variables marked as *retentive* |
| ARP_ECLR_SUPPORT            | Arp.Plc.Eclr<br/>Arp.Plc.EclrServices<br/>Arp.Plc.Eclr.ArpDomain | Embedded Common Language Runtime, for executing C# and IEC 61131-3 software |
| ARP_SYSTEM_WATCHDOG_SUPPORT | Arp.System.Watchdog.MainProcess | System Watchdog |
| ARP_NETLOAD_LIMITER_SUPPORT | Arp.Hardware.Nim                | |

In the remainder of this chapter, you will learn more about what each of these components does.
