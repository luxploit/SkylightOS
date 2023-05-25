/* sysinfo.h
 * Created on Thu May 25 2023 by Seal Sealy (seal331)
 * Codename "Esaul" Operating System
 * Copyright (c) 2023 - SkylightOS Project
*/


struct systeminfo {
	// the reason why buildnum is a char and not an int
	// is becausw we will later need to concatenate it with an str
	// and i don't feel like implementing snprintf for this
        //char[4] buildnum;
	char *buildnum;
	char *buildtype;
	char *buildlab;
	char *cpuarch;
	char *builddate;
};

struct systeminfo sysinfo();
