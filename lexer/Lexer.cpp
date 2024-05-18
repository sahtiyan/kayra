#include "../include/Lexer.h"

Lexer::Lexer(const std::string &source) : source(source), position(0) {}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    while (position < source.length()) {
        char current_char = source[position];
        if (isalpha(current_char)) {
            tokens.push_back(parseIdentifier());
        } else if (isdigit(current_char)) {
            tokens.push_back(parseNumber());
        } else if (current_char == '"') {
            tokens.push_back(parseString());
        } else if (isOperator(current_char)) {
            tokens.push_back(parseOperator());
        } else if (isDelimiter(current_char)) {
            tokens.push_back(parseDelimiter());
        } else {
            position++;
        }
    }
    return tokens;
}

Token Lexer::parseIdentifier() {
    std::string identifier;
    while (position < source.length() && isalnum(source[position])) {
        identifier += source[position++];
    }
    return Token(TokenType::Anahtar_Kelime, identifier);
}

Token Lexer::parseNumber() {
    std::string number;
    while (position < source.length() && isdigit(source[position])) {
        number += source[position++];
    }
    return Token(TokenType::Tamsayı, number);
}

Token Lexer::parseString() {
    std::string str;
    position++;  // Skip opening quote
    while (position < source.length() && source[position] != '"') {
        str += source[position++];
    }
    position++;  // Skip closing quote
    return Token(TokenType::Metin, str);
}

Token Lexer::parseOperator() {
    char current_char = source[position++];
    switch (current_char) {
        case '+': return Token(TokenType::Operator, "+");
        case '-': return Token(TokenType::Operator, "-");
        case '*': return Token(TokenType::Operator, "*");
        case '/': return Token(TokenType::Operator, "/");
        case '=': return Token(TokenType::Atama, "=");
        case '<': return Token(TokenType::Karsilastirma, "<");
        case '>': return Token(TokenType::Karsilastirma, ">");
        case '&': return Token(TokenType::Mantiksal, "&");
        case '|': return Token(TokenType::Mantiksal, "|");
        case '!': return Token(TokenType::Mantiksal, "!");
        case '%': return Token(TokenType::Operator, "%");
        case '^': return Token(TokenType::Bitwise, "^");
        case '~': return Token(TokenType::Bitwise, "~");
        default: return Token(TokenType::Bilinmeyen, std::string(1, current_char));
    }
}

Token Lexer::parseDelimiter() {
    char current_char = source[position++];
    switch (current_char) {
        case '(': return Token(TokenType::Ayraç, "(");
        case ')': return Token(TokenType::Ayraç, ")");
        case '{': return Token(TokenType::Ayraç, "{");
        case '}': return Token(TokenType::Ayraç, "}");
        case '[': return Token(TokenType::Ayraç, "[");
        case ']': return Token(TokenType::Ayraç, "]");
        case ';': return Token(TokenType::Noktalı_Virgül, ";");
        case ',': return Token(TokenType::Virgül, ",");
        case '.': return Token(TokenType::Nokta, ".");
        default: return Token(TokenType::Bilinmeyen, std::string(1, current_char));
    }
}

bool Lexer::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '=' ||
           c == '<' || c == '>' || c == '&' || c == '|' || c == '!' ||
           c == '%' || c == '^' || c == '~';
}

bool Lexer::isDelimiter(char c) {
    return c == '(' || c == ')' || c == '{' || c == '}' || c == '[' ||
           c == ']' || c == ';' || c == ',' || c == '.';
}
