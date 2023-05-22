from pathlib import Path
from SCons.Variables import *
from SCons.Environment import *
from SCons.Node import *

vars = Variables('config.py', ARGUMENTS) #type: ignore
vars.AddVariables(
    EnumVariable('config', help='Build Configuration', default='chk', allowed_values=('chk', 'fre')),
    EnumVariable('arch', help='Target Architecture', default='ia32', allowed_values=('ia32')),
    EnumVariable('image', help='Image Type', default='bin', allowed_values=('iso', 'bin'))
)
vars.Add('toolchain', help='Toolchain Path', default='/usr/local/bin/cross')

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

toolchain_dir = Path(hostenv['toolchain']).resolve()
toolchain_bin = Path(toolchain_dir, 'bin')

targetenv = hostenv.Clone(
    AS='nasm',
    CC = 'clang',
    CXX = 'clang++',
    LINK = f'{toolchain_bin}/{platform_prefix}-ld',
    STRIP = f'{toolchain_bin}/{platform_prefix}-strip',

    CFLAGS = ['-std=gnu99'],
    CXXFLAGS = ['-std=gnu++03', '-fno-exceptions', '-fno-rtti'],
    CCFLAGS = ['-ffreestanding', '-Wall', '-Wextra', '-nostdlib', '-fno-builtin'],
    LINKFLAGS = ['-nostdlib', '-static', '-z', 'max-page-size=4096', '-z', 'noexecstack'],

    PROJECTDIR = hostenv.Dir('.').srcnode(),
)

if targetenv['arch'] == 'ia32':
    targetenv.Append(ASFLAGS = ['-felf32'], CCFLAGS = ['--target=i686-pc-none-elf', '-march=i686'])

Help(vars.GenerateHelpText(hostenv)) #type: ignore
Export('hostenv')   #type: ignore
Export('targetenv') #type: ignore

build_dir= 'bin/{0}_{1}'.format(targetenv['arch'], targetenv['config'])

SConscript('src/base/libc/SConscript', variant_dir=f'{build_dir}/base/libc', duplicate=0)    #type: ignore
SConscript('src/base/esos/SConscript', variant_dir=f'{build_dir}/base/esos', duplicate=0)    #type: ignore
