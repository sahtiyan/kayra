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
    void parseReturnStatement();
    void parseObjectDeclaration();
    void parseMethodDeclaration();
    void parseOperator();
    void parseDelimiter();
    void parseAssignment();
    void parseComparison();
    void parseLogical();
    void parseBitwise();
    void parseComma();
    void parseSemicolon();
    void parseDot();
};

#endif // PARSER_H
