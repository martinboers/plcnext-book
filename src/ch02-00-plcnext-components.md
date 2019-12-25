# PLCnext Components

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

Before we look at how the PLCnext runtime instantiates components, lets look at what components are available on the PLC. Components are defined in C++ shared object libraries, which are located in the `/usr/bin` directory on the PLC. The tables below includes links to more information on each function.

### I/O Components

| Library file               | Component type                           | Function           |
|:---------------------------|:-----------------------------------------|:-------------------|
| libArp.Io.Axioline.so      | Arp::Io::Axioline::AxiolineComponent     | Axioline master    |
| libArp.Io.Interbus.so      | Arp::Io::Interbus::InterbusComponent     | Interbus master    |
| libArp.Io.EthernetIP.so    | Arp::Io::EthernetIP::EthernetIPComponent | Ethernet/IP device |
| libArp.Io.ProfinetStack.so | Arp::Io::ProfinetStack::System::SystemComponent<br/>Arp::Io::ProfinetStack::Controller::ControllerComponent<br/>Arp::Io::ProfinetStack::Device::DeviceComponent | Profinet system<br/>Profinet controller<br/>Profinet device |


1. Only available on AXC devices.


### Service Components

| Library file                          | Component type                                                              | Function                 |
|:--------------------------------------|:----------------------------------------------------------------------------|:-------------------------|
| libArp.Services.Fwm.so                | Arp::Services::Fwm::FwmComponent                                            | Firewall manager         |
| libArp.Services.Wbm.so                | Arp::Services::Wbm::WbmComponent                                            | Web-based management     |
| libArp.Services.Ehmi.so               | Arp::Services::Ehmi::EhmiComponent                                          | Embedded HMI             |
| libArp.Services.OpcUAServer.so        | Arp::Services::OpcUAServer::OpcUAServerComponent                            | OPC UA Server            |
| libArp.Services.Alarms.so             | Arp::Services::Alarms::AlarmsComponent                                      | ???                      |
| libArp.Services.ProfiCloud.so         | Arp::Services::ProfiCloud::ProfiCloudComponent                              | Proficloud TSD publisher |
| libArp.Services.NotificationLogger.so | Arp::Services::NotificationLogger::NotificationLoggerComponent              | ??? |
| libArp.Services.TraceController.so    | Arp::Services::TraceController::TraceControllerComponent                    | ??? |
| libArp.Services.NmUtilities.so        | Arp::Services::NmUtilities::NmPlcStateListener::NmPlcStateListenerComponent | ??? |
| libArp.Services.DataLogger.so         | Arp::Services::DataLogger::DataLoggerComponent                              | ??? |
| libArp.Services.AppManager.so         | Arp::Services::AppManager::AppManagerComponent                              | ??? |

### System Components

| Library file                       | Component type                           | Function           |
|:-----------------------------------|:-----------------------------------------|:-------------------|
| libArp.Device.Access.so            | Arp::Device::Access::DeviceAccessComponent | ??? |
| libArp.Device.HmiLed.so            | Arp::Device::HmiLed::HmiLedComponent | ??? |
| libArp.Device.Interface.so         | Arp::Device::Interface::DiComponent | RSC service ? |
| libArp.Hardware.Nim.so             | Arp::Hardware::Nim::NimComponent | ??? |
| libArp.System.Scm.so               | Arp::System::Scm::ScmComponent | System control manager (?) |
| libArp.System.Um.so                | Arp::System::Um::UmComponent | User manager |
| libArp.System.RscGateway.so        | Arp::System::RscGateway::RscGatewayComponent | Remote service call gateway |
| libArp.System.Commons.Services.so  | Arp::System::Commons::Services::Component | ??? |
| libArp.System.Security.Services.so | Arp::System::Security::Services::Component | ??? |
| libArp.System.Fwu.so               | Arp::System::Fwu::FwuComponent | ??? |
| libArp.System.Watchdog.so          | Arp::System::Watchdog::SystemWatchdogComponent | ??? |
| libArp.System.SysWatchdog.so       | ??? | ??? |

### PLC Components

These components implement features you would expect to find on PLCs.

| Library file               | Component type                           | Function           |
|:---------------------------|:-----------------------------------------|:-------------------|
| libArp.Plc.Eclr.so   | Arp::Plc::Eclr::EclrComponent<br/>Arp::Plc::Eclr::EclrServicesComponent<br/>Arp::Plc::Eclr::Internal::ArpDomainComponent | Embedded Common Language Runtime |
| libArp.Plc.Plm.so    | Arp::Plc::Plm::PlmComponent                    | Manages real-time C++ programs |
| libArp.Plc.Esm.so    | Arp::Plc::Esm::EsmComponent<br/>Arp::Plc::Esm::EsmControllerComponent | Execution and Synchronisation Manager |
| libArp.Plc.Gds.so    | Arp::Plc::Meta::MetaComponent<br/>Arp::Plc::Gds::GdsComponent | Manages the global data space |
| libArp.Plc.Domain.so | Arp::Plc::Domain::PlcDomainProxyComponent<br/>Arp::Plc::Domain::PlcManagerComponent<br/>Arp::Plc::Domain::PlcDomainComponent | ???<br/>???<br/>??? |
| libArp.Plc.Fbm.so    | Arp::Plc::Fbm::FbmComponent<br/>Arp::Plc::Fbm::FbIoComponent | Fieldbus manager |
| libArp.Plc.Retain.so | Arp::Plc::Retain::RetainComponent              | Manages retentive variables |
