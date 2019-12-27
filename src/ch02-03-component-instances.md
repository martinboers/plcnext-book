## Component Instances

When the PLCnext runtime starts, the following happens:

1. PLCnext libraries are loaded and given a unique name.
1. One or more processes are started.
1. PLCnext component instances are created in specified processes.

### Runtime Libraries

The following tables shows the name given to each PLCnext library when it is loaded by the PLCnext runtime.

Libraries can be loaded conditionally, based on the value of a boolean environment variable. If no condition is specified, the library is always loaded.

| Library file                          | Name assigned by PLCnext runtime        | Condition                   |
|:--------------------------------------|:----------------------------------------|:----------------------------|
| libArp.Io.Axioline.so<sup>1</sup>     | Arp.Io.Axl.Library                      | ARP_AXIOLINE_SUPPORT        |
| libArp.Io.Interbus.so<sup>1</sup>     | Arp.Io.IbM.Library                      | ARP_INTERBUS_SUPPORT        |
| libArp.Io.EthernetIP.so<sup>1</sup>   | Arp.Io.EthernetIP.Library               | ARP_ETHERNETIP_SUPPORT      |
| libArp.Io.ProfinetStack.so            | Arp.Io.Pn.Library                       | ARP_PROFINET_SUPPORT        |
| libArp.Services.Fwm.so                | Arp.Services.Fwm.Library                |                             |
| libArp.Services.Wbm.so                | Arp.Services.Wbm.Library                |                             |
| libArp.Services.Ehmi.so               | Arp.Services.Ehmi.Library               |                             |
| libArp.Services.OpcUAServer.so        | Arp.Services.OpcUAServer.Library        |                             |
| libArp.Services.Alarms.so             | Arp.Services.Alarms.Library             |                             |
| libArp.Services.ProfiCloud.so         | Arp.Services.ProfiCloud.Library         |                             |
| libArp.Services.NotificationLogger.so | Arp.Services.NotificationLogger.Library |                             |
| libArp.Services.TraceController.so    | Arp.Services.TraceController.Library    |                             |
| libArp.Services.NmUtilities.so        | Arp.Services.NmUtilities.Library        |                             |
| libArp.Services.DataLogger.so         | Arp.Services.DataLogger.Library         |                             |
| libArp.Services.AppManager.so         | Arp.Services.AppManager.Library         | ARP_APPMANAGER_SUPPORT      |
| libArp.Device.Access.so               | Arp.Device.Access.Library               |                             |
| libArp.Device.HmiLed.so               | Arp.Device.HmiLed.Library               |                             |
| libArp.Device.Interface.so            | Arp.Device.Interface.Library            |                             |
| libArp.Hardware.Nim.so                | Arp.Hardware.Nim.Library                |                             |
| libArp.System.Scm.so                  | Arp.System.Scm.Library                  |                             |
| libArp.System.Um.so                   | Arp.System.Um.Library                   |                             |
| libArp.System.RscGateway.so           | Arp.System.RscGateway.Library           |                             |
| libArp.System.Commons.Services.so     | Arp.System.Commons.Services.Library     |                             |
| libArp.System.Security.Services.so    | Arp.System.Security.Services.Library    |                             |
| libArp.System.Fwu.so                  | Arp.System.Fwu.Library                  |                             |
| libArp.System.Watchdog.so             | Arp.System.SystemWatchdog.Library       | ARP_SYSTEM_WATCHDOG_SUPPORT |
| libArp.System.SysWatchdog.so          | Arp.System.SysWatchdog.Library          |                             |
| libArp.Plc.Eclr.so                    | Arp.Plc.Eclr.Library                    |                             |
| libArp.Plc.Plm.so                     | Arp.Plc.Plm.Library                     |                             |
| libArp.Plc.Esm.so                     | Arp.Plc.Esm.Library                     |                             |
| libArp.Plc.Gds.so                     | Arp.Plc.Gds.Library                     |                             |
| libArp.Plc.Domain.so                  | Arp.Plc.Domain.Library                  |                             |
| libArp.Plc.Fbm.so                     | Arp.Plc.Fbm.Library                     |                             |
| libArp.Plc.Retain.so                  | Arp.Plc.Retain.Library                  | ARP_RETAIN_SUPPORT          |

