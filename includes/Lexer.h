#include "Utils.h"
#include <iostream>
#include <string.h>
#define null '\0'

class Lexer {
    public:
        Lexer(const char* src);
        ~Lexer();

        void advanceLexer();
        void Lex();
    private:
    const char* srcCode;
    char current;
    int counter;
    int line;

};