## PLCnext Runtime Components

PLCnext Control firmware was introduced briefly in the previous chapter. PLCnext Control firmware features can be broadly categorised as either:

1. Features commonly available on general-purpose Linux distributions, or
2. Features developed by Phoenix Contact, that are not available on other Linux distributions.

The second group of features includes:

* commands like `update-plcnext` and `recover-plcnext` that you saw previously, and
* software components that are started and controlled by the `PLCnext Runtime`.

This chapter will look at the `PLCnext Runtime`, and the factory-installed software components that are controlled by it:

* I/O and Fieldbus components
* Service components
* System components
* PLC components

An overview of these component categories is given in the [PLCnext Technology Info Center][comp-info].

Before we look at how the PLCnext runtime instantiates components, lets look at what components are available in each of the above categories. Components are defined in C++ shared object libraries, which are located in the `/usr/bin` directory on the PLC. The tables below includes links to more information on each feature.

### I/O Components

These components provide access to physical I/O modules through a variety of standard industrial networks.

| Library file               | Component type                           | Function                       |
|:---------------------------|:-----------------------------------------|:-------------------------------|
| libArp.Io.Axioline.so      | Arp::Io::Axioline::AxiolineComponent     | Axioline master<sup>1</sup>    |
| libArp.Io.Interbus.so      | Arp::Io::Interbus::InterbusComponent     | Interbus master<sup>1</sup>    |
| libArp.Io.EthernetIP.so    | Arp::Io::EthernetIP::EthernetIPComponent | Ethernet/IP device<sup>1</sup> |
| libArp.Io.ProfinetStack.so | Arp::Io::ProfinetStack::System::SystemComponent<br/>Arp::Io::ProfinetStack::Controller::ControllerComponent<br/>Arp::Io::ProfinetStack::Device::DeviceComponent | Profinet system<br/>Profinet controller<br/>Profinet device |

<sup>1</sup> Only available on AXC devices.

### Service Components

These components generally provide high-level features that are easily configurable by end users.

| Library file                          | Component type                                                              | Function                 |
|:--------------------------------------|:----------------------------------------------------------------------------|:-------------------------|
| libArp.Services.Fwm.so                | Arp::Services::Fwm::FwmComponent                                            | [Firewall manager][fwm-info] |
| libArp.Services.Wbm.so                | Arp::Services::Wbm::WbmComponent                                            | [Web-based management][wbm-info] |
| libArp.Services.Ehmi.so               | Arp::Services::Ehmi::EhmiComponent                                          | [Embedded HMI][ehmi-info] |
| libArp.Services.OpcUAServer.so        | Arp::Services::OpcUAServer::OpcUAServerComponent                            | [OPC UA Server][opc-info] |
| libArp.Services.Alarms.so             | Arp::Services::Alarms::AlarmsComponent                                      | [Alarm Dispatcher][alarms-info] |
| libArp.Services.ProfiCloud.so         | Arp::Services::ProfiCloud::ProfiCloudComponent                              | [Proficloud TSD publisher][tsd-info] |
| libArp.Services.NotificationLogger.so | Arp::Services::NotificationLogger::NotificationLoggerComponent              | [Notification Logger][nl-info] |
| libArp.Services.TraceController.so    | Arp::Services::TraceController::TraceControllerComponent                    | ??? |
| libArp.Services.NmUtilities.so        | Arp::Services::NmUtilities::NmPlcStateListener::NmPlcStateListenerComponent | [Notification Manager][nm-info] |
| libArp.Services.DataLogger.so         | Arp::Services::DataLogger::DataLoggerComponent                              | [Data Logger][dl-info] |
| libArp.Services.AppManager.so         | Arp::Services::AppManager::AppManagerComponent                              | [PLCnext Store App management][app-info] |

### System Components

These components implement low-level system features. They may provide an API, but are not generally designed to be configurable by end users.

