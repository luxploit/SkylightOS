/* klog.h
 * Created on Wed Apr 12 2023 by Laura Raine (lnkexploit)
 * Codename "Esaul" Operating System
 * Copyright (c) 2023 - SkylightOS Project
*/

void klog_info(const char* module, const char* message, ...);
void klog_warning(const char* module, const char* message, ...);
void klog_error(const char* module, const char* message, ...);
void klog_debug(const char* module, const char* message, ...);
void klog_fatal(const char* module, const char* message, ...);