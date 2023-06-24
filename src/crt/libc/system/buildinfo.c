/* buildinfo.c
 * Created on Thu May 25 2023 by Seal Sealy (seal331)
 * Added for Codename: "Esaul"
 * Copyright (c) 2023 - SkylightOS Project
*/

#include <system/buildinfo.h>
#include <system/osver.h>
#include <kernel/debug/klog.h>
#include <kernel/debug/kstdio.h>

build_info buildinfo_get() {
	build_info info;

	info.build_architecture = bld_arch;
	info.build_codename = bld_codename;
	info.build_date = bld_time;
	info.build_lab = bld_lab;
	info.build_type = bld_type;
	info.build_version = bld_version;

	return info;
}

void buildinfo_display() {
	build_info bld_info = buildinfo_get();

	kprintf("SkylightOS - Build %s.%s(%s).%s.%s\n", 
		bld_info.build_version, 
		bld_info.build_architecture,
		bld_info.build_type,
		bld_info.build_lab,
		bld_info.build_date
	);
}