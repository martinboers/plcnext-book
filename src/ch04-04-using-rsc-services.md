## Using RSC Services

[Previously][rsc-services] you learned that some PLCnext runtime features provide an application programming interface (API) in the form of *Remote Service Calls*, or RSC Services.

In this section, our ACF component will call C++ API on the [Device Info][device-info] RSC service. The Device Info service provides access to [Device Information][device-info-help]. You can use a similar technique to access [any RSC service][rsc-services-list] in the PLCnext Runtime.

Here are the steps to use the C++ API on the Device Info RSC service:

- Add the relevant header file to the .hpp file of the component:

   ```cpp
   #include "Arp/Device/Interface/Services/IDeviceInfoService.hpp"
   ```

- Declare a pointer to the Device Info service:

   ```cpp
   IDeviceInfoService::Ptr deviceInfoServicePtr = nullptr;
   ```

- In the component .cpp file, add the header for the RSC Service Manager:

   ```cpp
   #include "Arp/System/Rsc/ServiceManager.hpp"
   ```

- In the `SubscribeServices` method of the ACF component, get a pointer to the Device Info service:

   ```cpp
   this->deviceInfoServicePtr = ServiceManager::GetService<IDeviceInfoService>();
   ```

- In the `SetupConfig` method of the ACF component, use the Device Info service to read the device serial number, and log the value to the `Output.log` file:

   ```cpp
   RscVariant<512> serialNumber = this->deviceInfoServicePtr->GetItem("General.SerialNumber");
   if (serialNumber.GetType() == RscType::String)
   {
      this->log.Info("Serial number of this device: {0}%", serialNumber.GetChars());
   }
   else this->log.Info("Error reading device serial number");
   ```

- The above code is included in these source files:

  - [MyComponent.hpp][component-hpp]
  - [MyComponent.cpp][component-cpp]

  You can use these files to update the project you created in the previous section.

- Rebuild the project.

- Copy the resulting library file to the target.

- Restart the PLCnext runtime:

   ```text
   # sudo /etc/init.d/plcnext restart && tail -f -n 0 /opt/plcnext/logs/Output.log
   ```

Among the messages that appear in the `Output.log` file, you should see an INFO message from your component containing the serial number of your device.

[rsc-services]: ch03-06-rsc-services.md
[rsc-services-list]: appendix-02-list-of-rsc-services.md
[device-info]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Device_1_1Interface_1_1Services_1_1IDeviceInfoService.html
[device-info-help]: https://www.plcnext.help/te/Communication_interfaces/Remote_Service_Calls_RSC/RSC_device_interface_services.htm#IDeviceInfoService "PLCnext Info Center"
[component-hpp]: samples/ch04-04-using-rsc-services/MyProject/src/MyComponent.hpp
[component-cpp]: samples/ch04-04-using-rsc-services/MyProject/src/MyComponent.cpp
