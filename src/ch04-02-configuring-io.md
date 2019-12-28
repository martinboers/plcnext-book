## Configuring I/O

We want to start the Axioline, Interbus and/or Profinet bus and create GDS variables for all process data.

This process uses Technology Independent Configuration (`.tic`) files. These are in a proprietary XML format.

Offline configuration:
- Use NetCI tool
- Example using NetCI to generate config, then connect I/O to C++ program ports

Automatic and/or dynamic configuration:
- Use AxioMaster service, for example (BusConductor example in Github)
- Use Peer-Michael's Audi project
