#include "lexer.hpp"
#include <algorithm>
#include <print>

std::string tolower(std::string s){
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
    return s;
}

bool isNumber(char c){
    return c >= '0' && c <= '9';
}

bool isEOF(char c){
    return c == '\0';
}

bool isSkippable(char c){
    return c == ' ' || c == '\n' || c == '\t' || c == '\b';
}
    
Lexer::Lexer() {
    this->code = code;
}

std::vector<Token> Lexer::tokenize(std::string code) {
    this->code = code; // Store the code in the class member
    this->pos = 0;     // Reset position for each tokenize call
    
    std::vector<Token> tokens{};
    int col = 0;
    int line = 0;
    while(pos < code.size()){ // Safer comparison
        switch(get()){
            case ')': {
                Token tk(TokenType::CloseParen, eat(), col++, line);
                tokens.push_back(tk);
            } break;
            case '(': {
                Token tk(TokenType::OpenParen, eat(), col++, line);
                tokens.push_back(tk);
            } break;
            case '}': {
                Token tk(TokenType::CloseBrace, eat(), col++, line);
                tokens.push_back(tk);
            } break;
            case '{': {
                Token tk(TokenType::OpenBrace, eat(), col++, line);
                tokens.push_back(tk);
            } break;
            case '=': {
                Token tk(TokenType::Equals, eat(), col++, line);
                tokens.push_back(tk);
            } break;
            case ';': {
                Token tk(TokenType::Semicolon, eat(), col++, line);
                tokens.push_back(tk);
            } break;
            case ':': {
                Token tk(TokenType::Colon, eat(), col++, line);
                tokens.push_back(tk);
            } break;
            case ',': {
                Token tk(TokenType::Comma, eat(), col++, line);
                tokens.push_back(tk);
            } break;
            case '&': {
                Token tk(TokenType::Ampersand, eat(), col++, line);
                tokens.push_back(tk);
            } break;
            case '!': {
                Token tk(TokenType::ExclamationMark, eat(), col++, line);
                tokens.push_back(tk);
            } break;
            case '+': {
                Token tk(TokenType::Plus, eat(), col++, line);
                tokens.push_back(tk);
            } break;
            default: {
                if(get() == '/' && peek() == '*'){
                    eat(); // consume '/'
                    eat(); // consume '*'
                    while(pos + 1 < code.size() && !(get() == '*' && peek() == '/'))
                        eat();
                    if(pos < code.size()) eat(); // consume '*'
                    if(pos < code.size()) eat(); // consume '/'
                } else if(get() == '/' && peek() == '/'){
                    while(pos < code.size() && get() != '\n')
                        eat();
                } else if(isalpha(get()) || get() == '_'){
                    std::string buffer = "";
                    int start = pos;
                    while(pos < code.size() && (isalnum(get()) || get() == '_'))
                        buffer += eat();

                    if(keywords.find(buffer) == keywords.end()){
                        Token tk(TokenType::Identifier, buffer, line, col++);
                        tokens.push_back(tk);
                    } else {
                        Token tk(keywords[buffer], buffer);
                        tokens.push_back(tk);
                    }
                } else if(isdigit(get())){
                    std::string buffer = "";
                    while(pos < code.size() && isdigit(get()))
                        buffer += eat();

                    tokens.push_back(Token(TokenType::Number, buffer));
                } else if(isSkippable(get())){
                    eat();
                } else {
                    std::print("Unknown token found {}", get());                
                    exit(-2);
                }
            } break;
        }
    }
    tokens.push_back(Token(TokenType::_EOF));

    return tokens;
}

char Lexer::eat(){
    if(pos >= code.size()) return '\0';
    return code[pos++];
}

char Lexer::peek(){
    if(pos + 1 >= code.size()) return '\0';
    return code[pos+1];
}

void Lexer::set(int l, int c){
    // not used yet
}

char Lexer::get(){
    if(pos >= code.size()) return '\0';
    return code[pos];
}

/*
OLD:
#include "lexer.hpp"
#include <algorithm>
#include <print>

std::string tolower(std::string s){
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
    return s;
}

bool isNumber(char c){
    return c >= '0' && c <= '9';
}

bool isEOF(char c){
    return c == '\0';
}

bool isSkippable(char c){
    return c == ' ' || c == '\n' || c == '\t' || c == '\b';
}
    
Lexer::Lexer() {
    this->code = code;
}

std::vector<Token> Lexer::tokenize(std::string code) { // the errors message in english -> main.cpp
    std::vector<Token> tokens{};
    int col = 0;
    int line = 0;
    while(code.size() > pos){
        switch(get()){
            case ')': {
                Token tk(TokenType::CloseParen, eat(), col++, line);
                tokens.push_back(tk);
            } break;
            case '(': {
                Token tk(TokenType::OpenParen, eat(), col++, line);
                tokens.push_back(tk);
            } break;
            case '}': {
                Token tk(TokenType::CloseBrace, eat(), col++, line);
                tokens.push_back(tk);
            } break;
            case '{': {
                Token tk(TokenType::OpenBrace, eat(), col++, line);
                tokens.push_back(tk);
            } break;
            case '=': {
                Token tk(TokenType::Equals, eat(), col++, line);
                tokens.push_back(tk);
            } break;
            case ';': {
                Token tk(TokenType::Semicolon, eat(), col++, line);
                tokens.push_back(tk);
            } break;
            case ':': {
                Token tk(TokenType::Colon, eat(), col++, line);
                tokens.push_back(tk);
            } break;
            case ',': {
                Token tk(TokenType::Comma, eat(), col++, line);
                tokens.push_back(tk);
            } break;
            case '&': {
                Token tk(TokenType::Ampersand, eat(), col++, line);
                tokens.push_back(tk);
            } break;
            case '!': {
                Token tk(TokenType::ExclamationMark, eat(), col++, line);
                tokens.push_back(tk);
            } break;
            case '+': {
                Token tk(TokenType::Plus, eat(), col++, line);
                tokens.push_back(tk);
            } break;
            default: {
                if(get() == '/' && peek() == '*'){
                    while(get() != '*' && peek() == '/')
                        eat();
                    eat();
                    eat();
                } else if(get() == '/' || peek() == '/'){
                    while(get() != '\n')
                        eat();
                } else if(isalpha(get()) || get() == '_'){
                    std::string buffer = ""; // is bro dead? (17:38) | yes sir bro's dead (19:25) waiting since 15:07 btw
                    int start = pos;
                    while(code.size() > pos && isalnum(get()) || get() == '_')
                        buffer += eat();

                    if(keywords.find(buffer) == keywords.end()){
                        Token tk(TokenType::Identifier, buffer, line, col++);
                        tokens.push_back(tk);
                    } else {
                        Token tk(keywords[buffer], buffer);
                        tokens.push_back(tk);
                    }
                } else if(isdigit(get())){
                    std::string buffer = "";
                    while(code.size() > pos && isdigit(get()))
                        buffer += eat();

                    tokens.push_back(Token(TokenType::Number, buffer));
                } else if(isSkippable(get())){
                    eat();
                } else {
                    std::print("Unknown token found {}", get());                
                    exit(-2);
                }
            } break;
        }
    }
    tokens.push_back(Token(TokenType::_EOF));

    return tokens;
}

char Lexer::eat(){
    return code[pos++];
}

char Lexer::peek(){
    return code[pos+1];
}

void Lexer::set(int l, int c){
    // not used yet
}

char Lexer::get(){
    return code[pos];
}
*/