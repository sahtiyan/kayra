#include "../include/Parser.h"
#include <iostream>

Parser::Parser(std::vector<Token> t) : tokens(t), position(0) {}

void Parser::parse() {
    parseMainFunction();
}

void Parser::parseMainFunction() {
    std::cout << "Ana fonksiyon işle" << std::endl;

    while (position < tokens.size()) {
        Token current_token = tokens[position];
        switch (current_token.type) {
            case TokenType::Anahtar_Kelime:
                parseKeyword();
                break;
            case TokenType::Tamsayı:
                parseIntegerDeclaration();
                break;
            case TokenType::Ondalıklı_Sayı:
                parseFloatDeclaration();
                break;
            case TokenType::Metin:
                parseStringDeclaration();
                break;
            case TokenType::Ayraç:
                parseDelimiter();
                break;
            case TokenType::Operator:
                parseOperator();
                break;
            case TokenType::Virgül:
                parseComma();
                break;
            case TokenType::Noktalı_Virgül:
                parseSemicolon();
                break;
            case TokenType::Nokta:
                parseDot();
                break;
            default:
                std::cerr << "Bilinmeyen token: " << current_token.value << std::endl;
                position++;
                break;
        }
    }
}

void Parser::parseKeyword() {
    Token keyword_token = tokens[position++];
    if (keyword_token.value == "ana") {
        parseMainFunction();
    } else if (keyword_token.value == "tam") {
        parseIntegerDeclaration();
    } else if (keyword_token.value == "gerçek") {
        parseFloatDeclaration();
    } else if (keyword_token.value == "metin") {
        parseStringDeclaration();
    } else if (keyword_token.value == "dizi") {
        parseArrayDeclaration();
    } else if (keyword_token.value == "eğer") {
        parseIfStatement();
    } else if (keyword_token.value == "değilse") {
        parseElseStatement();
    } else if (keyword_token.value == "döngü") {
        parseLoopStatement();
    } else if (keyword_token.value == "dönüş") {
        parseReturnStatement();
    } else if (keyword_token.value == "nesne") {
        parseObjectDeclaration();
    } else if (keyword_token.value == "metot") {
        parseMethodDeclaration();
    } else if (keyword_token.value == "değişim") {
        parseSwitchStatement();
    } else if (keyword_token.value == "kes") {
        parseBreakStatement();
    } else if (keyword_token.value == "devam") {
        parseContinueStatement();
    } else if (keyword_token.value == "yeni") {
        parseNewKeyword();
    } else if (keyword_token.value == "bu") {
        parseThisKeyword();
    } else if (keyword_token.value == "boş") {
        parseVoid();
    } else if (keyword_token.value == "enum") {
        parseEnum();
    } else if (keyword_token.value == "yapı") {
        parseStruct();
    } else if (keyword_token.value == "birlik") {
        parseUnion();
    }
}

void Parser::parseIntegerDeclaration() {
    std::cout << "Tamsayı tanımını işle" << std::endl;
}

void Parser::parseFloatDeclaration() {
    std::cout << "Ondalıklı sayı tanımını işle" << std::endl;
}

void Parser::parseStringDeclaration() {
    std::cout << "Metin tanımını işle" << std::endl;
}

void Parser::parseArrayDeclaration() {
    std::cout << "Dizi tanımını işle" << std::endl;
}

void Parser::parseIfStatement() {
    std::cout << "Koşul ifadesini işle" << std::endl;
}

void Parser::parseElseStatement() {
    std::cout << "Alternatif koşul ifadesini işle" << std::endl;
}

void Parser::parseLoopStatement() {
    std::cout << "Döngüyü işle" << std::endl;
}

void Parser::parseReturnStatement() {
    std::cout << "Dönüş ifadesini işle" << std::endl;
}

void Parser::parseObjectDeclaration() {
    std::cout << "Nesne tanımını işle" << std::endl;
}

void Parser::parseMethodDeclaration() {
    std::cout << "Metot tanımını işle" << std::endl;
}

void Parser::parseSwitchStatement() {
    std::cout << "Değişim ifadesini işle" << std::endl;
}

void Parser::parseBreakStatement() {
    std::cout << "Kes ifadesini işle" << std::endl;
}

void Parser::parseContinueStatement() {
    std::cout << "Devam ifadesini işle" << std::endl;
}

void Parser::parseNewKeyword() {
    std::cout << "Yeni anahtar kelimesini işle" << std::endl;
}

void Parser::parseThisKeyword() {
    std::cout << "Bu anahtar kelimesini işle" << std::endl;
}

void Parser::parseVoid() {
    std::cout << "Boş anahtar kelimesini işle" << std::endl;
}

void Parser::parseEnum() {
    std::cout << "Enum tanımını işle" << std::endl;
}

void Parser::parseStruct() {
    std::cout << "Yapı tanımını işle" << std::endl;
}

void Parser::parseUnion() {
    std::cout << "Birlik tanımını işle" << std::endl;
}

void Parser::parseAssignment() {
    std::cout << "Atama işlemini işle" << std::endl;
}

void Parser::parseComparison() {
    std::cout << "Karşılaştırma işlemini işle" << std::endl;
}

void Parser::parseLogical() {
    std::cout << "Mantıksal işlemi işle" << std::endl;
}

void Parser::parseBitwise() {
    std::cout << "Bit düzeyinde işlemi işle" << std::endl;
}

void Parser::parseOperator() {
    Token operatorToken = tokens[position++];
    if (operatorToken.value == "=") {
        parseAssignment();
    } else if (operatorToken.value == "==" || operatorToken.value == "!=" ||
               operatorToken.value == "<" || operatorToken.value == ">" ||
               operatorToken.value == "<=" || operatorToken.value == ">=") {
        parseComparison();
    } else if (operatorToken.value == "&&" || operatorToken.value == "||" || operatorToken.value == "!") {
        parseLogical();
    } else if (operatorToken.value == "&" || operatorToken.value == "|" || operatorToken.value == "^" ||
               operatorToken.value == "<<" || operatorToken.value == ">>") {
        parseBitwise();
    }
}

void Parser::parseDelimiter() {
    std::cout << "Ayraçları işle: " << tokens[position++].value << std::endl;
}

void Parser::parseComma() {
    std::cout << "Virgül işle" << std::endl;
}

void Parser::parseSemicolon() {
    std::cout << "Noktalı virgül işle" << std::endl;
}

void Parser::parseDot() {
    std::cout << "Nokta işle" << std::endl;
}
