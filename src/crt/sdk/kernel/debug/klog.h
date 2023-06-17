/* klog.h
 * Created on Wed Apr 12 2023 by Laura Raine (lnkexploit)
 * Adding During Codename Phase: "Esaul"
 * Copyright (c) 2023 - SkylightOS Project
*/

void klog_info(const char* module, const char* message, ...);
void klog_warning(const char* module, const char* message, ...);
void klog_error(const char* module, const char* message, ...);
void klog_debug(const char* module, const char* message, ...);
void klog_fatal(const char* module, const char* message, ...);