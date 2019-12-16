# Introduction

> Note: This edition of the book is the same as [The Rust Programming
> Language][nsprust] available in print and ebook format from [No Starch
> Press][nsp].

[nsprust]: https://nostarch.com/rust
[nsp]: https://nostarch.com/

Welcome to *PLCnext Control for Programmers*, an introductory book about programming on the PLCnext Control platform.

## What Is PLCnext Control?

PLCnext Control refers to a range of embedded computers from Phoenix Contact, which are designed for automating industrial processes. These controllers share some characteristics with single-board computers like Raspberry Pi and Arduino, but PLCnext Control includes features that make it particularly suitable for industrial applications.

The PLCnext Control range includes the following hardware variants from the AXC<sup>1</sup> and RFC<sup>2</sup> range:

- AXC F 1152 (Cortex ARM)
- AXC F 2152 (Cortex ARM )
- AXC F 3152 (Cortex ARM )
- RFC 4072S (Intel i5)

A comparison of these controllers is available ... (where)

Each of these hardware platforms runs custom firmware that is based on a standard Linux kernel. Over time, this firmware can be upgraded by the user, if required. In general, newer firmware will only add non-breaking features and bug-fixes to older versions, so applications that are designed for a specific firmware version should (generally) be able to run on newer firmware versions without modification.

## Who PLCnext Control Is For

PLCnext Control is ideal for software and systems engineers involved in the automation of industrial processes.

Controllers from the PLCnext Control range can perform the role of traditional PLCs<sup>3</sup>, however they also include features that will be familiar to software engineers with a more general programming background.

### IEC 61131-3 software developers

Traditional PLCs generally can be programmed using any language defined by the IEC 61131-3 standard. Controllers from the PLCnext Control range are no different. For these developers, Phoenix Contact provides PLCnext Engineer software.

### Matlab Simulink software developers

(something here)

### Software engineers with experience in C/C++, Rust, C#, Java, Python, Javascript, HTML5, Go, ....

(something here) - including support tools (SDKs, add-ins for Visual Studio and Eclipse).

### Systems engineers and systems administrators

It is possible to simply install and configure pre-built applications on a PLCnext Control, without any major software engineering effort.

### Project teams with some or all of the above skills

PLCnext Control includes unique features - such as the Global Data Space (GDS) and the Execution and Synchronisation Manager (ESM) - that make it possible to combine components written in different languages into a single application.

## Who This Book Is For

(change the next sentence - we will mention PLCnext Engineer)
This book is not for IEC 61131-3 programmers (sorry). These programmers will find a familiar environment in PLCnext Engineer, and there are resources from Phoenix Contact that will help you get started with PLCnext Engineer software.

This book is for software engineers with more general programming experience. The book starts with a small python program, but otherwise uses C++ to demonstrate the features of PLCnext Control. C++ is used because PLCnext Control provides a C++ programming framework, and many of the open-source projects that are suitable for PLCnext Control projects are also written in C++. However, software engineers with other programming skills should be able to apply the principles found in this book to their language of choice. For these programmers, appendix ? gives references to language-specific resources.

## What You Will Need

Obviously, you will need a controller from the PLCnext Control range. These are available for purchase from your local Phoenix Contact subsidiary, or from a number of online automation resellers. You will need to power the PLC with a 24 VDC supply. A good option is the PLCnext Starter Kit, which includes an AXC F 2152 controller, a 24 VDC power supply unit with pre-wired mains plug, and digital and analog I/O modules.

Most sections of this book apply to all PLCnext Control hardware variants. Where hardware-specific features are used, this will be mentioned in the relevant section.

The PLCnext Control is a *target* (in embedded programming terminology), and it requires a *host*. This book uses Debian 9 as the host machine, but any popular Linux distribution - or even Microsoft Windows - should also work. The host machine must be connected to the internet. The host machine requires certain software development tools to be installed, and these will be described in the relevant sections of this book.

The controller must be connected to a local area network with access to both the internet and the host machine. Note that the controller does not include a wireless network adapter.

> Note: Throughout this book, the PLCnext Control will be referred to as either *PLC*, or *controller*, or *target*. In this book, these terms all refer to precisely the same device.

## How to Use This Book

