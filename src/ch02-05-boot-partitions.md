## Boot Partitions

There are always three firmware images on a PLCnext Control device:

1. Active boot image. This is used to boot the PLC during startup.

1. Inactive boot image. This is a "standby" image that is used in case the device cannot boot using the active image.

1. Recovery image. Used to replace the other two images during a type 2 reset (described in the next section).

Each image is located on a different partition on the device's internal storage.

When a device is shipped from the factory, all three firmware images are the same version - usually the latest LTS version that was available when the device was manufactured.

The firmware update procedure described in the previous section actually proceeds as follows:

- The new firmware image is installed on the inactive boot partition.
- When the device restarts next, the active and inactive partitions are swapped, so the device boots the newly installed firmware version.

These firmware images can be seen using the rauc status command:

This shows that the firmware that is currently running is version xxx, and that the other (inactive) firmware image is version xxx.

The PLCnext Info  Center gives this explanation:

> If the boot process failed several consecutive times, the inactive and the active boot partition will change their roles, too. This behavior has been implemented to keep the PLCnext Control device accessible even if the firmware update fails. The behavior can also occur when the boot process is interrupted e.g. by power loss. In this case you will observe that the controller boots with its previously installed firmware version.
> **To prevent such unintended firmware downgrades, Phoenix Contact recommends that after a successful firmware update, the same firmware should be installed once again.** This way both the active and the inactive boot partition contain the same firmware version.

The Recovery image cannot be changed by the user.
