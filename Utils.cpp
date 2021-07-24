#pragma once
#include "Utils.h"

string regex_all(string replacedStr, regex pattern, string replaceStr) {
    string regex_result = regex_replace(replacedStr, pattern, replaceStr);
    return regex_result;
}

string replaceStr(string& replacedStr, string from, string to) {
    const unsigned int pos = replacedStr.find(from);
    const int len = from.length();

    if (pos == string::npos || from.empty()) {
        return replacedStr;
    }

    return replacedStr.replace(pos, len, to);
}

int _path(string fpath) {
    int path_i = fpath.find_last_of("\\") + 1;    //    �t�@�C���p�X����A�Ō�̃f�B���N�g�����܂ł��������擾
    return path_i;
}
int _ext(string fpath) {
    int ext_i = fpath.find_last_of(".");        //    �t�@�C���p�X����A�Ō��.�܂ł̕������擾
    return ext_i;
}

string get_ext(string path) {
    string extname = path.substr(_ext(path));    //    �g���q�擾
    return extname;
}
string get_filename(string path) {
    string filename = path.substr(_path(path), _ext(path) - _path(path));    //    �t�@�C�����擾
    return filename;
}