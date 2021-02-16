## Component Instances

When the PLCnext runtime starts, the following happens:

1. One or more processes are started.
1. The libraries containing PLCnext component definitions are loaded into the specified process(es).
1. Component instances are created in the specified processes.

The configuration information in this section appears in the following files:

* `/etc/plcnext/device/Libraries.acf.config`
* `/etc/plcnext/device/MainProcess.acf.config`
* `/etc/plcnext/device/ExternalIoProcess.acf.config`
* `/etc/plcnext/device/AXCF2152.acf.config`

### Runtime Processes

Most component instance are created in the main PLCnext runtime process, which is called **MainProcess**. In the AXC F 2152, two additional processes are created, in which I/O component instances related to Profinet, Ethernet/IP and Interbus are created.

| Process name               | Local TCP port |
|:---------------------------|:---------------|
| MainProcess                | 41121          |
| ExternalIoProcess          | 41123          |
| LocalIoProcess<sup>1</sup> | 41124          |

<sup>1</sup> Only on AXC devices.

Since multiple Interbus and Ethernet hardware interfaces are possible on an AXC F 2152 device, these additional processes allow the corresponding I/O networks to be dynamically assigned to the the correct hardware interface.

### Component Libraries

The following table show the alias given to each component library by the PLCnext runtime.

Libraries can be loaded conditionally, based on the value of a boolean environment variable. If no condition is specified, the library is always loaded.

| Filename<br/>(libArp.\*.so) | Alias<br/>(Arp.\*.Library) | Condition |
|:-------------------|:--------------------|:------------------------------|
| **System.**        | **System.**         |                               |
| Um                 | Um                  |                               |
| RscGateway         | RscGateway          |                               |
| Commons.Services   | Commons.Services    |                               |
| Security.Services  | Security.Services   |                               |
| Fwu                | Fwu                 |                               |
| Watchdog           | SystemWatchdog      | ARP_COMPONENT_SYSTEM_WATCHDOG |
| SysWatchdog        | SysWatchdog         |                               |
| **Hardware.**      | **Hardware.**       |                               |
| Nim                | Nim                 |                               |
| IdentificationData | IdentificationData  |                               |
| FanControl         | FanControl          |                               |
| Fpga               | Fpga                |                               |
| OsControl          | OsControl           |                               |
| RealTimeClock      | RealTimeClock       |                               |
| ResourceMonitor    | ResourceMonitor     |                               |
| DeviceHmi          | DeviceHmi           |                               |
| Sensors            | Sensors             |                               |
| ExternalSDCard     | ExternalSDCard      |                               |
| ExternalPci        | ExternalPci         | ARP_COMPONENT_EXTERNAL_PCI    |
| **Device.**        | **Device.**         |                               |
| HmiLed             | HmiLed              |                               |
| Interface          | Interface           |                               |
| **Plc.**           | **Plc.**            |                               |
| Eclr               | Eclr                |                               |
| Plm                | Plm                 |                               |
| Esm                | Esm                 |                               |
| Gds                | Gds                 |                               |
| Domain             | Domain              |                               |
| Meta               | Meta                |                               |
| Fbm                | Fbm                 |                               |
| Retain             | Retain              | ARP_COMPONENT_RETAIN          |
| **Services.**      | **Services.**       |                               |
| Fwm                | Fwm                 |                               |
| Wbm                | Wbm                 |                               |
| Ehmi               | Ehmi                |                               |
| OpcUAServer        | OpcUAServer         |                               |
| Alarms             | Alarms              |                               |
| ProfiCloud         | ProfiCloud          | ARP_COMPONENT_PROFICLOUD      |
| ProfiCloudV3       | ProfiCloudV3        | ARP_COMPONENT_PROFICLOUD_V3   |
| NotificationLogger | NotificationLogger  |                               |
| TraceController    | TraceController     |                               |
| NmUtilities        | NmUtilities         |                               |
| DataLogger         | DataLogger          |                               |
| AppManager         | AppManager          | ARP_COMPONENT_APPMANAGER      |
| LinuxSyslog        | LinuxSyslog         | ARP_COMPONENT_LINUXSYSLOG     |
| Wcm                | Wcm                 |                               |
| Logging            | Logging             |                               |
| SpnsProxy          | SpnsProxy           |                               |
| **Io.**            | **Io.**             |                               |
| ProfinetStack      | Pn                  | ARP_COMPONENT_PROFINET<br/>or ARP_COMPONENT_PNC<br/>or ARP_COMPONENT_PND |
| Axioline.so<sup>1</sup>   | Axl          | ARP_COMPONENT_AXIOLINE        |
| Interbus.so<sup>1</sup>   | IbM          | ARP_COMPONENT_INTERBUS        |
| EthernetIP.so<sup>1</sup> | EthernetIP   | ARP_COMPONENT_ETHERNETIP      |

