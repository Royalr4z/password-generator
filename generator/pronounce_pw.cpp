#include <stdio.h>
#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <cmath>


std::string Senha_pronunciavel(size_t num_caracteres) {

    std::string caracteres_especiais = "@#$%&*()[]?!{}";
    std::string numeros = "0123456789";

    // Lista de silabas para o jogo
    std::string silabas[] = { "ba", "be", "bi", "bo", "bu", "ca", "ce","ci", "co", "cu",
            "da", "de", "di", "do", "du", "fa", "fe", "fi", "fo", "fu",
            "ga", "ge", "gi", "go", "gu", "ha", "he", "hi", "ho", "hu",
            "ja", "je", "ji", "jo", "ju", "ka", "ke", "ki", "ko", "ku",
            "la", "le", "li", "lo", "lu", "ma", "me", "mi", "mo", "mu",
            "na", "ne", "ni", "no", "nu", "pa", "pe", "pi", "po", "pu",
            "qa", "qe", "qi", "qo", "qu", "ra", "re", "ri", "ro", "ru",
            "sa", "se", "si", "so", "su", "ta", "te", "ti", "to", "tu",
            "va", "ve", "vi", "vo", "vu", "wa", "we", "wi", "wo", "wu",
            "xa", "xe", "xi", "xo", "xu", "ya", "ye", "yi", "yo", "yu",
            "za", "ze", "zi", "zo", "zu"};

    int num = floor((num_caracteres / 2) - 1 );
    int caracteres_faltante = num_caracteres - (num * 2); 
    std::string palavra = "";

    // Seed para o gerador de números aleatórios
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);


    for (int i = 0; i < num; i++) {

        // Gerar um índice aleatório para a silaba
        std::uniform_int_distribution<> i_slb(0, ( sizeof silabas ) / ( sizeof silabas[0] ) - 1);
        int indice_silaba = i_slb(gen);

        palavra += silabas[indice_silaba];
    }

    for (char& c : palavra) {
        if (std::rand() % 2 == 0) {
            c = std::toupper(c); // Transforma para maiúscula
        } else {
            c = std::tolower(c); // Transforma para minúscula
        }
    }

    if (caracteres_faltante == 2) {
    
        // Gerar um índice aleatório para o caractere
        std::uniform_int_distribution<> i_ctr(0, caracteres_especiais.size() - 1);
        int indice_caractere = i_ctr(gen);

        // Gerar um índice aleatório para o numero
        std::uniform_int_distribution<> i_num(0, numeros.size() - 1);
        int indice_num = i_num(gen);
    
        palavra += caracteres_especiais[indice_caractere];
        palavra += numeros[indice_num];

    } else if (caracteres_faltante == 3) {

        // Gerar um índice aleatório para o caractere
        std::uniform_int_distribution<> i_ctr(0, caracteres_especiais.size() - 1);
        int indice_caractere = i_ctr(gen);

        palavra += caracteres_especiais[indice_caractere];

        for (int i = 0; i < 2; i++) {

            // Gerar um índice aleatório para o numero
            std::uniform_int_distribution<> i_num(0, numeros.size() - 1);
            int indice_num = i_num(gen);

            palavra += numeros[indice_num];
        }
    }

    return palavra;
}
