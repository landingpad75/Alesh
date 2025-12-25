#include <print> 
#include <fstream>
#include <sstream>
#include <string>
#include "lexer/lexer.hpp"

std::string readFile(std::string fn) {
    std::ifstream input(fn);

    if(!input.is_open()){
        return "";
    }

    std::stringstream ss;
    ss << input.rdbuf();

    return ss.str();
}

int main(int argc, char* argv[], char* envp[]) {
    if(argc < 2) return -1;

    Lexer lexer(readFile(argv[1]));

    lexer.tokenize();

    return 0;
}