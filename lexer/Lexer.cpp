#include "../include/Lexer.h"
#include <cctype>

Lexer::Lexer(std::string src) : source(src), position(0) {}

std::vector<Token> Lexer::tokenize() {
    while (position < source.length()) {
        char current_char = source[position];
        if (isdigit(current_char)) {
            tokens.push_back(lexNumber());
        } else if (current_char == '"') {
            tokens.push_back(lexString());
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
    size_t start = ++position;
    while (position < source.length() && source[position] != '"') {
        position++;
    }
    position++;
    return {TokenType::Metin, source.substr(start, position - start - 1)};
}

Token Lexer::lexIdentifier() {
    size_t start = position;
    while (position < source.length() && isalnum(source[position])) {
        position++;
    }
    std::string identifier = source.substr(start, position - start);
    if (identifier == "ana" || identifier == "tam" || identifier == "gerçek" || identifier == "metin" ||
        identifier == "dizi" || identifier == "eğer" || identifier == "değilse" || identifier == "döngü") {
        return {TokenType::Anahtar_Kelime, identifier};
    } else if (identifier == "dönüş") {
        return {TokenType::Dönüş, identifier};
    }
    return {TokenType::Tanımsız, identifier};
}
