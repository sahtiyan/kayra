#ifndef PARSER_H
#define PARSER_H

#include "../include/Lexer.h"
#include <vector>

class Parser {
private:
    std::vector<Token> tokens;
    size_t position;

public:
    Parser(std::vector<Token> t);

    void parse();

private:
    void parseMainFunction();
    void parseKeyword();
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
    void parseSwitchStatement();
    void parseBreakStatement();
    void parseContinueStatement();
    void parseNewKeyword();
    void parseThisKeyword();
    void parseVoid();
    void parseEnum();
    void parseStruct();
    void parseUnion();
    void parseAssignment();
    void parseComparison();
    void parseLogical();
    void parseBitwise();
    void parseOperator();
    void parseDelimiter();
    void parseComma();
    void parseSemicolon();
    void parseDot();
};

#endif // PARSER_H
