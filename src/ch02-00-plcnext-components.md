# PLCnext Components

PLCnext Control firmware was introduced briefly in the previous chapter. PLCnext Control firmware features can be broadly categorised as either:

1. Features commonly available on general-purpose Linux distributions, or
2. Features developed by Phoenix Contact, that are not available on other Linux distributions.

The second group of features includes:

* commands like `update-plcnext` and `recover-plcnext` that you saw previously, and
* software components that are started and controlled by a single process called `plcnext`.

This chapter will look at the `plcnext` process, and the factory-installed components that are controlled by this process:

* I/O and Fieldbus components
* Service components
* System components
