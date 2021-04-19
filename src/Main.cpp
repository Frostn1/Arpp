#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <io.h>
#include "../includes/Utils.h"
#include "../includes/ErrorHandle.h"
#include "../includes/Lexer.h"
#include <vector>
#include <algorithm>



int main(int argc, char** argv) {
    std::vector<char> flags;
    int i = 1;
    for (i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help"))
            printHelp();
        else if (!strcmp(argv[i], "-l") || !strcmp(argv[i], "--lex")) {
            std::find(flags.begin(), flags.end(), 'l') == flags.end() ? flags.push_back('l') : throwError("multiple same flags given");
        }
        else break;
    }
    if (argc - 1 == flags.size()) throwError("missing file input");
    if (i != argc - 1) throwError("arguments order is misaligned");
    if (_access(argv[argc - 1], 0) == -1) throwError("file doesn't exist");
    
    
    std::ifstream ifs(argv[argc-1]);
    std::string code((std::istreambuf_iterator<char>(ifs)),
        (std::istreambuf_iterator<char>()));
    Lexer lex(code.c_str());
    lex.Lex();    
    
    
    return 0;
}