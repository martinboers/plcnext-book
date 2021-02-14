## Appendix B: List of RSC Services

The following table lists the RSC services that are available in the PLCnext runtime, including links to more information, API documentation and programming examples.

| Service | Methods | More<br/>Information |
|:--------|:------|:--------|
| Device control | Restart Device<br/>Start Firmware Update<br/>Reset to Factory Defaults | [🔍][device-control-api] [📄][device-control-info] |
| Device information | Get Item<br/>Get Items | [🔍][device-info-api] [📄][device-info-info] |
| Device settings | Read Value<br/>Read Values<br/>Write Value<br/>Write Values | [🔍][device-settings-api] [📄][device-settings-info] |
| Device status | Get Item<br/>Get Items | [🔍][device-status-api] [📄][device-status-info] |
| PLC information | Get Info<br/>Get Infos | [🔍][plc-info-api] |
| PLC manager (deprecated) | Load<br/>Start<br/>Stop<br/>Reset<br/>Get PLC State | [🔍][plc-mngr-api] |
| PLC manager | Load<br/>Start<br/>Stop<br/>Reset<br/>Get PLC State<br/>Change<br/>Restart | [🔍][plc-mngr2-api] [📄][plc-mngr2-info] |
| Global Data Space<br/>variable access | Read Single<br/>Read<br/>Write Single<br/>Write | [🔍][gds-access-api] [📄][gds-access-info] [🖥][gds-access-ex] |
| Global Data Space<br/>variable force control | Add Variable<br/>Remove Variable<br/>Get Variables<br/>Reset<br/>Is Forcable (_sic_)<br/>Is Active | [🔍][gds-force-api] [🖥][gds-force-ex] |
| Global Data Space<br/>variable subscription | Create Subscription<br/>Create Recording Subscription<br/>Add Variable<br/>Add Variables<br/>Remove Variable<br/>Subscribe<br/>Resubscribe<br/>Unsubscribe<br/>Delete Subscription<br/>Get Variable Infos<br/>Get Time Stamped Variable Infos<br/>Get Record Infos<br/>Read Values<br/>Read Time Stamped Values<br/>Read Records | [🔍][gds-subs-api] [📄][gds-subs-info] [🖥][gds-subs-ex] |
| Retentive variable management | Generate Backup File <br/>Prepare Latest Backup File For Restoring | [🔍][gds-retain-api] [📄][gds-retain-info] |
| Enumerate GDS variables | Find Instances By Typename | [🔍][gds-traverse-api] |
| Acyclic Axioline communication | PDI Read <br/>PDI Write | [🔍][ax-acyclic-comms-api] [📄][ax-acyclic-comms-info] |
| Axioline master access | Axio Control<br/>Create Configuration<br/>Read Configuration<br/>Write Configuration<br/>Activate Configuration<br/>Deactivate Configuration<br/>Reset Master | [🔍][ax-master-api] [🖥][ax-master-ex] |
| Interbus master access | Interbus Control<br/>Create Configuration<br/>Read Configuration<br/>Write Configuration<br/>Activate Configuration<br/>Deactivate Configuration<br/>Start Data Transfer<br/>Stop Data Transfer<br/>Alarm Stop | [🔍][interbus-master-api] [🖥][interbus-master-ex] |
| PCP device communication | PCP Initiate<br/>PCP Abort<br/>PCP Identify<br/>PCP Status<br/>PCP Read<br/>PCP Write | [🔍][pcp-api] |
| Acyclic Profinet communication | Record Read<br/>Record Write | [🔍][pn-acyclic-comms-api] [📄][pn-acyclic-comms-info] |
| Conversion of Profinet<br/>addresses and node IDs | Address To ID<br/>ID To Address | [🔍][pn-addr-api] |
| Profinet alarm receiver | Receive Alarm<br/>Enable Auto Alarm Acknowledge | [🔍][pn-alarm-api] |
| Profinet Application Relationships<br/>(AR) info | Get All AR Info<br/>Get All AR Attribute Names<br/>Get Attribute Value<br/>Get Attribute Values<br/>Get AR Diagnosis | [🔍][pn-ar-data-api] |
| Profinet Application Relationships<br/>(AR) manager | Get AR State<br/>Start AR<br/>Stop AR | [🔍][pn-ar-mngmnt-api] |
| Profinet Application Relationships<br/>(AR) statistics | Read<br/>Read Changes<br/>Read Missed Frames Global<br/>Reset | [🔍][pn-ar-stats-api] |
| Profinet system configuration | Read<br/>Write<br/>Get Controller Name<br/>Get Device Names | [🔍][pn-config-api] |
| File System Information  | Get Supported Traits<br/>Get Permissions<br/>Add Permissions<br/>Remove Permissions<br/>Get File System Traits Entry<br/>Get Space Info<br/>Get Root Directories<br/> | [🔍][file-info-api] |
| Directory Operations  | Exists<br/>Create<br/>Delete<br/>Clear<br/>Move<br/>Copy<br/>Enumerate File System Entries<br/>Enumerate File System Traits Entries | [🔍][directory-api] |
| File Operations | Exists<br/>Write<br/>Read<br/>Delete<br/>Move<br/>Copy | [🔍][file-api] |
| Device Identity Validator  | Validate | [🔍][device-id-api] |
| License Status  | Get License Status | [🔍][license-api] |
| Notification Manager  | Register Notification<br/>Unregister Notification<br/>Send Notification<br/>Get Notification Name<br/>Get Notification Name ID<br/>Get Notification Name IDs By Status<br/>Get All Known Notification Name IDs<br/>Get Notification Registration<br/>Get Payload Type ID<br/>Get Payload Type Name<br/>Get Number Of Submitted Notifications | [🔍][nm-api] [📄][nm-info] [🖥][nm-ex] |
| Notification logger | Query Stored Notifications<br/>Query Notifications<br/>Delete Notifications<br/>List Archives<br/>Get Archive Configuration<br/>Set Archive Configuration<br/>Reset Archive Configuration To Files | [🔍][nl-api] [📄][nl-info] [🖥][nl-ex] |
| Data Logger | List Session Names<br/>Create Session<br/>Remove Session<br/>Start Session<br/>Stop Session<br/>Configure Session<br/>Get Session Configuration<br/>Get Session State<br/>Set Variables<br/>Get Logged Variables<br/>Read Variables Data<br/>Get Rotated File Names<br/>Get Session Names<br/>Set Trigger Condition | [🔍][dl-api] [📄][dl-info] [🖥][dl-ex] |
| LTTng trace controller | Is Session Daemon Alive<br/>Load Session Configuration<br/>List Sessions<br/>Start Session<br/>Stop Session<br/>Destroy Session<br/>Load Tracepoint Lib<br/>Unload Tracepoint Lib<br/>Trigger Saving Trace Outputs<br/>Is Session In Snapshot Mode<br/>Is Session Enabled<br/>Is Session Loaded | [🔍][trace-api] |
| Network load limiter control | Get Settings<br/>Set Settings<br/>Set Byte Limit<br/>Set Packet Limit<br/>Enable Byte Limiter<br/>Disable Byte Limiter<br/>Enable Packet Limiter<br/>Disable Packet Limiter<br/>Get State | [🔍][netload-limiter-api] |

