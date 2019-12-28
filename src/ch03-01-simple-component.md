## Simple Extension Component

The simplest PLCnext component is a C++ class that inherits [`Arp::System::Acf::ComponentBase`][component-base-doc].

The C++ source files (`.hpp` and `.cpp`) for a simple component, called `MyComponent`, are ... (where?).

At this point `MyComponent` is a valid component, but it contains no functionality - this will be added later.

### Library Singleton

Named component instances are created by the PLCnext runtime from a singleton that inherits [`Arp::System::Acf::LibraryBase`][library-base-doc].

The C++ source files (`.hpp` and `.cpp`) for a singleton - called `MyLibrary` - that creates named instances of `MyComponent` are ... (where?).

Note that both `MyComponent` and `MyLibrary` are defined in a namespace called `MyNamespace`.

### Building the Library

You can build a shared object library containing both these classes (`MyComponent` and `MyLibrary`) using the SDK that you installed earlier.

The following procedure uses the build tools `CMake` and `Ninja`, so make sure these are also installed on the host machine.

Build the library as follows:

1. On your host machine, create a project directory. Under this directory, create two sub-directories called `src` and `tools`.

1. Copy the four source files to the `src` directory.

1. In the project root directory, create a CMakeLists.txt file containing the following text:

   ```cmake
   cmake_minimum_required(VERSION 3.13)
   
   project(MyProject)
   
   if(NOT CMAKE_BUILD_TYPE)
     set(CMAKE_BUILD_TYPE Release)
   endif()
   
   ################# create target #######################################################
   
   set (WILDCARD_SOURCE *.cpp)
   set (WILDCARD_HEADER *.h *.hpp *.hxx)
   
   file(GLOB_RECURSE Headers CONFIGURE_DEPENDS src/${WILDCARD_HEADER})
   file(GLOB_RECURSE Sources CONFIGURE_DEPENDS src/${WILDCARD_SOURCE})
   add_library(MyProject SHARED ${Headers} ${Sources})
   
   #######################################################################################
   
   ################# project include-paths ###############################################
   
   target_include_directories(MyProject
       PUBLIC
       $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>)
   
   #######################################################################################
   
   ################# include arp cmake module path #######################################
   
   list(INSERT CMAKE_MODULE_PATH 0 "${ARP_TOOLCHAIN_CMAKE_MODULE_PATH}")
   
   #######################################################################################
   
   ################# set link options ####################################################
   # WARNING: Without --no-undefined the linker will not check, whether all necessary    #
   #          libraries are linked. When a library which is necessary is not linked,     #
   #          the firmware will crash and there will be NO indication why it crashed.    #
   #######################################################################################
   
   target_link_options(MyProject PRIVATE LINKER:--no-undefined)
   
   #######################################################################################
   
   ################# add link targets ####################################################
   
   find_package(ArpDevice REQUIRED)
   find_package(ArpProgramming REQUIRED)
   
   target_link_libraries(MyProject PRIVATE ArpDevice ArpProgramming)
   
   #######################################################################################
   
   ################# install ############################################################
   
   string(REGEX REPLACE "^.*\\(([0-9]+\.[0-9]+\.[0-9]+\.[0-9]+).*$" "\\1" _ARP_SHORT_DEVICE_VERSION ${ARP_DEVICE_VERSION})
   install(TARGETS MyProject
       LIBRARY DESTINATION ${ARP_DEVICE}_${_ARP_SHORT_DEVICE_VERSION}/$<CONFIG>/lib
       ARCHIVE DESTINATION ${ARP_DEVICE}_${_ARP_SHORT_DEVICE_VERSION}/$<CONFIG>/lib
       RUNTIME DESTINATION ${ARP_DEVICE}_${_ARP_SHORT_DEVICE_VERSION}/$<CONFIG>/bin)
   unset(_ARP_SHORT_DEVICE_VERSION)
   
   #######################################################################################
   ```

