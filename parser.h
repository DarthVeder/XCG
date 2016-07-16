#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <assert.h>
#include "aircraft.h"

using namespace std;

const vector<string> c_type = { "//", ";" };

Aircraft parseCfgFile(ifstream &ac_file);
bool foundKeyValue(string &line, string &name, double &val);
void cleanLine(string &line);
bool isCommentLine(string &line);

#endif /* PARSER_H_INCLUDED */
