## Firmware

The PLCnext Control firmware includes both the Linux kernel and factory-installed software from Phoenix Contact. A PLCnext Control device can be updated with a different firmware version at any time, if required. In general, newer firmware will only add non-breaking features and bug-fixes to older versions, so applications that are designed for a specific firmware version should (generally) be able to run on newer firmware versions without modification.

### Checking the Firmware Version

It is important to know the firmware version that is running on the PLC for a number of reasons:

* When building native applications, you must use a software development kit (SDK) that is compatible with the firmware version that will run the application.

* When installing third-party applications that have been built specifically for PLCnext Control devices, you may need to select a version that is compatible with the firmware running on your PLC.

* When looking for assistance in the [PLCnext Community][plcnext-community], it will often help to know what firmware version is currently running on the PLC.

You can check the version of firmware currently running on the PLC by listing the contents of the `arpversion` file in the `/etc/plcnext/` directory.

```text
# cat /etc/plcnext/arpversion
Arpversion: 20.0.0.24752
Svn Revision: 24752
Build Job: "jenkins-PLCnext-Yocto_AXCF2152-release%2F20.0.x-57"
```

The firmware version is shown in the *Arpversion* field - in this case, 20.0.0.24752.

### Upgrading the Firmware

New versions of PLCnext Control firmware are released regularly. If the firmware on your PLC is not the latest, you may want to upgrade it to get the benefit of new features and bug fixes. The firmware on a PLCnext Control can be upgraded by following these steps:

* Download the firmware update file (ZIP archive) for your controller from the Phoenix Contact website.

* Extract the `.raucb` file from the archive.

* Copy the .raucb file to the PLC:

   ```text
   $ scp axcf2152-bundle-base-axcf2152.raucb admin@192.168.1.10:~
   (todo: response))
   ```

* Open a shell session on the PLC

   ```text
   $ ssh admin@192.168.1.10
   (todo: response))
   ```

* Update the firmware

   ```text
   # sudo update-plcnext
   ```

The PLC will take some time to install the new firmware, and the PLC will restart.

After the PLC restarts, open a new shell session and check the firmware version.

### Other Ways to Upgrade Firmware

There are three other ways to upgrade the firmware on the controller:

* Through [web-based management][wbm] (WBM).

* Using an OPC UA client (not currently documented).

* Using the `StartFirmwareUpdate` method on the [*Device Control*][service] PLCnext runtime service.

These features will all be introduced later in this book.

[plcnext-community]: https://www.plcnext-community.net
[wbm]: https://www.plcnext.help/te/WBM/Administration_Firmware_Update.htm
[service]: https://www.plcnext.help/te/About/#idevicecontrols
