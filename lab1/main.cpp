#include <algorithm>
#include "lib.h"


int main() {
    std::ifstream file;
    bool option;
    std::string word;
    char *cword = nullptr;
    try {
        option = menu();
        file_input(file);
        cword = subword_input(word);
        if (option) {
            cycle(file, word);
        } else {
            cycle(file, cword);
        }
    } catch (const std::exception &e) {
        file.close();
        delete [] cword;
        std::cerr << std::endl << "Error occured: " << e.what() << std::endl;
        return 1;
    }
    delete [] cword;
    file.close();
    return 0;
}
