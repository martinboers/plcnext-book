## Starting a Shell Session

The PLC is running a secure shell (ssh) daemon so, once the PLC is accessible on the local area network, you can go ahead and open a shell session on the PLC from the host:

```text
$ ssh admin@192.168.1.10
The authenticity of host '192.168.1.10 (192.168.1.10)' can't be established.
ECDSA key fingerprint is SHA256:uUhWsqW6TQy/KDZ7rdydja8zws7zABLF5CI2/wm5owQ.
Are you sure you want to continue connecting (yes/no)?
```

You are requesting to log on to the PLC as the user *admin*. This user is set up by default on every PLCnext Control. The warning about the authenticity of the host is normal when using `ssh` to connect to a device for the first time. By answering `yes` to the question, the following appears:

```text
Warning: Permanently added '192.168.1.10' (ECDSA) to the list of known hosts.
admin@192.168.1.10's password:
```

... and after entering the default password (printed on the housing of the PLC), the PLC's command prompt will appear:

```text
admin@axcf2152:~$
```
