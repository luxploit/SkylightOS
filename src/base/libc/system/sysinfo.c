/* sysinfo.c
 * Created on Thu May 25 2023 by Seal Sealy (seal331)
 * Codename "Esaul" Operating System
 * Copyright (c) 2023 - SkylightOS Project
*/

#include <sysinfo.h>
#include <system/osver.h>

systeminfo sysinfo() {
	systeminfo info;
	info.buildnum = bld_num;
	info.buildtype = bld_type;
	info.buildlab = bld_lab;
	info.cpuarch = bld_arch;
	info.builddate = bld_time;
	return info;
}
