## Appendix B: List of RSC Services

The following table lists the RSC services that are available in the PLCnext runtime, including links to more information, API documentation and programming examples:

| Service | Methods | More<br/>Information |
|:--------|:------|:--------|
| Device control | Restart Device<br/>Start Firmware Update<br/>Reset to Factory Defaults | [🔍][device-control-api] |
| Device information | Get Item<br/>Get Items | [🔍][device-info-api] [📄][device-info-info] |
| Device settings | Read Value<br/>Read Values<br/>Write Value<br/>Write Values | [🔍][device-settings-api]  |
| Device status | Get Item<br/>Get Items | [🔍][device-status-api] [📄][device-status-info] |
| Acyclic Axioline communication | PDI Read <br/>PDI Write | [🔍][ax-acyclic-comms-api] [📄][ax-acyclic-comms-info] |
| Axioline master access | Axio Control<br/>Create Configuration<br/>Read Configuration<br/>Write Configuration<br/>Activate Configuration<br/>Deactivate Configuration<br/>Reset Master | [🔍][ax-master-api] [🖥][ax-master-ex] |
| Interbus master access | Interbus Control<br/>Create Configuration<br/>Read Configuration<br/>Write Configuration<br/>Activate Configuration<br/>Deactivate Configuration<br/>Start Data Transfer<br/>Stop Data Transfer<br/>Alarm Stop | [🔍][interbus-master-api] [🖥][interbus-master-ex] |
| PCP device communication | PCP Initiate<br/>PCP Abort<br/>PCP Identify<br/>PCP Status<br/>PCP Read<br/>PCP Write | [🔍][pcp-api] |
| Acyclic Profinet communication | Record Read<br/>Record Write | [🔍][pn-acyclic-comms-api] [📄][pn-acyclic-comms-info] |
| Conversion of Profinet addresses and node IDs | Address To ID<br/>ID To Address | [🔍][pn-addr-api] |
| Profinet alarm receiver | Receive Alarm<br/>Enable Auto Alarm Acknowledge | [🔍][pn-alarm-api] |
| Profinet Application Relationships (AR) info | Get All AR Info<br/>Get All AR Attribute Names<br/>Get Attribute Value<br/>Get Attribute Values<br/>Get AR Diagnosis | [🔍][pn-ar-data-api] |
| Profinet Application Relationships (AR) manager | Get AR State<br/>Start AR<br/>Stop AR | [🔍][pn-ar-mngmnt-api] |
| Profinet Application Relationships (AR) statistics | Read<br/>Read Changes<br/>Read Missed Frames Global<br/>Reset | [🔍][pn-ar-stats-api] |
| Profinet system configuration | Read<br/>Write<br/>Get Controller Name<br/>Get Device Names | [🔍][pn-config-api] |

| PLC information | Get Info<br/>Get Infos | [🔍][plc-info-api] |

| PLC manager (deprecated) | Load<br/>Start<br/>Stop<br/>Reset<br/>Get PLC State | [🔍][plc-mngr-api] |
| PLC manager | Load<br/>Start<br/>Stop<br/>Reset<br/>Get PLC State<br/>Change<br/>Restart | [🔍][plc-mngr2-api] |
| Global Data Space variable access | Read Single<br/>Read<br/>Write Single<br/>Write | [🔍][gds-access-api] [📄][gds-access-info] |
| Global Data Space variable force control | Add Variable<br/>Remove Variable<br/>Get Variables<br/>Reset<br/>Is Forcable (_sic_)<br/>Is Active | [🔍][gds-force-api] |
| [Global Data Space variable subscription][gds-subs-info] | [ISubscriptionService][gds-subs-api] | CreateSubscription()<br/>CreateRecordingSubscription()<br/>AddVariable()<br/>AddVariables()<br/>RemoveVariable()<br/>Subscribe()<br/>Resubscribe()<br/>Unsubscribe()<br/>DeleteSubscription()<br/>GetVariableInfos()<br/>GetTimeStampedVariableInfos()<br/>GetRecordInfos()<br/>ReadValues()<br/>ReadTimeStampedValues()<br/>ReadRecords() |
| Enumerate GDS variables | [IDataTraverserService][gds-traverse-api] | FindInstancesByTypename() |

| Retentive variable management | [IRetainManagerService][gds-traverse-api] | FindInstancesByTypename() |

| Directory  | [IDirectoryService][directory-api] | IsSessionDaemonAlive()<br/>LoadSessionConfiguration()<br/>ListSessions()<br/>StartSession()<br/>StopSession()<br/>DestroySession()<br/>LoadTracepointLib()<br/>UnloadTracepointLib()<br/>TriggerSavingTraceOutputs()<br/>IsSessionInSnapshotMode()<br/>IsSessionEnabled()<br/>IsSessionLoaded() |
| File  | [IFileService][directory-api] | |
| File System Information  | [IFileSystemInfoService][directory-api] | |
| Device Identity  | [IDeviceIdentityValidatorService][directory-api] | |
| App License Status  | [ILicenseStatusService][directory-api] | |
| Notification Manager  | [ILicenseStatusService][directory-api] | |

