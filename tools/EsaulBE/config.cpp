#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int writetocfg(string cfg) {
        int line_number = 0;
        fstream read_file;
        read_file.open("../build/config.py");
        if (read_file.fail()) {
                cout << "Error opening config file for reading." << endl;
                return 1;
        }
        vector<string> lines;
        string line;
        while (getline(read_file, line)) {
                lines.push_back(line);
        }
        read_file.close();
        ofstream write_file;
        write_file.open("../build/config.py");
        if (write_file.fail()) {
                cout << "Error opening config file for writing." << endl;
                return 1;
        }
        for (int i = 0; i < lines.size(); i++) {
                if (i != line_number) {
                        write_file << lines[i] << endl;
                } else {
                        string tmp;
                        tmp = "config='" + cfg + "'";
                        write_file << tmp << endl;
                }
        }
        write_file.close();
	return 0;
}

int cfgwritecommand(string cfg) {
	if (cfg == "chk") {
		writetocfg("chk");
		cout << "If you didn't see any errors, the write has been successful." << endl;
	} else if (cfg == "fre") {
	        writetocfg("fre");
                cout << "If you didn't see any errors, the write has been successful." << endl;
	} else {
		cout << "[Error] Only chk and fre configs are supported." << endl;
	}
	return 0;
}