<sup>1</sup> Only available on AXC devices.

### Component Instances

Each component created by the PLCnext runtime:

* Can optionally be passed settings information. In the table below, all settings information represent files relative to the directory `/etc/plcnext/device`.
* Can be created conditionally, based on the value of a boolean environment variable. If no condition is specified, the component instance is always created.

| Instance name | Type | Settings information | Condition |
|:--------------|:-----|:---------------------|:----------|
| Arp.Io.AxlC<sup>1</sup> | Arp::Io::Axioline::AxiolineComponent | Io/AxlC/AxlC.settings | ARP_AXIOLINE_SUPPORT |
| Arp.Io.IbM<sup>1</sup> | Arp::Io::Interbus::InterbusComponent | Io/IbM/IbM.settings | ARP_INTERBUS_SUPPORT |
| Arp.Io.EthernetIP<sup>1</sup> | Arp::Io::EthernetIP::EthernetIPComponent | Io/EthernetIP/EthernetIP.settings | ARP_ETHERNETIP_SUPPORT |
| Arp.Io.PnS | Arp::Io::ProfinetStack::System::SystemComponent | Io/PnS/PnS.settings | ARP_PROFINET_SUPPORT |
| Arp.Io.PnC | Arp::Io::ProfinetStack::Controller::ControllerComponent | Io/PnC/PnC.settings | ARP_PROFINET_SUPPORT |
| Arp.Io.PnD | Arp::Io::ProfinetStack::Device::DeviceComponent | Io/PnD/PnD.settings | ARP_PROFINET_SUPPORT |
||||||                  
| Arp.Services.Fwm | Arp::Services::Fwm::FwmComponent | Services/Fwm/Fwm.settings | ARP_FWM_SUPPORT |
| Arp.Services.Wbm | Arp::Services::Wbm::WbmComponent | Services/Wbm/Wbm.settings | ARP_WBM_SUPPORT |
| Arp.Services.Ehmi | Arp::Services::Ehmi::EhmiComponent | Services/Ehmi/ehmi.settings | ARP_EHMI_SUPPORT |
| Arp.Services.OpcUAServer | Arp::Services::OpcUAServer::OpcUAServerComponent | Services/OpcUA/opcua.settings | ARP_OPC_UA_SUPPORT |
| Arp.Services.Alarms | Arp::Services::Alarms::AlarmsComponent |
| Arp.Services.ProfiCloud | Arp::Services::ProfiCloud::ProfiCloudComponent | Services/ProfiCloud/proficloud.settings.json | ARP_PROFICLOUD_SUPPORT |
| Arp.Services.NotificationLogger | Arp::Services::NotificationLogger::NotificationLoggerComponent | Services/NotificationLogger/NotificationLogger.settings |
| Arp.Services.TraceController | Arp::Services::TraceController::TraceControllerComponent | Services/TraceController/TraceController.settings | ARP_TRACECONTROLLER_SUPPORT |
| Arp.Services.NmUtilities.NmPlcStateListener | Arp::Services::NmUtilities::NmPlcStateListener::NmPlcStateListenerComponent |
| Arp.Services.DataLogger | Arp::Services::DataLogger::DataLoggerComponent | Services/DataLogger/dataLogger.settings | ARP_DATALOGGER_SUPPORT |
| Arp.Services.AppManager | Arp::Services::AppManager::AppManagerComponent | Services/AppManager/ | ARP_APPMANAGER_SUPPORT |
||||||
| Arp.Device.Access | Arp::Device::Access::DeviceAccessComponent |
| Arp.Device.HmiLed | Arp::Device::HmiLed::HmiLedComponent |
| Arp.Device.Interface | Arp::Device::Interface::DiComponent | Device/Interface/Di.settings |
| Arp.Hardware.Nim | Arp::Hardware::Nim::NimComponent | Hardware/Nim/Nim.settings | ARP_NETLOAD_LIMITER_SUPPORT |
| Arp.System.Scm | Arp::System::Scm::ScmComponent | System/Scm/Scm.settings |
| Arp.System.Um | Arp::System::Um::UmComponent | System/Um/Um.settings |
| Arp.System.RscGateway | Arp::System::RscGateway::RscGatewayComponent | System/RscGateway/RscGateway.settings |
| Arp.System.Commons.Services | Arp::System::Commons::Services::Component |
| Arp.System.Security.Services | Arp::System::Security::Services::Component |
| Arp.System.Fwu | Arp::System::Fwu::FwuComponent |
| Arp.System.Watchdog.MainProcess | Arp::System::Watchdog::SystemWatchdogComponent | System/Watchdog/Watchdog.settings | ARP_SYSTEM_WATCHDOG_SUPPORT |
||||||
| Arp.Plc.Eclr | Arp::Plc::Eclr::EclrComponent | Plc/Eclr/Eclr.settings | ARP_ECLR_SUPPORT |
| Arp.Plc.EclrServices | Arp::Plc::Eclr::EclrServicesComponent | | ARP_ECLR_SUPPORT |
| Arp.Plc.Eclr.ArpDomain | Arp::Plc::Eclr::Internal::ArpDomainComponent | | ARP_ECLR_SUPPORT |
| Arp.Plc.Plm | Arp::Plc::Plm::PlmComponent | Plc/Plm/Plm.settings |
| Arp.Plc.Esm | Arp::Plc::Esm::EsmComponent | Plc/Esm/Esm.settings |
| Arp.Plc.EsmController | Arp::Plc::Esm::EsmControllerComponent |
| Arp.Plc.Meta | Arp::Plc::Meta::MetaComponent | lc/Meta/Meta.settings |
| Arp.Plc.Gds | Arp::Plc::Gds::GdsComponent | Plc/Gds/Gds.settings |
| Arp.Plc.DomainProxy.LocalIoProcess<sup>1</sup> | Arp::Plc::Domain::PlcDomainProxyComponent |
| Arp.Plc.DomainProxy.ExternalIoProcess | Arp::Plc::Domain::PlcDomainProxyComponent |
| Arp.Plc.Manager | Arp::Plc::Domain::PlcManagerComponent |
| Arp.Plc.Domain | Arp::Plc::Domain::PlcDomainComponent | Plc/Domain/PlcDomain.settings |
| Arp.Io.FbIo.AxlC<sup>1</sup> | Arp::Plc::Fbm::FbIoComponent | Plc/FbIo.AxlC/FbIo.settings |
| Arp.Io.FbIo.IbM<sup>1</sup> | Arp::Plc::Fbm::FbIoComponent | Plc/FbIo.IbM/FbIo.settings |
| Arp.Io.FbIo.EthernetIP<sup>1</sup> | Arp::Plc::Fbm::FbIoComponent | Plc/FbIo.EthernetIP/FbIo.settings | ARP_ETHERNETIP_SUPPORT |
| Arp.Plc.Fbm | Arp::Plc::Fbm::FbmComponent | Plc/Fbm/Fbm.settings |
| Arp.Io.FbIo.PnC | Arp::Plc::Fbm::FbIoComponent | Plc/FbIo.PnC/FbIo.settings | ARP_PROFINET_SUPPORT |
| Arp.Io.FbIo.PnD | Arp::Plc::Fbm::FbIoComponent | Plc/FbIo.PnD/FbIo.settings | ARP_PROFINET_SUPPORT |
| Arp.Plc.Retain | Arp::Plc::Retain::RetainComponent | Plc/Retain/Retain.settings | ARP_RETAIN_SUPPORT |

<sup>1</sup> Only on AXC devices.

### Runtime Processes

Most component instance are created in the main PLCnext runtime process.

In the AXC F 2152, two additional processes are created, in which I/O component instances related to Profinet, Ethernet/IP and Interbus are created:

| Process name      | Component instances |
|:------------------|:--------------------|
| LocalIoProcess    | Arp.Plc.DomainProxy.LocalIoProcess<br/>Arp.Io.IbM |
| ExternalIoProcess | Arp.Plc.DomainProxy.ExternalIoProcess<br/>Arp.Io.PnSArp.Io.PnC<br/>Arp.Io.PnD<br/>Arp.Io.EthernetIP |

Since multiple Interbus and Ethernet hardware interfaces are possible on an AXC F 2152 device, these additional processes allow the corresponding I/O networks to be dynamically assigned to the the correct hardware interface.