1. In the project `tools` directory, create a file named `build.sh` containing the following text:

   ```bash
   #!/bin/bash
   #//
   #// Copyright (c) 2020 Phoenix Contact GmbH & Co. KG. All rights reserved.
   #// Licensed under the MIT. See LICENSE file in the project root for full license information.
   #// SPDX-License-Identifier: MIT
   #//
   while getopts t:a:n: option
   do
   case "${option}"
   in
   t) TOOLCHAIN=${OPTARG};;
   a) ARPVERSION=${OPTARG};;
   n) TARGETNAME=${OPTARG};;
   esac
   done
   
   VERSION=$(echo $ARPVERSION | grep -oP [0-9]+[.][0-9]+[.][0-9]+[.][0-9]+)
   echo "Version:${VERSION}"
   
   # Get the directory of this script
   DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
   
   echo CMAKE Configure
   cmake --configure -G "Ninja" \
   -DBUILD_TESTING=OFF \
   -DUSE_ARP_DEVICE=ON \
   -DCMAKE_STAGING_PREFIX="${DIR}/../deploy/" \
   -DCMAKE_INSTALL_PREFIX=/usr/local \
   -DCMAKE_PREFIX_PATH="${DIR}/../deploy/${TARGETNAME}_${VERSION}" \
   -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
   "-DARP_TOOLCHAIN_ROOT=${TOOLCHAIN}" \
   "-DARP_DEVICE=${TARGETNAME}" \
   "-DARP_DEVICE_VERSION=${ARPVERSION}" \
   "-DCMAKE_TOOLCHAIN_FILE=${TOOLCHAIN}/toolchain.cmake" \
   -S "${DIR}/../." \
   -B "${DIR}/../build/${TARGETNAME}_${VERSION}"
   
   cmake --build "${DIR}/../build/${TARGETNAME}_${VERSION}" \
   --config Debug \
   --target all -- -j 3
   
   cmake --build "${DIR}/../build/${TARGETNAME}_${VERSION}" \
   --config Debug --target install -- -j 3
   ```

1. From the project root directory, execute the build script:

   ```text
   $ tools/build.sh -t "/opt/pxc/sdk/AXCF2152/2020.0" -a "2020.0 LTS (20.0.0.24752)" -n "AXCF2152"
   Version:20.0.0.24752
   CMAKE Configure
      :
   [0/1] Install the project...
   -- Install configuration: "Release"
   -- Installing: /home/tcs-user/MyProject/tools/../deploy/AXCF2152_20.0.0.24752/Release/lib/libMyProject.so
   ```

You can see that a shared object library, `libMyProject.so`, has been created. This contains the component called `MyNamespace::MyComponent` and the singleton called `MyNamespace::MyLibrary`.

1. On the PLC, create a project directory e.g. `/opt/plcnext/projects/MyProject`, and a `lib` subdirectory.

1. Copy the shared object library from the host to the PLC:

   ```text
   $ scp deploy/AXCF2152_20.0.0.24752/Release/lib/libMyProject.so admin@192.168.1.10:~/projects/MyProject/lib
   ```

### Instantiating the Component

Now that the shared object library containing the extension component is on the PLC, the PLCnext runtime must be instructed to create an instance of `MyComponent`.

1. On the host, in the project root directory, create a file named `MyProject.acf.config`, containing the following text:

   ```xml
   <?xml version="1.0" encoding="UTF-8"?>
   <AcfConfigurationDocument
     xmlns="http://www.phoenixcontact.com/schema/acfconfig"
     xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
     xsi:schemaLocation="http://www.phoenixcontact.com/schema/acfconfig.xsd"
     schemaVersion="1.0" >
   
     <Processes>
       <Process name="MyProcess" settingsPath="$ARP_ACF_SETTINGS_FILE$" />
     </Processes>
   
     <Libraries>
       <Library name="MyProject" binaryPath="$ARP_PROJECTS_DIR$/MyProject/lib/libMyProject.so" />
     </Libraries>
   
     <Components>
       <Component name="MyComponentInstance" type="MyNamespace::MyComponent" library="MyProject" />
     </Components>
   
   </AcfConfigurationDocument>
   ```

1. Copy this ACF configuration file from the host to the target:

   ```text
   $ scp MyProject.acf.config admin@192.168.1.10:~/projects/Default
   ```

The PLCnext runtime will automatically load this configuration file, since the `Default.acf.config` file in the same directory includes all files that match the  pattern `*.acf.config`. The ACF configuration file for `MyProject` instructs the PLCnext runtime to:

* Create a new child process called `MyProcess`. (why?)
* Load the shared object library and name it `MyProject`. This name can be considered an alias, or shorthand reference, to the shared object library. This name does not have any relationship to the name of the class in the shared object library that inherited `LibraryBase`.
* Create an instance of `MyNamespace::MyComponent`, called `MyComponentInstance`, from the library it named `MyProject`.


1. Restart the PLCnext runtime:

   ```text
   # /etc/init.d/plcnext start && tail -f -n 0 /opt/plcnext/logs/Output.log
   (result)
   ```

Among the messages that appear in the Output.log file, you should see the following:

```text
LOADED LIBRARY
LOADED COMPONENT
```

Your first PLCnext extension component instance is now running!

[component-base-doc]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_API_Documentation/html/classArp_1_1System_1_1Acf_1_1ComponentBase.html

[library-base-doc]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_API_Documentation/html/classArp_1_1System_1_1Acf_1_1LibraryBase.html
