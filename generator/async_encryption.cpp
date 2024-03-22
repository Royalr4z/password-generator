#include <iostream>
#include <fstream>
#include <string>
#include <cryptopp/rsa.h>
#include <cryptopp/osrng.h>
#include <cryptopp/base64.h>

std::string Senha_criptografada() {

    CryptoPP::AutoSeededRandomPool rng;

    // Gerar chaves pública e privada
    CryptoPP::RSA::PrivateKey privateKey;
    privateKey.GenerateRandomWithKeySize(rng, 2048);

    CryptoPP::RSA::PublicKey publicKey(privateKey);

    // Serializar a chave privada
    std::string privateKeyStr;
    CryptoPP::StringSink privateKeySink(privateKeyStr);
    privateKey.DEREncode(privateKeySink);

    // Serializar a chave pública
    std::string publicKeyStr;
    CryptoPP::StringSink publicKeySink(publicKeyStr);
    publicKey.DEREncode(publicKeySink);

    std::string plainText;

    system("clear");

    // Mensagem a ser criptografada
    std::cout << "Informe a Senha: " << std::endl;;
    std::cin >> plainText;

    // Criptografar a mensagem com a chave pública
    std::string cipherText;
    CryptoPP::RSAES_OAEP_SHA_Encryptor encryptor(publicKey);
    CryptoPP::StringSource(plainText, true,
        new CryptoPP::PK_EncryptorFilter(rng, encryptor,
            new CryptoPP::StringSink(cipherText)
        )
    );

    // Descriptografar a mensagem com a chave privada
    std::string decryptedText;
    CryptoPP::RSAES_OAEP_SHA_Decryptor decryptor(privateKey);
    CryptoPP::StringSource(cipherText, true,
        new CryptoPP::PK_DecryptorFilter(rng, decryptor,
            new CryptoPP::StringSink(decryptedText)
        )
    );

    std::ofstream arquivo("Keys.txt");

    // Convertendo a chave Privada para Base64
    std::string base64PrivateKey;
    CryptoPP::StringSource(privateKeyStr, true,
        new CryptoPP::Base64Encoder(
            new CryptoPP::StringSink(base64PrivateKey),
            false // não quebrar linhas
        )
    );

    // Convertendo a chave Publica para Base64
    std::string base64PublicKey;
    CryptoPP::StringSource(publicKeyStr, true,
        new CryptoPP::Base64Encoder(
            new CryptoPP::StringSink(base64PublicKey),
            false // não quebrar linhas
        )
    );

    if (arquivo.is_open()) {

        // Imprimir as chaves
        arquivo << "Chave privada: " << std::endl;
        arquivo << base64PrivateKey << std::endl;

        arquivo << "Chave pública: " << std::endl;
        arquivo << base64PublicKey << std::endl;

    }

    // Convertendo a Senha Criptografada para Base64
    std::string base64Password;
    CryptoPP::StringSource(cipherText, true,
        new CryptoPP::Base64Encoder(
            new CryptoPP::StringSink(base64Password),
            false // não quebrar linhas
        )
    );

    return base64Password;
}
