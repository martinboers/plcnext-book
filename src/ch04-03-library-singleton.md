## Component Library Singleton

You won't need to worry too much about the `MyLibrary` singleton that you created with your extension component. This singleton provides a way for the PLCnext runtime to create named instances of your ACF component(s).

Each shared object file must only contain one singleton that inherits `LibraryBase`. This singleton can usually remain unchanged as you develop your components. The only time that this singleton must be modified is when you add or remove components from your library.

To add a component to the library:

- (show how)
- (can now add new entry to the acf.config file to create an instance of this new component).
