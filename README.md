# Password Generator

Este repositório Gera uma Password de acordo com o número de caracteres desejado.
Podendo ser uma Senha aleatória, Senha de fácil pronúncia ou uma senha criada a partir do input do usuário, 
Também tem a opção de criptografar sua senha gerando automaticamente uma chave pública e uma chave privada

# Como Compilar e Executar (Fedora Linux)

1. Certifique-se de ter um compilador C++ instalado em seu sistema.
```
sudo dnf install gpp
```
2. Clone este repositório em seu computador: <br/>
```
git clone https://github.com/Royalr4z/password-generator.git
```
3. Instale o Cryptopp: <br/>
```
sudo dnf install cryptopp-devel
```
4. Compile o Gerador de Senha: <br/>
```
g++ -o main main.cpp -lcryptopp
```
5. Execute o Gerador de Senha: <br/>
```
./main
```

# Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir issues relatando problemas, sugestões ou novos recursos que gostaria de ver. Se deseja contribuir com código, por favor, envie um pull request.
