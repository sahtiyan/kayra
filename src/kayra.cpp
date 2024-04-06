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
    if (argc < 2 || string(argv[1]) == "-h" || string(argv[1]) == "--help") {
        printHelp();
        return 0;
    }

    vector<string> args(argv + 1, argv + argc);
    vector<string> files;

    auto run_flag = find(args.begin(), args.end(), "-r");
    if (run_flag == args.end()) run_flag = find(args.begin(), args.end(), "--run");

    if (run_flag == args.end()) {
        cout << "Geçersiz kullanım: En az bir dosya belirtilmeli." << endl;
        return 1;
    } else {
        for (auto it = next(run_flag); it != args.end(); ++it) {
            if (it->at(0) == '-') {
                cout << "Geçersiz bayrak: " << *it << endl;
                return 1;
            }
            files.push_back(*it);
        }
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
