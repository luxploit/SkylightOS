#!/usr/bin/python3
from os import chdir, popen
from os import path as ospath
from sys import *
import importlib.util as omport
from datetime import datetime

abspath = ospath.abspath(__file__)
dname = ospath.dirname(abspath)
chdir(dname)

if ospath.isfile("SConstruct"):
    print('ERR: you are not running this script from the root SkylightOS directory')
    exit(1)

spec = omport.spec_from_file_location(
  "configo", dname + "/../build/config.py")

configo = omport.module_from_spec(spec)
spec.loader.exec_module(configo)

# if for some reason you need to override the automatic build number bump put it here instead of SPECIAL_NO
build_num_manual_override="SPECIAL_NO"

if len(argv) != 2:
    print(f'Usage: {argv[0]} read|update')
    exit(1)

if argv[1] == "read":
    with open(dname + "/../src/base/sdk/system/osver.h", "a+") as osver_h:
        osver_h.seek(0)
        lines = osver_h.readlines()
        line = lines[7]
        if "fre" in line:
            print("fre")
            exit(0)
        elif "chk" in line:
            print("chk")
            exit(0)
        else:
            print("ERR: unable to find the build type! Is osver.h corrupt?")
            exit(1)

elif argv[1] == "update":
    with open(dname + '/../src/base/sdk/system/osver.h') as f1:
        lines = f1.readlines()
        bnum = lines[-1]
        bnum = bnum.strip()
        bnum = bnum[14:]
        bnum = bnum[:-1]
        bnum = int(float(bnum))
    with open(dname + '/../src/base/sdk/system/osver.h', 'w') as f2:
        f2.writelines(lines[:-5])
        f2.write(f'#define btype "{configo.config}"\n')
        f2.write(f'#define lab "{popen("git symbolic-ref --short HEAD").read().strip()}"\n')
        f2.write(f'#define barch "{configo.arch}"\n')
        stamp = datetime.today().strftime('%Y%m%d-%H%M')
        f2.write(f'#define btime "{stamp}"\n')
        if build_num_manual_override != "SPECIAL_NO":
            f2.write(f'#define bnum "{str(build_num_manual_override)}"\n')
        else:
            f2.write(f'#define bnum "{str(bnum + 1)}.0"\n')

exit(0)
