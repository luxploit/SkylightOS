from pathlib import Path
from shutil import which
from sys import exit
from subprocess import *
from os import *
from SCons.Variables import *
from SCons.Environment import *
from SCons.Node import *

toollist = ['nasm', 'clang', 'clang++']
for tool in toollist:
    tempvar = which(tool)
    if tempvar is None:
        print(f'ERR: required tool {tool} was not found')
        exit(1)

vars = Variables('config.py', ARGUMENTS) #type: ignore
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

toollist = [f'{platform_prefix}-ld', f'{platform_prefix}-strip']
is_binutils_built_locally = False
if not which(f'toolchain/toolchain-binaries/bin/{toollist[0]}') is None or not which(f'toolchain/toolchain-binaries/bin/{toollist[1]}') is None:
    is_binutils_built_locally = True
    binpath = Path('toolchain').resolve()
    binpath = Path(binpath, 'toolchain-binaries')
    binpath = Path(binpath, 'bin')
elif which(toollist[0]) is None or which(toollist[1]) is None:
    print(f'ERR: {platform_prefix} binutils not found or incomplete')
    print('Should we attempt to build it? (YES if you agree, any other input if not')
    answer = input()
    if answer != 'YES':
        print(f'Please install {platform_prefix} binutils and rerun scons.')
        exit(1)
    print('Alright, attempting to build binutils')
    os.chdir(f'{os.getcwd()}/tools')
    popen = Popen(['bash', 'build_binutils.sh'], stdout=PIPE, universal_newlines=True)
    for line in iter(popen.stdout.readline, ""):
        print(line, end='')
    popen.stdout.close()
    return_code = popen.wait()
    if return_code:
        print('ERR: unable to build binutils! Please review previous output and repair failure.')
        exit(1)
    is_binutils_built_locally = True
    binpath = Path('..').resolve()
    binpath = Path(binpath, 'toolchain')
    binpath = Path(binpath, 'toolchain-binaries')
    binpath = Path(binpath, 'bin')

if is_binutils_built_locally:
    linker = f'{binpath}/{platform_prefix}-ld'
    striptool = f'{binpath}/{platform_prefix}-strip'
else:
    linker=f'{platform_prefix}-ld'
    striptool = f'{platform_prefix}-strip'

targetenv = hostenv.Clone(
    AS='nasm',
    CC = 'clang',
    CXX = 'clang++',
    LINK = linker,
    STRIP = striptool,

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
