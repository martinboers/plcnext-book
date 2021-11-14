## Installing Software

Now that you are familiar with some of the features of the Linux operating system on the PLCnext Control, lets see how you can extend the functionality of the controller by installing third-party software.

Those familiar with other Linux distributions will know about package managers like [apt][apt]. Unfortunately neither `apt` nor any eqiuvalent package manager is available on PLCnext Control devices by default. PLCnext Control firmware does include [dpkg][dpkg], but it does not include a database of installed software, so `dpkg` cannot know if any dependencies listed in a `.deb` package have already been installed with the firmware.

Various users of PLCnext Control devices have documented their own procedure for adding a package mananger to PLCnext Control devices, including `apt`, `ipkg` and `guix`. None of these are entirely problem-free, so if you decide to try this yourself- proceed with caution.

### The PLCnext Store

The recommended way to add packages to a PLCnext Control device is through the [PLCnext Store][store]. In order to install and use a package from the PLCnext Store:

- The package you need must be available in the PLCnext Store.

- The package must be installed and started from a web page, either remotely (at [plcnextstore.com][store]) or on the controller's local [web-based management][wbm] page. Package installation from the PLCnext Store cannot currently be automated.

- In most cases, in order to use a package from the PLCnext Store, the PLCnext Runtime must be running on your PLCnext Control device at all times.

To learn more about the PLCnext Store, visit the [PLCnext Store Info Center][store-info].

### OCI Containers

Containerised design has become popular in IT applications. [OCI][oci] containers can also be run on PLCnext Control devices, using one of the following popular container engines:

- [Podman][podman]. Included with PLCnext Control firmware from version 2021.9
- [Balena Engine][balena].
- [Docker Engine][docker].

Phoenix Contact has published a [Getting Started guide][getting-started] for installing Balena and Docker on PLCnext Control devices.

### Build It Yourself

- Directly install a pre-built binary, if available. This must be built for a compatible architecture (e.g. armv7 32 bit).

- Cross-compile an open-source project using a PLCnext Control SDK.

[apt]: https://en.wikipedia.org/wiki/APT_(software)
[dpkg]: https://en.wikipedia.org/wiki/Dpkg
[store]: https://www.plcnextstore.com
[wbm]: https://www.plcnext.help/te/WBM/Administration_PLCnext_Apps.htm
[store-info]: https://store.plcnext.help/
[oci]: https://opencontainers.org/
[podman]: https://podman.io/
[balena]: https://www.balena.io/engine/
[docker]: https://www.docker.com/products/container-runtime
[getting-started]: https://github.com/PLCnext/Docker_GettingStarted
