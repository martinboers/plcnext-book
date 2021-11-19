## Disk Partitions

The internal storage in a PLCnext Control device is divided into a number of partitions, including:

- Boot partition.
- Device data partition.
- 3 x Root File System (RFS) partitions.
- User data partition.

### Device Data

Device data includes data that is specific to an individual device, e.g. security certificates and other data that is tied to the specific trusted platform module (TPM) chip in the device. If this data is damaged, the device may become inoperable and unrecoverable.

### Root File Systems

There are always three root file systems on a PLCnext Control device:

1. Active file system.

1. Inactive file system. This is a "standby" file system that is used in case the device cannot boot using the active file system.

1. Recovery file system. Used to replace the other two file systems during a type 2 reset (described in the next section).

Each file system is located on a different partition on the device's internal storage.

When a device is shipped from the factory, all three root file systems are the same version - usually from the latest LTS firmware version that was available when the device was manufactured.

The firmware update procedure described in the previous section actually proceeds as follows:

- The new root file system is extracted from the firmware image and installed on the inactive boot partition.
- When the device restarts next, the active and inactive partitions are swapped, so the device uses the file system from the newly installed firmware.

The status of the root file systems can be seen using the following command:

```text
# rauc status --detailed
=== System Info ===
Compatible:  axcf2152_v1
Variant:    
Booted from: rootfs.0 (A)

=== Bootloader ===
Activated: rootfs.0 (A)

=== Slot States ===
o [rootfs.1] (/dev/mmcblk0p3, ext4, inactive)
bootname: B
boot status: good
      slot status:
          bundle:
              compatible=axcf2152_v1
              version=2021.9
              description=Update container for axcf2152
              build=20210930133602
          checksum:
              sha256=12c4bc62a65e6abd4479d1d2b930cba2bde3fc5412f6fc94b3d29761e33d2661
              size=575712256
          installed:
              timestamp=2020-03-11T13:35:02Z
              count=1
          activated:
              timestamp=2020-03-11T13:35:02Z
              count=1
          status=ok

x [rootfs.0] (/dev/mmcblk0p2, ext4, booted)
bootname: A
mounted: /media/rfs/ro
boot status: good
      slot status:
          bundle:
              compatible=axcf2152_v1
              version=2022.0
              description=Update container for axcf2152
              build=20211029212448
          checksum:
              sha256=0a27a82bb7f4c02449c3c78dadb1a3d300de9c861a40f27ea55db7c3af013558
              size=598693888
          installed:
              timestamp=2021-11-08T08:59:15Z
              count=1
          activated:
              timestamp=2021-11-08T08:59:16Z
              count=1
          status=ok
```

This shows that the active root file system contains firmware version 2022.0, and that the inactive root file system contains firmware version 2021.9.

The PLCnext Info  Center gives this explanation:

> If the boot process failed several consecutive times, the inactive and the active boot partition will change their roles, too. This behavior has been implemented to keep the PLCnext Control device accessible even if the firmware update fails. The behavior can also occur when the boot process is interrupted e.g. by power loss. In this case you will observe that the controller boots with its previously installed firmware version.
> **To prevent such unintended firmware downgrades, Phoenix Contact recommends that after a successful firmware update, the same firmware should be installed once again.** This way both the active and the inactive boot partition contain the same firmware version.

### User Data

The user data partition includes:

- All user-configurable files that are installed with the firmware.
- Any files added to the device by the user.

If a removeable SD card is inserted into the PLCnext Control device, then the user data partition on the internal storage device will not be used, and user data will instead be stored on the removeable SD card. External SD cards are currently available in sizes up to 32GB, which provides a much greater storage capacity than the user data partition in internal memory.
