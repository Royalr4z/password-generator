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
