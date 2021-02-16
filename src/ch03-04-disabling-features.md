## Disabling Features

By default, the PLCnext runtime starts a large number of components. These components implement features on the PLC. In some circumstances it may be desirable to disable some of these features - for example, you want to free the resources that unused features would otherwise consume.

In this section, you will learn how to disable specific features of the PLCnext runtime.

First, take a copy of the system file `Components.acf.settings`:

```text
# cp /etc/plcnext/Components.acf.settings /opt/plcnext/appshome/Custom.acf.settings
```

> The `/etc/plcnext/Components.acf.settings` file is installed as part of the firmware file system and should not be edited, for reasons given in the "Firmware" section of this book.

> The acronym *acf* is short for [*Application Component Framework*][acf-info], which is the framework used by all PLCnext components. You will learn more about this framework later, when you start writing your own PLCnext runtime components.

Next, edit the `Custom.acf.settings` file, using either the `nano` or `vi` (vim) editor on the PLC, as follows:

* Delete any `<EnvironmentVariables>` elements that you want to leave at the default value.
* Add an `override` attribute to each remaining `<EnvironmentVariable>` element.

The resulting file should look something like this:

```xml

<?xml version="1.0" encoding="UTF-8"?>
<AcfSettingsDocument
  xmlns="http://www.phoenixcontact.com/schema/acfsettings"
  xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
  xsi:schemaLocation="http://www.phoenixcontact.com/schema/acfsettings.xsd"
  schemaVersion="1.0" >

  <!-- Insert new entries in related domain section in alphabetic order -->
  <EnvironmentVariables>

    <!-- Device components-->
    <EnvironmentVariable name="ARP_COMPONENT_RFCDISPLAY" value="false" override="true" />

    <!-- Hardware components-->
    <EnvironmentVariable name="ARP_COMPONENT_NETLOAD_LIMITER" value="false" override="true" />
    <EnvironmentVariable name="ARP_COMPONENT_EXTERNAL_PCI" value="false" override="true" />
    <EnvironmentVariable name="ARP_COMPONENT_EXTERNAL_SDCARD" value="true" override="true" />

    <!-- Io components-->
    <EnvironmentVariable name="ARP_COMPONENT_AXIOLINE" value="false" override="true" />
    <EnvironmentVariable name="ARP_COMPONENT_ETHERNETIP" value="true" override="true" />
    <EnvironmentVariable name="ARP_COMPONENT_INTERBUS" value="false" override="true" />
    <EnvironmentVariable name="ARP_COMPONENT_PROFINET" value="true" override="true" />
    <EnvironmentVariable name="ARP_COMPONENT_PND" value="false" override="true" />
    <EnvironmentVariable name="ARP_COMPONENT_PNC" value="false" override="true" />

    <!-- Plc components-->
    <EnvironmentVariable name="ARP_COMPONENT_ECLR" value="true" override="true" />
    <EnvironmentVariable name="ARP_COMPONENT_RETAIN" value="true" override="true" />

    <!-- Services components-->
    <EnvironmentVariable name="ARP_COMPONENT_APPMANAGER" value="true" override="true" />
    <EnvironmentVariable name="ARP_COMPONENT_DATALOGGER" value="true" override="true" />
    <EnvironmentVariable name="ARP_COMPONENT_EHMI" value="true" override="true" />
    <EnvironmentVariable name="ARP_COMPONENT_FWM" value="true" override="true" />
    <EnvironmentVariable name="ARP_COMPONENT_LINUXSYSLOG" value="true" override="true" />
    <EnvironmentVariable name="ARP_COMPONENT_OPC_UA" value="true" override="true" />
    <EnvironmentVariable name="ARP_COMPONENT_PROFICLOUD" value="true" override="true" />
    <EnvironmentVariable name="ARP_COMPONENT_PROFICLOUD_V3" value="false" override="true" />
    <EnvironmentVariable name="ARP_COMPONENT_SPNSPROXY" value="false" override="true" />
    <EnvironmentVariable name="ARP_COMPONENT_TRACECONTROLLER" value="true" override="true" />
    <EnvironmentVariable name="ARP_COMPONENT_TSM" value="false" override="true" />
    <EnvironmentVariable name="ARP_COMPONENT_WBM" value="true" override="true" />
    <EnvironmentVariable name="ARP_COMPONENT_WCM" value="true" override="true" />
    <EnvironmentVariable name="ARP_COMPONENT_LOGGING" value="false" override="true" />
    <EnvironmentVariable name="ARP_COMPONENT_LOGMANAGER" value="false" override="true" />

    <!-- System components-->
    <EnvironmentVariable name="ARP_COMPONENT_SYSTEM_WATCHDOG" value="true" override="true" />

  </EnvironmentVariables>

</AcfSettingsDocument>
```

* Set the `value` attributes to `"true"` or `"false"`, to control whether this feature will be supported by the PLCnext runtime.

Save the file, and restart the PLCnext runtime:

```text
# /etc/init.d/plcnext restart
(result)
```

If you carefully examine the latest entries in the `Output.log` file, you will notice that there are no messages relating to the startup of components that implement the features that were disabled in the `.acf.settings` file.

### Components Included in each Feature Set

You have probably noticed that the environment variables in your custom `.acf.settings` file are the same as those listed in the tables in the previous section. Those tables provide a reference for which components will be instantiated (or not) depending on the value of a specific environment variable. In some cases, the library implementing that feature will not even be loaded by the PLCnext runtime.

> On AXC devices, the values of the environment variables `ARP_COMPONENT_AXIOLINE` and `ARP_COMPONENT_INTERBUS` are assigned automatically by the PLCnext runtime, based on whether an Inline adapter module is detected during startup. Do not attempt to change these environment variables in your own `.acf.settings` file.

### ACF Settings File Name(s)

The name of the custom settings file does not need to be `Custom.acf.settings`. The filename can be anything, as long as it ends in `.acf.settings`, and is located in the `/opt/plcnext/appshome` directory. You may have noticed that the custom settings file is included using this directive in the `/etc/plcnext/Device.acf.settings` file:

```xml
  <!-- Include settings files for overridden app specific settings -->
  <Include path="/opt/plcnext/appshome/*.acf.settings" />
```

As you can see, this directive will include *all* files that match the pattern specified in the `path` attribute. If multiple files match this pattern, then all the files will be processed. If there are any conflicts - e.g. if one file overrides an environment variable with the value "true", and another file overrides the same variable with the value "false" - then the final value of that environment variable could be either "true" or "false". It is up to the user to make sure that conflicts like this do not happen.

[acf-info]: https://www.plcnext.help/te/Programming/Cpp/Cpp_program_structure/ACF_Application_Component_Framework.htm
