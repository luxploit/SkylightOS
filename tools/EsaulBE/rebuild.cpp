#include "commands.h"

using namespace std;

int rebuildcommand() {
	return exec("cd ../.. && scons -c && scons");
}
