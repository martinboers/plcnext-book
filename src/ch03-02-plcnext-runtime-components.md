## PLCnext Runtime Components

Factory-installed software components that make up the PLCnext runtime include:

* Hardware components
* I/O and Fieldbus components
* System components
* PLC components
* Service components

An overview of these component categories is given in the [PLCnext Technology Info Center][comp-info]. The categories are somewhat arbitrary, but during startup all the components in one category are generally started before any components in the next category, and vice-versa during shutdown.

Components are defined in C++ shared object libraries, which are located in the `/usr/lib` directory on the PLC. The tables below list these shared object libraries, the components they define, and links to more information on the function that each component implements.

### Hardware Components

These components provide access to device hardware. They typically wrap Linux device drivers, making these devices available to other PLCnext runtime components via internal RSC services.

* Library filename prefix: `libArp.Hardware.`
* Component namespace: `Arp::Hardware`

| Library filename      | Component type name                                | Service description |
|:----------------------|:---------------------------------------------------|:--------------------|
| IdentificationData.so | IdentificationData::IdentificationDataComponent    | Device ID data |
| FanControl.so         | FanControl::FanControlComponent                    | Fan control operations |
| Fpga.so               | Fpga::FpgaComponent                                | FPGA information |
| OsControl.so          | OsControl::OsControlComponent                      | Operating system operations |
| RealTimeClock.so      | RealTimeClock::RealTimeClockComponent              | Real time clock operations |
| ResourceMonitor.so    | ResourceMonitor::ResourceMonitorComponent          | CPU, memory and partition monitoring |
| DeviceHmi.so          | DeviceHmi::DeviceHmiComponent                      | Device LEDs, buttons and switches |
| Sensors.so            | Sensors::SensorsComponent                          | Device temperature, humidity and power monitoring |
| Nim.so                | Nim::NimComponent<br/>Nim::NetloadLimiterComponent | Ethernet information, IP configuration and IP status<br/>[Network load limiter][load-limiter-info] (public)] |
| ExternalSDCard.so     | ExternalSDCard::ExternalSDCardComponent            | Information on the external SD card license, status and settings |
| ExternalPci.so        | ExternalPci::ExternalPciComponent                  | External PCI state information | ARP_COMPONENT_EXTERNAL_PCI |

### Device Components

These components provide device-specific abstractions for some low-level hardware services.

* Library filename prefix: `libArp.Device.`
* Component namespace: `Arp::Device`

| Library filename | Component type name     | Service description |
|:-----------------|:------------------------|:--------------------|
| HmiLed.so        | HmiLed::HmiLedComponent | LED management (internal) |
| Interface.so     | Interface::DiComponent  | [Device control][device-control-info] (public)<br/>[Device information][device-info-info] (public)<br/>[Device settings][device-settings-info] (public)<br/>[Device status][device-status-info] (public) |

### I/O Components

These components provide access to physical I/O modules through a variety of standard industrial networks.

* Library filename prefix: `libArp.Io.`
* Component namespace: `Arp::Io`

| Library filename | Component type name             | Function                       | Condition |
|:-----------------|:--------------------------------|:-------------------------------|:----------|
| Axioline.so      | Axioline::AxiolineComponent     | Axioline master<sup>1</sup>    | ARP_COMPONENT_AXIOLINE |
| Interbus.so      | Interbus::InterbusComponent     | Interbus master<sup>1</sup>    | ARP_COMPONENT_INTERBUS |
| EthernetIP.so    | EthernetIP::EthernetIPComponent | Ethernet/IP device<sup>1</sup> | ARP_COMPONENT_ETHERNETIP |
| ProfinetStack.so | ProfinetStack::System::SystemComponent<br/>ProfinetStack::Controller::ControllerComponent<br/>ProfinetStack::Device::DeviceComponent | Profinet system<br/>Profinet controller<br/>Profinet device | ARP_COMPONENT_PROFINET or ARP_COMPONENT_PNC or ARP_COMPONENT_PND |

<sup>1</sup> Only available on AXC devices.

### System Components

These components implement low-level PLCnext runtime features. They may provide an API, but are not generally designed to be configurable by end users.

