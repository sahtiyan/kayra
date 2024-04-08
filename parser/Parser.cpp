// Parser.cpp

#include "../include/Parser.h"
#include <iostream>

Parser::Parser(std::vector<Token> t) : tokens(t), position(0) {}

void Parser::parse() {
    parseMainFunction(); // Ana fonksiyonu doğrudan burada çağırın
}

void Parser::parseMainFunction() {
    // Ana fonksiyonu işle
    std::cout << "Ana fonksiyon işle" << std::endl;

    while (position < tokens.size()) {
        Token current_token = tokens[position];
        switch (current_token.type) {
            case TokenType::Anahtar_Kelime:
                parseKeyword();
                break;
            case TokenType::Tamsayı:
                parseInteger();
                break;
            case TokenType::Ondalıklı_Sayı:
                parseFloat();
                break;
            case TokenType::Metin:
                parseString();
                break;
            case TokenType::Ayraç:
                parseDelimiter();
                break;
            case TokenType::Operator:
                parseOperator();
                break;
            default:
                // Hata işleme veya geçme
                break;
        }
        // Pozisyonu artır
        position++;
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
    } else if (keyword.value == "dönüş") {
        parseReturnStatement();
    } else if (keyword.value == "nesne") {
        parseObjectDeclaration();
    } else if (keyword.value == "metot") {
        parseMethodDeclaration(); // "metot" anahtarı eklendi
    }
}

void Parser::parseIntegerDeclaration() {
    // Tamsayı tanımını işle
    std::cout << "Tamsayı tanımını işle" << std::endl;
}

void Parser::parseFloatDeclaration() {
    // Ondalıklı sayı tanımını işle
    std::cout << "Ondalıklı sayı tanımını işle" << std::endl;
}

void Parser::parseStringDeclaration() {
    // Metin tanımını işle
    std::cout << "Metin tanımını işle" << std::endl;
}

void Parser::parseArrayDeclaration() {
    // Dizi tanımını işle
    std::cout << "Dizi tanımını işle" << std::endl;
}

void Parser::parseIfStatement() {
    // Koşul ifadesini işle
    std::cout << "Koşul ifadesini işle" << std::endl;
}

void Parser::parseElseStatement() {
    // Alternatif koşul ifadesini işle
    std::cout << "Alternatif koşul ifadesini işle" << std::endl;
}

void Parser::parseLoopStatement() {
    // Döngüyü işle
    std::cout << "Döngüyü işle" << std::endl;
}

void Parser::parseInteger() {
    // Tamsayıyı işle
    std::cout << "Tamsayıyı işle: " << tokens[position++].value << std::endl;
}

void Parser::parseFloat() {
    // Ondalıklı sayıyı işle
    std::cout << "Ondalıklı sayıyı işle: " << tokens[position++].value << std::endl;
}

void Parser::parseString() {
    // Metni işle
    std::string text = tokens[position].value;
    // Tırnak işaretlerini kaldır
    text = text.substr(1, text.length() - 2);
    std::cout << "Metini işle: " << text << std::endl;
    position++; // Pozisyonu artır
}

void Parser::parseDelimiter() {
    // Ayraçları işle
    std::cout << "Ayraçları işle: " << tokens[position++].value << std::endl;
}

void Parser::parseOperator() {
    // Operatörleri işle
    std::cout << "Operatörleri işle: " << tokens[position++].value << std::endl;
}

void Parser::parseReturnStatement() {
    // Dönüş ifadesini işle
    std::cout << "Dönüş ifadesini işle" << std::endl;
}

void Parser::parseObjectDeclaration() {
    // Nesne tanımını işle
    std::cout << "Nesne tanımını işle" << std::endl;
}

void Parser::parseMethodDeclaration() {
    // Metot tanımını işle
    std::cout << "Metot tanımını işle" << std::endl;
}
