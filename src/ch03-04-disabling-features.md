## Disabling Features

By default, the PLCnext runtime starts a large number of components. These components implement features on the PLC. In some circumstances it may be desirable to disable some of these features - for example, you want to free the resources that unused features would otherwise consume.

In this section, you will learn how to disable specific features of the PLCnext runtime.

First, take a copy of the system file `Device.acf.settings`:

```text
# cp /etc/plcnext/Device.acf.settings /opt/plcnext/appshome/Custom.acf.settings
(result)
```

> The `/etc/plcnext/Device.acf.settings` file is installed as part of the firmware file system and should not be edited, for reasons given in the "Firmware" section of this book.

> The acronym *acf* is short for [*Application Component Framework*][acf-info], which is the framework used by all PLCnext components. You will learn more about this framework later, when you start writing your own PLCnext runtime components.

Next, edit the `Custom.acf.settings` file, using either the `nano` or `vi` (vim) editor on the PLC, as follows:

* Delete all the child elements under the `<AcfSettingsDocument>` element, *except* the `<EnvironmentVariables>` element.
* Delete all the `<EnvironmentVariables>` elements *except* those whose `name` ends with **_SUPPORT**.
* Delete any remaining `<EnvironmentVariables>` elements whose `value` is set by other environment variables.

The features controlled by the remaining environment variables are ones that you can disable, if required.

* Delete any `<EnvironmentVariables>` elements that you want to leave at the default value.
* Add an `overridden` attribute to each remaining `<EnvironmentVariable>` element.

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

If you carefully examine the latest entries in the `Output.log` file, you will notice that there are no messages relating to the startup of components that implement the features that were disabled in the `.acf.settings` file.

### Components Included in each Feature Set

You have probably noticed that the environment variables in your custom `.acf.settings` file are the same as those listed in the tables in the previous section. Those tables provide a reference for which components will be instantiated (or not) depending on the value of a specific environment variable. In some cases, the library implementing that feature will not even be loaded by the PLCnext runtime.

> On AXC devices, the values of the environment variables `ARP_AXIOLINE_SUPPORT` and `ARP_INTERBUS_SUPPORT` are assigned automatically by the PLCnext runtime, based on whether an Inline adapter module is detected during startup. Do not attempt to change these environment variables in your own `.acf.settings` file.

### Components Required by PLCnext Engineer

By default, the PLC is configured to run a PLCnext Engineer project. If this default configuration is not changed, the following should not be disabled:

* ARP_ECLR_SUPPORT
* ARP_PROFINET_SUPPORT
* ARP_ETHERNETIP_SUPPORT

Later, you will learn how to disable support for PLCnext Engineer, which will then give you the option of disabling any or all of these components.

### ACF Settings File Name(s)

The name of the custom settings file does not need to be `Custom.acf.settings`. The filename can be anything, as long as it ends in `.acf.settings`, and is located in the `/opt/plcnext/appshome` directory. You may have noticed that the custom settings file is included using this directive in the `/etc/plcnext/Device.acf.settings` file:

```xml
    <Include path="$ARP_HOME_DIR$/appshome/*.acf.settings" />
```

As you can see, this directive will include *all* files that match the pattern specified in the `path` attribute. If multiple files match this pattern, any conflicts in the file contents are resolved as follows:

(TODO: How are conflicts resolved?)

[acf-info]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/Programming/Cpp/Cpp_program_structure/ACF_Application_Component_Framework.htm
