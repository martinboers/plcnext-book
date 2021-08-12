## Installing a Software Development Kit

You can build native applications for a PLCnext Control device - either from third-party open-source code, or from your own code. To do this, you must install a software development kit (SDK) on the host, corresponding to the firmware that is running on the PLCnext Control device. The SDK contains the build tools and other resources required to create native applications for the target.

### PLCnext Command Line Interface

Software development kits for PLCnext Control targets are installed and managed using a command-line interface (CLI), called the *PLCnext CLI* or `plcncli`. It is possible to install SDKs on the host without using `plcncli`, but `plcncli` provides important features that will be required in later chapters of this book. For this reason, it is highly recommended to install and manage SDKs using `plcncli`.

To install `plcncli` on your host:

* Download the file *PLCnext Technology C++ tool chain for Linux* from the Phoenix Contact website. For example, the file `PLCnCLI_SDK_2021.6_Linux_AXC_F_2152.tar.gz` is for the AXC F 2152 running firmware version 2021.6.

* Extract the files from the archive.

* In a terminal window, navigate to the directory where the files were extracted.

* Optional: See what commands are available 

* Run the script to set up `plcncli` on the host, specifying the directory where the package should be installed.

   ```text
   $ ./PLCnCLI_Setup.sh --target ~/plcncli
   ```

   Read the terms and conditions carefully and, if you agree with them, type `y`.

* Create a symbolic link to the `plcncli` executable, as suggested by the installation message.

* Check that the installation has been successful.

   ```text
   $ plcncli
   plcncli 21.6.0 (21.6.0.726)
   Copyright (c) 2018 PHOENIX CONTACT GmbH & Co. KG
   ```

### PLCnext SDK

* In a terminal window, navigate to the directory where the files were extracted from the archive.

* Use plcncli to install the SDK. You are free to specify any destination directory you want, using the `-d` option.

   ```text
   $ plcncli install sdk -p pxc-glibc-x86_64-axcf2152-image-sdk-cortexa9t2hf-neon-axcf2152-toolchain-2021.6.sh -d /opt/pxc/sdk/AXCF2152/2021.6
   (todo: response))
   ```

   You may need to change the permissions on the SDK installation file to give the current user execute privilege.

* Check what SDKs and targets have been installed.

   ```text
   $ plcncli get sdks
   {
      "sdks": [
         {
            "path": "/opt/pxc/sdk/AXCF2152/2021.6"
         }
      ]
   }
   ```

   ```text
   $ plcncli get targets
   {
      "targets": [
         {
            "name": "AXCF2152",
            "version": "21.6.0.46",
            "longVersion": "2021.6.0 (21.6.0.46)",
            "shortVersion": "21.6.0",
            "available": null
         }
      ]
   }
   ```

Note that the above responses are in JSON format, which makes it easier to integrate plcncli operations into an automated workflow if required.

If you need to build applications for different PLCnext Control hardware and/or firmware variants, then it is possible to use `plcncli` to install multiple SDKs on the host. To do this, simply repeat the installation procedure for each additional SDK. There is no need to install `plcncli` again.

### Alternative SDK installation methods

If you are writing C++ applications in Eclipse or Visual Studio, then it is possible to install PLCnext SDKs through these IDEs. All SDK installation methods are described in the [PLCnext Info Center][sdk-install].

[sdk-install]: https://www.plcnext.help/te/Programming/Cpp/Cpp_programming/Required_Installations.htm
