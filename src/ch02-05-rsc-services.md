## RSC Services

For PLCnext runtime features that are user configurable, configuration can usually be performed through either the web-based management interface, or modifying text files on the PLC.

Some PLCnext runtime features also provide an application programming interface (API) in the form of *Remote Service Calls*, or [RSC Services][rsc-services-info].

Here is a list of the RSC services that are available in the PLCnext runtime, including links to the API documentation:

| Service (links to more information) | Class (links to API documentation) | Methods |
|:--------|:------|:--------|
| Device control | [Arp::Device::Interface::Services::IDeviceControlService][device-control-api] | RestartDevice()<br/>StartFirmwareUpdate()<br/>ResetToFactoryDefaults() |
| [Device information][device-info-info] | [Arp::Device::Interface::Services::IDeviceInfoService][device-info-api] | GetItem()<br/>GetItems() |
| Device settings | [Arp::Device::Interface::Services::IDeviceSettingsService][device-settings-api] | ReadValue()<br/>ReadValues()<br/>WriteValue()<br/>WriteValues() |
| [Device status][device-status-info] | [Arp::Device::Interface::Services::IDeviceStatusService][device-status-api] | GetItem()<br/>GetItems() |
| Network load limiter control | [Arp::Hardware::Nim::Services::INetloadLimiterService][netload-limiter-api] | GetSettings()<br/>SetSettings()<br/>SetByteLimit()<br/>SetPacketLimit()<br/>EnableByteLimiter()<br/>DisableByteLimiter()<br/>EnablePacketLimiter()<br/>DisablePacketLimiter()<br/>GetState() |
| [Acyclic Axioline communication][ax-acyclic-comms-info] | [Arp::Io::Axioline::Services::IAcyclicCommunicationService][ax-acyclic-comms-api] | PdiRead()<br/>PdiWrite()|
| Axioline master access | [Arp::Io::Axioline::Services::IAxioMasterService][ax-master-api] | AxioControl()<br/>CreateConfiguration()<br/>ReadConfiguration()<br/>WriteConfiguration()<br/>ActivateConfiguration()<br/>DeactivateConfiguration()<br/>ResetMaster() |
| Interbus master access | [Arp::Io::Interbus::Services::IInterbusMasterService][interbus-master-api] | InterbusControl()<br/>CreateConfiguration()<br/>ReadConfiguration()<br/>WriteConfiguration()<br/>ActivateConfiguration()<br/>DeactivateConfiguration()<br/>StartDataTransfer()<br/>StopDataTransfer()<br/>AlarmStop() |
| PCP device communication | [Arp::Io::Interbus::Services::IPcpService][pcp-api] | PcpInitiate()<br/>PcpAbort()<br/>PcpIdentify()<br/>PcpStatus()<br/>PcpRead()<br/>PcpWrite() |
| [Acyclic Profinet communication][pn-acyclic-comms-info] | [Arp::Io::ProfinetStack::Controller::Services::IAcyclicCommunicationService][pn-acyclic-comms-api] | RecordRead()<br/>RecordWrite() |
| Conversion of Profinet addresses and node IDs | [Arp::Io::ProfinetStack::Controller::Services::IAddressConversionService][pn-addr-api] | AddressToId()<br/>IdToAddress() |
| Profinet alarm receiver | [Arp::Io::ProfinetStack::Controller::Services::IAlarmService][pn-alarm-api] ||
| Profinet controller Application Relationships (AR) manager | [Arp::Io::ProfinetStack::Controller::Services::IArDataService][pn-ar-data-api] ||
| Profinet Application Relationships (AR) manager | [Arp::Io::ProfinetStack::Controller::Services::IArManagementService][pn-ar-mngmnt-api] ||
| Profinet Application Relationships (AR) statistics | [Arp::Io::ProfinetStack::Controller::Services::IArStatisticService][pn-ar-stats-api] ||
| Profinet system configuration | [Arp::Io::ProfinetStack::System::Services::IConfigurationService][pn-config-api] ||
| PLC manager (deprectated) | [Arp::Plc::Domain::Services::IPlcManagerService][plc-mngr-api] ||
| PLC manager | [Arp::Plc::Domain::Services::IPlcManagerService2][plc-mngr2-api] ||
| [Global Data Space variable access][gds-access-info] | [Arp::Plc::Gds::Services::IDataAccessService][gds-access-api] ||
| Global Data Space variable force control | [Arp::Plc::Gds::Services::IForceService][gds-force-api] ||
| [Global Data Space variable subscription][gds-subs-info] | [Arp::Plc::Gds::Services::ISubscriptionService][gds-subs-api] ||
| Enumerate GDS variables | [Arp::Plc::Meta::Services::IDataTraverserService][gds-traverse-api] ||
| [Notification logger][notifications-info] | [Arp::Services::NotificationLogger::Services::INotificationLoggerService][notifications-api] ||
| LTTng trace controller | [Arp::Services::TraceController::Services::ITraceControllerService][trace-api] ||




RSC services can be accessed in two ways:

