#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <regex>
#include <vector>
#include <iterator>

using namespace std;

bool shapingUAB(unsigned int option, char* targetpath, char* outputpath);
bool sortAll(char* targetpath, char* outputpath);
int _path(std::string fpath);
int _ext(std::string fpath);
string get_ext(string path);
string get_filename(string path);
string regex_all(string replacedStr, regex pattern, string replaceStr);
string replaceStr(string& replacedStr, string from, string to);