<sup>1</sup> Only available on AXC devices.

### Component Instances

Each component created by the PLCnext runtime:

* Is created in a specific process. If no process is specified, the component is created in the main PLCnext Runtime process ("MainProcess").
* Can optionally be passed settings information. In the table below, all settings information represent files relative to the directory `/etc/plcnext/device`.
* Can be created conditionally, based on the value of a boolean environment variable. If no condition is specified, the component instance is always created.

| Instance name<br/>(Arp.\*) | Type<br/>(Arp::\*) | Process | Settings information<br/>(`/etc/plcnext/device/*` | Condition |
|:---------------------|:------------------------------------------------|:--------|:---------------------|:----------|
| **System.**          | **System::**                                    || **System/** |
| Commons.Services     | Commons::Services::Component                    |
| Security.Services    | Security::Services::Component                   |
| Watchdog.MainProcess | Watchdog::SystemWatchdogComponent               || Watchdog/Watchdog.settings     | ARP_COMPONENT_SYSTEM_WATCHDOG |
| RscGateway           | RscGateway::RscGatewayComponent                 || RscGateway/RscGateway.settings |
| Um                   | Um::UmComponent                                 || Um/Um.settings                 |
| Fwu                  | Fwu::FwuComponent                               |
| Wcm                  | Wcm::WcmComponent                               || Wcm/Wcm.settings | ARP_COMPONENT_WCM |
| **Hardware.**        | **Hardware::**                                  || **Hardware/** |
| IdentificationData   | IdentificationData::IdentificationDataComponent || IdentificationData/IdentificationData.settings |
| FanControl           | FanControl::FanControlComponent                 || FanControl/FanControl.settings |
| Fpga                 | Fpga::FpgaComponent                             || Fpga/Fpga.settings |
| OsControl            | OsControl::OsControlComponent                   || OsControl/OsControl.settings |
| RealTimeClock        | RealTimeClock::RealTimeClockComponent           || RealTimeClock/RealTimeClock.settings |
| ResourceMonitor      | ResourceMonitor::ResourceMonitorComponent       || ResourceMonitor/ResourceMonitor.settings |
| DeviceHmi            | DeviceHmi::DeviceHmiComponent                   || DeviceHmi/DeviceHmi.settings |
| Sensors              | Sensors::SensorsComponent                       || Sensors/Sensors.settings |
| Nim                  | Nim::NimComponent                               || Nim/Nim.settings |
| NetloadLimiter       | Nim::NetloadLimiterComponent                    || Nim/NetloadLimiter.settings | ARP_COMPONENT_NETLOAD_LIMITER |
| ExternalSDCard       | ExternalSDCard::ExternalSDCardComponent         || ExternalSDCard/ExternalSDCard.settings |
| ExternalPci          | ExternalPci::ExternalPciComponent               || ExternalPci/ExternalPci.settings | ARP_COMPONENT_EXTERNAL_PCI |
| **Device.**          | **Device::**                                    || **Device/** |
| HmiLed               | HmiLed::HmiLedComponent                         |
| Interface            | Interface::DiComponent                          || Interface/Di.settings |
| **Plc.**             | **Plc::**                                       || **Plc/** |
| Manager              | Domain::PlcManagerComponent                     |
| Domain               | Domain::PlcDomainComponent                      || Domain/PlcDomain.settings |
| MetaDomain           | Meta::MetaDomainComponent                       |
| Meta                 | Meta::MetaComponent                             || Meta/Meta.settings |
| MetaController       | Meta::MetaControllerComponent                   |
| Eclr                 | Eclr::EclrComponent                             || Eclr/Eclr.settings | ARP_COMPONENT_ECLR |
| EclrServices         | Eclr::EclrServicesComponent                     ||| ARP_COMPONENT_ECLR |
| Eclr.ArpDomain       | Eclr::ArpDomainComponent                        ||| ARP_COMPONENT_ECLR |
| Plm                  | Plm::PlmComponent                               || Plm/Plm.settings |
| Esm                  | Esm::EsmComponent                               || Esm/Esm.settings |
| EsmController        | Esm::EsmControllerComponent                     |
| Gds                  | Gds::GdsComponent                               || Gds/Gds.settings |
| Retain               | Retain::RetainComponent                         || Retain/Retain.settings | ARP_COMPONENT_RETAIN |
| Fbm                  | Fbm::FbmComponent                               || Fbm/Fbm.settings |
| DomainProxy.ExternalIoProcess | Domain::PlcDomainProxyComponent | ExternalIoProcess |
| DomainProxy.LocalIoProcess<sup>1</sup> | Domain::PlcDomainProxyComponent | LocalIoProcess |
| **Io.**                     | **Plc::**          || **Plc/** |
| FbIo.PnC                    | Fbm::FbIoComponent || FbIo.PnC/FbIo.settings | ARP_COMPONENT_PROFINET<br/>or ARP_COMPONENT_PNC |
| FbIo.PnD                    | Fbm::FbIoComponent || FbIo.PnD/FbIo.settings | ARP_COMPONENT_PROFINET<br/>or ARP_COMPONENT_PND |
| FbIo.AxlC<sup>1</sup>       | Fbm::FbIoComponent || FbIo.AxlC/FbIo.settings |
| FbIo.IbM<sup>1</sup>        | Fbm::FbIoComponent || FbIo.IbM/FbIo.settings |
| FbIo.EthernetIP<sup>1</sup> | Fbm::FbIoComponent || FbIo.EthernetIP/FbIo.settings | ARP_COMPONENT_ETHERNETIP |
| **Io.**  | **Io::**                                       || **Io/** |
| PnS      | ProfinetStack::System::SystemComponent | ExternalIoProcess | PnS/PnS.settings | ARP_COMPONENT_PROFINET<br/>or ARP_COMPONENT_PNC<br/>or ARP_COMPONENT_PND |
| PnC      | ProfinetStack::Controller::ControllerComponent | ExternalIoProcess | PnC/PnC.settings | ARP_COMPONENT_PNC |
| PnD      | ProfinetStack::Device::DeviceComponent | ExternalIoProcess | PnD/PnD.settings | ARP_COMPONENT_PND |
| AxlC<sup>1</sup> | Axioline::AxiolineComponent || AxlC/AxlC.settings | ARP_COMPONENT_AXIOLINE |
| IbM<sup>1</sup> | Interbus::InterbusComponent | LocalIoProcess | IbM/IbM.settings | ARP_COMPONENT_INTERBUS |
| EthernetIP<sup>1</sup> | EthernetIP::EthernetIPComponent | ExternalIoProcess | EthernetIP/EthernetIP.settings | ARP_COMPONENT_ETHERNETIP |
| **Services.**                  | **Services::**                                       || **Services/** |
| Alarms                         | Alarms::AlarmsComponent |
| Fwm                            | Fwm::FwmComponent || Fwm/Fwm.settings | ARP_COMPONENT_FWM |
| Wbm                            | Wbm::WbmComponent || Wbm/Wbm.settings | ARP_COMPONENT_WBM |
| Ehmi                           | Ehmi::EhmiComponent || Ehmi/ehmi.settings | ARP_COMPONENT_EHMI |
| OpcUAServer                    | OpcUAServer::OpcUAServerComponent || OpcUA/opcua.settings | ARP_COMPONENT_OPC_UA |
| ProfiCloud                     | ProfiCloud::ProfiCloudComponent || ProfiCloud/Proficloud.settings | ARP_COMPONENT_PROFICLOUD |
| ProfiCloudV3                   | ProfiCloudV3::ProfiCloudV3Component || ProfiCloudV3/ProfiCloudV3.settings | ARP_COMPONENT_PROFICLOUD_V3 |
| NotificationLogger             | NotificationLogger::NotificationLoggerComponent || NotificationLogger/NotificationLogger.settings |
| TraceController                | TraceController::TraceControllerComponent || TraceController/TraceController.settings | ARP_COMPONENT_TRACECONTROLLER |
| NmUtilities.NmPlcStateListener | NmUtilities::NmPlcStateListener::NmPlcStateListenerComponent |
| DataLogger                     | DataLogger::DataLoggerComponent || DataLogger/dataLogger.settings | ARP_COMPONENT_DATALOGGER |
| AppManager                     | AppManager::AppManagerComponent || AppManager/AppManager.settings | ARP_COMPONENT_APPMANAGER |
| LinuxSyslog                    | LinuxSyslog::LinuxSyslogComponent || LinuxSyslog/LinuxSyslog.settings | ARP_COMPONENT_LINUXSYSLOG |
| Logging                        | Logging::LoggingComponent ||| ARP_COMPONENT_LOGGING |
| LogManager                     | Logging::LogManagerComponent ||| ARP_COMPONENT_LOGMANAGER |
| LogProvider                    | Logging::LogProviderComponent ||| ARP_COMPONENT_LOGMANAGER |
| SpnsProxy                      | SpnsProxy::SpnsProxyComponent || SpnsProxy/spnsproxy.settings | ARP_COMPONENT_SPNSPROXY |

<sup>1</sup> Only on AXC devices.
