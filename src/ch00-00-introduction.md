# Introduction

> Note: This edition of the book is the same as [The Rust Programming
> Language][nsprust] available in print and ebook format from [No Starch
> Press][nsp].

[nsprust]: https://nostarch.com/rust
[nsp]: https://nostarch.com/

Welcome to *The PLCnext Runtime*, an introductory book about programming on the PLCnext Control platform.

## What Is PLCnext Control?

PLCnext Control refers to a range of embedded computers from Phoenix Contact, which are designed for automating industrial processes. These controllers share some characteristics with popular single-board computers, but PLCnext Control includes features that make it particularly suitable for industrial applications.

The PLCnext Control range includes the following hardware variants from the [AXC](about:blank "AXC is short for \"Axioline Controller\", indicating that the controller has a dedicated hardware interface to connect directly to the Axioline range of I/O modules. \"Axioline\" is derived from the terms \"AutomationWorx\" (AX), a brand name used by Phoenix Contact, and \"I/O\", meaning \"Input/Output\". The term \"line\" can be taken to refer to a line of products, but in this case it was inherited from an earlier range of Phoenix Contact products called \"Inline\".")<sup>1</sup> and RFC<sup>2</sup> range:

- AXC F 1152 (Cortex ARM)
- AXC F 2152 (Cortex ARM )
- AXC F 3152 (Cortex ARM )
- RFC 4072S (Intel i5)

A comparison of these controllers is available ... (where)

Each of these hardware platforms runs custom firmware that is based on a Linux kernel with the [PREEMT-RT patch][preempt].

## Who PLCnext Control Is For

PLCnext Control is ideal for software and systems engineers involved in the automation of industrial processes.

Controllers from the PLCnext Control range can perform the role of traditional PLCs<sup>3</sup>, however they also include features that will be familiar to software engineers with a more general programming background.

### IEC 61131-3 software developers

Traditional PLCs generally can be programmed using any language defined by the IEC 61131-3 standard. Controllers from the PLCnext Control range are no different. For these developers, Phoenix Contact provides PLCnext Engineer software.

### Matlab Simulink software developers

(something here)

### Software engineers with experience in C/C++, Rust, C#, Java, Python, Javascript, HTML5, Go, ....

(something here) - including support tools (SDKs, add-ins for Visual Studio and Eclipse).

### Systems integrators and network administrators

It is possible to simply install and configure pre-built applications on a PLCnext Control, without any major software engineering effort.

### Project teams with some or all of the above skills

PLCnext Control includes unique features - such as the Global Data Space (GDS) and the Execution and Synchronisation Manager (ESM) - that make it possible to combine components written in different languages into a single application.

## Who This Book Is For

This book is aimed at software developers who want to extend the functionality of a PLCnext Control device with their own software. The book contain program examples and references in a number of popular languages, but generally uses C++ to demonstrate the features of PLCnext Control. C++ is used because PLCnext Control provides a C++ programming framework, and many of the open-source projects that are suitable for PLCnext Control projects are also written in C++. However, software engineers with other programming skills should be able to apply the principles found in this book to their language of choice. For these programmers, appendix ? gives references to language-specific resources.

This book does not cover PLCnext Engineer or programming in IEC 61131-3 languages, and in fact it is not necessary to read this book in order to become proficient in PLCnext Control programming using PLCnext Engineer. For IEC 61131-3 programmers, there are other resources from Phoenix Contact that will help you get started with PLCnext Engineer.

For systems integrators who don't want to write their own software, but who want to install and configure third-party software on a PLCnext Control - you will be most interested in Chapter 1, up to and including the "Installing Software" topic.

For systems and network administrators who will be managing PLCnext Control devices - you will also find Chapter 1 useful, up to and including "System Administration".

## What You Will Need

Obviously, you will need a controller from the PLCnext Control range. These are available for purchase from your local Phoenix Contact subsidiary, or from a number of online automation resellers. You will need to power the PLC with a 24 VDC supply. A good option is the PLCnext Starter Kit, which includes an AXC F 2152 controller, a 24 VDC power supply unit with pre-wired mains plug, and digital and analog I/O modules.

Most sections of this book apply to all PLCnext Control hardware variants. Where hardware-specific features are used, this will be mentioned in the relevant section.

The PLCnext Control is a *target* (in embedded programming terminology), and it requires a *host*. This book uses Debian 9 as the host machine, but any popular Linux distribution - or even Microsoft Windows - should also work. The host machine must be connected to the internet. The host machine requires certain software development tools to be installed, and these will be described in the relevant sections of this book.

The controller must be connected to a local area network with access to both the internet and the host machine. Note that the controller does not include a wireless network adapter.

> Note: Throughout this book, the PLCnext Control device will be referred to as either *PLC*, or *controller*, or *target*. In this book, these terms all refer to precisely the same device.

## How to Use This Book

This book should be read from front to back. It is not intended to be an exhaustive reference; that is provided by the [PLCnext Technology Info Centre][info-center]. Instead, this book will draw on material in relevant sections of the Info Center, and elsewhere, to build up the readers knowledge step by step.

Chapter 1 explains how to get started with a PLCnext Control device, from setting the IP address to writing your first "Hello, World" programs in Python, C++ and Rust. Chapter 2 introduces the PLCnext runtime by exploring the complete set of PLCnext components that are installed with the firmware. Chapter 3 looks at PLCnext runtime middleware, including the Global Data Space.

In Chapter 4, you will write your own PLCnext component in C++ and run it on the PLC. (using other services on the PLC) (Program components) (Writing RSC services.)

Chapter 5 looks at how to build and execute other runtimes on a PLCnext Control device, alongside the PLCnext runtime.

(chapters 6, 7, 8 - will these stay?)

(something about terminology and abbreviations - link to Glossary in the Info Centre)

> ### Command Line Notation
>
> Throughout this book, you will see commands that must be entered into a terminal on either the host or the target. Commands in a terminal on the host all start with `$` (you don’t need to enter the `$` character).
> Commands in a terminal on the target all start with `#` instead of `$` (you don’t need to enter the `#` character).
> Commands in a terminal running the python interpreter all start with `>>>` (you don’t need to enter the `>>>` characters).
> Lines that don’t start with `$`, `#` or `>>>` typically show the output of the previous command.

## Source Code

The source files from which this book is generated can be found on
[GitHub][book].

---

<sup>1</sup> *AXC* is short for *Axioline Controller*, indicating that the controller has a dedicated hardware interface to connect directly to the Axioline range of I/O modules. *Axioline* is derived from the terms *AutomationWorx* (AX), a brand name used by Phoenix Contact, and *I/O*, meaning *Input/Output*. The term *line* can be taken to refer to a line of products, but in this case it was inherited from an earlier range of Phoenix Contact products called *Inline*, so named because the I/O modules are assembled in a linear arrangement.

<sup>2</sup> *RFC* is short for *Remote Field Controller*. Unlike Axioline controllers, RFCs can only control *remote* I/O modules over a *field bus* like Profinet.

<sup>3</sup> *PLC* is short for [*Programmable Logic Controller*](https://en.wikipedia.org/wiki/Programmable_logic_controller).

[preempt]: https://wiki.linuxfoundation.org/realtime/start
[info-center]: http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/Home.htm
[book]: https://github.com/rust-lang/book/tree/master/src
