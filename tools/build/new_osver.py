#!/usr/bin/python3

# new_osver.py
# Created on Tue Jun 20 2023 by Laura Raine (lnkexploit)
# Added for Codename: "Esaul"
# Copyright (c) 2023 - SkylightOS Project

from ast import literal_eval
from datetime import datetime
import config as esos_config
from sys import argv
from os import chdir, path, getcwd, popen
from getpass import getuser

current_directory_path = getcwd()
current_buildmachine_user = getuser() 
current_build_number = 0
current_os_codename = "Esaul"

current_os_major_ver = "1"
current_os_minor_ver = "0"
current_os_revision = "0"

osver_header_location = "src/crt/sdk/system/osver.h"

# this excludes certain accounts from the build string, ex. build machines
build_user_special_accounts = [
    "idk imma leave this empty"
]

if len(argv) != 2:
    print(f'Usage: {argv[0]} -> read | update')
    exit(1)

# change into the system root as the current working dir is tools/build
chdir(current_directory_path)

if not path.isfile('SConstruct'):
   print('[Error]: You are not running from the OS root directory! Please rerun from the correct path.')
   exit(1)

def write_define(name, value):
    return "#define {0} \"{1}\"\n".format(name, value)

def get_lab():
    branch = popen("git symbolic-ref --short HEAD").read().strip()

    for lab in build_user_special_accounts:
        if current_buildmachine_user != lab:
            return "{0}({1})".format(branch, current_buildmachine_user)
        else:
            return branch

def write_version():
    return "{0}.{1}.{2}.{3}".format(current_os_major_ver, current_os_minor_ver, current_build_number+1, current_os_revision)

match argv[1]:
    case "read_config":
        print(f'{esos_config.config}')    
    case "read_arch":
        print(f'{esos_config.arch}')
    case "get_kernel":
        match esos_config.config:
            case "fre": print("ekernel.elf")
            case "chk": print("chkernel.elf")
    case "update":
        if path.isfile(osver_header_location):
            with open(osver_header_location) as header:
                # readout existing build number first
                current_build_number = header.readlines()[8].strip()    # readout, select, trim
                current_build_number = current_build_number[28:]        # trim define off the number
                                                                        # 28 in this case being the number of characters between the start of the line to the version itself
                current_build_number = current_build_number[:-1]        # here we trim off of the trailing quotation mark at the end
                current_build_number = int(current_build_number)        # convert str to int
                
            with open(osver_header_location, 'w') as new_header:
                new_header.write('''/* osver.h
 * Automatically Generated
 * Added for Codename: "{0}"
 * Copyright (c) 2023 - SkylightOS Project
*/

// DO NOT TOUCH LINES BELOW - AUTOMATICALLY GENERATED - DO NOT DELETE, EVER!//

'''.format(current_os_codename))
                new_header.write(write_define("__internal_bld_num", current_build_number+1))
                new_header.write("\n")
                new_header.write(write_define("bld_type", esos_config.config))
                new_header.write(write_define("bld_lab", get_lab()))
                new_header.write(write_define("bld_arch", esos_config.arch))
                new_header.write(write_define("bld_time", datetime.today().strftime('%Y%m%d-%H%M')))
                new_header.write(write_define("bld_codename", current_os_codename))
                new_header.write(write_define("bld_version", write_version()))
                
