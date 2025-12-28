#pragma once
#include <unordered_map>
#include <string>

#define stringifyTKT(x) #x

enum class TokenType {
    String,
    Number,
    Identifier,

    Equals,
    OpenParen,
    CloseParen,
    OpenBrace,
    CloseBrace,
    Semicolon,
    Colon,
    Comma,
    Ampersand,
    ExclamationMark,
    Plus,
    
    Function,
    Import,
    Return,

    _EOF
};

struct Token {
    int l, c; // line, column

    std::string value; // value must be a string since the whole file is a string
    TokenType kind; // Token Kind (e.g. Return)

    Token() {}
    Token(TokenType type) : kind(type), value(""), l(0), c(0) {}
    Token(TokenType type, std::string val) : kind(type), value(val), l(0), c(0) {}
    Token(TokenType type, std::string val, int line, int col) : kind(type), value(val), l(line), c(col) {}
    Token(TokenType type, char val, int line, int col) : kind(type), value(std::to_string(val)), l(line), c(col) {}
};

template<typename T, typename K>
using list = std::unordered_map<T, K>;

static list<std::string, TokenType> keywords = {
    {"fn", TokenType::Function},
    {"import", TokenType::Import},
    {"return", TokenType::Return}
};