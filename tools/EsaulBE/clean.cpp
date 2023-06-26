#include "commands.h"

using namespace std;

int cleancommand() {
	return exec("cd ../.. && scons -c");
}
