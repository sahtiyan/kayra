// Lexer.cpp

#include "../include/Lexer.h"
#include <iostream>
#include <cctype>

Lexer::Lexer(std::string src) : source(src), position(0) {}

std::vector<Token> Lexer::tokenize() {
    while (position < source.length()) {
        char current_char = source[position];
        if (isdigit(current_char)) {
            tokens.push_back(lexNumber());
        } else if (current_char == '"') {
            Token token = lexString();
            tokens.push_back(token);
            std::cout << "Metin tokeni: " << token.value << std::endl;
        } else if (isalpha(current_char)) {
            tokens.push_back(lexIdentifier());
        } else if (current_char == '{' || current_char == '}') {
            tokens.push_back({TokenType::Ayraç, std::string(1, current_char)});
            position++;
        } else if (current_char == '(' || current_char == ')' || current_char == '[' || current_char == ']') {
            tokens.push_back({TokenType::Ayraç, std::string(1, current_char)});
            position++;
        } else if (current_char == '+' || current_char == '-' || current_char == '*' || current_char == '/') {
            tokens.push_back({TokenType::Operator, std::string(1, current_char)});
            position++;
        } else if (current_char == '/') {
            if (position + 1 < source.length() && source[position + 1] == '/') {
                lexComment();
            } else {
                position++;
            }
        } else {
            position++;
        }
    }
    return tokens;
}

Token Lexer::lexNumber() {
    size_t start = position;
    bool hasDecimalPoint = false; // Ondalıklı sayı kontrolü için
    while (position < source.length() && (isdigit(source[position]) || source[position] == '.')) {
        if (source[position] == '.') {
            if (hasDecimalPoint) {
                break; // Birden fazla ondalık nokta varsa döngüyü sonlandır
            }
            hasDecimalPoint = true;
        }
        position++;
    }
    return {hasDecimalPoint ? TokenType::Ondalıklı_Sayı : TokenType::Tamsayı, source.substr(start, position - start)};
}

Token Lexer::lexString() {
    size_t start = position + 1; // Tırnak işaretinin sonundan sonraki pozisyondan başla
    position++; // Bir sonraki karaktere geç
    while (position < source.length() && source[position] != '"') {
        position++; // Tırnak işaretinin sonuna kadar ilerle
    }
    if (position == source.length()) {
        // Hata işleme: Metin bitiş tırnak işareti ile kapatılmamış
        return {TokenType::Hata, "Metin bitiş tırnak işareti ile kapatılmamış"};
    }
    std::string text = source.substr(start, position - start); // Tırnak işaretlerini dahil etmeden metni al
    position++; // Tırnak işaretinin sonundan sonraki karaktere geç
    return {TokenType::Metin, text};
}

Token Lexer::lexIdentifier() {
    size_t start = position;
    while (position < source.length() && isalnum(source[position])) {
        position++;
    }
    std::string identifier = source.substr(start, position - start);
    if (identifier == "ana" || identifier == "tam" || identifier == "gerçek" || identifier == "metin" ||
        identifier == "dizi" || identifier == "eğer" || identifier == "değilse" || identifier == "döngü" ||
        identifier == "nesne" || identifier == "metot") {
        return {TokenType::Anahtar_Kelime, identifier};
    }
    return {TokenType::Tanımsız, identifier};
}

Token Lexer::lexComment() {
    size_t start = position;
    while (position < source.length() && source[position] != '\n') {
        position++;
    }
    return {TokenType::Yorum, source.substr(start, position - start)};
}
