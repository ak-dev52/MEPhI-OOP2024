#include "rlib.h"

template<typename T>
bool try_read(T &str) {
    std::cin >> str;
    if (std::cin.eof()) {
        throw std::runtime_error("EOF at the end of input.\n");
    }
    if (std::cin.bad()) {
        throw std::runtime_error("Bad input.\n");
    }
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Failed input\nEnter once more\n>>";
        return false;
    }
    return true;
}

std::string sread() {
    std::string str;
    while (!try_read(str));
    return str;
}

int int_input(int min, int max) {
    int res;
    do {
        std::cout << "Enter integer inside the segment [" << min << ";" << max << "]" << std::endl << ">>";
        while (!try_read(res));
    } while (res < min || res > max);
    return res;
}

bool menu() {
    std::cout << "How to represent input?\n1: std::string; 2: char*" << std::endl;
    if (int_input(1, 2) == 1) {
        return true;
    }
    return false;
}

void file_input(std::ifstream &file) {
    std::cout << "Enter name of file to open" << std::endl << ">>";
    std::string filename = sread();
    file.open(filename);
    file_is_OK(file, filename);
}

char *subword_input(std::string &word) {
    std::cout << "Enter word to find in the file" << std::endl << ">>";
    word = sread();
    return to_char(word);
}

void file_is_OK(std::ifstream &file, const std::string &filename) {
    char *cfile = to_char(filename);
    access(cfile, R_OK);
    if (errno == EACCES) {
        delete [] cfile;
        throw std::runtime_error("Don't have access to file.\n");
    }
    if (!file.is_open()) {
        delete [] cfile;
        throw std::runtime_error("File doesn't present.\n");
    }
    delete [] cfile;
}

char *to_char(std::string s) {
    char *res = new char[s.size() + 1];
    strcpy(res, s.c_str());
    return res;
}
