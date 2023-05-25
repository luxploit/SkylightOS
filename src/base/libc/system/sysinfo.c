/* sysinfo.c
 * Created on Thu May 25 2023 by Seal Sealy (seal331)
 * Codename "Esaul" Operating System
 * Copyright (c) 2023 - SkylightOS Project
*/

#include <sysinfo.h>
#include <system/osver.h>

struct systeminfo sysinfo() {
	struct systeminfo info;
	info.buildnum = bnum;
	info.buildtype = btype;
	info.buildlab = lab;
	info.cpuarch = barch;
	info.builddate = btime;
	return info;
}
