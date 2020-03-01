## Users and Privileges

### admin user

By default, the `admin` user is granted the privilege to run a number of commands as a super-user. You can see the complete list of these commands as follows:

```text
admin@axcf2152:~$ sudo -l
Password:
User admin may run the following commands on axcf2152:
    (ALL) /usr/bin/passwd
    (ALL) /sbin/ifconfig
    (ALL) /bin/date
    (ALL) /etc/init.d/plcnext
    (ALL) /etc/init.d/openvpn
    (ALL) /etc/init.d/ntpd
    (ALL) /etc/init.d/sshd
    (ALL) /usr/sbin/ipsec
    (ALL) /usr/sbin/swanctl
    (ALL) /etc/init.d/firewall
    (ALL) /usr/sbin/nft
    (ALL) /sbin/ldconfig
    (ALL) /sbin/shutdown
    (ALL) /sbin/reboot
    (ALL) /usr/sbin/tcpdump
    (ALL) /usr/sbin/update-rc.d
    (ALL) /usr/sbin/update-plcnext
    (ALL) /usr/sbin/recover-plcnext
    (ALL) /usr/bin/dpkg
    (ALL) /usr/bin/gdbserver
    (ALL) /usr/bin/gdbserver-plcnext.sh
    (ALL) /usr/bin/gdbserver-preprocess.sh
    (ALL) /usr/bin/gdbserver-prio-request.sh
    (ALL) /usr/bin/gdbserver-prio-set.sh
    (ALL) /usr/bin/gdbserver-start-program-wrapper.sh
    (ALL) /usr/sbin/update-axcf2152
    (ALL) /usr/sbin/recover-axcf2152
    (ALL) /usr/bin/gdbserver-plcnext.sh
    (ALL) /usr/bin/gdbserver-preprocess.sh
    (ALL) /usr/bin/gdbserver-prio-request.sh
    (ALL) /usr/bin/gdbserver-prio-set.sh
    (ALL) /usr/bin/gdbserver-start-program-wrapper.sh
    (ALL) /usr/sbin/sdcard_state.sh
```

These sudo privileges are granted using configuration files in the `/etc/sudoers.d` directory.

### Extending admin privileges

In some cases it may be required to grant the `admin` user the privilege to execute more commands than those listed above. This can be done by editing the file `/etc/sudoers`.

> According to the notes included in that file, `/etc/sudoers` MUST be edited with the `visudo` command as `root`.

In the extreme case, it is possible to grant the admin user the right to execute all commands on the controller, by adding the following line to the `/etc/sudoers` file:

```text
admin ALL=(ALL) ALL
```

### root user

In some cases it may be required to switch to the root user. In this case, a root user password must first be set, using the following command:

```text
admin@axcf2152:~$ sudo passwd root

We trust you have received the usual lecture from the local System
Administrator. It usually boils down to these three things:

    #1) Respect the privacy of others.
    #2) Think before you type.
    #3) With great power comes great responsibility.

Password: *Enter admin user password*

Changing password for root
Enter the new password (minimum of 5 characters)
Please use a combination of upper and lower case letters and numbers.
New password: *Enter root user password*
Re-enter new password: *Confirm password*
```

You can now switch to the root user using the command `su root`, or simply `su`.

### Creating an ssh session as root

In some cases, it may be required to connect directly to the controller as `root`, using `ssh` or its associated utilities (`scp`, `sftp`, etc).

In order to open an ssh session on the controller as `root`, the ssh daemon must be configured to accept logins from that user. To do this, log in to the controller as `admin`, switch to the `root` user using the `su` command, and edit the `/etc/ssh/sshd_config` file using your favourite editor.

> The controller includes `vi` (vim) and `nano` text editors.
> There are many online resources available if you need to learn how to use one these editors.

In the `sshd_config` file, remove the comment symbol `#` from this line:

```text
#PermitRootLogin yes
```

Save the file, exit from the editor, and restart the ssh daemon:

```text
root@axcf2152:~# /etc/init.d/sshd restart
```
