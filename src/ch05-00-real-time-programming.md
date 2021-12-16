# Real Time Programming

The previous chapter showed how to write PLCnext runtime applications that do not require real-time, deterministic performance. The priority of the process executing ACF components (including worker threads) is no higher than other threads or processes on the device, and as a result the "jitter" - or the variation in the execution period - is likely to be very high for worker threads. This is fine for many applications, but some applications require a more deterministic execution period, like is available on traditional PLCs.

The Linux kernel on PLCnext Control devices includes the [PREEMPT-RT patch][preempt], so it is possible to execute code with real-time priority. On its own, the use of this feature requires extensive experience of C++ and POSIX thread handling.

Luckily for us, the PLCnext runtime includes a set of *PLC* components, which allow users to easily implement C++ applications that have the same deterministic performance as applications on traditional PLCs. One of these PLCnext runtime components is the Execution and Synchronisation Manager (ESM), which - as the name suggests - is responsible for scheduling and executing real-time tasks.

The ESM uses terminology from the [IEC 61131][iec] standard, which PLC programmers will be familiar with. For example, a *program* is a piece of code that will be executed in real time. One or more named *program instances* are created in a *task*. Tasks can be executed cyclically with a fixed period, or executed when other criteria are satisfied e.g. on a specified event. When a task is executed, the program instances defined in that task will be executed one after the other, in the order specified. It is possible for a PLC application to contain multiple tasks. On PLCnext Control devices, it is possible to assign tasks to one of multiple ESM instances. Each ESM instance corresponds to a core on the device CPU, so (for example) an AXC F 2152 with two CPU cores has two ESM instances in the PLCnext runtime.

There is more information about the ESM in the [PLCnext Info Center][info-center].

In the previous chapter we saw how to configure the Global Data Space using a `.gds.config` file in XML format. The ESM is configured in a similar way, using an `.esm.config` file. This configuration file:

- Defines real-time tasks.
- Assigns each task to an ESM instance.
- Defines real-time program instances.
- Assigns program instances to tasks.

This chapter will discuss C++ programs, and look at how to execute these on a PLCnext Control device.

[preempt]: https://wiki.linuxfoundation.org/realtime/start
[iec]: https://en.wikipedia.org/wiki/IEC_61131
[info-center]: https://www.plcnext.help/te/PLCnext_Runtime/ESM.htm
