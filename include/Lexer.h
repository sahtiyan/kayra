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
    Virgül,
    Noktalı_Virgül,
    Nokta,
    Atama,
    Karsilastirma,
    Mantiksal,
    Bitwise,
    Bilinmeyen
};

struct Token {
    TokenType type;
    std::string value;

    Token(TokenType t, const std::string &v) : type(t), value(v) {}
};

class Lexer {
private:
    std::string source;
    size_t position;

    Token parseIdentifier();
    Token parseNumber();
    Token parseFloat();
    Token parseString();
    Token parseOperator();
    Token parseDelimiter();
    bool isOperator(char c);
    bool isDelimiter(char c);

public:
    Lexer(const std::string &source);
    std::vector<Token> tokenize();
};

#endif // LEXER_H