| Library file                       | Component type                           | Function           |
|:-----------------------------------|:-----------------------------------------|:-------------------|
| libArp.Device.Access.so            | Arp::Device::Access::DeviceAccessComponent | ??? |
| libArp.Device.HmiLed.so            | Arp::Device::HmiLed::HmiLedComponent | ??? |
| libArp.Device.Interface.so         | Arp::Device::Interface::DiComponent | RSC service ? |
| libArp.Hardware.Nim.so             | Arp::Hardware::Nim::NimComponent | ??? |
| libArp.System.Scm.so               | Arp::System::Scm::ScmComponent | [System control manager][scm-info] |
| libArp.System.Um.so                | Arp::System::Um::UmComponent | [User manager][um-info] |
| libArp.System.RscGateway.so        | Arp::System::RscGateway::RscGatewayComponent | [Remote service call gateway][rsc-info] |
| libArp.System.Commons.Services.so  | Arp::System::Commons::Services::Component | ??? |
| libArp.System.Security.Services.so | Arp::System::Security::Services::Component | [???][security-info] |
| libArp.System.Fwu.so               | Arp::System::Fwu::FwuComponent | ??? |
| libArp.System.Watchdog.so          | Arp::System::Watchdog::SystemWatchdogComponent | ??? |
| libArp.System.SysWatchdog.so       | ??? | ??? |

### PLC Components

These components implement features you would expect to find on PLCs.

| Library file         | Component type | Function |
|:---------------------|:---------------|:---------|
| libArp.Plc.Eclr.so   | Arp::Plc::Eclr::EclrComponent<br/>Arp::Plc::Eclr::EclrServicesComponent<br/>Arp::Plc::Eclr::Internal::ArpDomainComponent | [Embedded Common Language Runtime][eclr-info] |
| libArp.Plc.Plm.so    | Arp::Plc::Plm::PlmComponent | [Manages real-time C++ programs][plm-info] |
| libArp.Plc.Esm.so    | Arp::Plc::Esm::EsmComponent<br/>Arp::Plc::Esm::EsmControllerComponent | [Execution and Synchronisation Manager][esm-info] |
| libArp.Plc.Gds.so    | Arp::Plc::Meta::MetaComponent<br/>Arp::Plc::Gds::GdsComponent | [Manages the global data space][gds-info] |
| libArp.Plc.Domain.so | Arp::Plc::Domain::PlcDomainProxyComponent<br/>Arp::Plc::Domain::PlcManagerComponent<br/>Arp::Plc::Domain::PlcDomainComponent | ???<br/>???<br/>??? |
| libArp.Plc.Fbm.so    | Arp::Plc::Fbm::FbmComponent<br/>Arp::Plc::Fbm::FbIoComponent | Fieldbus manager |
| libArp.Plc.Retain.so | Arp::Plc::Retain::RetainComponent | Manages retentive variables |

[comp-info]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/PLCnext_Runtime/Core_component.htm
[fwm-info]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/WBM/Security_Firewall.htm
[wbm-info]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/WBM/WBM.htm
[ehmi-info]: https://de89gmzz4wv9p.cloudfront.net/107838_en_01/Section05/Section05.htm
[opc-info]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/Service_Components/OPC_UA_Server/OPC_UA_server_eUA.htm
[alarms-info]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/Service_Components/Alarms/Alarms.htm
[tsd-info]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/Service_Components/PROFICLOUD/Transferring_values_to_PROFICLOUD.htm
[nl-info]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/Service_Components/Notifications/Notification_Logger.htm
[nm-info]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/Service_Components/Notifications/Notification_manager.htm
[dl-info]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/Service_Components/DataLogger/DataLogger.htm
[app-info]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/WBM/Administration_PLCnext_Apps.htm

[scm-info]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/PLCnext_Runtime/System_manager.htm#System_Manager
[um-info]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/WBM/Security_User_authentication.htm
[rsc-info]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/Service_Components/Remote_Service_Calls_RSC/RSC_Remote_Service_Calls.htm
[security-info]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/Security/Security.htm
[eclr-info]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/Programming/Csharp/eCLR_Programming_System.htm
[plm-info]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/Programming/Cpp/Cpp_program_structure/PLM_Program_Library_Manager.htm
[esm-info]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/PLCnext_Runtime/ESM.htm
[gds-info]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/PLCnext_Runtime/GDS_Global_Data_Space.htm
