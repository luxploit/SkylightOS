<div align="center">

# SkylightOS

[![GitHub](https://img.shields.io/github/license/EthernalRaine/SkylightOS?logo=AGPL-3.0&style=plastic)](LICENSE)
![GitHub commit activity](https://img.shields.io/github/commit-activity/m/EthernalRaine/SkylightOS?style=plastic)
![Lines of code](https://img.shields.io/tokei/lines/github/EthernalRaine/SkylightOS?style=plastic)

</div>


*Current Codename: Esaul*

SkylightOS is a small, portable and extensible RTOS designed for a multitude of platforms. Skylight is designed to from the ground up, free from any arbitrary limitations of traditional platforms. Skylight can easily be ported to a device or general platform of your liking easily and is highly extensible for developers and users alike.

## Build Instructions
For instructions on how to build GCC for your target architecture, check [GCC Build Docs](docs/building_gcc.md)

Prerequsites:
* Git
* Python 3.7+
* QEMU
* Netwide Assembler
* GCC for target arch
* GDB for target arch 
* Binutils
* Ninja
* Nanobuild (installable via pip)

Building:
```bash
tools/build.py
```
this will produce "build/ekernel.bin" which can be loaded by QEMU using:
```bash
qemu-system-i386 -kernel build/ekernel.bin
```

<br>

## License
<a href="https://www.gnu.org/licenses/agpl-3.0.en.html">
  <img align="right" height="96" alt="AGPL3 License" src="https://www.gnu.org/graphics/agplv3-155x51.png" />
</a>
SkylightOS is licensed under the <b>GNU Affero General Public License v3.0 only</b>.

The full text of the license can be accessed via [this link](https://www.gnu.org/licenses/agpl-3.0-standalone.html) and is also included in the [license](LICENSE) file of this software package.


## Credits
* [CodePulse](https://www.youtube.com/@CodePulse) for his amazing tutorial on writing a 64-bit kernel
* [Daedalus](https://www.youtube.com/@DaedalusCommunity) for his series on building an OS, helping me understand the basics a bit
* [OSDev Wiki](http://wiki.osdev.org) for the extensive documentation surrounding OS Development
* [OSDev Discord](https://discord.gg/osdev) for their support when my braincells went to get milk :p
* [EinTim](http://eintim.one) for giving me the idea and also helping me with some 1iq issues
* [nanobyte](https://www.youtube.com/@nanobyte-dev) for his amazing "Building an OS" series and showing me alternative build systems
* [Le Official WGE Discord Server](https://discord.gg/C8kVCUy75g) for rating my OS and being an awesome community <3