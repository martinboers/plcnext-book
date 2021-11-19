## RSC Services

For PLCnext runtime features that are user configurable, configuration can usually be performed through either the web-based management interface, or modifying text files on the PLC.

Some PLCnext runtime features also provide an application programming interface (API) in the form of *Remote Service Calls*, or [RSC Services][rsc-info].

A list of the RSC services that are available in the PLCnext runtime is given in [Appendix B][appendix-b].

RSC services can be accessed in two ways:

* Linking to the relevant C++ shared object libraries.
* (using TCP socket-based communication - like the Java library does)

In the next chapter, you will:

* Write your own PLCnext runtime component.
* Call RSC services from that component.

[rsc-info]: https://www.plcnext.help/te/Service_Components/Remote_Service_Calls_RSC/RSC_Remote_Service_Calls.htm
[appendix-b]: appendix-02-list-of-rsc-services.md
