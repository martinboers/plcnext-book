# Introduction

Welcome to *The PLCnext Runtime*, an introductory book about programming on the PLCnext Control platform.

## What Is PLCnext Control?

PLCnext Control refers to a range of embedded computers from Phoenix Contact, which are designed for automating industrial processes. These controllers share some characteristics with popular single-board computers, but PLCnext Control devices includes features that make them particularly suitable for industrial applications.

The PLCnext Control range currently includes the following hardware variants from the AXC<sup>1</sup>, EPC<sup>2</sup>, RFC<sup>3</sup> and BPC ranges:

- [AXC F 1152][axcf1152] (ARM® Cortex®-A9 2x 800 MHz)
- [AXC F 2152][axcf2152] (ARM® Cortex®-A9 2x 800 MHz, PCIe® connector)
- [AXC F 3152][axcf3152] (Intel® Atom™ x5-E3930 1.3 GHz Dual Core)
- [EPC 1502][epc1502] (Intel® Celeron® N3350 1.10/2.40 GHz, 2GB RAM)
- [EPC 1522][epc1522] (Intel® Celeron® N3350 1.10/2.40 GHz, 4GB RAM, 2x DB9 COM ports)
- [RFC 4072S][rfc4072s] (Intel® Core™ i5-6300U 2x 2.4 GHz + separate safety processors)
- [BPC 9102S][bpc9102s] (Intel® Core™ i7-10700TE 8x 2.4 GHz + separate safety processors)

Each of these hardware platforms runs custom firmware that is based on Linux kernel version 5.4 with the [PREEMT-RT patch][preempt].

## Who PLCnext Control Is For

PLCnext Control is ideal for software and systems engineers involved in the automation of industrial processes.

Controllers from the PLCnext Control range can perform the role of traditional PLCs<sup>4</sup>, however they also include features that will be familiar to software engineers with a more general programming background.

### IEC 61131-3 Software Developers

Traditional PLCs generally can be programmed using any language defined by the IEC 61131-3 standard. Controllers from the PLCnext Control range are no different. For these developers, Phoenix Contact provides [*PLCnext Engineer*][plcnext-engineer] software.

### Simulink® Software Developers

Simulink® is software for graphical, model-based development of dynamic systems. Simulink® models can be integrated into the PLCnext Engineer development environment using the [*PLCnext Target for Simulink*][simulink-add-on] software add-on.

### Software engineers with experience in C/C++, Rust, C#, Java, Python, Javascript, HTML5, Go, etc

Custom software applications written in any popular programming language can be run on the controller. These applications can make use of PLCnext runtime services if required.

### Systems integrators and network administrators

It is possible to simply install and configure pre-built applications on a PLCnext Control device, without any software engineering effort.

### Project teams with some or all of the above skills

PLCnext Control devices includes unique features - such as the Global Data Space (GDS) and the Execution and Synchronisation Manager (ESM) - that make it possible to combine components written in different languages into a single project.

## Who This Book Is For

This book is aimed at software developers who want to extend the functionality of a PLCnext Control device with their own software. The book contains program examples and references in a number of popular languages, but generally uses C++ to demonstrate the features of PLCnext Control. C++ is used because PLCnext Control provides a C++ programming framework, and many of the open-source projects that are suitable for PLCnext Control projects are also written in C++. However, software engineers with other programming skills should be able to apply the principles found in this book to their language of choice. For these programmers, appendix A gives references to language-specific resources.

This book does not cover PLCnext Engineer or programming in IEC 61131-3 languages, and in fact it is not necessary to read this book in order to become proficient in PLCnext Control programming using PLCnext Engineer. For IEC 61131-3 programmers, there are other resources from Phoenix Contact that will help you get started with PLCnext Engineer.

For systems integrators who don't want to write their own software, but who want to install and configure third-party software on a PLCnext Control - you will be most interested in Chapters 1 and 2.

For systems and network administrators who will be managing PLCnext Control devices - you will also find Chapters 1 and 2 useful.

## What You Will Need

Obviously, you will need a controller from the PLCnext Control range. These are available for purchase from your local Phoenix Contact subsidiary, or from a number of online automation resellers. You will need to power the controller with a 24 VDC supply. A good option is the [PLCnext Technology Starter Kit][starter-kit], which includes an AXC F 2152 controller, a 24 VDC power supply unit with pre-wired mains plug, and digital and analog input/output (I/O) modules.

All sections of this book apply to AXC F 1152 and 2152 devices, and most sections also apply to other PLCnext Control devices.

A PLCnext Control device is a *target* (in embedded programming terminology), and it requires a *host*. This book uses Debian 11 as the host machine, but any popular Linux distribution - or even Microsoft Windows - should also work. Windows commands are not shown in this book, so Windows users should consider installing [Windows Subsystem for Linux][wsl] to work along with this book.

The host machine must be connected to the internet. The host machine requires certain software development tools to be installed, and these will be described in the relevant sections of this book.

The controller must be connected to a local area network with access to both the internet and the host machine. Note that the controller does not include a wireless network adapter.

A knowledge of Ethernet networking would also be beneficial. The book "[Ethernet Basics][ethernet-basics]" by Phoenix Contact is recommended for this purpose.

