#include "commands.h"

int buildcommand() {
	return exec("cd ../.. && scons");
}
