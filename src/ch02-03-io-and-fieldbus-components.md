## I/O and Fieldbus Components

These components provide the communication interface to modules attached directly to the PLC, and to modules connected over fieldbus networks like Profinet and Ethernet/IP.

The names of these services generally start with `Arp.Io.`

### Axioline (AXC devices only)

Binary file:    `/usr/bin/libArp.Io.Axioline.so`
Component type: `Arp::Io::Axioline::AxiolineComponent`

PLCnext runtime process: `LocalIoProcess`
Library alias:           `Arp.Io.Axl.Library`
Component instance:      `Arp.Io.AxlC`

Axioline modules are connected to the right side of the PLC via DIN-rail connectors behind the modules. The Axioline component is enabled by the environment variable `ARP_AXIOLINE_SUPPORT`, which is set by default and only disabled when an Inline adapter is detected.

### Interbus (AXC devices only)



### PCI express (AXC devices only)

### Profinet Controller

### Profinet Device

### Ethernet/IP Device

