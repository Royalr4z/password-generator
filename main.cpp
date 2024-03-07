#include <stdio.h>
#include <iostream>
#include <string>
#include <random>
#include <chrono>

std::string Adicionando_numeros(std::string Senha) {

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


std::string Gerador_de_Senha(int num_caracteres) {

    std::string letras = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string caracteres_especiais = "@#$%&*()-_+=[]|?!/\\{}^_.";
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

    Senha = Adicionando_numeros(Senha);

    return Senha;
}


int main() {
    int num_caracteres = 0;
    std::string Senha;

    while (num_caracteres < 8 || num_caracteres > 20) {
        system("cls");
        std::cout << "--- Gerador de Senha ---";
        std::cout << "\n\n";
        std::cout << "Informe o Numero de Caracteres Desejado (Min 8 - Max 20)";
        std::cout << "\n";
        std::cin >> num_caracteres;
    }

    Senha = Gerador_de_Senha(num_caracteres);

    std::cout << "\n-----------------------\n";
    std::cout << Senha;

    return 0;
}