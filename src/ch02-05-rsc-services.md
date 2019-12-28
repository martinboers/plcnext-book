## RSC Services

For PLCnext runtime features that are user configurable, configuration can usually be performed through either the web-based management interface, or modifying text files on the PLC.

Some PLCnext runtime features also provide an application programming interface (API) in the form of *Remote Service Calls*, or [RSC Services][rsc-services-info].

A list of the RSC services that are available in the PLCnext runtime is given in [Appendix A][appendix-a].

RSC services can be accessed in two ways:

* Linking to the relevant C++ shared object libraries.
* (using TCP socket-based communication - like the Java library does)

In the next chapter, you will:

* Write your own PLCnext runtime component.
* Call RSC services from that component.
* Write your own RSC service.

[appendix-a]: appendix-01-list-of-rsc-services.md

[rsc-services-info]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/Service_Components/Remote_Service_Calls_RSC/RSC_Remote_Service_Calls.htm
