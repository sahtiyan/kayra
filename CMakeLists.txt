cmake_minimum_required(VERSION 3.10)
project(Kayra)

# Derleme ayarları
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Kaynak dosyalarını ekle
set(SOURCES 
    src/kayra.cpp
    lexer/Lexer.cpp
    parser/Parser.cpp
)

# Başlık dosyalarını ekle
set(HEADERS 
    include/Lexer.h
    include/Parser.h
)

# Örnek dosyaları ekle
set(EXAMPLES 
    examples/merhaba_dunya.ky
    examples/oo_ornek.ky
    examples/nesne_ornek.ky # Yeni dosya eklendi
)

# Yürütülebilir dosyayı oluştur
add_executable(kayra ${SOURCES} ${HEADERS})

# Örnek dosyaları hedefe kopyala
foreach(EXAMPLE ${EXAMPLES})
    file(COPY ${EXAMPLE} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/examples)
endforeach()
