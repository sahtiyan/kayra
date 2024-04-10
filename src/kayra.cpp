#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "../include/Lexer.h"
#include "../include/Parser.h"

using namespace std;

// Yardım metnini yazdıran fonksiyon
void printHelp() {
    cout << "Kullanım: kayra [SEÇENEKLER...] [DOSYA...]" << endl;
    cout << endl;
    cout << "SEÇENEKLER:" << endl;
    cout << "   -r, --run     Kayra kaynak kod dosyalarını çalıştırmak için." << endl;
    cout << "   -h, --help    Yardım menüsünü görüntülemek için." << endl;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printHelp();
        return 0;
    }

    string arg1 = argv[1];
    if (arg1 == "-h" || arg1 == "--help") {
        printHelp();
        return 0;
    }

    if (arg1 != "-r" && arg1 != "--run") {
        cout << "Geçersiz bayrak: " << arg1 << endl;
        return 1;
    }

    vector<string> files;
    for (int i = 2; i < argc; ++i) {
        string arg = argv[i];
        if (arg.empty() || arg[0] == '-') {
            cout << "Geçersiz bayrak veya dosya adı: " << arg << endl;
            return 1;
        }
        files.push_back(arg);
    }

    if (files.empty()) {
        cout << "Hata: Bir Kayra kaynak dosyası belirtilmedi." << endl;
        return 1;
    }

    // Dosyaları işleme
    for (const string& filename : files) {
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
    }

    return 0;
}
