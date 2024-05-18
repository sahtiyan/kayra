#include "../include/Parser.h"
#include <iostream>

Parser::Parser(std::vector<Token> t) : tokens(t), position(0) {}

void Parser::parse() {
    parseMainFunction();
}

void Parser::parseMainFunction() {
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
            case TokenType::Atama:
                parseAssignment();
                break;
            case TokenType::Karsilastirma:
                parseComparison();
                break;
            case TokenType::Mantiksal:
                parseLogical();
                break;
            case TokenType::Bitwise:
                parseBitwise();
                break;
            default:
                position++;
                break;
        }
    }
}

void Parser::parseKeyword() {
    Token keyword = tokens[position++];
    if (keyword.value == "ana") {
        // Ana fonksiyonu işleme gerek yok, zaten parseMainFunction() içindeyiz
    } else if (keyword.value == "tam") {
        parseIntegerDeclaration();
    } else if (keyword.value == "gerçek") {
        parseFloatDeclaration();
    } else if (keyword.value == "metin") {
        parseStringDeclaration();
    } else if (keyword.value == "dizi") {
        parseArrayDeclaration();
    } else if (keyword.value == "eğer") {
        parseIfStatement();
    } else if (keyword.value == "değilse") {
        parseElseStatement();
    } else if (keyword.value == "döngü") {
        parseLoopStatement();
    } else if (keyword.value == "nesne") {
        parseObjectDeclaration();
    } else if (keyword.value == "metot") {
        parseMethodDeclaration();
    } else if (keyword.value == "dön") {
        parseReturnStatement();
    } else if (keyword.value == "boş") {
        parseVoid();
    } else if (keyword.value == "değiştir") {
        parseSwitchStatement();
    } else if (keyword.value == "dur") {
        parseBreakStatement();
    } else if (keyword.value == "devam") {
        parseContinueStatement();
    } else if (keyword.value == "yeni") {
        parseNewKeyword();
    } else if (keyword.value == "bu") {
        parseThisKeyword();
    } else {
        std::cerr << "Bilinmeyen anahtar kelime: " << keyword.value << std::endl;
    }
}

void Parser::parseIntegerDeclaration() {
    std::cout << "Tamsayı değişkeni bildirimi işleniyor" << std::endl;
}

void Parser::parseFloatDeclaration() {
    std::cout << "Ondalıklı sayı değişkeni bildirimi işleniyor" << std::endl;
}

void Parser::parseStringDeclaration() {
    std::cout << "Metin değişkeni bildirimi işleniyor" << std::endl;
}

void Parser::parseArrayDeclaration() {
    std::cout << "Dizi bildirimi işleniyor" << std::endl;
}

void Parser::parseIfStatement() {
    std::cout << "Eğer bildirimi işleniyor" << std::endl;
}

void Parser::parseElseStatement() {
    std::cout << "Değilse bildirimi işleniyor" << std::endl;
}

void Parser::parseLoopStatement() {
    std::cout << "Döngü bildirimi işleniyor" << std::endl;
}

void Parser::parseReturnStatement() {
    std::cout << "Dönüş bildirimi işleniyor" << std::endl;
}

void Parser::parseObjectDeclaration() {
    std::cout << "Nesne bildirimi işleniyor" << std::endl;
}

void Parser::parseMethodDeclaration() {
    std::cout << "Metot bildirimi işleniyor" << std::endl;
}

void Parser::parseSwitchStatement() {
    std::cout << "Değiştir bildirimi işleniyor" << std::endl;
}

void Parser::parseBreakStatement() {
    std::cout << "Dur bildirimi işleniyor" << std::endl;
}

void Parser::parseContinueStatement() {
    std::cout << "Devam bildirimi işleniyor" << std::endl;
}

void Parser::parseNewKeyword() {
    std::cout << "Yeni bildirimi işleniyor" << std::endl;
}

void Parser::parseThisKeyword() {
    std::cout << "Bu bildirimi işleniyor" << std::endl;
}
