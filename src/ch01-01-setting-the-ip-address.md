## Setting the IP Address

Once you have assembled [everything you need to get started](ch00-00-introduction.md#what-you-will-need), your PLC will be powered up and plugged in to an Ethernet network with access to the internet. On an AXC PLC it doesn't matter which of the two Ethernet ports are used; these are switched internally.

The factory default IP address of every PLC is 192.168.1.10/24, but you will probably want to change this to something that suits your local network.

> Note: This chapter shows how to change the IP address of the PLC from the default value. In the remainder of this book, all examples will use the default IP address (192.168.1.10).

Here are two possible ways to change the IP address of the PLC:

### Use `netnames`

Netnames is a utility from Phoenix Contact that assists with the management of [Profinet](https://www.profibus.com/technology/profinet/) devices. Netnames for Linux 64 bit systems is available here.

By default, each PLCnext Control acts as a Profinet device, and so can be assigned an IP address using `netnames`.

From the `netnames` installation directory, run the following command, substituting `eth0` with the name of your Ethernet adapter with. You should get a response similar to the one shown.

```text
$ sudo ./netnames -i eth01 -c identify
axc-f-2152-1   AXC F 2152   00B0 0142 00:A0:45:A0:09:D8   192.168.1.10   255.255.0.0   0.0.0.0
```

The current address details of the PLC are shown in the response. The IP address, subnet mask and default gateway can be changed using a command similar to the following:

```text
$ sudo ./netnames -i eth01 -c setip -m 00:A0:45:A0:09:D8 -ip 192.168.178.10 -sm 255.255.0.0 -sg 192.168.178.1
(todo: response)
```

Obviously the above command will need to include parameters that suit your own network. The IP address of the PLC should be in the same subnet as the host, and the default gateway should give the PLC access to the internet.

Your PLC should now be accessible from your host machine, which can be verified using `ping`:

```text
$ ping -c 3 192.168.178.10
(todo: response)
```

### Use PLCnext Engineer

For Windows users, it is possible to set the IP address of the PLC using [PLCnext Engineer](http://www.phoenixcontact.com/qr/1046008/downloads).

Refer to the PLCnext Engineer user guide for help with this.
