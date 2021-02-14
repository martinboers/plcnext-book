## Component Instances

When the PLCnext runtime starts, the following happens:

1. PLCnext libraries are loaded and given a unique name.
1. One or more processes are started.
1. PLCnext component instances are created in specific processes.

The configuration information in this section appears in the following files:

* `/etc/plcnext/device/Libraries.acf.config`
* `/etc/plcnext/device/MainProcess.acf.config`
* `/etc/plcnext/device/ExternalIoProcess.acf.config`
* `/etc/plcnext/device/AXCF2152.acf.config`

### Runtime Libraries

The following table show the name given to each PLCnext library when it is loaded by the PLCnext runtime.

Libraries can be loaded conditionally, based on the value of a boolean environment variable. If no condition is specified, the library is always loaded.

| Library file                          | Name assigned by PLCnext runtime        | Condition                     |
|:--------------------------------------|:----------------------------------------|:------------------------------|
| libArp.System.Um.so                   | Arp.System.Um.Library                   |                               |
| libArp.Device.HmiLed.so               | Arp.Device.HmiLed.Library               |                               |
| libArp.Device.Interface.so            | Arp.Device.Interface.Library            |                               |
| libArp.Hardware.Nim.so                | Arp.Hardware.Nim.Library                |                               |
| libArp.System.RscGateway.so           | Arp.System.RscGateway.Library           |                               |
| libArp.System.Commons.Services.so     | Arp.System.Commons.Services.Library     |                               |
| libArp.System.Security.Services.so    | Arp.System.Security.Services.Library    |                               |
| libArp.System.Fwu.so                  | Arp.System.Fwu.Library                  |                               |
| libArp.System.Watchdog.so             | Arp.System.SystemWatchdog.Library       | ARP_COMPONENT_SYSTEM_WATCHDOG |
| libArp.System.SysWatchdog.so          | Arp.System.SysWatchdog.Library          |                               |
||||
| libArp.Hardware.IdentificationData.so | Arp.Hardware.IdentificationData.Library |                               |
| libArp.Hardware.FanControl.so         | Arp.Hardware.FanControl.Library         |                               |
| libArp.Hardware.Fpga.so               | Arp.Hardware.Fpga.Library               |                               |
| libArp.Hardware.OsControl.so          | Arp.Hardware.OsControl.Library          |                               |
| libArp.Hardware.RealTimeClock.so      | Arp.Hardware.RealTimeClock.Library      |                               |
| libArp.Hardware.ResourceMonitor.so    | Arp.Hardware.ResourceMonitor.Library    |                               |
| libArp.Hardware.DeviceHmi.so          | Arp.Hardware.DeviceHmi.Library          |                               |
| libArp.Hardware.Sensors.so            | Arp.Hardware.Sensors.Library            |                               |
| libArp.Hardware.ExternalSDCard.so     | Arp.Hardware.ExternalSDCard.Library     |                               |
| libArp.Hardware.ExternalPci.so        | Arp.Hardware.ExternalPci.Library        | ARP_COMPONENT_EXTERNAL_PCI    |
||||
| libArp.Plc.Eclr.so                    | Arp.Plc.Eclr.Library                    |                               |
| libArp.Plc.Plm.so                     | Arp.Plc.Plm.Library                     |                               |
| libArp.Plc.Esm.so                     | Arp.Plc.Esm.Library                     |                               |
| libArp.Plc.Gds.so                     | Arp.Plc.Gds.Library                     |                               |
| libArp.Plc.Domain.so                  | Arp.Plc.Domain.Library                  |                               |
| libArp.Plc.Meta.so                    | Arp.Plc.Meta.Library                    |                               |
| libArp.Plc.Fbm.so                     | Arp.Plc.Fbm.Library                     |                               |
| libArp.Plc.Retain.so                  | Arp.Plc.Retain.Library                  | ARP_COMPONENT_RETAIN          |
||||
| libArp.Services.Fwm.so                | Arp.Services.Fwm.Library                |                               |
| libArp.Services.Wbm.so                | Arp.Services.Wbm.Library                |                               |
| libArp.Services.Ehmi.so               | Arp.Services.Ehmi.Library               |                               |
| libArp.Services.OpcUAServer.so        | Arp.Services.OpcUAServer.Library        |                               |
| libArp.Services.Alarms.so             | Arp.Services.Alarms.Library             |                               |
| libArp.Services.ProfiCloud.so         | Arp.Services.ProfiCloud.Library         | ARP_COMPONENT_PROFICLOUD      |
| libArp.Services.ProfiCloudV3.so       | Arp.Services.ProfiCloudV3.Library       | ARP_COMPONENT_PROFICLOUD_V3   |
| libArp.Services.NotificationLogger.so | Arp.Services.NotificationLogger.Library |                               |
| libArp.Services.TraceController.so    | Arp.Services.TraceController.Library    |                               |
| libArp.Services.NmUtilities.so        | Arp.Services.NmUtilities.Library        |                               |
| libArp.Services.DataLogger.so         | Arp.Services.DataLogger.Library         |                               |
| libArp.Services.AppManager.so         | Arp.Services.AppManager.Library         | ARP_COMPONENT_APPMANAGER      |
| libArp.Services.LinuxSyslog.so        | Arp.Services.LinuxSyslog.Library        | ARP_COMPONENT_LINUXSYSLOG     |
| libArp.Services.Wcm.so                | Arp.Services.Wcm.Library                |                               |
| libArp.Services.Logging.so            | Arp.Services.Logging.Library            |                               |
| libArp.Services.SpnsProxy.so          | Arp.Services.SpnsProxy.Library          |                               |
||||
| libArp.Io.ProfinetStack.so            | Arp.Io.Pn.Library                       | ARP_COMPONENT_PROFINET<br/>or ARP_COMPONENT_PNC<br/>or ARP_COMPONENT_PND |
| libArp.Io.Axioline.so<sup>1</sup>     | Arp.Io.Axl.Library                      | ARP_COMPONENT_AXIOLINE        |
| libArp.Io.Interbus.so<sup>1</sup>     | Arp.Io.IbM.Library                      | ARP_COMPONENT_INTERBUS        |
| libArp.Io.EthernetIP.so<sup>1</sup>   | Arp.Io.EthernetIP.Library               | ARP_COMPONENT_ETHERNETIP      |

