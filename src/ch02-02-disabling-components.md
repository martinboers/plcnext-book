## Disabling Components

By default, the PLCnext runtime starts a large number of components, each implementing a different feature on the PLC. In some circumstances it may be desirable to disable some of these components - for example, you want to free the resources that unused components would otherwise consume.

To demonstrate the extreme case, let's disable *all* the components of the PLCnext runtime!

First, take a copy of the system file `Device.acf.settings`:

```text
# cp /etc/plcnext/Device.acf.settings /opt/plcnext/appshome/Custom.acf.settings
(result)
```

> The acronym *acf* is short for *Application Component Framework*, which is the framework used by all PLCnext components. You will learn more about this framework later, when you start writing your own PLCnext runtime components.

Next, edit the `Custom.acf.settings` file, using either the `nano` or `vi` (vim) editor on the PLC, as follows:

* Delete all the child elements under the `<AcfSettingsDocument>` element, *except* the `<EnvironmentVariables>` element.
* Delete all the `<EnvironmentVariables>` elements *except* those whose `name` ends with **_SUPPORT**.
* Delete any remaining `<EnvironmentVariables>` elements whose `value` is set by other environment variables.

The components controlled by the remaining environment variables are ones that you can disable, if required.

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

* Set the `value` attributes to `"true"` or `"false"`, to control whether the corresponding component will be started by the PLCnext runtime.
* Set the `overridden` attribute to `"true"` or `"false"`, to ... WHAT ???

Save the file, and restart the PLCnext runtime:

```text
# /etc/init.d/plcnext restart
(result)
```

If you carefully examine the latest entries in the `Output.log` file, you will notice that there are no messages relating to the startup of components that were disabled in the `.acf.settings` file.

This has not really disabled *all* the components of the PLCnext runtime - there are many other components that cannot be disabled, and which do not have an entry in the `.acf.settings` file.

In the remainder of this chapter, you will learn more about each of the components of the PLCnext runtime.

### ACF Settings File Name(s)

The name of the custom settings file does not need to be `Custom.acf.settings`. The filename can be anything, as long as it ends in `.acf.settings`, and is located in the `/opt/plcnext/appshome` directory. You may have noticed that your file is included using this directive in the `/etc/plcnext/Device.acf.settings` file:

```xml
    <Include path="$ARP_HOME_DIR$/appshome/*.acf.settings" />
```

As you can see, this directive will include *all* files that match the pattern specified in the `path` attribute. If multiple files match this pattern, any conflicts in the file contents are resolved as follows:

(TODO: How are conflicts resolved?)