[device-control-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Device_1_1Interface_1_1Services_1_1IDeviceControlService.html "API description"

[device-control-info]: https://www.plcnext.help/te/Service_Components/Remote_Service_Calls_RSC/RSC_device_interface_services.htm#IDeviceControlService "PLCnext Info Center"

[device-info-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Device_1_1Interface_1_1Services_1_1IDeviceInfoService.html "API description"

[device-info-info]: https://www.plcnext.help/te/Service_Components/Remote_Service_Calls_RSC/RSC_device_interface_services.htm#IDeviceInfoService "PLCnext Info Center"

[device-settings-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Device_1_1Interface_1_1Services_1_1IDeviceSettingsService.html "API description"

[device-settings-info]: https://www.plcnext.help/te/Service_Components/Remote_Service_Calls_RSC/RSC_device_interface_services.htm#IDeviceSettingsService "PLCnext Info Center"

[device-status-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Device_1_1Interface_1_1Services_1_1IDeviceStatusService.html "API description"

[device-status-info]: https://www.plcnext.help/te/Service_Components/Remote_Service_Calls_RSC/RSC_device_interface_services.htm#IDeviceStatusService "PLCnext Info Center"

[plc-info-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Plc_1_1Domain_1_1Services_1_1IPlcInfoService.html "API description"

[plc-mngr-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Plc_1_1Domain_1_1Services_1_1IPlcManagerService.html "API description"

[plc-mngr2-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Plc_1_1Domain_1_1Services_1_1IPlcManagerService2.html "API description"

[plc-mngr2-info]: https://www.plcnext.help/te/PLCnext_Runtime/System_manager.htm#PLCManager "PLCnext Info Center"

[gds-access-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Plc_1_1Gds_1_1Services_1_1IDataAccessService.html "API description"

[gds-access-info]: https://www.plcnext.help/te/Service_Components/Remote_Service_Calls_RSC/RSC_GDS_services.htm#IDataAccessService "PLCnext Info Center"

[gds-access-ex]: https://github.com/PLCnext/CppExamples/blob/master/Examples/DataAccessExample/README.MD "Programming example"

[gds-force-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Plc_1_1Gds_1_1Services_1_1IForceService.html "API description"

[gds-force-ex]: https://github.com/PLCnext/CppExamples/blob/master/Examples/ForceExample/README.MD "Programming example"

[gds-subs-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Plc_1_1Gds_1_1Services_1_1ISubscriptionService.html "API description"

[gds-subs-info]: https://www.plcnext.help/te/Service_Components/Remote_Service_Calls_RSC/RSC_GDS_services.htm#ISubscriptionService "PLCnext Info Center"

[gds-subs-ex]: https://github.com/PLCnext/CppExamples/blob/master/Examples/SubscriptionExample/README.MD "Programming example"

[gds-retain-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Plc_1_1Retain_1_1Services_1_1IRetainManagerService.html "API description"

[gds-retain-info]: https://www.plcnext.help/te/PLCnext_Runtime/Extended_retain_handling.htm "PLCnext Info Center"

[gds-traverse-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Plc_1_1Meta_1_1Services_1_1IDataTraverserService.html "API description"

[ax-acyclic-comms-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Io_1_1Axioline_1_1Services_1_1IAcyclicCommunicationService.html "API description"

[ax-acyclic-comms-info]: https://www.plcnext.help/te/Service_Components/Remote_Service_Calls_RSC/RSC_Axioline_Services.htm#IAcyclicCommunicationService "PLCnext Info Center"

[ax-master-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Io_1_1Axioline_1_1Services_1_1IAxioMasterService.html "API description"

[ax-master-ex]: https://github.com/PLCnext/BusConductor "Programming example"

[interbus-master-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Io_1_1Interbus_1_1Services_1_1IInterbusMasterService.html "API description"

[interbus-master-ex]: https://github.com/PLCnext/BusConductor "Programming example"

[pcp-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Io_1_1Interbus_1_1Services_1_1IPcpService.html "API description"

[pn-acyclic-comms-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Io_1_1ProfinetStack_1_1Controller_1_1Services_1_1IAcyclicCommunicationService.html "API description"

[pn-acyclic-comms-info]: https://www.plcnext.help/te/Service_Components/Remote_Service_Calls_RSC/RSC_PROFINET_Services.htm "PLCnext Info Center"

[pn-addr-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Io_1_1ProfinetStack_1_1Controller_1_1Services_1_1IAddressConversionService.html "API description"

[pn-alarm-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Io_1_1ProfinetStack_1_1Controller_1_1Services_1_1IAlarmService.html "API description"

[pn-ar-data-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Io_1_1ProfinetStack_1_1Controller_1_1Services_1_1IArDataService.html "API description"

[pn-ar-mngmnt-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Io_1_1ProfinetStack_1_1Controller_1_1Services_1_1IArManagementService.html "API description"

[pn-ar-stats-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Io_1_1ProfinetStack_1_1Controller_1_1Services_1_1IArStatisticService.html "API description"

[pn-config-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Io_1_1ProfinetStack_1_1System_1_1Services_1_1IConfigurationService.html "API description"

[file-info-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1System_1_1Commons_1_1Services_1_1Io_1_1IFileSystemInfoService.html "API description"

[directory-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1System_1_1Commons_1_1Services_1_1Io_1_1IDirectoryService.html "API description"

[file-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1System_1_1Commons_1_1Services_1_1Io_1_1IFileService.html "API description"

[device-id-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1System_1_1Commons_1_1Services_1_1Security_1_1IDeviceIdentityValidatorService.html "API description"

[license-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1System_1_1Lm_1_1Services_1_1ILicenseStatusService.html "API description"

[nm-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1System_1_1Nm_1_1Services_1_1INotificationManagerService.html "API description"

[nm-info]: https://www.plcnext.help/te/Service_Components/Notifications/Notifications_with_Cpp.htm "PLCnext Info Center"

[nm-ex]: https://github.com/PLCnext/CppExamples/blob/master/Examples/NotificationExample/README.MD "Programming example"

[nl-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Services_1_1NotificationLogger_1_1Services_1_1INotificationLoggerService.html "API description"

[nl-info]: https://www.plcnext.help/te/Service_Components/Remote_Service_Calls_RSC/Querying_notifications_via_RSC.htm "PLCnext Info Center"

[nl-ex]: https://github.com/PLCnext/CppExamples/blob/master/Examples/NotificationExample/README.MD "Programming example"

[dl-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Services_1_1DataLogger_1_1Services_1_1IDataLoggerService2.html "API description"

[dl-info]: https://www.plcnext.help/te/Service_Components/Remote_Service_Calls_RSC/RSC_IDataLoggerService2.htm "PLCnext Info Center"

[dl-ex]: https://github.com/PLCnext/PLCnext_RT_Datalogger "Programming example"

[trace-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Services_1_1TraceController_1_1Services_1_1ITraceControllerService.html "API description"

[netload-limiter-api]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Hardware_1_1Nim_1_1Services_1_1INetloadLimiterService.html "API description"
