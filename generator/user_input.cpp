#include <stdio.h>
#include <iostream>
#include <string>
#include <random>
#include <chrono>


std::string Senha_forte(size_t num_caracteres) {

    std::string letras = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string caracteres_especiais = "@#$%&*()[]?!{}";
    std::string numeros = "0123456789";
    std::string palavra_escolhida;

    std::cout << "\nInforme uma Palavra: ";
    std::cout << "\n";
    std::cin >> palavra_escolhida;

    std::srand(std::time(0)); // Seed para geração de números aleatórios

    for (char& c : palavra_escolhida) {
        if (std::rand() % 2 == 0) {
            c = std::toupper(c); // Transforma para maiúscula
        } else {
            c = std::tolower(c); // Transforma para minúscula
        }

        // Convertendo para Leet(1337)
        if (c == 'a' or c == 'A') {
            c = '4';
        } else if (c == 'e' or c == 'E') {
            c = '3';
        } else if (c == 'i' or c == 'I') {
            c = '1';
        } else if (c == 'o' or c == 'O') {
            c = '0';
        } else if (c == 't' or c == 'T') {
            c = '7';
        } else if (c == 's' or c == 'S') {
            c = '5';
        }
    
    }

    // Seed para o gerador de números aleatórios
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);

    int i_inicio = 0;
    int i_final = 0;

    while (palavra_escolhida.length() < num_caracteres) {

        // Gerar um índice aleatório para o caractere
        std::uniform_int_distribution<> i_ctr(0, caracteres_especiais.size() - 1);
        int indice_caractere = i_ctr(gen);

        // Gerar um índice aleatório para o numero
        std::uniform_int_distribution<> i_num(0, numeros.size() - 1);
        int indice_num = i_num(gen);

        // Gerar um índice aleatório para as letras
        std::uniform_int_distribution<> i_lts(0, letras.size() - 1);
        int indice_lts = i_lts(gen);

        if (palavra_escolhida.length() % 2 == 0) {
            
            if (i_final % 3 == 0) {
                palavra_escolhida += letras[indice_lts];
            } else if (i_final % 4 == 0) {
                palavra_escolhida += caracteres_especiais[indice_caractere];
            } else {
                palavra_escolhida += numeros[indice_num];
            }

            i_final++;

        } else {

            if (i_final % 3 == 0) {
                palavra_escolhida.insert(0, 1, caracteres_especiais[indice_caractere]);
            } else if (i_final % 4 == 0) {
                palavra_escolhida.insert(0, 1, numeros[indice_num]);
            } else {
                palavra_escolhida.insert(0, 1, letras[indice_lts]);
            }

            i_inicio++;
        }

    }

    return palavra_escolhida;
}
