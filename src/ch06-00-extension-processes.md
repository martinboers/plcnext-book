# Extension Processes

You have seen how to use the Application Component Framework to extend the PLCnext runtime with your own components and programs. By using the ACF, these components are integrated tightly with the PLCnext runtime, where they are treated in exactly the same way as factory-installed components.

It is also possible to extend the PLCnext runtime with extension *processes* (also called *External Function Extensions*).

Extension processes are useful for PLCnext Control functions that must be started and stopped with the PLCnext runtime - just like extension components - but that cannot use the ACF. A typical example: When porting a third-party PLC runtime to the PLCnext Control platform, it may be impractical to re-design the source code into PLCnext runtime components.

Extension processes also provide the ultimate answer to the question posed earlier in this book: *How can an application read and write inputs and outputs from/to the I/O modules attached to the PLC?* You have already seen how to read and write GDS variable data using RSC services and the REST API, and these interfaces can be used to access PLC I/O from any process running outside the PLCnext runtime. However, I/O data exchange using these methods is only suitable for non-deterministic applications. The PLCnext runtime provides a mechanism for extension processes to read and write PLC I/O in a deterministic way. This deterministic access to PLC I/O makes extension processes ideally suited to third-party runtimes like [Codesys][codesys], [Four-Zero][four-zero] and [4diac][4diac].

A high-level comparison of extension components (internal function extensions) and extension processes (external function extensions) is given in the [PLCnext Technology Info Center][comparison].

TODO:

* (Add an extra step to Sample Runtime - just start the process, don't start the ANSI-C components).
* Answer questions from Jan-Willem about the block diagram - draw on earlier chapters.

[codesys]: https://www.plcnextstore.com/#/220
[four-zero]: https://www.plcnextstore.com/#/168
[4diac]: https://www.eclipse.org/4diac/en_rte.php
[comparison]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/PLCnext_Runtime/Function_extensions_for_internal_processes.htm