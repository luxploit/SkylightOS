#include "commands.h"
#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

static bool exists(const string &Filename)
{
    return access( Filename.c_str(), 0 ) == 0;
}

int vmcommand() {
	string isopath = "../../publish/skylight.iso";
	if (!exists(isopath)) {
		cout << "[Error] ISO not found! Please build the ISO." << endl;
		return 1;
	} else {
		return exec("cd ../.. && tools/vm.sh");
	}
}