* Library filename prefix: `libArp.System.`
* Component namespace: `Arp::System`

| Library filename     | Component type name               | Function           |
|:---------------------|:----------------------------------|:-------------------|
| Commons.Services.so  | Commons::Services::Component      | [File system info][file-sys-info] (public)<br/>[Directory service][dir-info] (public)<br/>[File service][file-info] (public)<br/>[Device ID validator][device-id-info] (public)<br/>Trust store management (internal)<br/>Identity store management (internal)  |
| Security.Services.so | Security::Services::Component     | System security |
| Watchdog.so          | Watchdog::SystemWatchdogComponent | System watchdog configuration and monitoring |
| RscGateway.so        | RscGateway::RscGatewayComponent   | [Remote service call gateway][rsc-info] |
| Um.so                | Um::UmComponent                   | [User manager][um-info] |

### PLC Components

These components implement features you would expect to find on PLCs.

Library filename prefix: `libArp.Plc.`
Component namespace: `Arp::Plc`

| Library filename | Component type name | Function |
|:-----------------|:--------------------|:---------|
| Domain.so        | Domain::PlcDomainProxyComponent<br/>Domain::PlcManagerComponent<br/>Domain::PlcDomainComponent | Related to I/O<br/>?<br/>? |
| Meta.so          | Meta::MetaDomainComponent<br/>Meta::MetaComponent<br/>Meta::MetaControllerComponent | GDS traverser (public)<br/>GDS browser (internal) |
| Eclr.so          | Eclr::EclrComponent<br/>Eclr::EclrServicesComponent<br/>Eclr::ArpDomainComponent | [Embedded Common Language Runtime][eclr-info] |
| Plm.so           | Plm::PlmComponent | [Manages real-time C++ programs][plm-info] |
| Esm.so           | Esm::EsmComponent<br/>Esm::EsmControllerComponent | [Execution and Synchronisation Manager][esm-info] |
| Gds.so           | Gds::GdsComponent | [Manages the global data space][gds-info] |
| Retain.so        | Retain::RetainComponent | Manages retentive variables |
| Fbm.so           | Fbm::FbmComponent<br/>Fbm::FbIoComponent | Fieldbus manager |

### Service Components

These components generally provide high-level, non real time features that are easily configurable by end users.

Library filename prefix: `libArp.Services.`
Component namespace: `Arp::Services`

| Library filename      | Component type name                                          | Function |
|:----------------------|:-------------------------------------------------------------|:---------|
| Alarms.so             | Alarms::AlarmsComponent                                      | [Alarm dispatcher][alarms-info] |
| Fwm.so                | Fwm::FwmComponent                                            | [Firewall manager][fwm-info] |
| Wbm.so                | Wbm::WbmComponent                                            | [Web-based management][wbm-info] |
| Ehmi.so               | Ehmi::EhmiComponent                                          | [Embedded HMI][ehmi-info] |
| OpcUAServer.so        | OpcUAServer::OpcUAServerComponent                            | [OPC UA server][opc-info] |
| ProfiCloud.so         | ProfiCloud::ProfiCloudComponent                              | [Proficloud TSD publisher][tsd-info] (deprecated) |
| NotificationLogger.so | NotificationLogger::NotificationLoggerComponent              | [Notification logger][nl-info] |
| TraceController.so    | TraceController::TraceControllerComponent                    | [LTTng trace controller][trace-info] |
| NmUtilities.so        | NmUtilities::NmPlcStateListener::NmPlcStateListenerComponent | [Notification manager][nm-info] |
| DataLogger.so         | DataLogger::DataLoggerComponent                              | [Data logger][dl-info] |
| AppManager.so         | AppManager::AppManagerComponent                              | [PLCnext Store app management][app-info] |
| Fwu.so                | Fwu::FwuComponent                                            | Firmware update |
| LinuxSyslog.so        | LinuxSyslog::LinuxSyslogComponent                            | syslog-ng interface |
| ProfiCloudV3.so       | ProfiCloudV3::ProfiCloudV3Component                          | [Proficloud][proficloud-info] |
| Wcm.so                | Wcm::WcmComponent                                            | Web configuration management |
| Logging.so            | Logging::LoggingComponent<br/>Logging::LogManagerComponent<br/>Logging::LogProviderComponent | General event logger |
| SpnsProxy.so          | SpnsProxy::SpnsProxyComponent                                | Safety controller (SPNS) communications |

