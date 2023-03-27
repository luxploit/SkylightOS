from SCons.Variables import *
from SCons.Environment import *
from SCons.Node import *
from pathlib import Path

vars = Variables('tools/config.py')
vars.AddVariables(
    EnumVariable("config", help="Build configuration", default="chk", allowed_values=("chk", "rel")),
    EnumVariable("arch", help="Target architecture", default="ia32", allowed_values=("ia32")),
    EnumVariable("toolchain_path", help="Toolchain Path", default="/usr/local/bin/cross"),
    EnumVariable("gcc_version", help="GCC Version Number", default="12.2.0")
)

env = Environment(variables=vars, env=os.environ)

cc_prefix = ''
if env['arch'] == 'ia32':
    cc_prefix = 'i686-elf'

toolchain_dir = Path(env['toolchain_path']).resolve()
toolchain_bin = Path(toolchain_dir, 'bin')
toolchain_lib = Path(toolchain_dir, 'lib64', 'gcc', cc_prefix, env['gcc_version'])

target = env.Clone(
    AS = 'nasm',
    AR = f'{cc_prefix}-ar',
    CC = f'{cc_prefix}-gcc',
    CXX = f'{cc_prefix}-g++',
    LD = f'{cc_prefix}-g++',
    RANLIB = f'{cc_prefix}-ranlib',
    STRIP = f'{cc_prefix}-strip',

    ASFLAGS = [
        '-f', 'elf32', '-g'
    ],
    CFLAGS = [
        '-std=gnu99'
    ],
    CCFLAGS = [
        '-ffreestanding', '-nostdlib', '-g'
    ],
    CXXFLAGS = [
        '-fno-exceptions',
        '-fno-rtti',
    ],
    LINKFLAGS = [
        '-nostdlib'
    ],
    LIBS = [
        'gcc'
    ],
    LIBPATH = [ 
        str(toolchain_lib) 
    ],
)

target.Replace(
    ASCOMSTR        = "Assembling [$SOURCE]",
    CCCOMSTR        = "Compiling  [$SOURCE]",
    CXXCOMSTR       = "Compiling  [$SOURCE]",
    FORTRANPPCOMSTR = "Compiling  [$SOURCE]",
    FORTRANCOMSTR   = "Compiling  [$SOURCE]",
    SHCCCOMSTR      = "Compiling  [$SOURCE]",
    SHCXXCOMSTR     = "Compiling  [$SOURCE]",
    LINKCOMSTR      = "Linking    [$TARGET]",
    SHLINKCOMSTR    = "Linking    [$TARGET]",
    INSTALLSTR      = "Installing [$TARGET]",
    ARCOMSTR        = "Archiving  [$TARGET]",
    RANLIBCOMSTR    = "Ranlib     [$TARGET]"
)