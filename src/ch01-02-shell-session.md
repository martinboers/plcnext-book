## Starting a Shell Session

The PLC is running a secure shell (ssh) daemon so, once the PLC is accessible on the local area network, we can go ahead and open a shell session on the PLC from the host:

```text
$ ssh admin@192.168.178.10
(todo: response))
```

You'll notice a few things about this command:

1. You are requesting to log on to the PLC as the user *admin*. This user is set up by default on every PLCnext Control. The default password for this user is printed on the housing of the PLC.

1. The first time you run this command on a new PLC, it will ask you to confirm ... (todo: Finish this)

Once the shell session has been established, you will see the PLC command line:

```text
admin@axcf2152:~$
```
