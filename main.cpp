#include <stdio.h>
#include <iostream>
#include <string>
#include <random>
#include <chrono>

std::string Add_numeros(std::string Senha) {

    std::string numeros = "0123456789";

    // Seed para o gerador de números aleatórios
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);

    // Gerar um índice para a Senha
    std::uniform_int_distribution<> i_senha(0, Senha.size() - 1);
    int indice_Senha = i_senha(gen);

    // Gerar um índice aleatório para o número
    std::uniform_int_distribution<> i_num(0, numeros.size() - 1);
    int indice_numero = i_num(gen);

    // Adicionando um número aleatório em um índice aleatório
    Senha[indice_Senha] = numeros[indice_numero];

    return Senha;
}

std::string Add_caractere_especial(std::string Senha) {

    std::string caracteres_especiais = "@#$%&*()-_+=[]|?!/\\{}^_.";

    // Seed para o gerador de números aleatórios
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);

    // Gerar um índice para a Senha
    std::uniform_int_distribution<> i_senha(0, Senha.size() - 2);
    int indice_Senha = i_senha(gen);

    // Gerar um índice aleatório para o caractere
    std::uniform_int_distribution<> i_num(0, caracteres_especiais.size() - 1);
    int indice_caractere = i_num(gen);

    if (indice_Senha < 3) {
        // Adicionando um caractere aleatório em um índice aleatório
        Senha[indice_Senha + 3] = caracteres_especiais[indice_caractere];
    } else if (indice_Senha >= 3) {
        // Adicionando um caractere aleatório em um índice aleatório
        Senha[indice_Senha - 3] = caracteres_especiais[indice_caractere];
    }

    return Senha;
}


std::string Senha_aleatoria(int num_caracteres) {

    std::string letras = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string Senha;

    // Seed para o gerador de números aleatórios
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);

    for (int i = 0; i < num_caracteres; i++) {

        // Gerar um índice aleatório
        std::uniform_int_distribution<> dis(0, letras.size() - 1);
        int indice_aleatorio = dis(gen);

        // Pegar o caractere aleatório
        char caractere_aleatorio = letras[indice_aleatorio];
    
        Senha += caractere_aleatorio;

    }

    Senha = Add_numeros(Senha);
    Senha = Add_caractere_especial(Senha);

    return Senha;
}


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
                palavra_escolhida += caracteres_especiais[indice_caractere];
            } else if (i_final % 4 == 0) {
                palavra_escolhida += numeros[indice_num];
            } else {
                palavra_escolhida += letras[indice_lts];
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

    while (opcao < 1 || opcao > 3) {
        system("cls");
        std::cout << "Informe o Tipo da Senha:";
        std::cout << "\n  1. Senha Aleatoria";
        std::cout << "\n  2. Palavra Inserida pelo Usuario";
        std::cout << "\n  3. Sair";
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

        default:
            break;
    }

    std::cout << "\n-----------------------\n";
    std::cout << Senha;

    return 0;
}