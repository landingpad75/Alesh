#include <ast/ast.hpp>
#include "parser.hpp"

Expression(ProgramRoot) buildAST(std::string& sourceCode);

bool Parser::notEOF(){
    return tokens[pos].kind != TokenType::_EOF;
}

Token Parser::get(){
    return tokens[pos];
}

Token Parser::eat(){
    lastToken = get();
    pos++;
    return lastToken;
}

Token Parser::prev(){
    return lastToken;
}

Token Parser::peek() {
    return tokens[pos + 1];
}

BaseExpression parseStatement();
BaseExpression parseFunction();
BaseExpression parseVariables();
BaseExpression parseAssignment();
BaseExpression parseExpression();
BaseExpression parseMultiplication();
BaseExpression parseAddition();
BaseExpression parsePrimary();