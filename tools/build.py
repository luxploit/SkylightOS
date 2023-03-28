#!/usr/bin/env python3
import nanobuild as nb

env = nb.Environment(
    AS = 'nasm',
    CC = '/usr/local/bin/cross/bin/i686-elf-gcc',
    #CXX = '/usr/local/bin/cross/bin/i686-elf-g++',

    ASFLAGS = ['-felf32'],
    CCFLAGS = ['-std=gnu99', '-ffreestanding', '-O2', '-Wall', '-Wextra', '-nostdlib'],
    #CXXFLAGS = ['-std=c++03', '-ffreestanding', '-O2', '-Wall', '-Wextra', '-fno-exceptions', '-fno-rtti']
    LINKFLAGS = ['-T', 'target/linker/ia32_linker.ld', '-nostdlib', '-ffreestanding', '-O2', '-lgcc']
)

asm_sources = env.source_glob('**/*.asm')

c99_sources = env.source_glob('**/*.c')
c99_headers = env.source_glob('**/*.h')

#cxx_sources = env.source_glob('**/*.cpp')
#cxx_headers = env.source_glob('**/*.hpp')

asm_objects = env.AS(asm_sources)
c99_objects = env.CC(c99_sources, deps=c99_headers)
#cxx_objects = env.CXX(cxx_sources, deps=cxx_headers)

binary = env.CCLink([asm_objects, c99_objects], 'ekernel.bin')

nb.run(binary)