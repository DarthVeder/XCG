#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <assert.h>
#include "aircraft.h"

using namespace std;

const vector<string> c_type = { "//", ";" };

Aircraft parseCfgFile(ifstream &ac_file);
double setValue(string &line, string &name);
double setValue2(string &line, string &name);
void killWhiteSpaces(string &line);
void toLower(string &line);
void cleanLine(string &line);
bool isCommentLine(string &line);
bool isBlock(string &line, string &block_name);

#endif /* PARSER_H_INCLUDED */
