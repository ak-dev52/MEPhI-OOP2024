#include <fstream>
#include <algorithm>
#include "rlib.h"
#include <unistd.h>
#include <cstring>


bool in_check(const std::string &subword, const std::string &temp_line) {
    std::string new_line, new_subword;
    new_subword.resize(subword.size());
    new_line.resize(temp_line.size());
    std::transform(subword.begin(), subword.end(), new_subword.begin(), tolower);
    std::transform(temp_line.begin(), temp_line.end(), new_line.begin(), tolower);
    size_t pos = new_line.find(new_subword);
    return (pos != std::string::npos);
}


void cycle(std::ifstream &file, const std::string &subword) {
    int line_number = 1;
    std::string temp_line;
    while (!file.eof()) {
        if (file.bad()) {
            throw std::runtime_error("Something very bad happened to file.\n");
        }
        if (file.fail()) {
            throw std::runtime_error("File failed.\n");
        }
        std::getline(file, temp_line, '\n');
        if (in_check(subword, temp_line)) {
            std::cout << line_number << ": " << temp_line << std::endl;
        }
        ++line_number;
    }
}


bool in_check(const char *c_subword, const char *c_temp_line) {
    std::string new_c_subword = c_subword, new_c_temp_line = c_temp_line;
    std::transform(new_c_subword.begin(), new_c_subword.end(), new_c_subword.begin(), tolower);
    std::transform(new_c_temp_line.begin(), new_c_temp_line.end(), new_c_temp_line.begin(), tolower);
    size_t pos = new_c_temp_line.find(new_c_subword);
    return (pos != std::string::npos);
}


void cycle(std::ifstream &file, const char *c_subword) {
    int line_number = 1;
    std::string tmp;
    char *c_temp_line;
    while (!file.eof()) {
        if (file.bad()) {
            delete [] c_temp_line;
            throw std::runtime_error("Something very bad happened to file.\n");
        }
        if (file.fail()) {
            delete [] c_temp_line;
            throw std::runtime_error("File failed.\n");
        }
        std::getline(file, tmp, '\n');
        c_temp_line = to_char(tmp);
        if (in_check(c_subword, c_temp_line)) {
            std::cout << line_number << ": " << c_temp_line << std::endl;
        }
        delete [] c_temp_line;
        ++line_number;
    }
}
