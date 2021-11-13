## Firmware

The PLCnext Control firmware includes both the Linux kernel and factory-installed software from Phoenix Contact. A PLCnext Control device can be updated with a different firmware version at any time, if required. In general, newer firmware will only add non-breaking features and bug-fixes to older versions, so applications that are designed for a specific firmware version should (generally) be able to run on newer firmware versions without modification.

### Firmware Release Schedule

PLCnext Control firmware is generally released four times a year; the first is a Long Term Support (LTS) version, and the other three are "feature" releases for those who want the very latest features as early as possible. The [firmware release history and  future release schedule][releases] is shown in the PLCnext Info Center.

There is also some information on [upcoming firmware features][upcoming-features] in the PLCnext Info Center.

### Checking the Firmware Version

It is important to know the firmware version that is running on the device for a number of reasons:

* When building native applications, you must use a software development kit (SDK) that is compatible with the firmware version that will run the application.

* When installing third-party applications that have been built specifically for PLCnext Control devices, you may need to select a version that is compatible with the firmware running on your device.

* When looking for assistance in the [PLCnext Community][plcnext-community], it will often help to know what firmware version is currently running on the device.

You can check the version of firmware currently running on the device by listing the contents of the `arpversion` file in the `/etc/plcnext/` directory.

```text
# cat /etc/plcnext/arpversion
Arpversion: 21.6.0.46
GIT Commit Hash: 8f3c6754f20bab7c5cd88aa4de07a797c3153516
Build Job: "jenkins-PLCnext-Yocto_Targets-Yocto_AXCF2152-release%2F21.6.x-46"
```

The firmware version is shown in the *Arpversion* field - in this case, 21.6.0.46.

### Upgrading the Firmware

New versions of PLCnext Control firmware are released regularly. If the firmware on your device is not the latest, you may want to upgrade it to get the benefit of new features and bug fixes. The firmware on a PLCnext Control device can be upgraded by following these steps:

* Download the firmware update file (ZIP archive) for your controller from the Phoenix Contact website.

  For the AXC F 2152, you can browse [directly to the firmware download page][fw-download]. For other PLCnext Control devices, you need to navigate to the firmware download page through the relevant product page on the Phoenix Contact website.

* Extract the `.raucb` file from the archive.

  Now you can guess (correctly) that PLCnext Control devices use [RAUC][rauc] for firmware updates.

* Copy the .raucb file to the device:

   ```text
   $ scp axcf2152-bundle-base-axcf2152.raucb admin@192.168.1.10:~
   ```

* Open a shell session:

   ```text
   $ ssh admin@192.168.1.10
   ```

* Update the firmware:

   ```text
   # sudo /etc/init.d/plcnext stop
   Password:
   Stopping service plcnext
   plcnext stopped
   #
   # admin@axcf2152:~$ rauc install axcf2152-2022.0.0.13-LTS-beta.raucb
   installing
   0% Installing
   0% Determining slot states
   20% Determining slot states done.
   20% Checking bundle
   20% Verifying signature
   40% Verifying signature done.
   40% Checking bundle done.
   40% Checking manifest contents
   60% Checking manifest contents done.
   60% Determining target install group
   80% Determining target install group done.
   80% Updating slots
   80% Checking slot rootfs.0
   90% Checking slot rootfs.0 done.
   90% Copying image to rootfs.0
   100% Copying image to rootfs.0 done.
   100% Updating slots done.
   100% Installing done.
   Installing `/opt/plcnext/axcf2152-2022.0.0.13-LTS-beta.raucb` succeeded
   #
   # sudo reboot
   ```

After the device restarts, open a new shell session and check the firmware version.

### But There's More!

There are actually three firmware copies lurking on a PLCnext Control device, and all three may be different versions. The above procedure only replaces one of these three firmware installations. You will learn more about this in the next section.

### Other Ways to Upgrade Firmware

There are currently many other ways to upgrade the firmware on the controller, including:

* Using the `update-plcnext` script, as described in the [Firmware update][fw-update] section of the PLCnext Info Center.

* Through [web-based management][wbm] (WBM).

* Using the Device Management service on the [Proficloud][proficloud] web site.

* Using an OPC UA client (not currently documented).

* Using [Eclipse hawkBit™][hawkbit] with the [hawkBit™ client app][hawkbit-app] from the PLCnext Store.

* Using the `StartFirmwareUpdate` method on the [Device Control][service] PLCnext runtime service.

All the methods listed above require that the PLCnext Runtime be running. If this is the case, then firmware upgrades should be performed using one of these methods rather than using the `rauc` command.

[releases]: https://www.plcnext.help/te/About/Releases.htm
[upcoming-features]: https://www.plcnext.help/te/Features_and_roadmaps/Roadmaps.htm
[fw-download]: 
[rauc]: https://rauc.io/
[plcnext-community]: https://www.plcnext-community.net
[fw-update]: https://www.plcnext.help/te/Operating_System/Operating_system.htm
[wbm]: https://www.plcnext.help/te/WBM/Administration_Firmware_Update.htm
[proficloud]: https://proficloud.io/
[service]: https://www.plcnext.help/te/Service_Components/Remote_Service_Calls_RSC/RSC_device_interface_services.htm
[hawkbit]: https://www.eclipse.org/hawkbit/
[hawkbit-app]: https://www.plcnextstore.com/permalinks/apps/latest/60002172000381
