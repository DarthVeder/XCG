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

Aircraft parseCfgFile(ifstream &ac_file);
double setValue(string &line, string &name);

#endif /* PARSER_H_INCLUDED */
