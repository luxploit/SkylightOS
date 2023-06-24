/* buildinfo.h
 * Created on Thu May 25 2023 by Seal Sealy (seal331)
 * Added for Codename: "Esaul"
 * Copyright (c) 2023 - SkylightOS Project
*/

typedef struct build_info {
	char* build_version;
	char* build_codename;
	char* build_type;
	char* build_lab;
	char* build_architecture;
	char* build_date;

} build_info;

build_info buildinfo_get();
void buildinfo_display();