<sup>1</sup> Only available on AXC devices.

### Runtime Processes

Most component instance are created in the unnamed main PLCnext runtime process. In the AXC F 2152, two additional processes are created, in which I/O component instances related to Profinet, Ethernet/IP and Interbus are created.

| Process name               | Local TCP port |
|:---------------------------|:---------------|
| (main)                     | 41121          |
| ExternalIoProcess          | 41123          |
| LocalIoProcess<sup>1</sup> | Arp.Plc.DomainProxy.LocalIoProcess<br/>Arp.Io.IbM | 41124

<sup>1</sup> Only on AXC devices.

Since multiple Interbus and Ethernet hardware interfaces are possible on an AXC F 2152 device, these additional processes allow the corresponding I/O networks to be dynamically assigned to the the correct hardware interface.

### Component Instances

Each component created by the PLCnext runtime:

* Is created in a specific process. If no process is specified, the component is created in the unnamed main PLCnext Runtime process.
* Can optionally be passed settings information. In the table below, all settings information represent files relative to the directory `/etc/plcnext/device`.
* Can be created conditionally, based on the value of a boolean environment variable. If no condition is specified, the component instance is always created.

| Instance name | Type | Process | Settings information | Condition |
|:--------------|:-----|:--------|:---------------------|:----------|
| Arp.System.Commons.Services | Arp::System::Commons::Services::Component |
| Arp.System.Security.Services | Arp::System::Security::Services::Component |
| Arp.System.Watchdog.MainProcess | Arp::System::Watchdog::SystemWatchdogComponent || System/Watchdog/Watchdog.settings | ARP_COMPONENT_SYSTEM_WATCHDOG |
| Arp.System.RscGateway | Arp::System::RscGateway::RscGatewayComponent || System/RscGateway/RscGateway.settings |
| Arp.System.Um | Arp::System::Um::UmComponent || System/Um/Um.settings |
||||||
| Arp.Hardware.IdentificationData | Arp::Hardware::IdentificationData::IdentificationDataComponent || Hardware/IdentificationData/IdentificationData.settings |
| Arp.Hardware.FanControl | Arp::Hardware::FanControl::FanControlComponent || Hardware/FanControl/FanControl.settings |
| Arp.Hardware.Fpga | Arp::Hardware::Fpga::FpgaComponent || Hardware/Fpga/Fpga.settings |
| Arp.Hardware.OsControl | Arp::Hardware::OsControl::OsControlComponent || Hardware/OsControl/OsControl.settings |
| Arp.Hardware.RealTimeClock | Arp::Hardware::RealTimeClock::RealTimeClockComponent || Hardware/RealTimeClock/RealTimeClock.settings |
| Arp.Hardware.ResourceMonitor | Arp::Hardware::ResourceMonitor::ResourceMonitorComponent || Hardware/ResourceMonitor/ResourceMonitor.settings |
| Arp.Hardware.DeviceHmi | Arp::Hardware::DeviceHmi::DeviceHmiComponent || Hardware/DeviceHmi/DeviceHmi.settings |
| Arp.Hardware.Sensors | Arp::Hardware::Sensors::SensorsComponent || Hardware/Sensors/Sensors.settings |
| Arp.Hardware.Nim | Arp::Hardware::Nim::NimComponent | Hardware/Nim/Nim.settings |
| Arp.Hardware.NetloadLimiter | Arp::Hardware::Nim::NetloadLimiterComponent || Hardware/Nim/NetloadLimiter.settings | ARP_COMPONENT_NETLOAD_LIMITER |
| Arp.Hardware.ExternalSDCard | Arp::Hardware::ExternalSDCard::ExternalSDCardComponent || Hardware/ExternalSDCard/ExternalSDCard.settings |
| Arp.Hardware.ExternalPci | Arp::Hardware::ExternalPci::ExternalPciComponent || Hardware/ExternalPci/ExternalPci.settings | ARP_COMPONENT_EXTERNAL_PCI |
||||||
| Arp.Device.HmiLed | Arp::Device::HmiLed::HmiLedComponent |
| Arp.Device.Interface | Arp::Device::Interface::DiComponent || Device/Interface/Di.settings |
||||||
| Arp.Plc.Manager | Arp::Plc::Domain::PlcManagerComponent |
| Arp.Plc.Domain | Arp::Plc::Domain::PlcDomainComponent || Plc/Domain/PlcDomain.settings |
| Arp.Plc.MetaDomain | Arp::Plc::Meta::MetaDomainComponent |
| Arp.Plc.Meta | Arp::Plc::Meta::MetaComponent || Plc/Meta/Meta.settings |
| Arp.Plc.MetaController | Arp::Plc::Meta::MetaControllerComponent |
| Arp.Plc.Eclr | Arp::Plc::Eclr::EclrComponent || Plc/Eclr/Eclr.settings | ARP_COMPONENT_ECLR |
| Arp.Plc.EclrServices | Arp::Plc::Eclr::EclrServicesComponent ||| ARP_COMPONENT_ECLR |
| Arp.Plc.Eclr.ArpDomain | Arp::Plc::Eclr::ArpDomainComponent ||| ARP_COMPONENT_ECLR |
| Arp.Plc.Plm | Arp::Plc::Plm::PlmComponent || Plc/Plm/Plm.settings |
| Arp.Plc.Esm | Arp::Plc::Esm::EsmComponent || Plc/Esm/Esm.settings |
| Arp.Plc.EsmController | Arp::Plc::Esm::EsmControllerComponent |
| Arp.Plc.Gds | Arp::Plc::Gds::GdsComponent || Plc/Gds/Gds.settings |
| Arp.Plc.Retain | Arp::Plc::Retain::RetainComponent || Plc/Retain/Retain.settings | ARP_COMPONENT_RETAIN |
||||||
| Arp.Plc.Fbm | Arp::Plc::Fbm::FbmComponent || Plc/Fbm/Fbm.settings |
| Arp.Io.FbIo.PnC | Arp::Plc::Fbm::FbIoComponent || Plc/FbIo.PnC/FbIo.settings | ARP_COMPONENT_PROFINET<br/>or ARP_COMPONENT_PNC |
| Arp.Io.FbIo.PnD | Arp::Plc::Fbm::FbIoComponent || Plc/FbIo.PnD/FbIo.settings | ARP_COMPONENT_PROFINET<br/>or ARP_COMPONENT_PND |
||||||
| Arp.Services.Alarms | Arp::Services::Alarms::AlarmsComponent |
| Arp.Services.Fwm | Arp::Services::Fwm::FwmComponent || Services/Fwm/Fwm.settings | ARP_COMPONENT_FWM |
| Arp.Services.Wbm | Arp::Services::Wbm::WbmComponent || Services/Wbm/Wbm.settings | ARP_COMPONENT_WBM |
| Arp.Services.Ehmi | Arp::Services::Ehmi::EhmiComponent || Services/Ehmi/ehmi.settings | ARP_COMPONENT_EHMI |
| Arp.Services.OpcUAServer | Arp::Services::OpcUAServer::OpcUAServerComponent || Services/OpcUA/opcua.settings | ARP_COMPONENT_OPC_UA |
| Arp.Services.ProfiCloud | Arp::Services::ProfiCloud::ProfiCloudComponent || Services/ProfiCloud/Proficloud.settings | ARP_COMPONENT_PROFICLOUD |
| Arp.Services.NotificationLogger | Arp::Services::NotificationLogger::NotificationLoggerComponent || Services/NotificationLogger/NotificationLogger.settings |
| Arp.Services.TraceController | Arp::Services::TraceController::TraceControllerComponent || Services/TraceController/TraceController.settings | ARP_COMPONENT_TRACECONTROLLER |
| Arp.Services.NmUtilities.NmPlcStateListener | Arp::Services::NmUtilities::NmPlcStateListener::NmPlcStateListenerComponent |
| Arp.Services.DataLogger | Arp::Services::DataLogger::DataLoggerComponent || Services/DataLogger/dataLogger.settings | ARP_COMPONENT_DATALOGGER |
| Arp.Services.AppManager | Arp::Services::AppManager::AppManagerComponent || Services/AppManager/AppManager.settings | ARP_COMPONENT_APPMANAGER |
| Arp.System.Fwu | Arp::System::Fwu::FwuComponent |
| Arp.Services.LinuxSyslog | Arp::Services::LinuxSyslog::LinuxSyslogComponent || Services/LinuxSyslog/LinuxSyslog.settings | ARP_COMPONENT_LINUXSYSLOG |
| Arp.Services.ProfiCloudV3 | Arp::Services::ProfiCloudV3::ProfiCloudV3Component || Services/ProfiCloudV3/ProfiCloudV3.settings | ARP_COMPONENT_PROFICLOUD_V3 |
| Arp.System.Wcm | Arp::System::Wcm::WcmComponent || System/Wcm/Wcm.settings | ARP_COMPONENT_WCM |
| Arp.Services.Logging | Arp::Services::Logging::LoggingComponent ||| ARP_COMPONENT_LOGGING |
| Arp.Services.LogManager | Arp::Services::Logging::LogManagerComponent ||| ARP_COMPONENT_LOGMANAGER |
| Arp.Services.LogProvider | Arp::Services::Logging::LogProviderComponent ||| ARP_COMPONENT_LOGMANAGER |
| Arp.Services.SpnsProxy | Arp::Services::SpnsProxy::SpnsProxyComponent || Services/SpnsProxy/spnsproxy.settings | ARP_COMPONENT_SPNSPROXY |
||||||
| Arp.Plc.DomainProxy.ExternalIoProcess | Arp::Plc::Domain::PlcDomainProxyComponent | ExternalIoProcess |
| Arp.Io.PnS | Arp::Io::ProfinetStack::System::SystemComponent | ExternalIoProcess | Io/PnS/PnS.settings | ARP_COMPONENT_PROFINET<br/>or ARP_COMPONENT_PNC<br/>or ARP_COMPONENT_PND |
| Arp.Io.PnC | Arp::Io::ProfinetStack::Controller::ControllerComponent | ExternalIoProcess | Io/PnC/PnC.settings | ARP_COMPONENT_PNC |
| Arp.Io.PnD | Arp::Io::ProfinetStack::Device::DeviceComponent | ExternalIoProcess | Io/PnD/PnD.settings | ARP_COMPONENT_PND |
||||||
| Arp.Plc.DomainProxy.LocalIoProcess<sup>1</sup> | Arp::Plc::Domain::PlcDomainProxyComponent | LocalIoProcess |
| Arp.Io.AxlC<sup>1</sup> | Arp::Io::Axioline::AxiolineComponent || Io/AxlC/AxlC.settings | ARP_COMPONENT_AXIOLINE |
| Arp.Io.FbIo.AxlC<sup>1</sup> | Arp::Plc::Fbm::FbIoComponent || Plc/FbIo.AxlC/FbIo.settings |
| Arp.Io.IbM<sup>1</sup> | Arp::Io::Interbus::InterbusComponent | LocalIoProcess | Io/IbM/IbM.settings | ARP_COMPONENT_INTERBUS |
| Arp.Io.FbIo.IbM<sup>1</sup> | Arp::Plc::Fbm::FbIoComponent || Plc/FbIo.IbM/FbIo.settings |
| Arp.Io.EthernetIP<sup>1</sup> | Arp::Io::EthernetIP::EthernetIPComponent | ExternalIoProcess | Io/EthernetIP/EthernetIP.settings | ARP_COMPONENT_ETHERNETIP |
| Arp.Io.FbIo.EthernetIP<sup>1</sup> | Arp::Plc::Fbm::FbIoComponent || Plc/FbIo.EthernetIP/FbIo.settings | ARP_COMPONENT_ETHERNETIP |

<sup>1</sup> Only on AXC devices.
