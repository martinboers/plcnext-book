## Component Example: TCP Server

Create a TCP server that opens a port - set from a Settings file (just a number!), starts listening on the port and registers a callback for when a client connects.

Create two instances of the component, then connect to the servers from the host using netcat (the server should send a welcome message).

-> this uses "Common Classes", provided in the SDK. Common classes implement some standard C++ functions. By using Common Classes instead of the corresponding standard C++ functions:
- classes are optimised for PLCnext Control targets. For example, methods on the [Arp::Mutex][arp-mutex] class can be called from real-time tasks without the risk of blocking a real-time thread, while methods on the [std::mutex][std-mutex] class cannot.
- code can be run on PLCnext Control targets with different architectures (e.g. arm, x64) without modification.

[arp-mutex]: https://api.plcnext.help/api_docs_2021-9/classArp_1_1System_1_1Commons_1_1Threading_1_1Mutex.html
[std-mutex]: https://en.cppreference.com/w/cpp/thread/mutex
