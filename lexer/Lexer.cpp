#include "../include/Lexer.h"
#include <cctype>
#include <cstring>
#include <iostream>

Lexer::Lexer(std::string src) : source(src), position(0) {}

std::vector<Token> Lexer::tokenize() {
    while (position < source.length()) {
        char current_char = source[position];

        if (isspace(current_char)) {
            position++;
            continue;
        }

        if (isdigit(current_char)) {
            tokens.push_back(lexNumber());
        } else if (current_char == '"' || current_char == '\'') {
            tokens.push_back(lexString());
        } else if (isalpha(current_char)) {
            tokens.push_back(lexIdentifier());
        } else if (current_char == '/' && source[position + 1] == '/') {
            tokens.push_back(lexComment());
        } else if (strchr("+-*/%=&|<>!", current_char)) {
            tokens.push_back(lexOperator());
        } else if (strchr("(){}[]", current_char)) {
            tokens.push_back(lexDelimiter());
        } else if (current_char == ',') {
            tokens.push_back(lexComma());
        } else if (current_char == ';') {
            tokens.push_back(lexSemicolon());
        } else if (current_char == '.') {
            tokens.push_back(lexDot());
        } else {
            tokens.push_back({TokenType::Hata, std::string(1, current_char)});
            position++;
        }
    }
    return tokens;
}

Token Lexer::lexNumber() {
    size_t start_position = position;
    while (isdigit(source[position]) || source[position] == '.') {
        position++;
    }
    return {TokenType::Tamsayı, source.substr(start_position, position - start_position)};
}

Token Lexer::lexString() {
    char quote_type = source[position];
    size_t start_position = ++position;
    while (source[position] != quote_type) {
        position++;
    }
    position++; // Closing quote
    return {TokenType::Metin, source.substr(start_position, position - start_position - 1)};
}

Token Lexer::lexIdentifier() {
    size_t start_position = position;
    while (isalnum(source[position]) || source[position] == '_') {
        position++;
    }
    std::string identifier = source.substr(start_position, position - start_position);

    TokenType type = TokenType::Anahtar_Kelime;
    if (identifier == "ana" || identifier == "tam" || identifier == "gerçek" ||
        identifier == "metin" || identifier == "dizi" || identifier == "eğer" ||
        identifier == "değilse" || identifier == "döngü" || identifier == "dönüş" ||
        identifier == "nesne" || identifier == "metot" || identifier == "boş" ||
        identifier == "değişim" || identifier == "kes" || identifier == "devam" ||
        identifier == "yeni" || identifier == "bu") {
        type = TokenType::Anahtar_Kelime;
    } else {
        type = TokenType::Tanımsız;
    }

    return {type, identifier};
}

Token Lexer::lexComment() {
    size_t start_position = position;
    while (source[position] != '\n') {
        position++;
    }
    return {TokenType::Yorum, source.substr(start_position, position - start_position)};
}

Token Lexer::lexOperator() {
    size_t start_position = position;
    while (strchr("+-*/%=&|<>!", source[position])) {
        position++;
    }
    return {TokenType::Operator, source.substr(start_position, position - start_position)};
}

Token Lexer::lexDelimiter() {
    return {TokenType::Ayraç, std::string(1, source[position++])};
}

Token Lexer::lexComma() {
    return {TokenType::Virgül, std::string(1, source[position++])};
}

Token Lexer::lexSemicolon() {
    return {TokenType::Noktalı_Virgül, std::string(1, source[position++])};
}

Token Lexer::lexDot() {
    return {TokenType::Nokta, std::string(1, source[position++])};
}
