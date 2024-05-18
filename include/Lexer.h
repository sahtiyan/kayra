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
    Nesne,
    Yorum,
    Hata,
    Virgül,
    Noktalı_Virgül,
    Nokta,
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
    Token lexComment();
    Token lexOperator();
    Token lexDelimiter();
    Token lexComma();
    Token lexSemicolon();
    Token lexDot();
};

#endif // LEXER_H
