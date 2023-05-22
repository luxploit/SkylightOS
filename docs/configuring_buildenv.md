# Configuring the Build Environment

To build SkylightOS, the following packages are required:
* Clang
* Binutils
* Scons

Scons can be acquired through pip, the python package manager:
```bash
sudo pip install scons
```
Clang and Binutils can be installed through your package manager of choice. Here are some common ones:
 | Distro | Packages                                          |
|--------|---------------------------------------------------|
| Fedora | sudo dnf install clang binutils                   |
| Gentoo | sudo emerge -a sys-devel/clang sys-devel/binutils |
| Arch   | sudo pacman -S binutils clang                     |
| Debian | sudo apt install clang-15 binutils                |

You can now build SkylightOS as per the instructions in the [Compiling SkylightOS](compiling_skylightos.md) Documentation