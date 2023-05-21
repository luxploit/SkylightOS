<div align="center">

# SkylightOS

[![GitHub](https://img.shields.io/github/license/EthernalRaine/SkylightOS?logo=AGPL-3.0&style=plastic)](LICENSE)
![GitHub commit activity](https://img.shields.io/github/commit-activity/m/EthernalRaine/SkylightOS?style=plastic)
![Lines of code](https://img.shields.io/tokei/lines/github/EthernalRaine/SkylightOS?style=plastic)

*the lines of code are currently broken, upstream from shields.io*

</div>

*Current Codename: Esaul*

SkylightOS is a small, portable and extensible RTOS designed for a multitude of platforms. Skylight is designed from the ground up, free from any arbitrary limitations of traditional platforms. Skylight can easily be ported to a device or general platform of your liking easily and is highly extensible for developers and users alike.

**SkylightOS is not POSIX compliant by design**, this may be followed up in the future with a POSIX compliant subsystem but this is just a pipedream for now.

For a roadmap on Skylight's development, check the [SkylightOS Milestone Roadmap](https://github.com/users/EthernalRaine/projects/2)

<br>

## Build Instructions
For instructions on how to build GCC for your target architecture, check [GCC Build Docs](docs/building_gcc.md)

Prerequisites:
* Git
* Python 3.10+
* QEMU
* Netwide Assembler
* GCC for target arch
* GDB for target arch 
* Binutils
* GRUB2
* Scons (installable via pip)

For build instructions, check [SkylightOS Build Docs](docs/building_skylightos.md) for a list of all targets and architectures or browse the [docs/architectures](docs/architectures/) folder directly.

<br>

## License
<a href="https://www.gnu.org/licenses/agpl-3.0.en.html">
  <img align="right" height="96" alt="AGPL3 License" src="https://www.gnu.org/graphics/agplv3-155x51.png" />
</a>
SkylightOS is licensed under the <b>GNU Affero General Public License v3.0</b>.

The full text of the license can be accessed via [this link](https://www.gnu.org/licenses/agpl-3.0-standalone.html) and is also included in the [license](LICENSE) file of this software package.

## Credits
* [CodePulse](https://www.youtube.com/@CodePulse) for his amazing tutorial on writing a 64-bit kernel
* [Daedalus](https://www.youtube.com/@DaedalusCommunity) for his series on building an OS, helping me understand the basics a bit
* [OSDev Wiki](http://wiki.osdev.org) for the extensive documentation surrounding OS Development
* [OSDev Discord](https://discord.gg/osdev) for their support when my braincells went to get milk :p
* [EinTim](http://eintim.one) for giving me the idea and also helping me with some 0 iq issues
* [nanobyte](https://www.youtube.com/@nanobyte-dev) for his amazing "Building an OS" series and his nanobuild system
* [Le Official WGE Discord Server](https://discord.gg/C8kVCUy75g) for rating my OS and being an awesome community <3
* [RedsonBr140](https://github.com/RedsonBr140) for his excellent BlobOS terminal driver
