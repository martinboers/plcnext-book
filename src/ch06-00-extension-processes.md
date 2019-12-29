# Extension Processes

You have seen how to use the Application Component Framework to extend the PLCnext runtime with your own components and programs. By using the ACF, these components are integrated tightly with the PLCnext runtime, where they are treated in exactly the same way as factory-installed components.

It is also possible to extend the PLCnext runtime with *Extension Processes* (also called *External Function Extensions*).

Extension processes are useful for PLCnext Control functions that must be started and stopped with the PLCnext runtime - just like extension components - but that cannot use the ACF. A typical example: When porting a third-party PLC runtime to the PLCnext Control platform, it may be impractical to re-structure the source code into PLCnext runtime components. This is precisely the situation with Codesys, Four-Zero and 4diac.

Extension processes also provide the ultimate answer to the question posed earlier in this book: *How can a program read and write inputs and outputs from/to the I/O modules attached to the PLC?*

You have already seen how to read and write GDS variable data using RSC services and the REST API, and these interfaces can be used to access PLC I/O from any process running outside the PLCnext runtime. However, I/O data exchange using these methods is only suitable for non-deterministic applications. PLCnext runtime processes provide the *only* way to read and write PLC I/O in a deterministic way from outside the PLCnext runtime.

Add an extra step - just start the process, don't start the ANSI-C components.


- Answer questions from Jan-Willem about the block diagram - draw on earlier chapters.