> Throughout this book, the PLCnext Control hardware will be referred to as either *PLCnext Control device*, or *controller*, or *target*. In this book, these terms are used interchangeably. Controllers from other manufacturers are often referred to with the term  *PLC*, but in this book the term *PLC* will only be used to refer to those firmware components on the controller that implement real-time automation functions.

## How to Use This Book

This book should be read from front to back. It is not intended to be an exhaustive reference; that is provided by the [PLCnext Technology Info Centre][info-center]. Instead, this book will draw on material in relevant sections of the Info Center, and elsewhere, to build up the readers knowledge in incremental steps.

Chapter 1 explains how to get started with a PLCnext Control device, from setting the IP address to writing your first "Hello, World!" programs in Python, C++ and Rust. Chapter 2 looks at some basic features of the Linux operating system (firmware) that runs on PLCnext Control devices. Chapter 3 introduces the PLCnext runtime by exploring the complete set of PLCnext runtime components that are installed with the firmware.

In Chapter 4, you will write your own PLCnext runtime extension component in C++. You will learn how extension components can use PLCnext runtime services, how they can provide their own services to other components, and how they can exchange data with other components through the global data space.

Chapter 5 introduces real-time programming on PLCnext Control devices. You will write a C++ program and configure the execution and synchronisation manager to run the program in a real-time PLC task. In Chapter 6 you will learn how a real-time program can read and write process data on Axioline I/O modules attached to the controller.

Chapter 7 looks at some additional tools that can help with PLCnext runtime programming.

Chapter 8 is for developers who want to port an existing runtime to a PLCnext Control device, or write a completely new runtime. You will learn how external runtimes can access the I/O that is connected to the controller, and how they can continue to utilise services provided by the PLCnext runtime.

A glossary of terms used in this book is available in the [PLCnext Technology Info Center][glossary].

> ### Command Line Notation
>
> Throughout this book, you will see commands that must be entered into a terminal on either the host or the target.
>
> Commands in a terminal on the host all start with `$` (you don’t need to enter the `$` character).
>
> Commands in a terminal on the target all start with `#` (you don’t need to enter the `#` character).
>
> Commands in a terminal running the python interpreter all start with `>>>` (you don’t need to enter the `>>>` characters).
>
> Lines that don’t start with `$`, `#` or `>>>` typically show the output of the previous command.

## Versions

This book will be kept up to date with the latest release of PLCnext Control firmware. As soon as a new version of PLCnext Control firmware is released, the book source code will be tagged with the version number of the firmware that has just been superseded.

## Source Code

The source files used to generate this book can be found on [GitHub][book].

---

<sup>1</sup> *AXC* is short for *Axioline Controller*, indicating that the controller has a dedicated hardware interface to connect directly to the Axioline range of I/O modules. *Axioline* is derived from the terms *AutomationWorx* (AX), a brand name used by Phoenix Contact, and *I/O*, meaning *Input/Output*. The term *line* can be taken to refer to a line of products, but in this case it was inherited from an earlier range of Phoenix Contact products called *Inline*. The letter "F" after "AXC" is used to distinguish these devices from earlier Axioline controllers, but otherwise has no meaning.

<sup>2</sup> *EPC* is short for *Edge Personal Computer*. EPCs combine real-time PLC features with popular Industrial Internet of Things (IIoT) applications like [Node-RED][node-red] and [InfluxDB][influx]. EPCs are designed for industrial [Edge computing][edge-computing] applications.

<sup>3</sup> *RFC* is short for *Remote Field Controller*. Unlike Axioline controllers, RFCs can only control *remote* I/O modules over a *field bus* like Profinet.

<sup>4</sup> *PLC* is short for [*Programmable Logic Controller*](https://en.wikipedia.org/wiki/Programmable_logic_controller).

[axcf1152]: http://www.phoenixcontact.com/product/1151412
[axcf2152]: http://www.phoenixcontact.com/product/2404267
[axcf3152]: http://www.phoenixcontact.com/product/1069208
[epc1502]: http://www.phoenixcontact.com/product/1185416
[epc1522]: http://www.phoenixcontact.com/product/1185423
[rfc4072s]: http://www.phoenixcontact.com/product/1051328
[bpc9102s]: http://www.phoenixcontact.com/product/1246285
[preempt]: https://wiki.linuxfoundation.org/realtime/start
[plcnext-engineer]: http://www.phoenixcontact.com/product/1046008
[simulink-add-on]: http://www.phoenixcontact.com/product/1326100
[starter-kit]: http://www.phoenixcontact.com/product/1188165
[wsl]: https://learn.microsoft.com/en-us/windows/wsl/about
[ethernet-basics]: http://plcnext-runtime.com/downloads/Ethernet_Basics_rev2_en.pdf
[info-center]: https://www.plcnext.help/te/About/Home.htm
[glossary]: https://www.plcnext.help/te/About/Home.htm?agt=glossary
[book]: https://github.com/martinboers/plcnext-book/tree/master/src
[edge-computing]: https://en.wikipedia.org/wiki/Edge_computing
[node-red]: https://nodered.org/
[influx]: https://www.influxdata.com/
