#include <iostream>
#include <fstream>
#include <string>
#include "../include/Lexer.h"   // Lexer başlık dosyasını dahil et
#include "../include/Parser.h"  // Parser başlık dosyasını dahil et

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Kullanım: kayra run <dosya_adı.ky>" << endl;
        return 1;
    }

    string arg = argv[1];
    if (arg != "run") {
        cout << "Geçersiz komut. Sadece 'run' komutu desteklenmektedir." << endl;
        return 1;
    }

    if (argc < 3) {
        cout << "Kullanım: kayra run <dosya_adı.ky>" << endl;
        return 1;
    }

    string filename = argv[2];

    // .ky dosyasını oku
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Dosya bulunamadı: " << filename << endl;
        return 1;
    }

    string source;
    string line;
    while (getline(file, line)) {
        source += line + "\n";
    }
    file.close();

    // Lexer ile kaynak kodu tokenize et
    Lexer lexer(source);
    vector<Token> tokens = lexer.tokenize();

    // Parser ile tokenleri analiz et ve işle
    Parser parser(tokens);
    parser.parse();

    return 0;
}
