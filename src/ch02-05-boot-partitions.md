## Boot Partitions

Three firmware images:

Recovery image. Installed in the factory. Usually the latest LTS version that was available when the device was manufactured.

Boot images 1 and 2. Initally, both are the same as the recovery image.

Each image is located on a different partition on the device's internal storage.

The firmware update procedure described in the previous chapter actually proceeds as follows:

- The new firmware image is installed on the inactive boot partition.
- When the device restarts next, the active and inactive partitions are swapped, so the device boots the newly installed firmware version.

These firmware images can be seen using the rauc status command:

This shows that the firmware that is currently running is version xxx, and that the other (inactive) firmware image is version xxx.

But why?

(explanation in the Info Center):

> If the boot process failed several consecutive times, the inactive and the active boot partition will change their roles, too. This behavior has been implemented to keep the PLCnext Control device accessible even if the firmware update fails. The behavior can also occur when the boot process is interrupted e.g. by power loss. In this case you will observe that the controller boots with its previously installed firmware version.
> **To prevent such unintended firmware downgrades, Phoenix Contact recommends that after a successful firmware update, the same firmware should be installed once again.** This way both the active and the inactive boot partition contain the same firmware version.

The Recovery Image is used during a "Factory Reset" (described in the next chapter), which may be required if the active firmware image becomes irreparably damamged for some reason. During this type of reset, the recovery image is copied to both (?) boot partitions.
