#include "commands.h"
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <algorithm>
#include <unistd.h>

using namespace std;

static string exec_getoutput(const char* cmd) {
    array<char, 128> buffer;
    string result;
    unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

static bool exists(const string &Filename)
{
    return access( Filename.c_str(), 0 ) == 0;
}

int buildisocommand() {
	string cpuarch = exec_getoutput("cd ../.. && tools/build/new_osver.py read_arch");
	string buildtype = exec_getoutput("cd ../.. && tools/build/new_osver.py read_config");
	cpuarch.erase(remove(cpuarch.begin(), cpuarch.end(), '\n'), cpuarch.cend());
	buildtype.erase(remove(buildtype.begin(), buildtype.end(), '\n'), buildtype.cend());
	string kernelpath = "../../bin/" + cpuarch + "_" + buildtype + "/base/esos/ekernel.elf";
	if (!exists(kernelpath)) {
		cout << "[Error] Kernel not found! Please rebuild the OS." << endl;
		return 1;
	} else {
		return exec("cd ../.. && tools/build_iso.sh");
	}
}
