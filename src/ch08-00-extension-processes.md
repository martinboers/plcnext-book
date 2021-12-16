# Extension Processes in C/C++

You have seen how to use the Application Component Framework to extend the PLCnext runtime with your own components. By using the ACF, these components are integrated tightly with the PLCnext runtime, where they are treated in exactly the same way as factory-installed components.

It is also possible to extend the PLCnext runtime with extension *processes* (also called *External Function Extensions*).

A high-level comparison of extension components (internal function extensions) and extension processes (external function extensions) is given in the [PLCnext Technology Info Center][comparison].

Extension processes are useful for PLCnext Control functions that must be started and stopped with the PLCnext runtime - just like extension components - but that cannot or do not want to use the ACF. A typical example: When porting a third-party PLC runtime to the PLCnext Control platform, it may be impractical to re-design the source code into PLCnext runtime components.

One challenge faced by extension processes is that GDS ports cannot be created on extension process. So the question once again arises: *How can an extension process read and write inputs and outputs from/to the I/O modules attached to the PLCnext Control device?*

You have already seen how to read and write GDS variable data using RSC services, and RSC services can also be used to (indirectly) access PLC I/O from any process running outside the PLCnext runtime. However, as discussed previously, RSC services are only suitable for non-real time applications, like ACF components. This solution may be fine for any extension process that does not require deterministic I/O access.

For more demanding applications, the PLCnext runtime provides a mechanism for extension processes to read and write PLC I/O in a deterministic way. This deterministic access to PLC I/O makes extension processes ideally suited to third-party runtimes like [Codesys][codesys], [Four-Zero][four-zero] and [4diac][4diac]. In this case the solution involves the use of an ANSI-C interface. This type of solution is described in detail in the [Sample Runtime tutorial][sample-runtime] on Github.

<!--
TODO:

* (Add an extra step to Sample Runtime - just start the process, don't start the ANSI-C components).
* Answer questions from Jan-Willem about the block diagram - draw on earlier chapters.
-->

[comparison]: https://www.plcnext.help/te/PLCnext_Runtime/Function_extensions_for_internal_processes.htm
[codesys]: https://www.plcnextstore.com/#/220
[four-zero]: https://www.plcnextstore.com/#/168
[4diac]: https://www.eclipse.org/4diac/en_rte.php
[sample-runtime]: https://github.com/PLCnext/SampleRuntime