This book should be read from front to back. It is not intended to be an authoritative reference; that is provided by the [PLCnext Technology Info Centre](http://plcnext-infocenter.s3-website.eu-central-1.amazonaws.com/PLCnext_Technology_InfoCenter/PLCnext_Technology_InfoCenter/Home.htm). Instead, this book will draw on material in relevant sections of the Info Center to build up the readers knowledge in small steps.

(something about skipping chapters, if they are not relevant)

> ### Command Line Notation
>
> Throughout this book, you will see commands that must be entered into a terminal on either the host or the target. Commands in a terminal on the host all start with `$` (you don’t need to enter the `$` character).
> Commands in a terminal on the target all start with `#` instead of `$` (you don’t need to enter the `#` character).
> Lines that don’t start with `$` or `#` typically show the output of the previous command.






You’ll find two kinds of chapters in this book: concept chapters and project
chapters. In concept chapters, you’ll learn about an aspect of Rust. In project
chapters, we’ll build small programs together, applying what you’ve learned so
far. Chapters 2, 12, and 20 are project chapters; the rest are concept chapters.

Chapter 1 explains how to install Rust, how to write a “Hello, world!” program,
and how to use Cargo, Rust’s package manager and build tool. Chapter 2 is a
hands-on introduction to the Rust language. Here we cover concepts at a high
level, and later chapters will provide additional detail. If you want to get
your hands dirty right away, Chapter 2 is the place for that. At first, you
might even want to skip Chapter 3, which covers Rust features similar to those
of other programming languages, and head straight to Chapter 4 to learn about
Rust’s ownership system. However, if you’re a particularly meticulous learner
who prefers to learn every detail before moving on to the next, you might want
to skip Chapter 2 and go straight to Chapter 3, returning to Chapter 2 when
you’d like to work on a project applying the details you’ve learned.

Chapter 5 discusses structs and methods, and Chapter 6 covers enums, `match`
expressions, and the `if let` control flow construct. You’ll use structs and
enums to make custom types in Rust.

In Chapter 7, you’ll learn about Rust’s module system and about privacy rules
for organizing your code and its public Application Programming Interface
(API). Chapter 8 discusses some common collection data structures that the
standard library provides, such as vectors, strings, and hash maps. Chapter 9
explores Rust’s error-handling philosophy and techniques.

Chapter 10 digs into generics, traits, and lifetimes, which give you the power
to define code that applies to multiple types. Chapter 11 is all about testing,
which even with Rust’s safety guarantees is necessary to ensure your program’s
logic is correct. In Chapter 12, we’ll build our own implementation of a subset
of functionality from the `grep` command line tool that searches for text
within files. For this, we’ll use many of the concepts we discussed in the
previous chapters.

Chapter 13 explores closures and iterators: features of Rust that come from
functional programming languages. In Chapter 14, we’ll examine Cargo in more
depth and talk about best practices for sharing your libraries with others.
Chapter 15 discusses smart pointers that the standard library provides and the
traits that enable their functionality.

In Chapter 16, we’ll walk through different models of concurrent programming
and talk about how Rust helps you to program in multiple threads fearlessly.
Chapter 17 looks at how Rust idioms compare to object-oriented programming
principles you might be familiar with.

Chapter 18 is a reference on patterns and pattern matching, which are powerful
ways of expressing ideas throughout Rust programs. Chapter 19 contains a
smorgasbord of advanced topics of interest, including unsafe Rust, macros, and
more about lifetimes, traits, types, functions, and closures.

In Chapter 20, we’ll complete a project in which we’ll implement a low-level
multithreaded web server!

Finally, some appendixes contain useful information about the language in a
more reference-like format. Appendix A covers Rust’s keywords, Appendix B
covers Rust’s operators and symbols, Appendix C covers derivable traits
provided by the standard library, Appendix D covers some useful development
tools, and Appendix E explains Rust editions.

There is no wrong way to read this book: if you want to skip ahead, go for it!
You might have to jump back to earlier chapters if you experience any
confusion. But do whatever works for you.

<span id="ferris"></span>

An important part of the process of learning Rust is learning how to read the
error messages the compiler displays: these will guide you toward working code.
As such, we’ll provide many examples that don’t compile along with the error
message the compiler will show you in each situation. Know that if you enter
and run a random example, it may not compile! Make sure you read the
surrounding text to see whether the example you’re trying to run is meant to
error. Ferris will also help you distinguish code that isn’t meant to work:

| Ferris                                                                 | Meaning                                          |
|------------------------------------------------------------------------|--------------------------------------------------|
| <img src="img/ferris/does_not_compile.svg" class="ferris-explain"/>    | This code does not compile!                      |
| <img src="img/ferris/panics.svg" class="ferris-explain"/>              | This code panics!                                |
| <img src="img/ferris/unsafe.svg" class="ferris-explain"/>              | This code block contains unsafe code.            |
| <img src="img/ferris/not_desired_behavior.svg" class="ferris-explain"/>| This code does not produce the desired behavior. |

In most situations, we’ll lead you to the correct version of any code that
doesn’t compile.

## Source Code

The source files from which this book is generated can be found on
[GitHub][book].

[book]: https://github.com/rust-lang/book/tree/master/src

---

<sup>1</sup> *AXC* is short for *Axioline Controller*, indicating that the controller has a dedicated hardware interface to connect directly to the Axioline range of I/O modules. *Axioline* is derived from the terms *AutomationWorx* (AX), a brand name used by Phoenix Contact, and *I/O*, meaning *Input/Output*. The term *line* can be taken to refer to a line of products, but in this case it was inherited from an earlier range of Phoenix Contact products called *Inline*, so named because the I/O modules are assembled in a linear arrangement.

<sup>2</sup> *RFC* is short for *Remote Field Controller*. Unlike Axioline controllers, RFCs can only control *remote* I/O modules over a *field bus* like Profinet.
