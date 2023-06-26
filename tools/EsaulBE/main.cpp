#include <iostream>
#include <string>
#include "commands.h"

using namespace std;

int main() {
	cout << "SkylightOS Build Environment - For Internal Development Only" << endl;
	cout << "(C) SkylightOS Development Team, 2023" << endl;
	while (1) {
		cout << "EsaulBE> ";
		string command;
		cin >> command;
		if (command == "build") {
                        buildcommand();
		} else if (command == "rebuild") {
                        rebuildcommand();
		} else if (command == "clean") {
                        cleancommand();
		} else if (command == "buildiso") {
                        buildisocommand();
		} else if (command == "vm") {
                        vmcommand();
                } else if (command == "vmdbg") {
                        vmdbgcommand();
		} else if (command == "cfgwrite") {
			cout << "Please enter the desired configuration (chk/fre)." << endl;
			cout << "EsaulBE/cfgwrite> ";
			string cfgtype;
			cin >> cfgtype;
                        cfgwritecommand(cfgtype);
		} else if (command == "majorwrite") {
			majorwritecommand();
		} else if (command == "minorwrite") {
                        minorwritecommand();
		} else if (command == "revwrite") {
                        revwritecommand();
		} else if (command == "quit") {
			return 0;
		} else {
			cout << "Unknown command! Please recheck and retype." << endl;
		}
	}
}
