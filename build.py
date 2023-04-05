#!/usr/bin/env python3
import pathlib
import nanobuild as nb

env = nb.Environment(
    AS = 'nasm',
    CC = '/usr/local/bin/cross/bin/i686-elf-gcc',
    #CXX = '/usr/local/bin/cross/bin/i686-elf-g++',

    ASFLAGS = ['-felf32'],
    CCFLAGS = ['-I', 'src/base/sdk', '-std=gnu99', '-ffreestanding', '-O2', '-Wall', '-Wextra', '-nostdlib'],
    #CXXFLAGS = ['-std=c++03', '-ffreestanding', '-O2', '-Wall', '-Wextra', '-fno-exceptions', '-fno-rtti']
    LINKFLAGS = ['-T', 'src/base/esos/linker.ld', '-nostdlib', '-ffreestanding', '-O2', '-lgcc']
)

c99_sources = env.source_glob('**/*.c')
c99_headers = env.source_glob('**/*.h')

#cxx_sources = env.source_glob('**/*.cpp')
#cxx_headers = env.source_glob('**/*.hpp')

c99_objects = env.CC(c99_sources, deps=c99_headers)
#cxx_objects = env.CXX(cxx_sources, deps=cxx_headers)

entry_source = env.source_glob("src/base/esos/ia32/entry.asm")
entry_object = env.AS(entry_source)

crti_source = env.source_glob("src/base/esos/crti.asm")
crti_object = env.AS(crti_source)

crtn_source = env.source_glob("src/base/esos/crtn.asm")
crtn_object = env.AS(crtn_source)

objects = [
    entry_object,
    crti_object,
    pathlib.Path("/usr/local/bin/cross/lib64/gcc/i686-elf/12.2.0/crtbegin.o"),
    c99_objects,
    pathlib.Path("/usr/local/bin/cross/lib64/gcc/i686-elf/12.2.0/crtend.o"),
    crtn_object,
]

binary = env.CCLink(objects, 'ekernel.bin')

nb.run(binary)