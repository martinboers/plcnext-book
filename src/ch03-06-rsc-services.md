## RSC Services

For PLCnext runtime features that are user configurable, configuration can usually be performed through either the web-based management interface, or modifying text files on the PLC.

Some PLCnext runtime features also provide an application programming interface (API) in the form of *Remote Service Calls*, or [RSC Services][rsc-info].

A list of the RSC services that are available in the PLCnext runtime is given in [Appendix B][appendix-b].

RSC services can be accessed at least in two ways:

* Using an SDK to link to the relevant C++ shared object libraries. This provides local access to RSC services running on the same device as the C++ client.
* Via [gRPC][grpc], either locally via a Unix Domain Socket or remotely using Transport Layer Security (TLS).

In the next chapter, you will:

* Write your own PLCnext runtime component.
* Call RSC services from that component.

[rsc-info]: https://plcnext.help/te/Communication_interfaces/Remote_Service_Calls_RSC/RSC_Remote_Service_Calls.htm
[appendix-b]: appendix-02-list-of-rsc-services.md
[grpc]: https://grpc.io/
