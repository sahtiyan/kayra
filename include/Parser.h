#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include "Lexer.h"

class Parser {
private:
    std::vector<Token> tokens;
    size_t position;

public:
    Parser(std::vector<Token> t);

    void parse();

private:
    void parseKeyword();
    void parseMainFunction();
    void parseIntegerDeclaration();
    void parseFloatDeclaration();
    void parseStringDeclaration();
    void parseArrayDeclaration();
    void parseIfStatement();
    void parseElseStatement();
    void parseLoopStatement();
    void parseReturnStatement(); // "dönüş" anahtarını işlemek için fonksiyon eklendi
    void parseInteger();
    void parseFloat();
    void parseString();
    void parseDelimiter();
    void parseOperator();
};

#endif // PARSER_H
