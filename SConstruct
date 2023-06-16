from pathlib import Path
from shutil import which
from sys import exit
from subprocess import *
from os import *
from SCons.Variables import *
from SCons.Environment import *
from SCons.Node import *

toollist = ['nasm', 'clang', 'clang++', 'strip']
for tool in toollist:
    tempvar = which(tool)
    if tempvar is None:
        print(f'ERR: required tool {tool} was not found')
        exit(1)

vars = Variables('build/config.py', ARGUMENTS) 
vars.AddVariables(
    EnumVariable('config', help='Build Configuration', default='chk', allowed_values=('chk', 'fre')),
    EnumVariable('arch', help='Target Architecture', default='ia32', allowed_values=('ia32')),
    EnumVariable('image', help='Image Type', default='bin', allowed_values=('iso', 'bin'))
)

hostenv = Environment(variables=vars,
    ENV=os.environ,

    # these are from https://github.com/nanobyte-dev/nanobyte_os/blob/master/SConstruct
    ASCOMSTR        = "[ASM]    Assembling  [$SOURCE]",
    CCCOMSTR        = "[CC]     Compiling   [$SOURCE]",
    CXXCOMSTR       = "[CXX]    Compiling   [$SOURCE]",
    SHCCCOMSTR      = "[CC]     Compiling   [$SOURCE]",
    SHCXXCOMSTR     = "[CXX]    Compiling   [$SOURCE]",
    LINKCOMSTR      = "[LINK]   Linking     [$TARGET]",
    SHLINKCOMSTR    = "[LINK]   Linking     [$TARGET]",
    ARCOMSTR        = "[AR]     Archiving   [$TARGET]",
    RANLIBCOMSTR    = "[RANLIB] Indexing    [$TARGET]"
)

if hostenv['config'] == 'chk':
    hostenv.Append(CCFLAGS = ['-O0'], ASFLAGS = ['-g'])
else :
    hostenv.Append(CCFLAGS = ['-O2'])


platform_prefix = ''
if hostenv['arch'] == 'ia32':
    platform_prefix = 'i686-elf'

print("[GEN]    Generating  [src/crt/sdk/system/osver.h]")
call(["python3", "tools/update_osver.py", "update"])

targetenv = hostenv.Clone(
    AS='nasm',
    CC = 'clang',
    CXX = 'clang++',
    LINK = 'ld.lld',
    STRIP = 'strip',

    CFLAGS = ['-std=gnu99'],
    CXXFLAGS = ['-std=gnu++03', '-fno-exceptions', '-fno-rtti'],
    CCFLAGS = ['-ffreestanding', '-Wall', '-Wextra', '-nostdlib', '-fno-builtin'],
    LINKFLAGS = ['-nostdlib', '-static', '-z', 'max-page-size=4096', '-z', 'noexecstack', '--build-id=none'],

    PROJECTDIR = hostenv.Dir('.').srcnode(),
)

if targetenv['arch'] == 'ia32':
    targetenv.Append(ASFLAGS = ['-felf32'], CCFLAGS = ['--target=i686-pc-none-elf', '-march=i686'])

Help(vars.GenerateHelpText(hostenv)) 
Export('hostenv')   
Export('targetenv') 

build_dir= 'bin/{0}_{1}'.format(targetenv['arch'], targetenv['config'])

SConscript('src/crt/libk/SConscript', variant_dir=f'{build_dir}/crt/libk', duplicate=0)    
SConscript('src/crt/libc/SConscript', variant_dir=f'{build_dir}/crt/libc', duplicate=0)    
SConscript('src/base/esos/SConscript', variant_dir=f'{build_dir}/base/esos', duplicate=0)    
