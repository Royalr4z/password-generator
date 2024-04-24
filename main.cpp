#include <stdio.h>
#include <iostream>
#include <string>
#include <random>
#include <chrono>

#include "generator/random_hash.cpp"
#include "generator/user_input.cpp"
#include "generator/pronounce_pw.cpp"

// Verifica se o sistema operacional é Windows.
// OBS: Geralmente, o Cryptopp não está instalado no Windows,
// o que pode resultar em um erro no "generator/async_encryption.cpp".
#ifdef _WIN32
    #define _Linux false
    #define _NumOptions 4
    std::string Senha_criptografada();
#else
    #define _Linux true
    #define _NumOptions 5
    #include "generator/async_encryption.cpp"
#endif



int main() {
    srand(static_cast<unsigned>(time(NULL)));

    int num_caracteres = 0;
    int opcao = 0;
    std::string Senha;

    while (opcao < 1 || opcao > _NumOptions) {
        system("clear");

        std::cout << "       .--------.         " << std::endl;
        std::cout << "      / .------. \\       " << std::endl;
        std::cout << "     / /        \\ \\     " << std::endl;
        std::cout << "     | |        | |       " << std::endl;
        std::cout << "    _| |________| |_      " << std::endl;
        std::cout << "  .' |_|        |_| '.    " << std::endl;
        std::cout << "  '._____ ____ _____.'    " << std::endl;
        std::cout << "  |     .'____'.     |    " << std::endl;
        std::cout << "  '.__.'.'    '.'.__.'    " << std::endl;
        std::cout << "  '.__  | LOCK |  __.'    " << std::endl;
        std::cout << "  |   '.'.____.'.'   |    " << std::endl;
        std::cout << "  '.____'.____.'____.'    " << std::endl;
        std::cout << "  '.________________.'    " << std::endl;
        std::cout << "========================" << std::endl;

        std::cout << "Informe o Tipo da Senha:" << std::endl;
        std::cout << "  1. Senha Aleatoria" << std::endl;
        std::cout << "  2. Palavra Inserida pelo Usuario" << std::endl;
        std::cout << "  3. Senha de facil pronuncia" << std::endl;

        if (_Linux) {
            std::cout << "  4. Senha Criptografada" << std::endl;
            std::cout << "  5. Sair" << std::endl;
        } else if (!_Linux) {
            std::cout << "  4. Sair" << std::endl;
        }

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
            if (_Linux) {
                Senha = Senha_criptografada();
            }

            break;

        default:
            break;
    }

    std::cout << "\n-----------------------\n";
    std::cout << Senha;
    std::cout << "\n-----------------------\n";

    return 0;
}