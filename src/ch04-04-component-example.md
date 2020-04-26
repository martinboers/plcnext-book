## Component Example: TCP Server

Create a TCP server that opens a port - set from a Settings file (just a number!), starts listening on the port and registers a callback for when a client connects.

Create two instances of the component, then connect to the servers from the host using netcat (the server should send a welcome message).

-> this uses "Common Classes", provided in the SDK. Common Classes abstract/wrap some Linux API. By using Common Classes instead of the API itself, future changes in the Linux API will not affect your code.
