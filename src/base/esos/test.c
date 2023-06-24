/* test.c
 * Created on Thu Jun 15 2023 by Laura Raine (lnkexploit)
 * Added for Codename: "Esaul"
 * Copyright (c) 2023 - SkylightOS Project
*/

#include "test.h"
#include <kernel/debug/klog.h>

void test_logger() {
    klog_info("test", "this is an info");
    klog_warning("test", "this is a warning");
    klog_error("test", "this is an error");
    klog_debug("test", "this is a debug message");
    klog_fatal("test", "this is a fatal error");
}