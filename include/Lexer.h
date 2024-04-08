// Lexer.h

#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>

enum class TokenType {
    Anahtar_Kelime,
    Tamsayı,
    Ondalıklı_Sayı,
    Metin,
    Ayraç,
    Operator,
    Dönüş,
    Nesne, // Yeni eklendi
    Yorum, // Yeni eklendi
    Hata,  // Yeni eklendi
    Tanımsız
};

struct Token {
    TokenType type;
    std::string value;
};

class Lexer {
private:
    std::string source;
    std::vector<Token> tokens;
    size_t position;

public:
    Lexer(std::string src);

    std::vector<Token> tokenize();

private:
    Token lexNumber();
    Token lexString();
    Token lexIdentifier();
    Token lexComment(); // Yeni eklendi
};

#endif // LEXER_H
