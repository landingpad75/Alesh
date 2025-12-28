#pragma once

#include <iostream>
#include <memory>
#include <ast/ast.hpp>
#include <lexer/lexer.hpp>
template<typename T>
    concept token = std::is_same_v<T, TokenType>;

class Parser {
public:
    explicit Parser() {}
    Expression(ProgramRoot) buildAST(std::string& sourceCode);
private:
    Lexer lexer;
    int pos = 0;
    std::vector<Token> tokens;
    Token lastToken;
    
    bool notEOF();
    Token get();
    Token eat();
    Token peek();
    Token prev();

    template <token... Args>
    Token expect(Args... args){
        Token tok = tokens[pos];
        pos++;

        bool matches = ((tok.kind == args) || ...);

        if(!matches){
            std::cout << "Unexpected token found, Found: " << stringifyTKT(tok.kind) << "\nNeeded: ";

            // look main.cpp

            exit(1); // make good error messages with color output and the program should give some help how to fix that
        }
        
        return tok;
    } 

    BaseExpression parseStatement();
    BaseExpression parseFunction();
    BaseExpression parseVariables();
    BaseExpression parseAssignment();
    BaseExpression parseExpression();
    BaseExpression parseMultiplication();
    BaseExpression parseAddition();
    BaseExpression parsePrimary();
};