## Component Library Singleton

You won't need to worry too much about the `MyLibrary` singleton that you created with your extension component. This singleton provides a way for the PLCnext runtime to create named instances of your ACF component(s).

Each shared object file must only contain one singleton that inherits `LibraryBase`. This singleton can usually remain unchanged as you develop your components. The only time that this singleton must be modified is when you add or remove components from your library.

To add a component to the library:

- Create the new component in your C++ project. These two source files contain the definition for a component named `MyOtherComponent`, which you can add to the `src` directory of the project you created in the previous section:

  - [MyOtherComponent.hpp][component-hpp]
  - [MyOtherComponent.cpp][component-cpp]

- Add the header file for `MyOtherComponent` to the library `.cpp` file.

- In the library constructor, add a call to the method `componentFactory.AddFactoryMethod` to register the new component.

   The new library source file can be downloaded here:

   - [MyLibrary.cpp][library-cpp]

- Rebuild the project and copy the resulting `.so` file to the target.

- You can create an instance of MyOtherComponent by adding a new entry to the .acf.config file, as follows:

   ```xml
    <Component name="MyOtherComponentInstance" type="MyNamespace::MyOtherComponent" library="MyProject" process="MyProcess" />
    ```

- Copy the new configuration file to the target and restart the PLCnext runtime. You will now see these entries in the Output.log file:

```text
INFO  - Component 'MyComponentInstance' in process 'MainProcess' created.
INFO  - Component 'MyOtherComponentInstance' in process 'MainProcess' created.
```

[component-hpp]: samples/ch04-02-library-singleton/MyProject/src/MyOtherComponent.hpp
[component-cpp]: samples/ch04-02-library-singleton/MyProject/src/MyOtherComponent.cpp
[library-cpp]: samples/ch04-02-library-singleton/MyProject/src/MyLibrary.cpp
