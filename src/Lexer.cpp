#include "../includes/Lexer.h"

Lexer::Lexer(const char* src) {
    this->counter = 0;
    this->line = 0;
    srcCode = src;
    current = srcCode[0];
}
Lexer::~Lexer() {}

void Lexer::Lex() {
    while(this->counter != strlen(this->srcCode)) {
        while(is_space(current) && this->counter != strlen(this->srcCode)) advanceLexer();
        while(is_digit(current) && this->counter != strlen(this->srcCode))  {
            std::cout << "Number: " << current << std::endl;
            advanceLexer();
        }
        while(is_space(current) && this->counter != strlen(this->srcCode)) advanceLexer();
        while(is_identifier_char(current) && this->counter != strlen(this->srcCode)) {
            std::cout << "Iden: " << current << std::endl;
            advanceLexer();
        }
        while(is_space(current) && this->counter != strlen(this->srcCode)) advanceLexer();
        while(!is_digit(current) && !is_identifier_char(current) && this->counter != strlen(this->srcCode)) {
            std::cout << "Unknown: " << current << std::endl;
            advanceLexer();
        }
        
    }
    
}

void Lexer::advanceLexer() {
    this->current = this->srcCode[++this->counter]; 
}