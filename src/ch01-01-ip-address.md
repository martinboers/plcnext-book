## Setting the IP Address

Once you have assembled [everything you need to get started][what-you-will-need], your PLC will be powered up and plugged in to an Ethernet network with access to the internet. On an AXC PLC it doesn't matter which of the two Ethernet ports are used; these are switched internally.

The factory default IP address of every PLC is 192.168.1.10/24, but you will probably want to change this to something that suits your local network.

> This section shows how to change the IP address of the PLC from the default value. In the remainder of this book, all examples will use the default IP address (192.168.1.10).

Here are two possible ways to change the IP address of the PLC:

### Use `netnames`

Netnames is a utility from Phoenix Contact that assists with the management of [Profinet][profinet] devices. Netnames is available for [Linux 64 bit][netnames-linux] and [Windows][netnames-win] operating systems. The remainder of this section uses the Linux version of Netnames.

Firstly, make sure that netnames can be executed. From the `netnames` installation directory, run the following command:

```text
$ chmod a+x netnames
```

By default, each PLCnext Control acts as a Profinet device, and so can be assigned an IP address using `netnames`.

Run the following command, substituting `eth0` with the name of your Ethernet adapter. You should get a response similar to the one shown.

```text
$ sudo ./netnames -i eth0 -c identify
axc-f-2152-1   AXC F 2152   00B0 0142 00:A0:45:A0:09:D8   192.168.1.10   255.255.255.0   0.0.0.0
```

The MAC address and current IP address details of the PLC are shown in the response.

If you get no response, then make sure the name of the Ethernet adapter is correct. Also, be aware that the [Discovery and Configuration Protocol][profinet-dcp] (DCP) used by `netnames` is a link layer protocol, and so is not routable.

The IP address, subnet mask and default gateway can be changed using a command similar to the following:

```text
$ sudo ./netnames -i eth0 -c setip -m 00:A0:45:A0:09:D8 -ip 192.168.178.10 -sm 255.255.255.0 -sg 192.168.178.1
Device responded: OK
```

Obviously the above command will need to include parameters that suit your own device and network. The IP address of the PLC should be in the same subnet as the host, and the default gateway should give the PLC access to the internet.

Your PLC should now be accessible from your host machine, which can be verified using `ping`:

```text
$ ping -c 3 192.168.178.10
PING 192.168.178.10 (192.168.178.221) 56(84) bytes of data.
64 bytes from 192.168.178.10: icmp_seq=1 ttl=64 time=5.73 ms
64 bytes from 192.168.178.10: icmp_seq=2 ttl=64 time=4.87 ms
64 bytes from 192.168.178.10: icmp_seq=3 ttl=64 time=18.4 ms

--- 192.168.178.10 ping statistics ---
3 packets transmitted, 3 received, 0% packet loss, time 2010ms
rtt min/avg/max/mdev = 4.877/9.690/18.464/6.214 ms
```

### Use PLCnext Engineer

For Windows users, it is also possible to set the IP address of the PLC using [PLCnext Engineer][plcnext-eng] software. Refer to the guide "[Getting started with PLCnext Engineer][plcnext-eng-getting-started]" for instructions on how to do this.

[what-you-will-need]: ch00-00-introduction.md#what-you-will-need
[profinet]: https://www.profibus.com/technology/profinet/
[netnames-linux]: http://plcnext-runtime.com/downloads/netnames/linux-x64/netnames
[netnames-win]: http://www.phoenixcontact.net/qr/2316390/softw
[profinet-dcp]: (https://profinetuniversity.com/naming-addressing/profinet-dcp/)
[plcnext-eng]: http://phoenixcontact.net/product/1046008
[plcnext-eng-getting-started]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/PLCnext_Engineer/Getting_started_with_PLCnext_Engineer.htm