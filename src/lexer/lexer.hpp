#pragma once
#include "token.hpp"
#include <vector>

class Lexer {
public:
    Lexer(std::string code);

    std::vector<Token> tokenize();

private:
    std::string code; // we store the code here
    int pos = 0;

    char eat();
    char peek();
    void set(int l, int c);
    char get();
};