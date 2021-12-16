## Real-time C++ Programming Guidelines

The Execute method in a C++ program must not contain any code that could compromise the strict deterministic performance of the system. The Execute method *must* complete within a "reasonable" period of time. This must be considered this when using time-consuming program constructs like loops.

Perhaps the most common mistake made in a developer's first real-time C++ program is to treat the `Execute` method like the `main` function in a C++ application, and include something like a `while(true)` loop in that method. Not only is this not necessary (the `Execute` method will be called at a fixed frequency from a cyclic task), this type of endless loop will immediately "crash" the PLC because the `Execute` method will never exit, and either the task watchdog timer or the system watchdog timer will be exceeded.

Here are some other tips for real-time C++ programming:

- Never allocate or re-allocate memory in the `Execute` method. e.g.
  - don't use `malloc`
  - don't use `new`
  - don't assign a value to a string variable unless you know it will not result in memory re-allocation.
  - be careful when using classes like `std::vector`, since these can allocate memory automatically.

- Never use `std::mutex` in a real-time C++ program. If mutexes are required, use `Arp::Mutex`.

- Don't use third-party code (e.g. libraries) if that code does any of the above. Since third-party code is generally not designed with these limitations in mind, this means it is very unlikely that you will be able to use any third-party code directly in a C++ program without modification.

- Do not call methods on RSC services from the `Execute` method.

To help make sure you keep within these guidelines:

- Perform all memory allocation in the program constructor, e.g. allocating memory for the maximum expected size of all string and vector variables.
- Check any operations that might re-allocate memory in the `Execute` method (e.g. vector resizing).
- Consider doing non-real time work in the component that is associated with the program, and use `Arp::Mutex` to synchronise variable access between the component and the program.
- If in doubt, don't use third party code in the `Execute` method.
