## Component Methods

After completing the previous sections, an instance of your PLCnext extension component - called `MyComponentInstance` - has been created by the PLCnext runtime. At the moment, this component instance is not doing much. The PLCnext runtime has called a number of the methods that you defined in the `MyComponent` class, but because these methods are empty, we don't see any evidence that this has happened. Let's write some messages to the `Output.log` file, so we can see when these methods are called.

One way that our component instance can write to the Output.log file is if it inherits a base class created from the template [`Arp::System::Commons::Diagnostics::Logging::Loggable`][loggable-doc].

The main steps to do this are:

- Add the header file to the .hpp file of our component:

   ```cpp
   #include "Arp/System/Commons/Logging.h"
   ```

- Inherit the `Loggable` template class, by adding the following to the component class definition:

   ```cpp
   private Loggable<MyComponent>
   ```

   The component class thereby inherits a private field - called `log` - of type [Arp::System::Commons::Diagnostics::Logging::Log][log-doc].

- Add log messages where required.

   In this case, we have added a log message to every method in the component's `.cpp` file. The resulting source files are available here:

   - [MyComponent.hpp][component-hpp]
   - [MyComponent.cpp][component-cpp]

   You can use these files to update the project you created in the previous section.

- Rebuild the project.

- Copy the resulting library file to the target.

- Restart the PLCnext runtime:

   ```text
   # sudo /etc/init.d/plcnext restart && tail -f -n 0 /opt/plcnext/logs/Output.log
   ```

Among the messages that appear in the Output.log file, you should see the following:

```text
INFO  - MyComponent::Initialize
INFO  - MyComponent::SubscribeServices
INFO  - MyComponent::LoadSettings - settings path = ''
INFO  - MyComponent::SetupSettings
INFO  - MyComponent::PublishServices
INFO  - MyComponent::LoadConfig
INFO  - MyComponent::SetupConfig
```

These methods are called, in sequence, when the component instance is created by the PLCnext runtime. Other methods are called when the PLCnext runtime shuts down, just before the component instance is destroyed. Some types of components even have methods that are called during normal PLCnext runtime operation, under certain circumstances. For example, it is possible for a component to be notified when the PLC component - which executes deterministic, real-time tasks - stops and restarts.

Each of these methods allows the component to perform one or more common functions, if required, at the appropriate time. For example, the `SubscribeServices` method, as the name suggests, is a good place for the component to subscribe to any RSC services that it needs to use.

The table below shows when `ComponentBase` methods are called on ACF components. It is based on a [similar table in the PLCnext Info Center][info-center].

| Method | Called on an ACF component … |
|:--|:--|
| Initialize<br/>SubscribeServices<br/>LoadSettings<br/>SetupSettings<br/>PublishServices | During the first stage of ACF startup * |
| LoadConfig<br/>SetupConfig<br/> | During the second stage of ACF startup * |
| ResetConfig | During the first stage of ACF shutdown |
| Dispose | During the second stage of ACF shutdown |
| PowerDown | Only when an unexpected power loss occurs,<br/>and only on devices that have a power status sensor |

In the above table, all the methods listed in the sections marked with * are called one after the other on each component instance in the order listed, so in practice it makes no difference in which of these method(s) the user chooses to implement their application-specific code.

You can see that only one of the standard component methods has a parameter. The `const String&` parameter on the `LoadSettings` method allows this method to receive a string value. This parameter is generally used by firmware components to get the path to a settings file - hence the parameter name. However, you can use this parameter to pass *any* string information to your component instance during startup:

- In the `.acf.config` file, replace this line:

  ```xml
    <Component name="MyComponentInstance" type="MyNamespace::MyComponent" library="MyProject" process="MyProcess" />
  ```

  ... with these lines:

  ```xml
    <Component name="MyComponentInstance" type="MyNamespace::MyComponent" library="MyProject" process="MyProcess">
      <Settings path="Settings data" />
    </Component>
  ```

- Copy the `.acf.config` file to the target, and restart the PLCnext runtime.

You should now see a line in the `Output.log` file with this message:

```text
INFO  - MyComponent::LoadSettings - settings path = 'Settings data'
```

Using this method, it is possible to pass user-configurable String data to the component during component startup.

[loggable-doc]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1System_1_1Commons_1_1Diagnostics_1_1Logging_1_1Loggable_3_01Derived_00_01true_01_4.html
[log-doc]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1System_1_1Commons_1_1Diagnostics_1_1Logging_1_1Log.html
[component-hpp]: samples/ch04-03-component-methods/MyProject/src/MyComponent.hpp
[component-cpp]: samples/ch04-03-component-methods/MyProject/src/MyComponent.cpp
[info-center]: https://www.plcnext.help/te/Programming/Cpp/Cpp_program_structure/PLM_Program_Library_Manager.htm
