#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include "aircraft.h"

using namespace std;

Aircraft parseCfgFile(ifstream &ac_file);


#endif // PARSER_H_INCLUDED