* Linking to the relevant C++ shared object libraries.
* (using TCP socket-based communication - like the Java library does)

In the next chapter, we will:

* Write our own PLCnext runtime component that uses RSC services.
* Write our own RSC service.


[rsc-services-info]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/Service_Components/Remote_Service_Calls_RSC/RSC_Remote_Service_Calls.htm

[device-control-api]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_API_Documentation/html/classArp_1_1Device_1_1Interface_1_1Services_1_1IDeviceControlService.html

[device-info-info]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/Service_Components/Remote_Service_Calls_RSC/RSC_device_interface_services.htm#ideviceinfoserv

[device-info-api]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_API_Documentation/html/classArp_1_1Device_1_1Interface_1_1Services_1_1IDeviceInfoService.html

[device-settings-api]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_API_Documentation/html/classArp_1_1Device_1_1Interface_1_1Services_1_1IDeviceSettingsService.html

[device-status-info]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/Service_Components/Remote_Service_Calls_RSC/RSC_device_interface_services.htm#idevicestatusse

[device-status-api]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_API_Documentation/html/classArp_1_1Device_1_1Interface_1_1Services_1_1IDeviceStatusService.html

[device-status-api]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_API_Documentation/html/classArp_1_1Device_1_1Interface_1_1Services_1_1IDeviceStatusService.html

[netload-limiter-api]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_API_Documentation/html/classArp_1_1Hardware_1_1Nim_1_1Services_1_1INetloadLimiterService.html

[ax-acyclic-comms-info]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/Service_Components/Remote_Service_Calls_RSC/RSC_Axioline_Services.htm#iacycliccommuni

[ax-acyclic-comms-api]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_API_Documentation/html/classArp_1_1Io_1_1Axioline_1_1Services_1_1IAcyclicCommunicationService.html

[ax-master-api]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_API_Documentation/html/classArp_1_1Io_1_1Axioline_1_1Services_1_1IAxioMasterService.html

[interbus-master-api]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_API_Documentation/html/classArp_1_1Io_1_1Interbus_1_1Services_1_1IInterbusMasterService.html

[pcp-api]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_API_Documentation/html/classArp_1_1Io_1_1Interbus_1_1Services_1_1IPcpService.html

[pn-acyclic-comms-info]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/Service_Components/Remote_Service_Calls_RSC/RSC_PROFINET_Services.htm

[pn-acyclic-comms-api]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_API_Documentation/html/classArp_1_1Io_1_1ProfinetStack_1_1Controller_1_1Services_1_1IAcyclicCommunicationService.html

[pn-addr-api]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_API_Documentation/html/classArp_1_1Io_1_1ProfinetStack_1_1Controller_1_1Services_1_1IAddressConversionService.html

[pn-alarm-api]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_API_Documentation/html/classArp_1_1Io_1_1ProfinetStack_1_1Controller_1_1Services_1_1IAlarmService.html

[pn-ar-data-api]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_API_Documentation/html/classArp_1_1Io_1_1ProfinetStack_1_1Controller_1_1Services_1_1IArDataService.html

[pn-ar-mngmnt-api]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_API_Documentation/html/classArp_1_1Io_1_1ProfinetStack_1_1Controller_1_1Services_1_1IArManagementService.html

[pn-ar-stats-api]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_API_Documentation/html/classArp_1_1Io_1_1ProfinetStack_1_1Controller_1_1Services_1_1IArStatisticService.html

[pn-config-api]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_API_Documentation/html/classArp_1_1Io_1_1ProfinetStack_1_1System_1_1Services_1_1IConfigurationService.html

[plc-mngr-api]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_API_Documentation/html/classArp_1_1Plc_1_1Domain_1_1Services_1_1IPlcManagerService.html

[plc-mngr2-api]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_API_Documentation/html/classArp_1_1Plc_1_1Domain_1_1Services_1_1IPlcManagerService2.html

[gds-access-info]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/Service_Components/Remote_Service_Calls_RSC/RSC_GDS_services.htm#idataaccessserv

[gds-access-api]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_API_Documentation/html/classArp_1_1Plc_1_1Gds_1_1Services_1_1IDataAccessService.html

[gds-force-api]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_API_Documentation/html/classArp_1_1Plc_1_1Gds_1_1Services_1_1IForceService.html

[gds-subs-info]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/Service_Components/Remote_Service_Calls_RSC/RSC_GDS_services.htm#isubscriptionse

[gds-subs-api]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_API_Documentation/html/classArp_1_1Plc_1_1Gds_1_1Services_1_1ISubscriptionService.html

[gds-traverse-api]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_API_Documentation/html/classArp_1_1Plc_1_1Meta_1_1Services_1_1IDataTraverserService.html

[notifications-info]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/Service_Components/Remote_Service_Calls_RSC/Querying_notifications_via_RSC.htm

[notifications-api]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_API_Documentation/html/classArp_1_1Services_1_1NotificationLogger_1_1Services_1_1INotificationLoggerService.html

[trace-api]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_API_Documentation/html/classArp_1_1Services_1_1TraceController_1_1Services_1_1ITraceControllerService.html
