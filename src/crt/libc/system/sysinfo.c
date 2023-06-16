/* sysinfo.c
 * Created on Thu May 25 2023 by Seal Sealy (seal331)
 * Codename "Esaul" Operating System
 * Copyright (c) 2023 - SkylightOS Project
*/

#include <sysinfo.h>
#include <system/osver.h>
#include <kernel/debug/klog.h>
#include <kernel/debug/kstdio.h>

systeminfo sysinfo() {
	systeminfo info;
	info.buildmajorminor = bld_majorminor;
	info.buildnum = bld_num;
	info.buildtype = bld_type;
	info.buildlab = bld_lab;
	info.builduser = bld_user;
	info.cpuarch = bld_arch;
	info.builddate = bld_time;
	return info;
}

void sysinfo_display() {
	systeminfo sys_info = sysinfo();

	if (sys_info.builduser != "__OFFICIAL__") {
		kprintf("SkylightOS - Build %s.%s.%s(%s).%s(%s).%s\n", 
			sys_info.buildmajorminor, 
			sys_info.buildnum, 
			sys_info.cpuarch, 
			sys_info.buildtype, 
			sys_info.buildlab, 
			sys_info.builduser,
			sys_info.builddate
		);
	} else {
		kprintf("SkylightOS - Build %s.%s.%s(%s).%s.%s\n", 
			sys_info.buildmajorminor, 
			sys_info.buildnum, 
			sys_info.cpuarch, 
			sys_info.buildtype, 
			sys_info.buildlab, 
			sys_info.builddate
		);
	}
}