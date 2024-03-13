#include <stdio.h>
#include <iostream>
#include <string>
#include <random>
#include <chrono>

#include "generator/random_hash.cpp"
#include "generator/user_input.cpp"
#include "generator/pronounce_pw.cpp"


int main() {
    srand(static_cast<unsigned>(time(NULL)));

    int num_caracteres = 0;
    int opcao = 0;
    std::string Senha;

    while (num_caracteres < 8 || num_caracteres > 20) {
        system("cls");
        std::cout << "--- Gerador de Senha ---";
        std::cout << "\n\n";
        std::cout << "Informe o Numero de Caracteres Desejado (Min 8 - Max 20)";
        std::cout << "\n";
        std::cin >> num_caracteres;
    }

    while (opcao < 1 || opcao > 4) {
        system("cls");
        std::cout << "Informe o Tipo da Senha:";
        std::cout << "\n  1. Senha Aleatoria";
        std::cout << "\n  2. Palavra Inserida pelo Usuario";
        std::cout << "\n  3. Senha de facil pronuncia"; 
        std::cout << "\n  4. Sair";
        std::cout << "\n";
        std::cin >> opcao;
    }

    switch (opcao) {
        case 1:
            Senha = Senha_aleatoria(num_caracteres);
            break;
        
        case 2:
            Senha = Senha_forte(num_caracteres);
            break;

        case 3:
            Senha = Senha_pronunciavel(num_caracteres);
            break;

        default:
            break;
    }

    std::cout << "\n-----------------------\n";
    std::cout << Senha;

    return 0;
}