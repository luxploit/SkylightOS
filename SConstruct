from pathlib import Path
from SCons.Variables import *
from SCons.Environment import *
from SCons.Node import *

vars = Variables('tools/config.py', ARGUMENTS) #type: ignore
vars.AddVariables(
    EnumVariable('config', help='Build Configuration', default='chk', allowed_values=('chk', 'fre')),
    EnumVariable('arch', help='Target Architecture', default='ia32', allowed_values=('ia32')),
    EnumVariable('image', help='Image Type', default='bin', allowed_values=('iso', 'bin'))
)
vars.Add('toolchain', help='Toolchain Path', default='/usr/local/bin/cross')

deps = {
    'binutils' : '2.40',
    'gcc' : '12.2.0',
    'gdb' : '13.1'
}

hostenv = Environment(variables=vars,
    ENV=os.environ,

    # these are from https://github.com/nanobyte-dev/nanobyte_os/blob/master/SConstruct
    ASCOMSTR        = "Assembling [$SOURCE]",
    CCCOMSTR        = "Compiling  [$SOURCE]",
    CXXCOMSTR       = "Compiling  [$SOURCE]",
    SHCCCOMSTR      = "Compiling  [$SOURCE]",
    SHCXXCOMSTR     = "Compiling  [$SOURCE]",
    LINKCOMSTR      = "Linking    [$TARGET]",
    SHLINKCOMSTR    = "Linking    [$TARGET]"
)

if hostenv['config'] == 'chk':
    hostenv.Append(CCFLAGS = ['-O0'], ASFLAGS = ['-g'])
else :
    hostenv.Append(CCFLAGS = ['-O2'])


platform_prefix = ''
if hostenv['arch'] == 'ia32':
    platform_prefix = 'i686-elf-'

toolchain_dir = Path(hostenv['toolchain']).resolve()
toolchain_bin = Path(toolchain_dir, 'bin')
toolchain_lib = Path(toolchain_dir, 'lib', 'gcc', platform_prefix.removesuffix('-'), deps['gcc'])

targetenv = hostenv.Clone(
    AS='nasm',
    CC = f'{toolchain_bin}/{platform_prefix}gcc',
    CXX = f'{toolchain_bin}/{platform_prefix}g++',
    LD = f'{toolchain_bin}/{platform_prefix}gcc',
    STRIP = f'{toolchain_bin}/{platform_prefix}strip',

    CFLAGS = ['-std=gnu99'],
    CXXFLAGS = ['-std=c++03', '-fno-exceptions', '-fno-rtti'],
    CCFLAGS = ['-ffreestanding', '-Wall', '-Wextra', '-nostdlib'],
    LINKFLAGS = ['-nostdlib'],

    PROJECTDIR = hostenv.Dir('.').srcnode(),

    LIBGCC_TOOLCHAIN = str(toolchain_lib)
)

if targetenv['arch'] == 'ia32':
    targetenv.Append(ASFLAGS = ['-felf32'])

Help(vars.GenerateHelpText(hostenv)) #type: ignore
Export('hostenv')   #type: ignore
Export('targetenv') #type: ignore

build_dir= 'build/{0}_{1}'.format(targetenv['arch'], targetenv['config'])

SConscript('src/base/libc/SConscript', variant_dir=f'{build_dir}/base/libc', duplicate=0)    #type: ignore
SConscript('src/base/esos/SConscript', variant_dir=f'{build_dir}/base/esos', duplicate=0)    #type: ignore
