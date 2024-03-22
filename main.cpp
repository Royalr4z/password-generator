#include <stdio.h>
#include <iostream>
#include <string>
#include <random>
#include <chrono>

#include "generator/random_hash.cpp"
#include "generator/user_input.cpp"
#include "generator/pronounce_pw.cpp"
#include "generator/async_encryption.cpp"


int main() {
    srand(static_cast<unsigned>(time(NULL)));

    int num_caracteres = 0;
    int opcao = 0;
    std::string Senha;

    while (opcao < 1 || opcao > 5) {
        system("clear");
        std::cout << "Informe o Tipo da Senha:";
        std::cout << "\n  1. Senha Aleatoria";
        std::cout << "\n  2. Palavra Inserida pelo Usuario";
        std::cout << "\n  3. Senha de facil pronuncia"; 
        std::cout << "\n  4. Senha Criptografada";
        std::cout << "\n  5. Sair";
        std::cout << "\n";
        std::cin >> opcao;
    }

    if (opcao >= 4) { num_caracteres = 8; }

    while (num_caracteres < 8 || num_caracteres > 20) {
        system("clear");
        std::cout << "--- Gerador de Senha ---";
        std::cout << "\n\n";
        std::cout << "Informe o Numero de Caracteres Desejado (Min 8 - Max 20)";
        std::cout << "\n";
        std::cin >> num_caracteres;
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
        
        case 4:
            Senha = Senha_criptografada();
            break;

        default:
            break;
    }

    std::cout << "\n-----------------------\n";
    std::cout << Senha;
    std::cout << "\n-----------------------\n";

    return 0;
}