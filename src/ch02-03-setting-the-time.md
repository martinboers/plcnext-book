## Setting the Time

Like with other Linux distributions, it is possible to set the date and time on a PLCnext Control device using the `date` command.

By default, each PLCnext Control device is configured to use Coordinated Universal Time (UTC). You should set the date and time on your device to the correct UTC time. This will - among other things - avoid problems with security certificates, which often require the time on the device to be more or less correct.

### Network Time Protocol

If the device has access to a Network Time Protocol (NTP) server, either locally or on the internet, then it is possible to use that NTP server to maintain the correct time on the PLCnext Control device. Like with other Linux distributions, this can be achieved by editing the file `/etc/ntp.conf` on the device.

Information on how to set the time on a PLCnext Control device using various methods is available in the [PLCnext Info Center][info-center].

### Setting the Time Zone

For applications that use local time rather than universal time, you may want to set the time zone on your PLCnext Control device using the procedure in the following article:

[How to set the time zone on a PLCnext Control device.][time-zone]

The release notes for firmware version 2021.9 state that "Setting local time zones is not fully supported". The procedure in the above article involves editing a system configuration file, which may cause problems during future firmware upgrades.

[info-center]: https://www.plcnext.help/te/Operating_System/System_time.htm
[time-zone]: https://pxc1.esc-eu-central-1.empolisservices.com/gatekeeper/guesttoken/45?app=/service-express/portal/cb?redirect=https://pxc1.esc-eu-central-1.empolisservices.com/service-express/portal/object/esc/en-so-deb95804-1aba-4247-8d77-da744c190b90
