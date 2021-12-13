## Worker Threads

After completing the previous section, you may have your eye on another quite interesting RSC service - the [Data Access][data-access] service. This service provides access to [Global Data Space][gds-info] (GDS) variables in the PLCnext runtime.

Many variables in the GDS will change over time, and it may be necessary for an ACF component to exchange data with GDS variables during the lifetime of the component. However, the only component methods we have seen so far are called during the startup or shutdown of the component. It would be useful to have a component method that is executed periodically during the complete lifetime of the component, so that (for example) data can be exchanged with GDS variables using the Data Access service.

The ARP provides a [*worker thread*][worker-thread] class that can be used for this purpose. An ACF component can create a worker thread and, in the thread constructor, specify:

- an execution frequency, and
- a method that will be executed on the worker thread at that frequency.

[An example][thread-example] of how to use worker threads (and other types of ARP threads) is provided in Github.

> ARP threads, including worker threads, are not designed to be used for "real time" processing. Worker threads should not be confused with Cyclic Tasks in a PLC. The execution period of a worker thread is not deterministic, and the actual execution frequency cannot be guaranteed.

For applications where a deterministic task cycle is not required, a worker thread may be a good solution.

Many of the [C++ examples in Github][cpp-examples] use a worker thread to call various RSC services. For example, the [Data Access example][data-access-example] uses a worker thread to read and write GDS variable data using the Data Access service.

[data-access]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1Plc_1_1Gds_1_1Services_1_1IDataAccessService.html 
[gds-info]: https://www.plcnext.help/te/PLCnext_Runtime/GDS_Global_Data_Space.htm "PLCnext Info Center"
[worker-thread]: https://api.plcnext.help/api_docs_2021-0-LTS/classArp_1_1System_1_1Commons_1_1Threading_1_1WorkerThread.html
[thread-example]: https://github.com/PLCnext/CppExamples/tree/master/Examples/ThreadExample
[cpp-examples]: https://github.com/PLCnext/CppExamples
[data-access-example]: https://github.com/PLCnext/CppExamples/blob/master/Examples/DataAccess
