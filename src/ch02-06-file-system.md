## File System

Files in a PLCnext Control are arranged in an [overlay file system][overlay].

The firmware is installed in the lower (read only) directory. All files created by users, and any changes to files in the lower directory, are stored in the upper (read/write) directory.

### Storage Media

Each PLCnext Control device includes internal, non-volatile, solid-state memory. The PLC is also supplied with an empty SD card slot.

> The firmware will only recognise SD cards specifically designed for PLCnext Control devices.

The firmware file system, mounted as the read-only lower directory, is *always* stored in internal memory. This includes all three of firmware images described in the previous section. Information on the firmware file system is available in the [PLCnext Technology Info Centre][fw-dirs-info].

If the PLC boots without an SD card present, the internal memory is used as the primary storage media for the user file system, since it is the only memory available. If the PLC boots with an SD card present, the SD card is used as the primary storage media for the user file system.

> Please note the SD card handling guidelines in the user manual for your PLCnext Control device.

In relation to the upper directory, the behaviour of the system when booting depends on the presence or absence of an external SD card, and the presence or absence of a user file system on the primary storage media:

|                     | User file system absent on primary media  | User file system present on primary media |
|:--------------------|:-----------------------------------------|:-----------------------------------------|
| **SD card absent**  | User file system is created in internal memory<br/>and mounted as upper directory. | Existing file system in internal memory<br/>is mounted as upper directory. |
| **SD card present** |  User file system is moved from internal memory to<br/>the SD card and mounted as upper directory. | Existing user file system on SD card<br/>is mounted as upper directory.<br/>*Any internal user file system is deleted.* |

> Note that in the case shown in the lower right corner of the above table, data loss may occur.

More information on this topic is available in the [PLCnext Technology Info Centre][sd-card-info].

### Deleting and Restoring File Systems

The following procedures will affect the complete firmware and/or user file system in a PLCnext Control device:

#### Firmware Update

During a firmware update, the contents of the firmware file system are replaced with new firmware files. The user file system remains unaffected, and so (for example) the IP address of the PLC will be retained, passwords will be unaffected, and user-installed files will not be deleted.

> Note: Since manual changes to firmware files are stored in the upper directory, any firmware files that were changed manually before a firmware update will remain in the upper directory and will continue to mask the corresponding file in the new firmware file system. This may adversely affect the operation of the PLC after a firmware update. It is therefore recommended that firmware files are never manually changed or deleted.

#### Type 1 Reset

A type 1 reset deletes the entire contents of the user file system on the primary storage device. The contents of the firmware file system remain unaffected.

To perform a type 1 reset, open a secure shell session on the PLC, and issue the following command:

```text
# sudo recover-plcnext 1
```

#### Type 2 Reset

A type 2 reset:

* Deletes the entire contents of the user file system on the primary storage device, just like a type 1 reset.

* Replaces the firmware file system with a factory-default firmware version.

Note that a type 2 reset may not restore the device to its factory default state, since some user files may have been stored outside the upper directory. The most common way this happens is when using an [OCI][oci] engine like Docker, Balena or Podman, which store files outside the overlay file system by default.

To perform a type 2 reset, open a secure shell session on the PLC, and issue the following command:

```text
# sudo recover-plcnext 2
```

> Warning: After either a type 1 or a type 2 reset, all user data will be deleted and the PLC's IP address and `admin` password will be restored to factory defaults.

On some devices, it is also possible to perform a type 1 or a type 2 reset using a button on the front of the PLCnext Control. See the user manual for details.

### Backups

It is highly recommended to take regular backups of the user file system.

Phoenix Contact does not currently provide a standard backup/restore procedure for user data, however you can prepare your own procedure using the examples on the [PLCnext Github page][backup].

[overlay]: https://www.datalight.com/blog/2016/01/27/explaining-overlayfs-%E2%80%93-what-it-does-and-how-it-works
[fw-dirs-info]: https://www.plcnext.help/te/Operating_System/Firmware_directories.htm
[sd-card-info]: https://www.plcnext.help/te/WBM/Security_SD_Card_settings.htm
[oci]: https://opencontainers.org/
[backup]: https://github.com/PLCnext/UtilityScripts#backups
