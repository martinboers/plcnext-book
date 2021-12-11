## Using RSC Services

[Previously][rsc-services] you learned that some PLCnext runtime features provide an application programming interface (API) in the form of *Remote Service Calls*, or RSC Services.

In this section, our ACF component will call C++ API on the [Data Access][data-access] RSC service. The Data Access service provides access to [Global Data Space][gds-info] (GDS) variables. You can use a similar technique to access any RSC service in the PLCnext Runtime.

Here are the steps to use the C++ API on the Data Access RSC service:

- Add the relevant header file to the .hpp file of our component:

   ```cpp
   #include "Arp/Plc/Gds/Services/IDataAccessService.hpp"
   ```

- Declare a pointer to the Data Access service:

   ```cpp
   IDataAccessService::Ptr dataAccessServicePtr = nullptr;
   ```

- Declare one variable for each GDS variable that will be accessed using the Data Access service. In this example, we will be reading the average CPU load value from the GDS:

   ```cpp
   Arp::int16 avgCpuLoad {0};
   ```

- In the component .cpp file, add the header for the RSC Service Manager:

   ```cpp
   #include "Arp/System/Rsc/ServiceManager.hpp"
   ```

- In the `SubscribeServices` method of the ACF component, get a pointer to the Data Access service:

   ```cpp
   this->dataAccessServicePtr = ServiceManager::GetService<IDataAccessService>();
   ```

- In the `SetupConfig` method of the ACF component, use the Data Access service to read the average CPU load from the GDS, and log the value to the `Output.log` file:

   ```cpp
   // 1. Read a single variable
   // "ReadSingle" can only be used with primitive types
   ReadItem readPortData = this->dataAccessServicePtr->ReadSingle("Arp.Plc.Eclr/DEVICE_STATE.CPU_LOAD_ALL_CORES");
   if (readPortData.Error == DataAccessError::None)
   {
       readPortData.Value.CopyTo(avgCpuLoad);
       this->log.Info("Average CPU at component startup = {0}%", avgCpuLoad);
   }
   else this->log.Info("Error reading average CPU load from GDS");
   ```




Link to more examples (Info Center, Github, Forum).

[rsc-services]: ch03-05-rsc-services.md
[data-access]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Plc_1_1Gds_1_1Services_1_1IDataAccessService.html 
[gds-info]: https://www.plcnext.help/te/PLCnext_Runtime/GDS_Global_Data_Space.htm "PLCnext Info Center"
