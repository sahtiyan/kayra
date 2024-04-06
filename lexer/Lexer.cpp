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
            // Metin tokenini aldığımızda metni ekrana yazdıralım
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
                lexComment(); // Yorum satırı işleme
            } else {
                position++;
            }
        } else {
            // Diğer durumlar için hata işleme veya geçme
            position++;
        }
    }
    return tokens;
}

Token Lexer::lexNumber() {
    size_t start = position;
    while (position < source.length() && (isdigit(source[position]) || source[position] == '.')) {
        position++;
    }
    return {TokenType::Tamsayı, source.substr(start, position - start)};
}

Token Lexer::lexString() {
    size_t start = ++position; // Çift tırnak işaretini atlayarak başlayalım
    while (position < source.length() && source[position] != '"') {
        position++;
    }
    std::string text = source.substr(start, position - start); // Çift tırnak işareti olmadan metni al
    position++; // Son çift tırnak işaretini geç
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
