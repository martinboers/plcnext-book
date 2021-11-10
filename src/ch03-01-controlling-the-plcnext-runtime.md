## Controlling the PLCnext Runtime

When the device boots, it automatically runs the script in the file `/etc/init.d/plcnext`. This starts the *PLCnext runtime*.

We can stop the PLCnext runtime any time, using the same script:

```text
# sudo /etc/init.d/plcnext stop
Stopping service plcnext
plcnext stopped
```

Start the PLCnext runtime, and watch entries being added to the default log file:

```text
# sudo /etc/init.d/plcnext start && tail -f -n 0 /opt/plcnext/logs/Output.log
Starting service plcnext
Set plcnext exports
plcnext started (bus system is axioline)
12.08.21 19:42:14.764 Arp.System.Acf.Internal.ApplicationBase     INFO  - ArpVersion: 2021.6.0 (21.6.0.46)
  :
```

You can see lots of activity in the `Output.log` file when the PLCnext Runtime starts up. The `Output.log` file is an important source of information - for example, if your PLCnext Control device ever behaves unexpectedly, the `Output.log` file will often help you to identify the problem.

But what does the PLCnext Runtime do? Basically, the PLCnext runtime turns an otherwise ordinary device into a PLC, and at the same time turns that device into much more than an ordinary PLC.

You have already used one feature of the PLCnext Runtime, when you set the IP address using `netnames`. Netnames is used to manage Profinet devices, and the PLCnext Runtime starts a component that makes the controller behave like a Profinet device. See what happens when we try to use `netnames` when the PLCnext Runtime is stopped:

```text
# sudo /etc/init.d/plcnext stop
```

On the host machine:

```text
$ sudo ./netnames -i eth0 -c identify
(no result)
```

We can still ping the PLC:

```text
$ ping 192.168.1.10
```

... because ICMP messages are handled by the Linux operating system, not by the PLCnext runtime. This is also why we can maintain a remote shell session on the PLC, regardless of whether the PLCnext runtime is running or stopped.

Start the PLCnext Runtime again:

```text
# sudo /etc/init.d/plcnext start
```

... and `netnames` will again be able to discover the PLC. You may need to wait for up to a minute for the PLCnext runtime to finish starting before `netnames` will see it.
