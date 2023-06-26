#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int writetoscript(string revision, int linenum) {
        int line_number = linenum;
        fstream read_file;
        read_file.open("../build/new_osver.py");
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
        write_file.open("../build/new_osver.py");
        if (write_file.fail()) {
                cout << "Error opening config file for writing." << endl;
                return 1;
        }
        for (int i = 0; i < lines.size(); i++) {
                if (i != line_number) {
                        write_file << lines[i] << endl;
                } else {
                        string tmp;
			if (linenum == 18) {
                            tmp = "current_os_major_ver = \"" + revision + "\"";
			} else if (linenum == 19) {
                            tmp = "current_os_minor_ver = \"" + revision + "\"";
                        } else if (linenum == 20) {
                            tmp = "current_os_revision = \"" + revision + "\"";
                        }
                        write_file << tmp << endl;
                }
        }
        write_file.close();
	return 0;
}

int majorwritecommand() {
	cout << "Please enter the desired major version number." << endl;
        cout << "EsaulBE/majorwrite> ";
        string majornum;
        cin >> majornum;
        writetoscript(majornum, 18);
        cout << "If you didn't see any errors, the write has been successful." << endl;
	return 0;
}

int minorwritecommand() {
        cout << "Please enter the desired minor version number." << endl;
        cout << "EsaulBE/minorwrite> ";
        string minornum;
        cin >> minornum;
        writetoscript(minornum, 19);
        cout << "If you didn't see any errors, the write has been successful." << endl;
        return 0;
}

int revwritecommand() {
        cout << "Please enter the desired revision number." << endl;
        cout << "EsaulBE/revwrite> ";
        string revnum;
        cin >> revnum;
        writetoscript(revnum, 20);
        cout << "If you didn't see any errors, the write has been successful." << endl;
        return 0;
}
