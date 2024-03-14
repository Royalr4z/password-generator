#include <iostream>
#include <string>
#include <cryptopp/rsa.h>
#include <cryptopp/osrng.h>
#include <cryptopp/base64.h>

int main() {
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

    // Imprimir as chaves
    std::cout << "Chave privada: " << std::endl;
    std::cout << privateKeyStr << std::endl;

    std::cout << "Chave pública: " << std::endl;
    std::cout << publicKeyStr << std::endl;

    // Mensagem a ser criptografada
    std::string plainText = "Mensagem secreta";

    // Criptografar a mensagem com a chave pública
    std::string cipherText;
    CryptoPP::RSAES_OAEP_SHA_Encryptor encryptor(publicKey);
    CryptoPP::StringSource(plainText, true,
        new CryptoPP::PK_EncryptorFilter(rng, encryptor,
            new CryptoPP::StringSink(cipherText)
        )
    );

    std::cout << "Texto criptografado: " << std::endl;
    std::cout << cipherText << std::endl;

    // Descriptografar a mensagem com a chave privada
    std::string decryptedText;
    CryptoPP::RSAES_OAEP_SHA_Decryptor decryptor(privateKey);
    CryptoPP::StringSource(cipherText, true,
        new CryptoPP::PK_DecryptorFilter(rng, decryptor,
            new CryptoPP::StringSink(decryptedText)
        )
    );

    std::cout << "Texto descriptografado: " << std::endl;
    std::cout << decryptedText << std::endl;

    return 0;
}
