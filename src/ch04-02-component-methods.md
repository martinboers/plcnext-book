## Component Methods

After completing the previous section, an instance of your PLCnext extension component - called `MyComponentInstance` - has been created by the PLCnext runtime. At the moment, this component instance is not doing much. The PLCnext runtime has called a number of the methods that you defined in the `MyComponent` class, but because these methods are empty, we don't see any evidence that this has happened. Let's write some messages to the `Output.log` file, so we can see when these methods are called.

One way that our component instance can write to the Output.log file is if it inherits a base class created from the template [`Arp::System::Commons::Diagnostics::Logging::Loggable`][loggable-doc].

- Add the header (possibly link to documentation).
- Add private inheritance of the `Loggable` class. Our component class thereby inherits a private field - called `log` - of type [Arp::System::Commons::Diagnostics::Logging::Log][log-doc].
- Add log messages to each method (link to the  ). The methods available 

- Restart the PLCnext runtime:

   ```text
   # /etc/init.d/plcnext start && tail -f -n 0 /opt/plcnext/logs/Output.log
   (result)
   ```

Among the messages that appear in the Output.log file, you should see the following:

```text
METHOD CALLS
```

You will see that some of the methods we defined are called when the component instance is created by the PLCnext runtime. Other methods are called when the PLCnext runtime shuts down, just before the component instance is destroyed. Some types of components even have methods that are called during normal PLCnext runtime operation, under certain circumstances. For example, it is possible for a component to be notified when the PLC component - which executes deterministic, real-time tasks - stops and restarts.

- Look at each of the component methods.

- Only one method has a parameter - this allows us to load a Settings file, like we saw for some of the components that come with the PLCnext firmware.

[loggable-doc]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1System_1_1Commons_1_1Diagnostics_1_1Logging_1_1Loggable_3_01Derived_00_01true_01_4.html

[log-doc]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1System_1_1Commons_1_1Diagnostics_1_1Logging_1_1Log.html