| [Notification logger][notifications-info] | [INotificationLoggerService][notifications-api] | QueryStoredNotifications()<br/>QueryNotifications()<br/>DeleteNotifications()<br/>ListArchives()<br/>GetArchiveConfiguration()<br/>SetArchiveConfiguration()<br/>ResetArchiveConfigurationToFiles() |

| Data Logger | [IDataLoggerService2][directory-api] | |

| LTTng trace controller | [ITraceControllerService][trace-api] | IsSessionDaemonAlive()<br/>LoadSessionConfiguration()<br/>ListSessions()<br/>StartSession()<br/>StopSession()<br/>DestroySession()<br/>LoadTracepointLib()<br/>UnloadTracepointLib()<br/>TriggerSavingTraceOutputs()<br/>IsSessionInSnapshotMode()<br/>IsSessionEnabled()<br/>IsSessionLoaded() |
| Network load limiter control | [INetloadLimiterService][netload-limiter-api] | GetSettings()<br/>SetSettings()<br/>SetByteLimit()<br/>SetPacketLimit()<br/>EnableByteLimiter()<br/>DisableByteLimiter()<br/>EnablePacketLimiter()<br/>DisablePacketLimiter()<br/>GetState() |


[device-control-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Device_1_1Interface_1_1Services_1_1IDeviceControlService.html "API description"

[device-info-info]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/Service_Components/Remote_Service_Calls_RSC/RSC_device_interface_services.htm#ideviceinfoserv

[device-info-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Device_1_1Interface_1_1Services_1_1IDeviceInfoService.html "API description"

[device-settings-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Device_1_1Interface_1_1Services_1_1IDeviceSettingsService.html "API description"

[device-status-info]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/Service_Components/Remote_Service_Calls_RSC/RSC_device_interface_services.htm#idevicestatusse

[device-status-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Device_1_1Interface_1_1Services_1_1IDeviceStatusService.html "API description"

[device-status-api]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_API_Documentation/html/classArp_1_1Device_1_1Interface_1_1Services_1_1IDeviceStatusService.html "API description"

[netload-limiter-api]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_API_Documentation/html/classArp_1_1Hardware_1_1Nim_1_1Services_1_1INetloadLimiterService.html "API description"

[ax-acyclic-comms-info]: https://www.plcnext.help/te/Service_Components/Remote_Service_Calls_RSC/RSC_Axioline_Services.htm#IAcyclicCommunicationService

[ax-acyclic-comms-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Io_1_1Axioline_1_1Services_1_1IAcyclicCommunicationService.html "API description"

[ax-master-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Io_1_1Axioline_1_1Services_1_1IAxioMasterService.html "API description"

[ax-master-ex]: https://github.com/PLCnext/BusConductor "Programming example"

[interbus-master-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Io_1_1Interbus_1_1Services_1_1IInterbusMasterService.html "API description"

[interbus-master-ex]: https://github.com/PLCnext/BusConductor "Programming example"

[pcp-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Io_1_1Interbus_1_1Services_1_1IPcpService.html "API description"

[pn-acyclic-comms-info]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/Service_Components/Remote_Service_Calls_RSC/RSC_PROFINET_Services.htm

[pn-acyclic-comms-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Io_1_1ProfinetStack_1_1Controller_1_1Services_1_1IAcyclicCommunicationService.html "API description"

[pn-addr-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Io_1_1ProfinetStack_1_1Controller_1_1Services_1_1IAddressConversionService.html "API description"

[pn-alarm-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Io_1_1ProfinetStack_1_1Controller_1_1Services_1_1IAlarmService.html "API description"

[pn-ar-data-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Io_1_1ProfinetStack_1_1Controller_1_1Services_1_1IArDataService.html "API description"

[pn-ar-mngmnt-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Io_1_1ProfinetStack_1_1Controller_1_1Services_1_1IArManagementService.html "API description"

[pn-ar-stats-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Io_1_1ProfinetStack_1_1Controller_1_1Services_1_1IArStatisticService.html "API description"

[pn-config-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Io_1_1ProfinetStack_1_1System_1_1Services_1_1IConfigurationService.html "API description"

[plc-info-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Plc_1_1Domain_1_1Services_1_1IPlcInfoService.html "API description"

[plc-mngr-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Plc_1_1Domain_1_1Services_1_1IPlcManagerService.html "API description"

[plc-mngr2-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Plc_1_1Domain_1_1Services_1_1IPlcManagerService2.html "API description"

[gds-access-info]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/Service_Components/Remote_Service_Calls_RSC/RSC_GDS_services.htm#idataaccessserv

[gds-access-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Plc_1_1Gds_1_1Services_1_1IDataAccessService.html "API description"

[gds-force-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Plc_1_1Gds_1_1Services_1_1IForceService.html "API description"

[gds-subs-info]: 

[gds-subs-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Plc_1_1Gds_1_1Services_1_1ISubscriptionService.html "API description"

[gds-traverse-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Plc_1_1Meta_1_1Services_1_1IDataTraverserService.html "API description"

[notifications-info]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/Service_Components/Remote_Service_Calls_RSC/Querying_notifications_via_RSC.htm

[notifications-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Services_1_1NotificationLogger_1_1Services_1_1INotificationLoggerService.html "API description"

[trace-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Services_1_1TraceController_1_1Services_1_1ITraceControllerService.html "API description"
