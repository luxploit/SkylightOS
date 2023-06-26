#include <string>

using namespace std;

// supplementary functions
int exec(string command);

// actual commands
int buildcommand();
int rebuildcommand();
int cleancommand();
int buildisocommand();
int vmcommand();
int vmdbgcommand();
int cfgwritecommand(string cfg);
int majorwritecommand();
int minorwritecommand();
int revwritecommand();