[comp-info]: https://www.plcnext.help/te/PLCnext_Runtime/Core_component.htm
[load-limiter-info]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Hardware_1_1Nim_1_1Services_1_1INetloadLimiterService.html "API description"
[device-control-info]: https://www.plcnext.help/te/Service_Components/Remote_Service_Calls_RSC/RSC_device_interface_services.htm#IDeviceControlService "PLCnext Info Center"
[device-info-info]: https://www.plcnext.help/te/Service_Components/Remote_Service_Calls_RSC/RSC_device_interface_services.htm#IDeviceInfoService "PLCnext Info Center"
[device-settings-info]: https://www.plcnext.help/te/Service_Components/Remote_Service_Calls_RSC/RSC_device_interface_services.htm#IDeviceSettingsService "PLCnext Info Center"
[device-status-info]: https://www.plcnext.help/te/Service_Components/Remote_Service_Calls_RSC/RSC_device_interface_services.htm#IDeviceStatusService "PLCnext Info Center"
[file-sys-info]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1System_1_1Commons_1_1Services_1_1Io_1_1IFileSystemInfoService.html "API description"
[dir-info]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1System_1_1Commons_1_1Services_1_1Io_1_1IDirectoryService.html "API description"
[file-info]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1System_1_1Commons_1_1Services_1_1Io_1_1IFileService.html "API description"
[device-id-info]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1System_1_1Commons_1_1Services_1_1Security_1_1IDeviceIdentityValidatorService.html "API description"
[rsc-info]: https://www.plcnext.help/te/Service_Components/Remote_Service_Calls_RSC/RSC_Remote_Service_Calls.htm "PLCnext Info Center"
[um-info]: https://www.plcnext.help/te/WBM/Security_User_authentication.htm "PLCnext Info Center"
[eclr-info]: https://www.plcnext.help/te/Programming/Csharp/eCLR_Programming_System.htm "PLCnext Info Center"
[plm-info]: https://www.plcnext.help/te/Programming/Cpp/Cpp_program_structure/PLM_Program_Library_Manager.htm "PLCnext Info Center"
[esm-info]: https://www.plcnext.help/te/PLCnext_Runtime/ESM.htm "PLCnext Info Center"
[gds-info]: https://www.plcnext.help/te/PLCnext_Runtime/GDS_Global_Data_Space.htm "PLCnext Info Center"
[alarms-info]: https://www.plcnext.help/te/Service_Components/Alarms/Alarms.htm "PLCnext Info Center"
[fwm-info]: https://www.plcnext.help/te/WBM/Security_Firewall.htm "PLCnext Info Center"
[wbm-info]: https://www.plcnext.help/te/WBM/WBM.htm "PLCnext Info Center"
[ehmi-info]: https://www.plcnext.help/te/Programming/IEC_61131-3/Creating_a_PLCnext_Engineer_HMI_application.htm "PLCnext Info Center"
[opc-info]: https://www.plcnext.help/te/Service_Components/OPC_UA_Server/OPC_UA_server_eUA.htm "PLCnext Info Center"
[tsd-info]: https://www.plcnext.help/te/Service_Components/PROFICLOUD/Transferring_values_to_PROFICLOUD.htm "PLCnext Info Center"
[nl-info]: https://www.plcnext.help/te/Service_Components/Notifications/Notification_Logger.htm "PLCnext Info Center"
[trace-info]: https://lttng.org/  "LTTng"
[nm-info]: https://www.plcnext.help/te/Service_Components/Notifications/Notification_manager.htm "PLCnext Info Center"
[dl-info]: https://www.plcnext.help/te/Service_Components/DataLogger/DataLogger.htm "PLCnext Info Center"
[app-info]: https://www.plcnext.help/te/WBM/Administration_PLCnext_Apps.htm "PLCnext Info Center"
[proficloud-info]: https://www.plcnext.help/te/Service_Components/PROFICLOUD/Proficloud_V3_Introduction.htm "PLCnext Info Center"
