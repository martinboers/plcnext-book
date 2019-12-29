## Connecting GDS variables

You have previously seen how your component instance can create its own GDS variables, and read and write other GDS variables using RSC services like the Data Access service.

There is another way to transfer data between any two GDS variables with compatible type - by using configuration files.

The following is an example of a `gds.config` file:

...

- Example showing how to transfer data into / out of a component (e.g. from system variables) using a gds.config file.

- Advantage: Very simple to set up. No code required. Can access I/O variables (this is not possible using RSC services)
- Disadvantage: All GDS variables must be defined and connected at design-time. The RSC service provides more flexibility, if required.


(NEXT CHAPTER - REST API - ANOTHER WAY TO ACCESS GDS VARIABLES)
